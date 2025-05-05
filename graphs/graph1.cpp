#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// check if is cyclic for directed graph dfs
bool dfs_check_cyclic_directed(int node, vector<int>adj[], int vis[], int path[]) {
    vis[node]=1;
    path[node]=1;
    //traverse through adjacent node
    for(auto it:adj[node]) {
        // when the node is not visited
        if(!vis[it]) {
            if(dfs_check_cyclic_directed(it,adj,vis,path)==true) {return true;}
            // if the node has been previously visited
            // but it has to be visited on same path
            else if(path[it]) {
                return true;
            }
        }
    }
    path[node]=0;
    return false;
}

bool is_cyclic_dfs_directed(int v, vector<int>adj[]) {
    int vis[v] = {0};
    int path[v] = {0};
    for(int i=0;i<v;i++) {
        if(!vis[i]) {
            if(dfs_check_cyclic_directed(i,adj,vis,path)==true) {return true;}
        }
    }
    return false;
}

// topological sorting dfs
// linear ordering
// for the directed acyclic graph
// if there is a edge b/w u and v, then u appears before v in linear ordering
void dfs_toposort(int node, int vis[], stack<int>st, vector<int>adj[]) {
    vis[node]=1;
    for(auto it:adj[node]) {
        if(!vis[it]) dfs_toposort(it,vis,st,adj);
    }
    st.push(node);
}

vector<int> toposort_dfs(int v, vector<int>adj[]) {
    int vis[v] = {0};
    stack<int>st;
    for(int i=0;i<v;i++) {
        if(!vis[i]) {
            dfs_toposort(i,vis,st,adj);
        }
    }
    vector<int>ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

vector<int> toposort_bfs(int v, vector<int>adj[]) {
    int indegree[v] = {0};
    for(int i=0;i<v;i++) {
        for(auto it:adj[i]) {
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<v;i++) {
        if(indegree[i]==0) {
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty()) {
        int node =q.front();
        q.pop();
        topo.push_back(node);
        // node is in your topo sort
        // so pls remove it from indegree
        for(auto it:adj[node]) {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    return topo;
}

// check is cyclic ? DAG -> directed acyclic graph - toposort
bool is_cyclic(int v, vector<int>adj[]) {
    int indegree[v] = {0};
    for(int i=0;i<v;i++) {
        for(auto it: adj[i]) {
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<v;i++) {
        if(indegree[i]==0) {
            q.push(i);
        }
    }
    int count=0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        count++;
        //node in your topo sort
        //so pls minimize the indegree
        for(auto it:adj[node]) {
            indegree[it]--;
            if(indegree[it]==0) {q.push(it);}
        }
    }
    //no cycle all node processed
    if(count==v) return false;
    return true;
}

// given a pair of task -> if it could be performed/not performed

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
	// cout << "Following is Breadth First Traversal: "<< endl;
    // bfs_traversal(adj,v,0);
    // cout << endl;
    // cout << "Following is Depth First Traversal: "<< endl;
    // dfs_traversal(adj,v,0);
    // cout << endl;
    return 0;
}