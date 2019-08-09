#include<bits/stdc++.h>
using namespace std;
 
vector <int> adj[1000001];
int indegree[1000001];
vector <int> V;
 
void topological_sort(int v)
{
    queue <int> Q;
    /* Counting In-degree of all nodes of the graph */
    memset(indegree,0,sizeof(indegree));
    for(int i=1; i<=v; i++)
    {
        for(int j=0; j<adj[i].size(); j++)
        {
            indegree[adj[i][j]]++;
        }
    }
    /* Pushing nodes with in-degree=0 into the queue*/
    for(int i=1; i<=v; i++)
        if(indegree[i]==0)
            Q.push(i);
    /*BFS like traversal */
    while(!Q.empty())
    {                                               //no need of visited array
        int f=Q.front();                            //because if visited array is used
        Q.pop();                                    //one adjacent node will be visited only once
        V.push_back(f);                             //and so degree of the node will be decreased once
        int l=adj[f].size();                        //but the node may be adjacent of another node
        for(int i=0; i<l; i++)                      //that might need to be decreased again
        {
            //no need of if visited condition
            indegree[adj[f][i]]--;
            if(indegree[adj[f][i]]==0)
            {
                Q.push(adj[f][i]);
            }
        }
    }
 
}
int main()
{
    int v,e;
    int x,y;
    while(~scanf("%d%d",&v,&e))
    {
        if(v==0&&e==0)
            return 0;
        for(int i=0; i<e; i++)
        {
            scanf("%d%d",&x,&y);
            adj[x].push_back(y);
        }
 
        topological_sort(v);
        if(V.size()==v)
        for(int i=0;i<v;i++) cout<<V[i]<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
        V.clear();
        for(int i=1; i<=v; i++)
            adj[i].clear();
 
 
    }
    return 0;
}
 
