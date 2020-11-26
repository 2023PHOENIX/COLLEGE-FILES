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
bool s(Edge a,Edge b)
{
  return a.weight < b.weight;
}

int find_parent(int V,int *parent)
{
  if(parent[V] == V )
    return V;
  return find_parent(parent[V],parent);
}

void Krushkal(Edge *input,int n,int E)
{
  sort(input,input+E,s);


  Edge* output = new Edge[n-1];

  int* parent = new int[n];


  for(int i=0;i<n;i++)
  {
    parent[i] = i;
  }

  int c{0},i{0};

  while(c!=n-1)
  {
    Edge currentEdge = input[i];

    int sourceParent = find_parent(currentEdge.source,parent);
    int destParent = find_parent(currentEdge.dest , parent);

    if(sourceParent != destParent)
      {
        output[c] = currentEdge;
        parent[sourceParent] = destParent;
        c++;
      }
      i++;

  }
  for(int i=0;i<n-1;i++)
  {
    cout<<output[i].source<<" "<<output[i].dest <<" "<<output[i].weight<<endl;
  }
}
int main()
{
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL);

  int n,E;  cin>>n>>E;

  Edge* input = new Edge[E];

  for(int i=0;i<E;i++)
  {
    int s,d,w;  cin>>s>>d>>w;

    input[i].source = s;
    input[i].dest = d;
    input[i].weight = w;
    
  }

  Krushkal(input,n,E);



  
}