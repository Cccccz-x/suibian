/*查询是否存在某条边：O(m)。

遍历一个点的所有出边：O(m)。

遍历整张图：O(nm)。

空间复杂度：O(m)。
*/


#include<vector>
#include<iostream>
using namespace std;

struct Edge{
    int u,v;
};

int n,m;
vector<Edge>e;
vector<bool>vis;

bool find_edge(int u,int v){
    for(int i=1;i<=m;++i){
        if(e[i].u==u&&e[i].v==v){
            return true;
        }
    }
}

void dfs(int u){
    if(vis[u])return;
    vis[u]=true;
    for(int i=1;i<m;++i){
        if(e[i].u==u){
            dfs(e[i].v);
        }
    }
}

int main(){
    cin>>n>>m;
    vis.resize(n+1,false);
    e.resize(m+1);
    for(int i=1;i<=m;++i) cin>>e[i].u>>e[i].v;    
}