#include<bits/stdc++.h>
using namespace std;

// undirected graph cycle detection using dfs

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

    void print(){

        for(auto node: adj){
            cout<< node.first << " --> ";
            for(auto nbr : node.second){
                cout<< nbr << ", ";
            }
            cout<<endl;
        }
    }


    bool checkcycle(int src , unordered_map<int , bool>&vis , int parent){

            vis[src] = true;
            cout<<src<<" ";

            for(auto child : adj[src]){
                if(!vis[child]){
                    bool ans = checkcycle(child , vis , src);
                    if(ans){
                        return true;
                    }
                }
                else if(child == parent){
                    continue;
                }
                else{
                    return true;
                }
            }
            return false;
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

    unordered_map<int , bool > vis;

    for(int i=0;i<=5;i++){

        if(!vis[i]){
            int parent = -1 ;
            bool ans = g.checkcycle(i , vis , -1);
            if(ans){
                cout<<"cycle is present";
                break;
            }
        }
    }
    
    return 0;
}