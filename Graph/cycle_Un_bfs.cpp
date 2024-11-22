#include<bits/stdc++.h>
using namespace std;

// unweighted graph 

class Graph{
    public:

    unordered_map<int , list<int>>adj;

    void addEdge(int u, int v , bool direction ){
        if(direction){
            adj[u].push_back(v);
        }
        else{
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    // undirected grapg cycle using bfs

    bool check_cycle(int src , unordered_map<int , bool > &vis){
        queue<int> q;
        unordered_map<int , int>parent;

        q.push(src);
        vis[src] = true;
        parent[src] = -1;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            for(auto nbr : adj[node]){
                int child = nbr;

                if(!vis[child]){
                    q.push(child);
                    vis[child] = true;
                    parent[child] = node;
                }
                else if(child == parent[node]){
                    continue;
                }
                else{
                    return true;
                }
            }

        }

        return false;
    }

    void print(){

        for(auto node: adj){
            cout<< node.first << " --> ";
            for(auto nbr : node.second){
                cout<< nbr << ", ";
            }
            cout<<endl;
        }
    }

};

int main(){
    Graph g ;

    g.addEdge(1 , 2, 0);
    g.addEdge(1 , 5, 0);
    g.addEdge(1 , 4, 0);
    g.addEdge(5 , 3, 0);
    g.addEdge(3 , 2, 0);

    g.print();
    cout<<endl;
    unordered_map<int , bool>vis;
    for(int i=1 ;i <6;i++){
        if(!vis[i]){
           bool ans =  g.check_cycle(i , vis);
           if(ans){
            cout<< "cycle is present";
           }
           else{

            cout<< "cycle is not present";
           }
        }
    }
    
    return 0;
}