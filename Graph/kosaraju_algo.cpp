#include<bits/stdc++.h>
using namespace std;

// unweighted graph 

class Graph{
    public:

    unordered_map<int , list<int>>adj;

    void addEdge(int u, int v ,int wt, bool direction ){
        if(direction){
            adj[u].push_back(v);
        }
        else{
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void dfs1(int src , stack<int>&topo , unordered_map<int , bool>&vis1){
        vis1[src] = true;

        for(auto nbr: adj[src]){
            if(!vis1[nbr]){
                dfs1(nbr ,topo , vis1 );
            }
        }

        topo.push(src);
    }
    void dfs2(int src , unordered_map<int , bool>&vis1 , unordered_map< int , list<int> > &radj){
        vis1[src] = true;

        for(auto nbr: radj[src]){
            if(!vis1[nbr]){
                dfs2(nbr , vis1 ,radj);
            }
        } 
    }

    void kosaraju(int n){
        // topo ordering

        unordered_map<int , bool>vis1;
        stack<int>topo;

        for(int i=0;i<n;i++){
            if(!vis1[i]){
                dfs1(i , topo , vis1);
            }
        }

        // reverse 
        unordered_map< int , list<int> > radj;

        for(auto a : adj){
            for(auto b : a.second){
                radj[b].push_back(a.first);
            }
        }

        // dfs2 
        int cnt =0;
        unordered_map<int , bool > vis2;
        while(!topo.empty()){
            int i = topo.top();
            topo.pop();
            if(!vis2[i]){
                dfs2(i , vis2, radj);
                cnt++;
            }
        }
        

        cout<<"totoal no of component is "<<cnt<<endl;
    }



};

int main(){
    Graph g ;

     g.addEdge(0, 1, 1, 1);
    g.addEdge(1, 2, 1, 1);
    g.addEdge(2, 3, 1, 1);
    g.addEdge(3, 0, 1, 1);

    g.addEdge(2, 4, 1, 1);

    g.addEdge(4, 5, 1, 1);
    g.addEdge(5, 6, 1 , 1);
    g.addEdge(6, 4, 1, 1);

    g.addEdge(6, 7, 1, 1);


    

   

    
   
    g.kosaraju(8);

    
 
    
    return 0;
}