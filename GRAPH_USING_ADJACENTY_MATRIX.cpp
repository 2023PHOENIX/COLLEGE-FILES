#define ll long long 


const int INT_MAX = 2147483647;
const int INT_MIN = -2147483647;

#include<bits/stdc++.h>

using namespace std;
void addEdge(vector<int> V[], int a, int b)
{
    V[a].push_back(b);
    V[b].push_back(a);
}
void printG(vector<int> V[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i;
        for (auto v : V[i])
            cout << "->" << v;
        cout << endl;
    }
}
int main()
{
    int n = 5;
    vector<int> V[5];
    cout << "ENter linkers :";
    int l; cin >> l;
    for (int i = 0; i < l; i++)
    {
        int a, b;  cin >> a >> b;
        addEdge(V, a, b);
    }
    printG(V, n);



}