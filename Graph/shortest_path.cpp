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

    void bfs(int src , int dist){
        queue<int> q;
        unordered_map<int , bool > vis;
        unordered_map<int , int > parent;
        parent[src] = -1;

        q.push(src);
        vis[src] = true;


        while(!q.empty()){

            int node = q.front();
            // cout<<node<<" ";
            q.pop();

            for(auto nbr : adj[node]){
                int child = nbr.first;
                if(!vis[child]){
                    q.push(child);
                    vis[child] = true;
                    parent[child] = node;   
                }
            }
        }

        vector<int>shortest;
        while(dist != -1){
            shortest.push_back(dist);
            dist = parent[dist];
        }

        reverse(shortest.begin() , shortest.end());

        for(auto ele:shortest){
            cout<<ele<<" ";
        }
    }

  

};

int main(){
    Graph g ;

    g.addEdge(1 , 2,6, 1);
    // g.addEdge(1 , 5,7, 1);
    g.addEdge(1 , 4,8, 1);
    g.addEdge(3 , 5,2, 1);
    g.addEdge(2 , 3,1, 1);

    g.print();

    unordered_map< int , bool > vis;

    vector<int>st;
    // for(int i=1 ;i <6;i++){
    //     if(!vis[i]){
    //     }
    // }
            g.bfs(1 , 5);

    reverse(st.begin(), st.end());
    for(auto ele : st){
        cout<<ele<<" ";
    }
   
 
    
    return 0;
}