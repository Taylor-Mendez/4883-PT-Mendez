#include <iostream>
#include <bits/stdc++.h>

using namespace std;
 
// a structure to represent a weighted edge in graph
struct Edge{
    int src,
        dest,
        weight;
};
 
// a structure to represent a connected, directed and
// weighted graph
struct Graph{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
 
    // graph is represented as an array of edges.
    struct Edge* edge;
};
 
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E){
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}
 
// A utility function used to print the solution
void printArr(int dist[], int n){
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
 
// The main function that finds shortest distances from src to
// all other vertices using Bellman-Ford algorithm.  The function
// also detects negative weight cycle
int BellmanFord(struct Graph* graph, int src, int time){
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    int mice = 0;       // keep track of mice that get out
 
    // Step 1: Initialize distances from src to all other vertices
    // as INFINITE
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
 
    // Step 2: Relax all edges |V| - 1 times. A simple shortest
    // path from src to any other vertex can have at-most |V| - 1
    // edges
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
 
    // Step 3: check for negative-weight cycles.  The above step
    // guarantees shortest distances if graph doesn't contain
    // negative weight cycle.  If we get a shorter path, then there
    // is a cycle.
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle");
            return 0; // If negative cycle is detected, simply return
        }
    }
 
    //printArr(dist, V);

    // Get number of mice
    for (int i = 0; i < V; i++){
        if (dist[i] <= time)
            mice++;
    }
 
    return mice;
}
 
// Driver program to test above functions
int main(){
    ifstream cin("input2.txt");
    int C;
    
    cin >> C;

    for (int j = 0; j < C; j++){
        int V,      // number of cells or vertices
            exit,   // exit cell
            T,      // time
            E;      // number of connections or edges
        
        cin >> V;
        cin >> exit;
        cin >> T;
        cin >> E;

        exit--;

        // create graph w give # of vertices and edges
        struct Graph* graph = createGraph(V,E);

        // add edges
        for (int i = 0; i < E; i++){
            int src,
                dest,
                weight;

            cin >> src;
            cin >> dest;
            cin >> weight;

            // make labels of cells match
            // for the bellmanFord function
            src--;
            dest--;

            // reverse to find from exit to every other cell
            graph->edge[i].src = dest;
            graph->edge[i].dest = src;
            graph->edge[i].weight = weight;
        }

        if (j == (C-1))
            cout << BellmanFord(graph, exit, T) << endl;
        else
            cout << BellmanFord(graph, exit, T) << endl << endl;
    }
 
    return 0;
}