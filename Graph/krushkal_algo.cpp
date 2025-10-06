//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet{
    public:
    vector<int> rank , size , parent;
    
    DisjointSet(int n ){
        rank.resize(n+1 , 0);
        parent.resize(n+1);
        size.resize(n+1 ,1);
        
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    
    int getparent(int node){
        if(node == parent[node]){
            return node;
        }
        
        return parent[node] = getparent(parent[node]);
    }
    
    void unionbyrank(int u , int v){
        int pu = getparent(u);
        int pv = getparent(v);
        
        if(pu == pv) return ;
        
        if(rank[pu] < rank[pv]){
            parent[pu] = pv ;
        }
        else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    void unionbysize(int u , int v){
        int pu = getparent(u);
        int pv = getparent(v);
        
        if(pu == pv) return ;
        
        if(size[pu] < size[pv]){
            size[pv] += size[pu];
            parent[pu] = pv ;
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    
};


class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        vector<pair<int , pair<int , int>>>e;
        
        for(int i=0;i<V;i++){
            for(auto a : adj[i]){
                int node = a[0];
                int wt = a[1];
                
                e.push_back({wt , {i ,node}});
            }
        }
        
        DisjointSet ds(V);
        
        sort(e.begin() , e.end());
        int ans =0;
        
        for(int i=0;i<e.size();i++){
            int wt = e[i].first;
            int u = e[i].second.first;
            int v = e[i].second.second;
            
            if(ds.getparent(u) != ds.getparent(v)){
                ans += wt;
                ds.unionbysize(u , v);
            }
            
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
