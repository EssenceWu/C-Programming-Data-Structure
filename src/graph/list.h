
#include "../common.h"

typedef struct c_edge
{
	int		adjvex;
	int		weight;
	struct c_edge	*right;
} c_edge;

typedef struct c_vertex
{
	c_station	station;
	int		in_degree;
	struct c_edge	*next;
} c_vertex;

typedef struct c_graph_list
{
	c_vertex	vertex[MAXSIZE];
	int		vertex_num;
	int		edge_num;
} c_graph_list;

bool c_graph_list_sort( c_graph_list *graph );