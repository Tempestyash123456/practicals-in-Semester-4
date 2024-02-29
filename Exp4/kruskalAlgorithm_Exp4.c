#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Graph {
    int V, E;
    Edge* edge;
} Graph;

Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge*) malloc(graph->E * sizeof(Edge));
    return graph;
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[yroot] = xroot;
}

int compare(const void* a, const void* b) {
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

void KruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[V];
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);
    int* parent = (int*) malloc(V * sizeof(int));
    for (int v = 0; v < V; ++v)
        parent[v] = v;
    int e = 0;
    int i = 0;
    while (e < V - 1) {
        Edge next_edge = graph->edge[i++];
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);
        if (x != y) {
            result[e++] = next_edge;
            Union(parent, x, y);
        }
    }
    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    return;
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter the adjacency matrix:\n");
    int adjMatrix[V][V];
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
    // Convert adjacency matrix to edge list
    E = 0;
    for(int i = 0; i < V; i++) {
        for(int j = i+1; j < V; j++) {
            if(adjMatrix[i][j] != 0) E++;
        }
    }
    Graph* graph = createGraph(V, E);
    int k = 0;
    for(int i = 0; i < V; i++) {
        for(int j = i+1; j < V; j++) {
            if(adjMatrix[i][j] != 0) {
                graph->edge[k].src = i;
                graph->edge[k].dest = j;
                graph->edge[k].weight = adjMatrix[i][j];
                k++;
            }
        }
    }
    KruskalMST(graph);
    return 0;
}