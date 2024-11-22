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
    
    return 0;
}