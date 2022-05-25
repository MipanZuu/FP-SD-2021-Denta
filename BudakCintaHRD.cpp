//
//  main.cpp
//  FINAL PROJECT
//
//  Created by Denta Bramasta Hidayat on 14/06/21.
//

#include<bits/stdc++.h>
using namespace std;
#define NIL -1
#define INF INT_MAX

typedef pair <int, int> pii;
 
class graph
{
    int V;
    vector< pii > *adj;
    void bridgeUtil(int v, bool visited[], int disc[], int low[], int parent[], vector< pii > bdg[]);
public:
    graph(int V); // Constructor
    void addEdge(int u, int v, long long w);
    void bridge(vector< pii > bdg[]);
    void shortestPath(int src, vector< pii > bdg[], long long dist[]);
};
 
graph::graph(int V)
{
    this->V = V;
    adj = new vector< pii >[V];
}
 
void graph::addEdge(int u, int v, long long w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 
void graph::bridgeUtil(int u, bool visited[], int disc[],
    int low[], int parent[], vector< pii > bdg[])
{
    static int time = 0;
 
    visited[u] = true;
 
    disc[u] = low[u] = ++time;
 
    vector< pii >::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = i->first;
        long long w = i->second;
 
        if (!visited[v])
        {
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent, bdg);
 
            low[u] = min(low[u], low[v]);
 
            if (low[v] > disc[u])
            {
                bdg[u].push_back(make_pair(v,w));
                bdg[v].push_back(make_pair(u,w));
            }
        }
 
        else if (v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}
 
void graph::bridge(vector< pii > bdg[])
{
    bool visited[V];
    int disc[V];
    int low[V];
    int parent[V];
 
    for (int i=0;i<V;i++)
    {
        parent[i] = NIL;
        visited[i] = false;
    }
 
    for (int i=0;i<V;i++)
        if (!visited[i])
            bridgeUtil(i, visited, disc, low, parent, bdg);
}
 
void graph::shortestPath(int src, vector< pii > bdg[], long long dist[])
{
     priority_queue< int, vector <int> , greater<int> > pq;
 
    for (int i = 0 ; i < V ; i++)
        dist[i] = -1 ;
 
    pq.push(src);
    dist[src] = 0;
    
    while (!pq.empty())
    {
        int u = pq.top();
        pq.pop();
 
        vector<pii>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            long long weight = (*i).second;
 
            if (dist[v] > dist[u] + weight ||  dist[v] == -1)
            {
                pii target = make_pair(v, weight);
                if (find(bdg[u].begin(), bdg[u].end(), target) == bdg[u].end())
                    dist[v] = dist[u];
                else
                    dist[v] = dist[u] + weight;
                pq.push(v);
            }
        }
    }
}
int main() {
    int N, M;

    cin >> N >> M;
    graph graphh(N);
    vector< pii > bridge[N];
    for (int i=0; i<M; i++){
        int from, to;
        long long weight;
        
        cin >> from >> to >> weight;
        graphh.addEdge(from-1, to-1, weight);
    }
    
    graphh.bridge(bridge);
    long long dist[N][N];
    for(int i = 0; i < N; i++){
        graphh.shortestPath(i, bridge, dist[i]);
    }
    int Q;
    cin >> Q;
    while(Q--){
        int Xi, Yi;
        cin >> Xi >> Yi;
        cout << dist[Xi-1][Yi-1] << "\n";
    }
    return 0;
}
