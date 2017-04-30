//remove states that are unreachable
#include<bits/stdc++.h>
#define up(j,k,i) for(i=j;i<k;i++)
#define down(j,k,i) for(i=j;i>k;i--)
#define pp(n) printf("%lld\n",n)
#define ps(s) printf("%s",s)
#define is(n) scanf("%lld",&n)
#define ips(n) scanf("%lld",n)
#define ss(s) scanf("%s",s)
#define cool 0
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define f(i) cout<<i<<endl;
#define pll pair<lld,lld> 
#define pi acos(-1)
#define dg(x) cout<<#x<<' '<<x<<endl;
#define dg2(x,y) cout<<#x<<' '<<x<<' '<<#y<<' '<<y<<endl;
#define dg3(x,y,z) cout<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define ds(n,m) scanf("%lld %lld",&n,&m)
#define ts(n,m,k) scanf("%lld %lld %lld",&n,&m,&k)
typedef long double ld;
typedef long long int lld;
using namespace std;
const lld M =1e4+7;
const lld mod=1e9+7;
const lld infi =LLONG_MAX;
const lld MAX_STATES=1e5+5;
lld i,j,ans,n,x,y,m,mymax=LLONG_MIN,mymin=LLONG_MAX,b,c,z,sum;
map <vector<lld>,lld> t_table,tf_table;//transitions table
bool is_finale[MAX_STATES];
vector <lld> row_t_table[MAX_STATES];
vector <pll> occurrence[MAX_STATES];
lld q0;
lld mycount[MAX_STATES+10];
//void mergef(lld original_state,lld current_state);
void merge(lld original_state,lld current_state)//merging for non final_states
{
 lld k;
 if(current_state==q0)
 {
  q0=original_state;
 }
 up(0,occurrence[current_state].size(),k)
 {
  if(is_finale[occurrence[current_state][k].F]==false)
  {
    t_table.erase(row_t_table[occurrence[current_state][k].F]);
    row_t_table[occurrence[current_state][k].F][occurrence[current_state][k].S-1]=original_state;
    if(t_table.find(row_t_table[occurrence[current_state][k].F])==t_table.end())
      t_table[row_t_table[occurrence[current_state][k].F]]=occurrence[current_state][k].F;
    else
      merge(t_table[row_t_table[occurrence[current_state][k].F]],occurrence[current_state][k].F);
  }
  else
  {
    tf_table.erase(row_t_table[occurrence[current_state][k].F]);
    row_t_table[occurrence[current_state][k].F][occurrence[current_state][k].S-1]=original_state;
    if(tf_table.find(row_t_table[occurrence[current_state][k].F])==tf_table.end())
      tf_table[row_t_table[occurrence[current_state][k].F]]=occurrence[current_state][k].F;
    else
      merge(tf_table[row_t_table[occurrence[current_state][k].F]],occurrence[current_state][k].F);
  }
 
 }
}
//void mergef(lld original_state,lld current_state)//merging for final_states
//{
//  up(0,occurrence[current_state].size(),k)
// {
//  if(is_finale[occurrence[current_state][k].F]==true)
//  {
//    tf_table.erase(row_t_table[occurrence[current_state][k].F]);
//    row_t_table[occurrence[current_state][k].F][occurrence[current_state][k].S-1]=original_state;
//    if(tf_table.find(row_t_table[occurrence[current_state][k].F])==tf_table.end())
//      tf_table[row_t_table[occurrence[current_state][k].F]]=occurrence[current_state][k].F;
//    else
//      mergef(tf_table[row_t_table[occurrence[current_state][k].F]],occurrence[current_state][k].F);
//  }
//  else
//  {
//    t_table.erase(row_t_table[occurrence[current_state][k].F]);
//    row_t_table[occurrence[current_state][k].F][occurrence[current_state][k].S-1]=original_state;
//    if(t_table.find(row_t_table[occurrence[current_state][k].F])==t_table.end())
//      t_table[row_t_table[occurrence[current_state][k].F]]=occurrence[current_state][k].F;
//    else
//      merge(t_table[row_t_table[occurrence[current_state][k].F]],occurrence[current_state][k].F);
//  }
// 
// }
//}
int main()
{
       lld k;
       freopen("preDFA.txt","r",stdin);
       freopen("minDFA.out","w",stdout);
       lld no_of_states,no_of_symbols,no_of_final_states;
       cin>>no_of_states>>no_of_symbols;//symbol from 1 to no_of_symbols
        //states from 0 to no_of_states-1
       vector <lld> final_states;
       cin>>no_of_final_states;
       lld transitions[no_of_states+10][no_of_symbols+10];
       up(0,no_of_final_states,i)
       {
        cin>>x;
        is_finale[x]=true;
       }
       lld source,symbol,destination;
       while(cin>>source>>symbol>>destination)
       {
          transitions[source][symbol]=destination;
          occurrence[destination].pb({source,symbol});
          mycount[destination]++;
       }
       up(0,no_of_states,i)
       {
        vector<lld> temp;
        if(mycount[i]==0)//removes states that are unreachable
          continue;
        up(1,no_of_symbols+1,j)
        {
          temp.pb(transitions[i][j]);
        }  
        if(is_finale[i]==true)
        {
          if(tf_table.find(temp)!=tf_table.end())
          {
              lld original_state=tf_table[temp];
              merge(original_state,i);
          }
          else
          {
              tf_table[temp]=i;
              row_t_table[i]=temp;
          }
        }
        else
        {
          if(t_table.find(temp)!=t_table.end())
          {
              lld original_state=t_table[temp];
              merge(original_state,i);
          }
          else
          {
              t_table[temp]=i;
              row_t_table[i]=temp;
          }
        }
       }
       //output format
       //total_states
       //total_transition
       //initial state
       //no of final_states
       //transitions
       //final states
       no_of_states=0;
       no_of_final_states=0;
       vector<pll> final_transitions[MAX_STATES+10];
       lld no_of_transitions=0;
       for(auto states:t_table)
       {
        j=1;
        lld current_state=states.S;
        no_of_states++;
        for(auto kk:states.F)
        {
          final_transitions[current_state].pb({j,kk});
          no_of_transitions++;
          j++;
        }
       } 
       for(auto states:tf_table)
       {
        j=1;
        lld current_state=states.S;
        no_of_states++;
        no_of_final_states++;
        final_states.pb(current_state);
        for(auto kk:states.F)
        {
          final_transitions[current_state].pb({j,kk});
          no_of_transitions++;
          j++;
        }
       }
       cout<<no_of_states<<' '<<no_of_transitions<<' '<<q0<<' '<<no_of_final_states<<endl;
       up(0,MAX_STATES+10,i)
       {
        for(auto kk:final_transitions[i])
        {
          cout<<i<<' '<<kk.F<<' '<<kk.S<<endl;
        }
       }
       for(auto kk:final_states)
       {
        cout<<kk<<' ';
       }
       cout<<endl;
        return 0;
}
