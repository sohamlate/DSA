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

    void floyd(int n){
        vector<vector<int>>dist(n , vector<int>(n , 1e9));

        for(int i=0;i<n;i++){
            dist[i][i] =0;
        }

        for(auto a:adj){
            for(auto b:a.second){
                int u = a.first;
                int v = b.first;
                int wt = b.second;

                dist[u][v] = wt;
            }
        }

        for(int helper =0;helper <n;helper++){
            for(int src =0;src<n;src++){
                for(int dest=0;dest<n;dest++){
                    dist[src][dest] = min(dist[src][dest] , dist[src][helper] + dist[helper][dest]);
                }
            }
        }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<dist[i][j]<<" ";
                }
                cout<<endl;
            }

    }

    

    

  

};

int main(){
    Graph g ;

    g.addEdge(1 , 2,2, 1);
    g.addEdge(5 , 1,7, 1);
    g.addEdge(1 , 4,3, 1);
    g.addEdge(3 , 5,9, 1);
    g.addEdge(2 , 3,11, 1);

    g.print();

    unordered_map< int , bool > vis;

    
   
    g.floyd(6);

    
 
    
    return 0;
}