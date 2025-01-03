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

    void bfs(int src , unordered_map<int , bool > &vis){
        queue<int> q;

        q.push(src);
        vis[src] = true;

        while(!q.empty()){

            int node = q.front();
            cout<<node<<" ";
            q.pop();

            for(auto nbr : adj[node]){
                int child = nbr.first;

                if(!vis[child]){
                    q.push(child);
                    vis[child] = true;
                }
            }

        }
    }

    void dfs(int src ,unordered_map<int , bool >&vis ){
        vis[src] = true;
        cout<<src<<" ";

        for(auto nbr : adj[src]){
            if(!vis[nbr.first]){
                dfs(nbr.first , vis);
            }
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

    unordered_map< int , bool > vis;

    cout<<"bfs"<<endl;
    for(int i=1 ;i <6;i++){
        if(!vis[i]){
            g.bfs(i , vis);
        }
    }
    cout<<endl<<"dfs"<<endl;;
    vis.clear();
    for(int i=1 ;i <6;i++){
        if(!vis[i]){
            g.dfs(i , vis);
        }
    }
    
    return 0;
}