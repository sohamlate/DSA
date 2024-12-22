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

    void bellmon(int src , int n){
        vector<int>dist(n , INT_MAX);

        dist[src] =0;
        for(int i=1;i<n;i++){
            for(auto a:adj){
                for(auto b:a.second){
                    int u = a.first;
                    int v = b.first;
                    int wt = b.second;

                    if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        bool chage = false;

        for(auto a:adj){
            for(auto b:a.second){
                int u = a.first;
                int v = b.first;
                int wt = b.second;

                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                    chage = true;
                    break;
                    dist[v] = dist[u] + wt;
                }
            }
        }

        if(chage){
            cout<<"NEgative Cycle\n";
        }
        else{
            cout<<"NO negative cycle\n";
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

    
   
    g.bellmon(1 , 5);

    
 
    
    return 0;
}