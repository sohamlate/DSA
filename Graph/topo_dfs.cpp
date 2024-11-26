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

    void topo(int src ,unordered_map<int , bool >&vis, stack<int>&st ){
        vis[src] = true;
        cout<<src<<" ";

        for(auto nbr : adj[src]){
            if(!vis[nbr]){
                topo(nbr , vis, st);
            }
        }
        st.push(src);
    }

};

int main(){
    Graph g ;

    g.addEdge(1 , 2, 1);
    // g.addEdge(5 , 1,1 );
    g.addEdge(1 , 4, 1);
    g.addEdge(3 , 5, 1);
    g.addEdge(2 , 3, 1);

    g.print();

    unordered_map<int , bool > vis;
    stack<int>st;

    for(int i=0;i<=5;i++){

        if(!vis[i]){
           g.topo(i , vis ,st);
        }
    }
    cout<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    
    return 0;
}