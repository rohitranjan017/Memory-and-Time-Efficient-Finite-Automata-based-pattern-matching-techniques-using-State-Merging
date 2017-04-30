#include<bits/stdc++.h>
using namespace std;
void preKMP(string pattern, int f[])
{
    int m = pattern.length(), k;
    f[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = f[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = f[k];
        }
        f[i] = k + 1;
    }
}
 
//check whether target string contains pattern 
bool KMP(string pattern, string target)
{
    int m = pattern.length();
    int n = target.length();
    int f[m];     
    preKMP(pattern, f);     
    int i = 0;
    int k = 0;        
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m)
                return 1;
        }
        else
            k = f[k];
    }
    return 0;
}
int main()
{
	 fstream fins;
	fins.open("sam.txt",ios::in);
	
	double time=clock();

	while(!fins.eof())
	{
	
	
	fstream fin;

	fin.open("keywords.txt",ios::in);
	
	int t;
	
	fin>>t;
	
		string txt;
		   
    
		fins>>txt;
	
	for(int i=0;i<t;i++)
	{
		string pat;
		fin>>pat;
		KMP(pat,txt);
	}
	
	fin.close();
	
	
	}	
	
	time=(clock()-time)/CLOCKS_PER_SEC;
	cout<<time<<endl;
	
	
	return 0;
}


