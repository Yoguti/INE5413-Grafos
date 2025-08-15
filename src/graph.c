#include <stdio.h>
#include <stdlib.h>

struct Vertex {
  float vertex_value;
  struct Vertex *next;
};
typedef struct Vertex Vertex;

struct Graph {
  int num_vertex;
  Vertex **adjacency_list;
};
typedef struct Graph Graph;

Vertex *createVertex(float value) {
  Vertex *new_vertex = malloc(sizeof(Vertex));
  new_vertex->vertex_value = value;
  new_vertex->next = NULL;
  return new_vertex;
}

Graph *createGraph(int vertex_q) {
  Graph *new_graph = malloc(sizeof(Graph));
  new_graph->num_vertex = vertex_q;
  new_graph->adjacency_list = malloc(vertex_q * sizeof(Vertex));

  for (int i = 0; i < vertex_q; i++) {
    new_graph->adjacency_list[i] = NULL;
  }
  return new_graph;
}

void addEdge(float source, int destination, Graph *graph) {
  Vertex *sourceVertex = createVertex(source);
  sourceVertex->next = graph->adjacency_list[destination];
}

void connect(int source, float destination_value, Graph *graph) {
  // if head of graph does not exist, create head, else
  if (graph->adjacency_list[source] != NULL) {
    Vertex *p = graph->adjacency_list[source];
    while (p->next != NULL) {
      p = p->next;
    }
    p->next = createVertex(destination_value);
  } else {
    graph->adjacency_list[source] = createVertex(destination_value);
  }
}
