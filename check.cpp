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
const lld M =1e18+7;
const lld mod=1e9+7;
const lld infi =LLONG_MAX;
const lld max_no_of_states=1e5+5;
map <char,lld> transitions[max_no_of_states];
int main()
{
	

  fstream in_dfa;
  in_dfa.open("minDFA.out",ios::in);
  lld no_of_states,no_of_transitions,q0,no_of_final_states;
  in_dfa>>no_of_states>>no_of_transitions>>q0>>no_of_final_states;
  set<lld> final_states;
  lld i;
  up(0,no_of_transitions,i)
  {
    lld source,destination,label;
    in_dfa>>source>>label>>destination;
    if(!isalpha(label))
    {
      //cout<<"converting_labels into character assuming a to be 0\n";
      label+='a';
    }
    transitions[source][char(label-1)]=destination;
//    cout<<source<<' '<<char(label)<<' '<<destination<<endl;
  }
  up(0,no_of_final_states,i)
  {
    lld temp;
    in_dfa>>temp;
    final_states.insert(temp);
  }
  in_dfa.close();
   fstream fin;
    fin.open("sam.txt",ios::in);
    
    double time=clock();
  while(!fin.eof())
  {
    //cout<<"Enter string to be checked\nEnter -1 to exit\n";
    string input;
    
   
    
    fin>>input;
    if(input=="-1")break;
    i=0;
    lld current_state=q0;
    while(i<input.size())
    {
    	if(isalpha(input[i]))
    	input[i]=tolower(input[i]);
    	else
    	if(input[i]<'a' or input[i]>'z')
    	{
    		current_state=0;
    		i++;
    		continue;
    	}
    
      if(transitions[current_state].find(input[i])==transitions[current_state].end())
      {
        break;
      }
      current_state=transitions[current_state][input[i]];
      
       if(final_states.find(current_state)!=final_states.end())
       {
       		//cout<<"Block ";//input<<endl;
       		break;
       }
      
     // cout<<current_state<<endl;
      i++;
    }
    if(final_states.find(current_state)==final_states.end())
    {
      //cout<<"Allow ";//input<<endl;
    }
    
    
  }
  time=(clock()-time)/CLOCKS_PER_SEC;
  
  cout<<time<<endl;
  
  fin.close();
  
  return 0;
}
