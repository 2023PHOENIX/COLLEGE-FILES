#include<bits/stdc++.h>

using namespace std;

bool subset(vector<int> A,int sum,int n)
{
    bool K[n+1][sum+1];
    
    for(int i=0;i<=n;i++)
    {
        K[i][0] = true;
    }
    for(int j=1;j<=sum;j++)
        K[0][j] = false;
        
        
    for(int i=1;i<=n;i++)
    {    for(int j=1;j<=sum;j++)
        {
            if(j<A.at(i-1)) //ignore
                K[i][j] = K[i-1][j];
            if(j>=A.at(i-1))
                K[i][j] = K[i-1][j]||K[i-1][j-A.at(i-1)];
        }
    
    }
    return K[n][sum];
        
}


int main()
{
    vector<int> A{3, 34, 4, 12, 5, 2 };
    int sum=78;
    
    cout << subset(A,sum,A.size());
}