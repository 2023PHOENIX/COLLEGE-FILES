#include<bits/stdc++.h>

using namespace std;

int min_edge_wt(int *edge,bool *included,int n)
{
    int min = INT_MAX;
    int min_index;
    
    for(int i=0;i<n;i++)
    {
        if(included[i]== false and edge[i] < min)
            min = edge[i],min_index = i;
    }
    return min_index;
}
void prim(int **graph,int n)
{
    int *parent = new int[n];
    int *edge = new int[n];
    bool *included = new bool[n];
    
    
    for(int i=0;i<n;i++)
    {
        edge[i] = INT_MAX;
        included[i] = false;
    }
     edge[0] = 0;
    parent[0] = -1;
   
    for(int c = 0 ; c<n-1;c++)
    {
        int u = min_edge_wt(edge,included,n);
        included[u] = true;
        for(int v=0;v<n;v++)
            {
                if(graph[u][v] and included[v]==false and graph[u][v] < edge[v] )
                    parent[v] = u , edge[v] = graph[u][v];
                    
            }
    }
    
    for(int i=1;i<n;i++)
    {
        cout<<parent[i]<<":"<<i<<"--> " << graph[i][parent[i]]<<endl;
    }
}

int main()
{
    int n,e;    cin>>n>>e;

    int **graph = new int*[n];
    
    
    for(int i=0;i<n;i++)
    {
        graph[i] = new int[n];
        
        for(int j=0;j<n;j++)
            graph[i][j] = 0;
            
    }
    
    for(int i=0;i<e;i++)
    {
        int a,b,c;  cin>>a>>b>>c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    
    prim(graph,n);
}