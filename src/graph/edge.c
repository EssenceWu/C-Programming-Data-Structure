
#include "edge.h"


void c_graph_edge_kruskal( c_graph_edge *graph )
{
	int tree[MAXSIZE];
	for ( int idx = 0; idx < graph->edge_num; idx++ )
	{
		tree[idx] = -1;
	}
	c_graph_edge_sort( graph, 0, graph->edge_num - 1 );
	for ( int idx = 0; idx < graph->edge_num; idx++ )
	{
		int begin	= graph->edge[idx].begin,
		    end		= graph->edge[idx].end,
		    m		= c_graph_edge_find( tree, begin ),
		    n		= c_graph_edge_find( tree, end );
		if ( m != n )
		{
			printf( "%s->%s(%d)\n", graph->vertex[begin].name, graph->vertex[end].name, graph->edge[idx].weight );
			tree[begin] = end;
		}
	}
}


void c_graph_edge_sort( c_graph_edge *graph, int left, int right )
{
	if ( left >= right )
		return;
	int	idx	= left, jdx = right;
	c_edge	pivot	= graph->edge[left];
	while ( idx < jdx )
	{
		while ( idx < jdx && graph->edge[jdx].weight >= pivot.weight )
			jdx--;
		graph->edge[idx] = graph->edge[jdx];
		while ( idx < jdx && graph->edge[idx].weight <= pivot.weight )
			idx++;
		graph->edge[jdx] = graph->edge[idx];
	}
	graph->edge[idx] = pivot;
	c_graph_edge_sort( graph, left, idx - 1 );
	c_graph_edge_sort( graph, idx + 1, right );
}


int c_graph_edge_find( int *tree, int pos )
{
	while ( tree[pos] != -1 )
	{
		pos = tree[pos];
	}
	return(pos);
}