#include<bits/stdc++.h>
using namespace std;

#define MAX 100000

vector <int> adj[MAX]; //vector for adjacency list of the graph
vector <int> visited(MAX),low(MAX),parent(MAX);  //vectors for AP and bridge determination

set <int> vertex; //vector for saving AP
vector < pair<int,int> > edge; //vector for bridges
int tym; //tym variable

void articulation_point(int s)
{
    if(visited[s]!=-1)
        return;
    visited[s]=low[s]=++tym;  //initially visit time and low time is same
    int child=0;
    for(int i=0; i<adj[s].size(); i++)
    {
        int f=adj[s][i];
        if(visited[f]==-1)
        {
            parent[f]=s;     //storing parents of every vertex
            child++;         //child counting but not saving only to determine if the root node is AP or not

            articulation_point(f);

            low[s]=min(low[s],low[f]);       //updating low time when returning

            if(parent[s]==-1&&child>1)       //condition for root node being AP
            {
                vertex.insert(s);
            }
            else if(parent[s]!=-1&&low[f]>=visited[s]) //condition for nodes other than root node being AP
            {
                vertex.insert(s);
            }
        }
        else if(f!=parent[s])
        {
            low[s]=min(low[s],visited[f]);   //A back edge is detected and low time is updated
        }
    }

}

void bridge(int s)
{
    if(visited[s]!=-1)
        return;
    visited[s]=low[s]=++tym;    //initially visit time and low time is same
    for(int i=0; i<adj[s].size(); i++)
    {
        int f=adj[s][i];
        if(visited[f]==-1)
        {
            parent[f]=s;    //storing parents of every vertex , but child count is not necessary for bride determination

            bridge(f);

            low[s]=min(low[s],low[f]); //updating low time when returning

            if(low[f]>visited[s])
            {
                edge.push_back(make_pair(min(f,s),max(f,s)));   //storing bridges
            }
        }
        else if(f!=parent[s])
        {
            low[s]=min(low[s],visited[f]);  //updating low time when back edge is detected
        }
    }

}


int main()
{
    cout<<"0---1---2---3"<<endl;
    cout<<"|       |"<<endl;
    cout<<"----4----"<<endl;
    /*input of graph*/
    int v,e;
    v=5,e=5;
    adj[0].push_back(1);        adj[1].push_back(0);
    adj[1].push_back(2);        adj[2].push_back(1);
    adj[2].push_back(3);        adj[3].push_back(2);
    adj[0].push_back(4);        adj[4].push_back(0);
    adj[2].push_back(4);        adj[4].push_back(2);
    /*preparing variable and storage for algorithm*/
    tym=0;
    for(int i=0;i<v;i++) visited[i]=low[i]=parent[i]=-1;

    articulation_point(0);

    /*preparing variable and storage for algorithm*/
    tym=0;
    for(int i=0;i<v;i++) visited[i]=low[i]=parent[i]=-1;
    bridge(0);


    /*output*/
    cout<<"articulation points : "<<endl;
    for(set <int> :: iterator it=vertex.begin();it!=vertex.end();it++) cout<<*it<<endl;
    cout<<"bridges : "<<endl;
    for(int i=0;i<edge.size();i++) cout<<edge[i].first<<"-"<<edge[i].second<<endl;

    /*clearing*/
    for(int i=0;i<v;i++) adj[i].clear();
    vertex.clear();
    edge.clear();


}

