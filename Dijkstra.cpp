const int INT_MAX = 2147483647;
const int INT_MIN = -2147483647;
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int findmin(int *dist,bool *visited,int V)
{
    int minVert = -1;

    for(int i=0;i<V;i++)
    {
        if(visited[i]==false and (minVert == -1 || dist[i] < dist[minVert] ) )
            minVert = i;
    }

    return minVert;
}
void dijkstra(int **graph,int n)
{
    // we need to array to store distance and visited or not 
    int *dist = new int[n];
    bool *visited = new bool[n];

    for(int i=0;i<n;i++)
        dist[i] = INT_MAX,   visited[i] = false;    // initalising the dist and vist
    
    dist[0] = 0;


    for(int i=0;i<n;i++)
    {
        int minVert = findmin(dist,visited,n);
        visited[minVert] = true;

        for(int j=0;j<n;j++)
        {
            if(graph[minVert][j])
                {
                    if(visited[j] == false and dist[minVert] + graph[minVert][j] < dist[j] )
                        dist[j] = dist[minVert] + graph[minVert][j];
                }
        }
    }
    
    
    for(int i=0;i<n;i++)
        cout<<i<<" : "<<dist[i]<<"\n";



}

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    int v,E;    cin>>v>>E;

    int **graph = new int*[v];

    for(int i=0;i<v;i++)
    {
        graph[i] = new int[v];
        
        for(int j=0;j<v;j++)
            graph[i][j] = 0;

    }

    // taking inputs;

    for(int i=0;i<E;i++)
    {
        int a,b,d;      cin>>a>>b>>d;

        graph[a][b] = d;
        graph[b][a] = d;

    }
    dijkstra(graph,v);
}
