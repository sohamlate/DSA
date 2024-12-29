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

  

  

    void dijkstra(int src , int dest , int n ){
        
        
        set<pair<int , int>>s;
        s.insert({0, src});
        vector<int>dist(n, INT_MAX);
        dist[src] =0;

       while(!s.empty()){
            auto top = *s.begin();
            int topnode = top.second;
            int topdist = top.first;
            s.erase(s.begin());

            for(auto nbr : adj[topnode]){
                int nbrnode = nbr.first;
                int nbrwt = nbr.second;

                if(topdist + nbrwt < dist[nbrnode]){

                    auto pre = s.find({dist[nbrnode] , nbrnode});
                    if(pre != s.end()){

                        s.erase(pre);
                    }

                    dist[nbrnode] = topdist + nbrwt;
                    s.insert({dist[nbrnode], nbrnode});


                }
            }

       }





       cout<<endl<<"ans is "<<dist[dest];




    }

};

int main(){
    Graph g ;

    g.addEdge(1 , 2,5, 0);
    g.addEdge(0 , 1,5, 0);
    g.addEdge(5 , 1,1,0 );
    g.addEdge(1 , 4,4, 0);
    g.addEdge(3 , 5,3, 0);
    g.addEdge(2 , 3,2, 0);

    // g.print();

    unordered_map<int , bool > vis;
    stack<int>st;

    
     

    g.dijkstra(0 , 5, 6);



    
    return 0;
}
