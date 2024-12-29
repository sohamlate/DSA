//{ Driver Code Starts
#include <cstdio> // for freopen
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


// } Driver Code Ends
// User function Template for C++
#include<bits/stdc++.h>

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
     
      
    
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        int n = V;
        
        cout<<"debug";
        vector<int>dist(n , INT_MAX);
        
        unordered_map<int , list<pair<int , int>>>adj;
        
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        dist[src] =0;
        for(int i=1;i<n;i++){
            for(auto a:adj){
                for(auto b:a.second){
                    int u = a.first;
                    int v = b.first;
                    int wt = b.second;
                    cout<<u<<" "<<v<<endl;

                    if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }


        for(auto a:adj){
            for(auto b:a.second){
                int u = a.first;
                int v = b.first;
                int wt = b.second;

                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                   return {-1};
                }
            }
        }
        
      
        return dist;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int N, m;
        cin >> N >> m;
        cout<<N<<" "<<m;

        vector<vector<int> > edges;

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;


            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        // cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(N, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends