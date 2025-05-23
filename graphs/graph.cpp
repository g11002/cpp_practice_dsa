#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs_traversal(vector<int>adj[], int v, int s) {
    bool visited[v];
    for(int i=0;i<v;i++) {visited[i]=false;};

    queue<int>q;
    visited[s]=true;
    q.push(s);

    while(!q.empty()) {
        int u=q.front();
        q.pop();
        cout << u << " ";
        for(auto v:adj[u]) {
            if (visited[v]==false) {
                visited[v]=true;
                q.push(v);
            }
        }
    }
}

void dfs_recursive(vector<int>adj[], int s, bool visited[]) {
    visited[s]=true;
    cout<<s<<" ";
    for(auto u:adj[s]) {
        if(visited[u]==false) {
            dfs_recursive(adj,u,visited);
        }
    }
}

void dfs_traversal(vector<int>adj[], int v, int s) {
    bool visited[v];
    for(int i=0;i<v;i++) {visited[i]=false;};
    dfs_recursive(adj,s,visited);
}

bool bfs_cycle(int src,vector<int>adj[],int vis[]) {
    vis[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty()) {
        int node=q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto u:adj[node]) {
            if(!vis[u]) {
                vis[u]=1;
                q.push({u,node});
            }
            else if(parent!=u) {
                return true;
            }
        }
    }
    return false;
}

bool bfs_isCycle(int V,vector<int>adj[]) {
    int vis[V]={0};
    for(int i=0;i<V;i++) {
        if(!vis[i]) {
            if(bfs_cycle(i,adj,vis)) return true;
        }
    }
    return false;
}

bool dfs_cycle(vector<int>adj[], int s, bool visited[], int parent) {
    visited[s]=true;
    for(int u:adj[s]) {
        if(visited[u]==false) {
            if(dfs_cycle(adj,u,visited,s)==true) {return true;}
        }
        else if(u!=parent) {return true;}
    }
    return false;
}

bool dfs_isCycle(int V, vector<int> adj[]) {
    bool visited[V]={false};
    for(int i=0;i<V;i++) {
        if(visited[i]==false) {
            if(dfs_cycle(adj,i,visited,-1)==true) {return true;}
        }
    }
    return false;
}

// Input: mat[][] = [[0, 1, 2], [0, 1, 2], [2, 1, 1]]
// Output: 1
// Explanation: Oranges at positions (0,2), (1,2), (2,0) will rot oranges at (0,1), (1,1), (2,2) and (2,1) in unit time.
int orangesRotting(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    queue<pair<pair<int,int>,int>>q;
    int vis[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(mat[i][j]==2) {
                q.push({{i,j},0});
                vis[i][j]=2;
            } else {
                vis[i][j]=0;
            }
        }
    }
    int tm=0;
    int drow[] = {-1,0,+1,0};
    int dcol[] = {0,+1,0,-1};
    while(q.empty()==false) {
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        tm=max(tm,t);
        q.pop();
        for(int i=0;i<4;i++) {
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && mat[nrow][ncol]==1) {
                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol]=2;
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if (vis[i][j]!=2 && mat[i][j]==1) {
                return -1;
            }
        }
    }
    return tm;
}

void dfs_island(int row, int col, vector<vector<int>>grid, vector<vector<int>>vis, vector<pair<int,int>>vec, int row0, int col0) {
    int n=grid.size();
    int m=grid[0].size();
    vis[row][col]=1;
    vec.push_back({row-row0,col-col0});

    int drow[] = {-1,0,+1,0};
    int dcol[] = {0,+1,0,-1};
    for(int i=0;i<4;i++) {
        int nrow = row+drow[i];
        int ncol = col+dcol[i];
        if(nrow>=0 && nrow<n && ncol>0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1) {
            dfs_island(nrow,ncol,grid,vis,vec,row0,col0);
        }
    }
}

int count_distinct_island(vector<vector<int>>grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    set<vector<pair<int,int>>>st;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!vis[i][j] && grid[i][j]==1) {
                vector<pair<int,int>>vec;
                dfs_island(i,j,grid,vis,vec,i,j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}

bool check_bfs_bipartite(int start, int v, vector<int>adj[], int color[]) {
    queue<int>q;
    q.push(start);
    color[start]=0;
    while(!q.empty()) {
        int node=q.front();
        q.pop();
        for(auto it:adj[node]) {
            // if the adjacent is yet not colored
            // you will give the opposite color of the node
            if(color[it]==-1) {
                color[it] = !color[node];
                q.push(it);
            }
            // if the adjacent node having the same color
            // someone did color it on some other path
            else if(color[it]==color[node]) {
                return false;
            }
        }
    }
    return true;
}

bool is_bfs_bipartite(int v, vector<int>adj[]) {
    int color[v];
    for(int i=0;i<v;i++) color[i]=-1;

    for(int i=0;i<v;i++) {
        if(color[i]==-1) {
            if(check_bfs_bipartite(i,v,adj,color) == false) {
                return false;
            }
        }
    }
    return true;
}

bool dfs_bipartite(int node, int col, int color[], vector<int>adj[]) {
    color[node]=col;
    for(auto it:adj[node]) {
        if(color[it]==-1) {
            if (dfs_bipartite(it, !col, color, adj) == false) return false;
            else if(color[it]==col) {return false;};
        }
    }
    return true;
}

bool is_dfs_bipartite(int v, vector<int>adj[]) {
    int color[v];
    for(int i=0;i<v;i++) color[i]=-1;

    for(int i=0;i<v;i++) {
        if(color[i]==-1) {
            if(dfs_bipartite(i,0,color,adj)==false) {
                return false;
            }
        }
    }
    return true;
}

void add_edge(vector<int>adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int v=5;
    vector<int>adj[v];
    add_edge(adj,0,1);
	add_edge(adj,0,2);
	add_edge(adj,1,2);
	add_edge(adj,2,3);
	add_edge(adj,1,3);
	add_edge(adj,3,4);
	add_edge(adj,2,4);
	cout << "Following is Breadth First Traversal: "<< endl;
    bfs_traversal(adj,v,0);
    cout << endl;
    cout << "Following is Depth First Traversal: "<< endl;
    dfs_traversal(adj,v,0);
    cout << endl;
    return 0;
}