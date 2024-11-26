#include<bits/stdc++.h>
using namespace std;

// directed graph cycle detection using dfs

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


    bool checkcycle(int src , unordered_map<int , bool>&vis , unordered_map<int , bool>&dfsTrack, int parent){

            vis[src] = true;
            dfsTrack[src] = true;
            cout<<src<<" ";

            for(auto child : adj[src]){
                if(!vis[child]){
                    bool ans = checkcycle(child , vis, dfsTrack , src);
                    if(ans){
                        return true;
                    }
                }
                else if(dfsTrack[child] == 1){
                    return true;
                }
            
            }

            dfsTrack[src] = false;
            return false;
    }

};

int main(){
    Graph g ;

    g.addEdge(1 , 2, 1);
    g.addEdge(5 , 1,1 );
    g.addEdge(1 , 4, 1);
    g.addEdge(3 , 5, 1);
    g.addEdge(2 , 3, 1);

    g.print();

    unordered_map<int , bool > vis;
    unordered_map<int , bool > dfsTrack;

    for(int i=0;i<=5;i++){

        if(!vis[i]){
            int parent = -1 ;
            bool ans = g.checkcycle(i , vis ,dfsTrack, -1);
            if(ans){
                cout<<"cycle is present";
                break;
            }
        }
    }
    
    return 0;
}