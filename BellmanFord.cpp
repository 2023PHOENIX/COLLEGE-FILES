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

void BellManFord(Edge *graph,int n,int e)
{
    int *parent = new int[n];
    int *cost_parent = new int[n];

    int *min_wt = new int[n];

    for(int i=0;i<n;i++)
        min_wt[i] = INT_MAX;
    

    parent[0] = -1;
    min_wt[0] = 0;
    bool flag;
    for(int i=0;i<n-1;i++)      // vertex-1 total number of time relaxation will be done 
    {
        flag = false;

        for(int j=0;j<e;j++)
        {
            int u = graph[j].source;
            int v = graph[j].dest;
            int w = graph[j].weight;

            if(min_wt[u] != INT_MAX and min_wt[u] + w < min_wt[v])
            {   
                 min_wt[v] = min_wt[u] + w;
                parent[v] = u;
                cost_parent[v] = min_wt[u];
                flag = true;
            }
        }
        if(flag == false)
            break;
    }

    // check for cycle in the graph
    
        for(int j=0;j<e and flag ==true;j++)
            {
                int u = graph[j].source;
                int v = graph[j].dest;
                int w = graph[j].weight;

                if(min_wt[u] != INT_MAX and min_wt[u]+ w < min_wt[v])
                    cout<<"neative cycle present in the graph\n";
                    
            }
    

    for(int i=1;i<n;i++)
    {
        cout<<parent[i] <<" to " << i << " --> " << min_wt[i]<<"\n";
    }

}

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    int n,e;    cin>>n>>e;

    Edge *graph = new Edge[n];

    for(int i=0;i<e;i++)
        {
            int a,b,c;  cin>>a>>b>>c;

            graph[i].source = a;
            graph[i].dest = b;
            graph[i].weight = c;

        }


    BellManFord(graph,e,n);



    
}