
#include<bits/stdc++.h>
using namespace std;
/*
class graph{
    private:
    
    map<string,list<pair<string,int>>>l;
    public:
    void addEdge(string x, string y, bool bidir,int wt){
        l[x].push_back(make_pair(y,wt));
        if(bidir)
            l[y].push_back(make_pair(x,wt));
    }
    void printAdjList(){
        for(auto city : l){
            string first = city.first;
            cout << first <<"->";
            list<pair<string,int>>nbrs = city.second;
            for(auto nbr : nbrs){
                cout << nbr.first <<" "<<nbr.second << ",";
            }
            cout << endl;
        }
    }
    
};
int main(){
    graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,40);
    g.addEdge("A","C",true,10);
    g.addEdge("C","D",true,40);
    g.addEdge("A","D",false,50);
    g.printAdjList();
    
}
*/

//Graph traversal
    // BFS and DFS Breadth = iterative || Depth = recursive
    // BFS start from src and go to nbr, if we go first time then mark it visited 
    // for storing we use Queue Stl DS
    // each time we pop out and push ite nbr and mark it visited
    

template<typename t>
class graph{
    public:
    map<t,list<t>>l;
    void addEdge(t x,t y){ // undirected graph
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void addEdgeDirected(t x,t y){ // for directed
        l[x].push_back(y);
    }
    void addEdgeSnake(t x,t y){ // for snake and ledder
        l[x].push_back(y);
    }
    void addEdgeDFS(int x,int y){ // for dfs
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(t src){
        queue<t> q;
        map<t,int> v;
        q.push(src);
        v[src] = true;
        while(!q.empty()){
            t node = q.front();
            q.pop();
            cout << node <<" ";
            for(auto nbr:l[node]){
                if(!v[nbr]){
                      q.push(nbr);
                      v[nbr] = true;
                }        
            }
        }
    }
    void bfsForShortestPath(t src){
        queue<t> q;
        map<t,int> dis;
        for(auto x : l){
            t node = x.first;
            dis[node] = INT_MAX; // initilly infinity
        }
        q.push(src);
        dis[src] = 0;
        while(!q.empty()){
            t node = q.front();
            q.pop();
           // cout << node <<" ";
            for(auto nbr:l[node]){
                if(dis[nbr] == INT_MAX){
                    q.push(nbr);
                    dis[nbr] = dis[node]+1;
                }        
            }
        }

        for(auto node_pair:l){
            t node = node_pair.first;
            int d = dis[node];
            cout << "node " << node << " Distance from src " << d << endl;
        }
    }

    void dfsHelper(t src,map<t,bool>&visited){


        cout << src <<" ";
        visited[src] = true;
        // go to all nbr of that is not viited

        for(t nbr : l[src]){
            if(!visited[nbr])
                dfsHelper(nbr,visited);
        }
    }

    void DFS(t src){
        map<t,bool> visited;
        // mark them as not vsited in the biginning 

        for(auto i : l){
            t node = i.first;
            visited[node] = false;
        }
        dfsHelper(src,visited);
    }

    // connected component in undirected graph 
    // multiple disconnected graph called graph forrest collection of tree
    // using DFS

    void dfsConnectedComponent(t src){
        map<t,bool>visited;
        for(auto p:l){
            t node = p.first;
            visited[node] = false;
        }
        int c = 0; // for how many component are there
        for(auto nbr:l){
            t node = nbr.first;
            if(!visited[node]){
                cout <<"component" << c <<"-->";
                dfsHelper(node,visited);
                c++;
                cout << endl;
            }
        }
    }
    void dfsToplogicalSortHelper(t src,map<t,bool>&visited,list<t>&ordering){
        visited[src] = true;
        // go to all nbr of that is not vsited

        for(t nbr : l[src]){
            if(!visited[nbr])
                dfsToplogicalSortHelper(nbr,visited,ordering);
        }
        ordering.push_front(src);
    }
    void dfsTopologicalSort(){
         map<t,bool> visited;
         list<t> ordering;
        // mark them as not vsited in the biginning 

        for(auto i : l){
            t node = i.first;
            visited[node] = false;
        }

        for(auto p:l){
            t node = p.first;
            if(!visited[node]){
                dfsToplogicalSortHelper(node,visited,ordering);
            }

        }
        for(auto x: ordering){
            cout << x <<" ";
        }
    }



}; 

int main(){
   // graph<int> g;
    // g.addEdge(0,1);
    // g.addEdge(1,2);
    // g.addEdge(0,3);
    // g.addEdge(3,4);
    // g.addEdge(4,5);
    // g.bfs(0);
    // cout << endl;
    // g.bfsForShortestPath(0);
    // cout << endl;
    // Snake ledder with graph
    // snake position is -ve and ledder is +ve
    /*int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] =18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;
    graph <int> g;
    for(int i = 0; i <= 36; i++){
        for(int dice = 1; dice<=6;dice++){
            int j = i+dice;
            if(j <=36){
                g.addEdgeSnake(i,j);
            }
        }
    }

*/
/*
    // DFS 
    graph<int>g;
    g.addEdgeDFS(0,1);
    g.addEdgeDFS(1,2);
    g.addEdgeDFS(0,3);
    g.addEdgeDFS(3,2);
    g.addEdgeDFS(3,4);
    g.addEdgeDFS(4,5);
    g.DFS(0);
    */


    // DFS connected component 
  /*  graph<int> g;
    g.addEdgeDFS(0,4);
    g.addEdgeDFS(0,1);
    g.addEdgeDFS(1,2);
    g.addEdgeDFS(2,3);
    g.addEdgeDFS(5,6);
    g.addEdgeDFS(6,7);
    g.addEdgeDFS(8,8);
    g.dfsConnectedComponent(0);
    */

    
    // Topological sorting
    graph<string> g;
    g.addEdgeSnake("py","dataP"); // bcz directed graph
    g.addEdgeSnake("py","pyt");
     g.addEdgeSnake("dataP","ml");
    g.addEdgeSnake("py","ml");
     g.addEdgeSnake("pyt","DL");
      g.addEdgeSnake("DL","FR");
     g.addEdgeSnake("ml","DL");
     g.addEdgeSnake("DS","FR");
     g.dfsTopologicalSort();

    



    
}