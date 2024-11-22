#include<bits/stdc++.h>
using namespace std;

// unweighted graph 

class Graph{
    public:

    unordered_map<int , list<pair<int , int>>>adj;

    void addEdge(int u, int v ,int wt, bool direction ){
        if(direction){
            adj[u].push_back({v, wt});
        }
        else{
            adj[u].push_back({v , wt});
            adj[v].push_back({u , wt});
        }
    }

    void print(){

        for(auto node: adj){
            cout<< node.first << " --> ";
            for(auto nbr : node.second){
                cout<< nbr.first <<" - " << nbr.second << "  ,  ";
            }
            cout<<endl;
        }
    }

};

int main(){
    Graph g ;

    g.addEdge(1 , 2,6, 0);
    g.addEdge(1 , 5,7, 0);
    g.addEdge(1 , 4,8, 0);
    g.addEdge(5 , 3,2, 0);
    g.addEdge(3 , 2,1, 0);

    g.print();
    
    return 0;
}