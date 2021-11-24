/*使用一个支持动态增加元素的数据结构构成的数组，如 vector<int> adj[n + 1] 来存边，
其中 adj[u] 存储的是点u的所有出边的相关信息（终点、边权等）。
查询是否存在u到v的边：O(u的出度)
（如果事先进行了排序就可以使用 二分查找 做到O(log(u的出度))）。

遍历点u的所有出边：O(u的出度)。

遍历整张图：O(n+m)。

空间复杂度：O(m)。m+n?
*/
#include<vector>
#include<iostream>
using namespace std;

int n,m;
vector<bool>vis;
vector<vector<int>>adj;

bool find_edge(int u,int v){
    for(int i=0;i<adj[u].size();++i){
        if(adj[u][i]==v){
            return true;
        }
    }
}

void dfs(int u){
    if(vis[u])return;
    vis[u]=true;
    for(int i=0;i<adj[u].size();++i){
        dfs(adj[u][i]);
    }
}

int main(){
    cin>>n>>m;
    vis.resize(n+1,false);
    adj.resize(n+1);
    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);//从0开始插入 有向图只插一个点 无向两个点都要插
    }
}