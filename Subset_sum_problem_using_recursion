#include<bits/stdc++.h>

using namespace std;

// return true or false for sum--> x 
// from array A[] has subset 

bool Subset(vector<int> A,int sum,int n)
{
    
    
    if(sum==0)
        return true;
    if(n==0)
        return false;
    
    // if element of A is bigger than sum
    
    if(A.at(n-1) > sum)    //ignore
        return Subset(A,sum,n-1);
    else        //either we include otherwise not 
        return Subset(A,sum,n-1)||Subset(A,sum-A.at(n-1),n-1);
    
    
}

int main()
{
    vector<int> A = {3, 34, 4, 12, 5, 2 }; 
    int sum = 89;
    
    cout <<Subset(A,sum,A.size());
}