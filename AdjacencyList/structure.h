typedef struct edge_s{
  struct vertex_s *vertex;
  int weight;
  struct edge_s *next;
}edge_t;

typedef struct vertex_s{
  char *id;
  int nIn, nOut;
  int visited;
  int hasAtm;
  edge_t *edge;
  struct vertex_s *next;
}vertex_t;

typedef struct graph_s{
  vertex_t *head;
  int n;
}graph_t;

graph_t *graph_allocate(void);
graph_t *graph_read(char *filename);
vertex_t *find_vertex(graph_t *graph, char *id);
void vertex_add(graph_t *graph, char *id);
void edge_add(vertex_t *vertex1, vertex_t *vertex2, int weight);
void graph_write(graph_t *graph);
void graph_dispose(graph_t *graph);
