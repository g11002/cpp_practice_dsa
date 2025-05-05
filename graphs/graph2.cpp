#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// n = 4, prerequisites[][] = [[1, 0], [2, 0], [3, 1], [3, 2]]
// Output: true
// Explanation: There are a total of 4 tasks to pick. To pick task 3 you should have finished both tasks 1 and 2. Both tasks 1 and 2 should be pick after you finished task 0. So one correct task order is [0, 1, 2, 3]. Another correct ordering is [0, 2, 1, 3]. Returning any of these order will result in an output of true.
bool is_possible(int v, vector<pair<int,int>> prequistes) {
    vector<int>adj[v];
    for(auto it: prequistes) {
        adj[it.first].push_back(it.second);
    }
    int indegree[v] = {0};
    for(int i=0;i<v;i++) {
        for(auto it:adj[v]) {
            indegree[it]++;
        }
    }
    queue<int>q;
    vector<int>topo;
    for(int i=0;i<v;i++) {
        if (indegree[i]==0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int node=q.front();
        topo.push_back(node);
        q.pop();
        for(auto it:adj[node]) {
            indegree[it]--;
            if(indegree[it]==0) {q.push(it);}
        }
    }
    if(topo.size()==v) return true;
    return false;
}

void toposort_dfs_path(int node, vector<pair<int,int>>adj[], int vis[], stack<int>st) {
    vis[node]=1;
    for(auto it:adj[node]) {
        int v=it.first;
        if(!vis[v]) {
            toposort_dfs_path(v,adj,vis,st);
        }
    }
    st.push(node);
}

// shortest path in directed acyclic graph - weighted
vector<int>shortest_path_weighted(int n, int m, vector<int>edges[]) {
    vector<pair<int,int>>adj[n];
    for(int i=0;i<n;i++) {
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        adj[u].push_back({v,w});
    }
    //find topo sort
    int vis[n]={0};
    stack<int>st;
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            toposort_dfs_path(i,adj,vis,st);
        }
    }
    //step 2 calc shortest distance
    vector<int>dist(n);
    for(int i=0;i<n;i++) dist[i]=1e9;
    dist[0]=0;
    while (!st.empty()) {
        int node=st.top();
        st.pop();
        for(auto it:adj[node]) {
            int v=it.first;
            int wt=it.second;
            if(dist[v]>dist[node]+wt) {
                dist[v]=dist[node]+wt;
            }
        }
    }
    return dist;
    
}

//shortest path for the undirected graph not weighted
//n nodes m edges src source
vector<int>shortest_path_undirected(vector<vector<int>>edges, int n, int m, int src) {
    vector<int>adj[n];
    for(auto it:edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    int dist[n];
    for(int i=0;i<n;i++) dist[i]=1e9;
    dist[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty()) {
        int node=q.front();
        q.pop();
        for(auto it:adj[node]) {
            if(dist[it]>dist[node]+1) {
                dist[it]=1+dist[node];
                q.push(it);
            }
        }
    }
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++) {
        if(dist[i]!=1e9) {
            ans[i]=dist[i];
        }
    }
    return ans;
}

//dijkstra's algorithm
//only applicable for positive weights
//tc - elogv
vector<int> dijkstra(int v, vector<vector<int>>adj[], int s) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(v);
    for(int i=0;i<v;i++) dist[i]=1e9;

    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it:adj[node]) {
            int edgew=it[1];
            int adjn=it[0];
            if(dis+edgew<dist[adjn]) {
                dist[adjn]=dis+edgew;
                pq.push({dist[adjn],adjn});
            }
        }
    }
    return dist;
}

int main() {
    return 0;
}