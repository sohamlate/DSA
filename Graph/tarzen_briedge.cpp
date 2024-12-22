#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int src , int parent , int &timer , unordered_map< int , bool >&vis, vector<vector<int>>&ans , vector<int>&tin , vector<int>&low , unordered_map<int , list<int>> &adj){
        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for(auto nbr :adj[src]){
            if(nbr == parent){
                continue;
            }
            else if(!vis[nbr]){

                dfs(nbr , src , timer , vis ,ans , tin ,low ,adj);

                low[src] = min(low[src] , low[nbr]);

                if(low[nbr] > tin[src]){
                    vector<int>temp;
                    temp.push_back(src);
                    temp.push_back(nbr);
                    ans.push_back(temp);
                }
            }
            else{
                low[src] = min(low[src] , low[nbr]);
            }
        }

    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connection) {
        unordered_map<int , list<int>> adj;

        for(int i=0;i<connection.size();i++){
            adj[connection[i][0]].push_back(connection[i][1]);
            adj[connection[i][1]].push_back(connection[i][0]);
        }

        vector<int>tin(n , 0);
        vector<int>low(n ,0);
        vector<vector<int>>ans;
        unordered_map<int , bool > vis;
        int timer =0;
        int src =0;
        int parent = -1 ;

        dfs(src , parent , timer , vis , ans, tin , low, adj);



        return ans;

    }
};