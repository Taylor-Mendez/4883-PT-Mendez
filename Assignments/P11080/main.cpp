#include <bits/stdc++.h>
using namespace std;
 
bool isBipartite(int V, vector<int> adj[])
{
    // vector to store colour of vertex
    // assigning all to -1 i.e. uncoloured
    // colours are either 0 or 1
    // for understanding take 0 as red and 1 as blue
    vector<int> col(V, -1);
 
    // queue for BFS storing {vertex , colour}
    queue<pair<int, int> > q;

    // for keeping track of min guards
    int minGuards = 0;
   
    //loop incase graph is not connected
    for (int i = 0; i < V; i++) {

        int count[2] = {0};
       
        //if not coloured
        if (col[i] == -1) {
           
            //colouring with 0 i.e. red
            q.push({ i, 0 });
            col[i] = 0;
            ++count[col[i]];
           
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
               
                //current vertex
                int v = p.first;
                  //colour of current vertex
                int c = p.second;
                 
                //traversing vertexes connected to current vertex
                for (int j : adj[v]) {
                   
                    //if already coloured with parent vertex color
                    //then bipartite graph is not possible
                    if (col[j] == c){
                        cout << "-1" << endl;
                        return 0;
                    }
                   
                    //if uncooloured
                    if (col[j] == -1) {
                        //colouring with opposite color to that of parent
                        col[j] = (c) ? 0 : 1;
                        ++count[col[j]];
                        q.push({ j, col[j] });
                    }
                }
            }
            minGuards += max(1, min(count[0], count[1]));
        }
    }


    // // print the colors of the vertices
    // for (int i = 0; i < V; i++){
    //     cout << col[i] << endl;
    // }

    cout << minGuards << endl;

    //if all vertexes are coloured such that
    //no two connected vertex have same colours
    return 1;
}
 
 
// Add edge
void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s);
}
 
 
// { Driver Code Starts.
int main()
{
 
    ifstream cin("input7.txt");

    int A;          // external loop counter
    cin >> A;

    for (int i = 0; i < A; i++){
        int vertices, edges;
        cin >> vertices >> edges;


        //adjacency list for storing graph
        vector<int> adj[vertices];
        for (int j = 0; j < edges; j++){
            int a, b;
            cin >> a >> b;
            addEdge(adj, a, b);
        }
   

        isBipartite(vertices, adj);
    }
 
    return 0;
}