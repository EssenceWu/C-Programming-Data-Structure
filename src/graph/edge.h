
#include "../common.h"

typedef struct c_edge 
{
	int	begin;
	int	end;
	int	weight;
} c_edge;

typedef struct c_graph_edge 
{
	c_station	vertex[MAXSIZE];
	c_edge		edge[MAXSIZE];
	int		vertex_num;
	int		edge_num;
} c_graph_edge;

void c_graph_edge_kruskal( c_graph_edge *graph );


void c_graph_edge_sort( c_graph_edge *graph, int left, int right );


int c_graph_edge_find( int *tree, int pos );