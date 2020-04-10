
#include "../common.h"
#include "../stack.h"

typedef struct c_graph_matrix
{
	c_stop	vertex[MAXSIZE];
	c_array edge;
	int	vertex_num;
	int	edge_num;
} c_graph_matrix;

void c_graph_matrix_dfs( c_graph_matrix *graph );


void c_graph_matrix_visit( c_graph_matrix *graph, int *visit, int pos );


void c_graph_matrix_bfs( c_graph_matrix *graph );


void c_graph_matrix_prim( c_graph_matrix *graph, int pos );


void c_graph_matrix_dijskra( c_graph_matrix *graph, int *tree, int *weight, int pos );


void c_graph_matrix_floyd( c_graph_matrix *graph, c_array *tree, c_array *weight );


void c_graph_matrix_astar( c_graph_matrix *graph, int *path, int begin, int end );


void c_graph_matrix_set( c_astar *table, int pos, double weight, int adjvex );