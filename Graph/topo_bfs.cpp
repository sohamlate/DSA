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

    void topo(int n){

        unordered_map<int , int>indegree;

        for(auto i : adj){
            for(auto nbr : i.second){
                indegree[nbr]++;
            }
        }

        queue<int> q;

        for(int i=0;i<=n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }


        while(!q.empty()){

            int node = q.front();
            cout<<node<<" ";
            q.pop();

            for(auto nbr : adj[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }

        }
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


    stack<int>st;

   
    g.topo(5);
   
    
    return 0;
}