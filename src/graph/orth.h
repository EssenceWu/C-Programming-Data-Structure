
#include "../common.h"

typedef struct c_edge
{
	int		begin;
	int		end;
	int		weight;
	struct c_edge	*left;
	struct c_edge	*right;
} c_edge;

typedef struct c_vertex
{
	c_station	station;
	struct c_edge	*left;
	struct c_edge	*right;
} c_vertex;

typedef struct c_graph_orth
{
	c_vertex	vertex[MAXSIZE];
	int		vertex_num;
	int		edge_num;
} c_graph_orth;