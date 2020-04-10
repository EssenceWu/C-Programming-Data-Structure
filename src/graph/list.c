
#include "list.h"

bool c_graph_list_sort( c_graph_list * graph )
{
	int	vertex_num	= 0;
	c_stack *stack		= c_stack_create();
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		if ( !graph->vertex[idx].in_degree )
			c_stack_push( stack, 0, &graph->vertex[idx] );
	}
	while ( c_stack_length( stack ) )
	{
		c_vertex *vertex = c_stack_pop( stack, 0 );
		printf( "->%s", vertex->stop.name );
		vertex_num++;
		for ( c_edge *edge = vertex->next; edge; edge = edge->right )
		{
			graph->vertex[edge->adjvex].in_degree--;
			if ( !graph->vertex[edge->adjvex].in_degree )
				c_stack_push( stack, 0, &graph->vertex[edge->adjvex] );
		}
	}
	c_stack_close( stack );
	return(vertex_num == graph->vertex_num ? true : false);
}