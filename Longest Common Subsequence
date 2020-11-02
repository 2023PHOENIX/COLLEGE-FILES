#include<bits/stdc++.h>

using namespace std;

int longestCommon(string s1,string s2)
{
    int a = s1.size();
    int b = s2.size();
    
    int Z[a+1][b+1];
    
    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=b;j++)
        {
            if(i==0||j==0)
                Z[i][j] = 0;
            else if(s1.at(i-1)==s2.at(j-1))
                Z[i][j] = Z[i-1][j-1] + 1;
            else 
                Z[i][j] = max(Z[i-1][j],Z[i][j-1]);
        }
    }
    return Z[a][b];
}
int main()
{
    string s1;
    string s2;
    
    cin>>s1>>s2;
    
    cout<<longestCommon(s1,s2);
    
    
}