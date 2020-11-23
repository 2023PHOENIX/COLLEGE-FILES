const int INT_MAX = 2147483647;
const int INT_MIN = -2147483647;
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Edge
{
  public: 
    int source;
    int dest;
    int weight;

};

bool S(Edge a,Edge b)
{
  return a.weight > b.weight;
}

int findParent(int v,int *parent)
{
  if(parent[v] = v)
    return v;
  return findParent(parent[v],parent);
}
void Kruskals(Edge *input,int n,int E)
{
  // sort the input array 
  sort(input,input+E,S);

  Edge * output = new Edge[n-1];

  int count{0};
  int i{0};
  int *parent = new int[n];


  for(int i=0;i<n;i++)
    parent[i] = i;

  while(count<=n-1)
  {
    Edge currentEdge = input[i];  
    // check for cycle for current Edge
  int sourceParent = findParent(currentEdge.source,parent);
  int destParent = findParent(currentEdge.dest,parent);

  if(sourceParent != destParent)
      output[count] = currentEdge;
      count++;
      parent[sourceParent] = destParent;

   i++;
  }
 for(int i=0;i<n-1;i++)
  { 
    cout<<output[i].source <<" "<<output[i].dest <<" "<<output[i].weight <<"\n";
  }

}
int main()
{
ios_base:: sync_with_stdio(false);
cin.tie(NULL);
  int n,E;
  cin>>n>>E;

  Edge *input = new Edge[E];

  for(int i=0;i<E;i++)
  {
    int s,d,w;
    cin>>s>>d>>w;
    input[i].source = s;
    input[i].dest = d;
    input[i].weight = w;
  }

  Kruskals(input,n,E);
}