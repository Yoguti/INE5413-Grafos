#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Vertex {
  int label;
  char* string_label;
  float vertex_value;
  struct Vertex *next;
};
typedef struct Vertex Vertex;

struct Graph {
  int num_vertex;
  int num_edges;
  bool isDirected; 
  Vertex **adjacency_list;
};
typedef struct Graph Graph;

Vertex *createVertex(int label, float value, char* string_label) {
  Vertex *new_vertex = malloc(sizeof(Vertex));
  new_vertex->label = label;
  new_vertex->vertex_value = value;
  new_vertex->string_label = string_label;
  new_vertex->next = NULL;
  return new_vertex;
}

Graph *createGraph(int vertex_q, int isDirected) {
    Graph *new_graph = malloc(sizeof(Graph));
    new_graph->num_vertex = vertex_q;
    new_graph->num_edges = 0;
    new_graph->isDirected = isDirected;
    new_graph->adjacency_list = malloc(vertex_q * sizeof(Vertex *));
    for (int i = 0; i < vertex_q; i++) {
        new_graph->adjacency_list[i] = NULL;
    }
    return new_graph;
}

void connectVertex(int source, int destination, float destination_value, char* destination_name, Graph *graph) {
    Vertex *new_vertex = createVertex(destination, destination_value, destination_name);

    if (graph->adjacency_list[source] == NULL) {
        graph->adjacency_list[source] = new_vertex;
    } else {
        Vertex *p = graph->adjacency_list[source];
        while (p->next != NULL) p = p->next;
        p->next = new_vertex;
    }

    graph->num_edges++;

    // se unidirecional, adicionar a outra edge
    if (!graph->isDirected) {
        Vertex *reverse_vertex = createVertex(source, graph->adjacency_list[source]->vertex_value,
                                             graph->adjacency_list[source]->string_label);
        if (graph->adjacency_list[destination] == NULL) {
            graph->adjacency_list[destination] = reverse_vertex;
        } else {
            Vertex *p = graph->adjacency_list[destination];
            while (p->next != NULL) p = p->next;
            p->next = reverse_vertex;
        }
        graph->num_edges++;
    }
}

int qtdVertices(Graph* graph) {
  return graph->num_vertex;
}

int qtdArestas(Graph* graph) {
  if (graph->isDirected) {
    return graph->num_edges;
  } else {
    return (int)(graph->num_edges / 2);
  }
}

int grau(Graph* graph, Vertex* vertex) {
  int grau = 0;
  Vertex* p = graph->adjacency_list[vertex->label];
  while (p != NULL)
  {
    p = p->next;
    grau++;
  }
  return grau;
}

char* rotulo(Vertex *v) { //retorna o rotulo do vertice v;
  v->string_label;
}

Vertex* vizinhos(Vertex* v) { // retorna os vizinhos do vertice v;
  return v->next;
}
bool haAresta(Vertex* u, Vertex* v,Graph* graph) { // se {u, v} ∈ E, retorna verdadeiro; se nao existir, retorna falso;
  Vertex* p = graph->adjacency_list[u->label];
  while (p != NULL)
  {
    if (p == v)
    {
      return true;
    } else {
      return false;
    }
    
  }
  
  
}
peso(u, v) { // se {u, v} ∈ E, retorna o peso da aresta {u, v}; se nao existir, retorna um valor infinito positivo;

}
ler(arquivo) {

}