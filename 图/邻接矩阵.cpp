/*查询是否存在某条边：O(1)。

遍历一个点的所有出边：O(n)。

遍历整张图：O(n^2)。

空间复杂度：O(n^2)。
*/

#include<vector>
#include<iostream>
using namespace std;

struct Edge{
    int u,v;
};

int n,m;
vector<vector<int>>adj;
vector<bool>vis;

int find_edge(int u,int v){
    return adj[u][v];
}

void dfs(int u){
    if(vis[u])return;
    vis[u]=true;
    for(int v=1;v<n;++v){
        if(adj[u][v]>0){
            dfs(v);
        }
    }
}

int main(){
    cin>>n>>m;
    vis.resize(n+1,false);
    adj.resize(n+1,vector<int>(n+1,0));
    for(int i=1;i<=m;++i){
        int u,v,weight;
        cin>>u>>v>>weight;
        adj[u][v]=weight;
    }     
}