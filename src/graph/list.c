
#include "list.h"
#include "../queue.h"

bool c_graph_list_sort( c_graph_list * graph )
{
	int	vertex_num	= 0;
	c_queue *queue		= c_queue_create();
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		if ( !graph->vertex[idx].in_degree )
		{
			c_queue_lpush( queue, &graph->vertex[idx] );
		}
	}
	while ( c_queue_length( queue ) )
	{
		c_vertex *vertex = c_queue_rpop( queue );
		printf( "->%s", vertex->station.name );
		vertex_num++;
		for ( c_edge *edge = vertex->next; edge; edge = edge->right )
		{
			graph->vertex[edge->adjvex].in_degree--;
			if ( !graph->vertex[edge->adjvex].in_degree )
			{
				c_queue_lpush( queue, &graph->vertex[edge->adjvex] );
			}
		}
	}
	c_queue_close( queue );
	return(vertex_num == graph->vertex_num ? true : false);
}