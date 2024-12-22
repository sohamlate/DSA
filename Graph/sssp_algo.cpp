#include<bits/stdc++.h>
using namespace std;

// undirected graph cycle detection using dfs

class Graph{
    public:

    unordered_map<int , list<pair<int, int>>>adj;

    void addEdge(int u, int v , int wt , bool direction ){
        if(direction){
            adj[u].push_back({v, wt});
        }
        else{
            adj[u].push_back({v, wt});
            adj[v].push_back({u , wt});
        }
    }

    // void print(){

    //     for(auto node: adj){
    //         cout<< node.first << " --> ";
    //         for(auto nbr : node.second){
    //             cout<< nbr << ", ";
    //         }
    //         cout<<endl;
    //     }
    // }

    void topo(int src ,unordered_map<int , bool >&vis, stack<int>&st ){
        vis[src] = true;
        cout<<src<<" ";

        for(auto nbr : adj[src]){
            int nbrnode = nbr.first;
            if(!vis[nbrnode]){
                topo(nbrnode , vis, st);
            }
        }
        st.push(src);
    }

    void sssp(stack<int>&topo ,int n ){
        
        int src = topo.top();
        vector<int>dist(n , INT_MAX);
        topo.pop();

        dist[src] =0;

        for(auto nbr : adj[src]){
            int nbrnode = nbr.first;
            int nbrwt = nbr.second;

            if(dist[src] + nbrwt < dist[nbrnode]){
                dist[nbrnode] = dist[src] + nbrwt;
            }
        }

        while(!topo.empty()){
            int src = topo.top();
            topo.pop();
            for(auto nbr : adj[src]){
            int nbrnode = nbr.first;
                int nbrwt = nbr.second;

                if(dist[src] + nbrwt < dist[nbrnode]){
                    dist[nbrnode] = dist[src] + nbrwt;
                }
            }
        }
        cout<<endl;
        for(auto ele:dist){
            cout<<ele<<" ";
        }




    }

};

int main(){
    Graph g ;

    g.addEdge(1 , 2,5, 1);
    g.addEdge(0 , 1,5, 1);
    // g.addEdge(5 , 1,1,1 );
    g.addEdge(1 , 4,4, 1);
    g.addEdge(3 , 5,3, 1);
    g.addEdge(2 , 3,2, 1);

    // g.print();

    unordered_map<int , bool > vis;
    stack<int>st;

    for(int i=0;i<=5;i++){

        if(!vis[i]){
           g.topo(i , vis ,st);
        }
    }
     

    g.sssp(st , 5);



    
    return 0;
}