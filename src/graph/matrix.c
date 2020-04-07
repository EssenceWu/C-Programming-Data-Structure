
#include "matrix.h"

void c_graph_matrix_dfs( c_graph_matrix *graph )
{
	int visit[MAXSIZE];
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		visit[idx] = -1;
	}
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		if ( visit[idx] == -1 )
		{
			c_graph_matrix_visit( graph, visit, idx );
		}
	}
}


void c_graph_matrix_visit( c_graph_matrix *graph, int *visit, int pos )
{
	printf( "->%s", graph->vertex[pos].name );
	visit[pos] = pos;
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		if ( graph->edge[pos][idx] && visit[idx] == -1 )
		{
			c_graph_matrix_visit( graph, visit, idx );
		}
	}
}


void c_graph_matrix_bfs( c_graph_matrix *graph )
{
	int visit[MAXSIZE];
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		visit[idx] = -1;
	}
	c_queue *queue = c_queue_create();
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		if ( visit[idx] == -1 )
		{
			printf( "->%s", graph->vertex[idx].name );
			visit[idx] = idx;
			c_queue_lpush( queue, &visit[idx] );
			while ( c_queue_length( queue ) )
			{
				int *pos = c_queue_rpop( queue );
				for ( int jdx = 0; jdx < graph->vertex_num; jdx++ )
				{
					if ( graph->edge[*pos][jdx] && visit[jdx] == -1 )
					{
						printf( "->%s", graph->vertex[jdx].name );
						visit[jdx] = jdx;
						c_queue_lpush( queue, &visit[jdx] );
					}
				}
			}
		}
	}
	c_queue_close( queue );
}


void c_graph_matrix_prim( c_graph_matrix *graph, int pos )
{
	int tree[MAXSIZE], weight[MAXSIZE], visit[MAXSIZE];
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		tree[idx] = pos, weight[idx] = graph->edge[pos][idx], visit[idx] = -1;
	}
	visit[pos] = pos;
	for ( int idx = 1; idx < graph->vertex_num; idx++ )
	{
		int link = -1, min = INF;
		for ( int jdx = 0; jdx < graph->vertex_num; jdx++ )
		{
			if ( weight[jdx] && weight[jdx] < min && visit[jdx] == -1 )
			{
				link	= jdx;
				min	= weight[jdx];
			}
		}
		if ( link == -1 )
			break;
		printf( "%s->%s(%d)\n", graph->vertex[tree[link]].name, graph->vertex[link].name, min );
		visit[link] = link;
		for ( int jdx = 0; jdx < graph->vertex_num; jdx++ )
		{
			int a = graph->edge[link][jdx];
			if ( a && (!weight[jdx] || a < weight[jdx]) && visit[jdx] == -1 )
			{
				tree[jdx] = link, weight[jdx] = a;
			}
		}
	}
}


void c_graph_matrix_dijskra( c_graph_matrix *graph, int *tree, int *weight, int pos )
{
	int visit[MAXSIZE];
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		tree[idx] = pos, weight[idx] = graph->edge[pos][idx], visit[idx] = -1;
	}
	visit[pos] = pos;
	for ( int idx = 1; idx < graph->vertex_num; idx++ )
	{
		int link = -1, min = INF;
		for ( int jdx = 1; jdx <= graph->vertex_num; jdx++ )
		{
			if ( weight[jdx] && weight[jdx] < min && visit[jdx] == -1 )
			{
				link = jdx, min = weight[jdx];
			}
		}
		if ( link == -1 )
			break;
		visit[link] = link;
		for ( int jdx = 0; jdx < graph->vertex_num; jdx++ )
		{
			int a = graph->edge[link][jdx];
			if ( a && (!weight[jdx] || weight[jdx] > (min + a) ) && visit[jdx] == -1 )
			{
				tree[jdx] = link, weight[jdx] = min + a;
			}
		}
	}
}


void c_graph_matrix_floyd( c_graph_matrix *graph, c_array *tree, c_array *weight )
{
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		for ( int jdx = 0; jdx < graph->vertex_num; jdx++ )
		{
			(*tree)[idx][jdx] = jdx, (*weight)[idx][jdx] = graph->edge[idx][jdx];
		}
	}
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		for ( int jdx = 0; jdx < graph->vertex_num; jdx++ )
		{
			for ( int kdx = 0; kdx < graph->vertex_num; kdx++ )
			{
				int a = (*weight)[jdx][kdx], b = (*weight)[jdx][idx], c = (*weight)[idx][kdx];
				if ( b && c && (!a || a > b + c) )
				{
					(*tree)[jdx][kdx] = (*tree)[jdx][idx], (*weight)[jdx][kdx] = b + c;
				}
			}
		}
	}
}


void c_graph_matrix_astar( c_graph_matrix *graph, int *path, int begin, int end )
{
	c_astar open[MAXSIZE], closed[MAXSIZE];
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		c_graph_matrix_set( open, idx, 0, -1 );
		c_graph_matrix_set( closed, idx, 0, -1 );
	}
	c_graph_matrix_set( open, begin, 0, begin );
	while ( true )
	{
		int pos = c_graph_matrix_find( graph, open );
		if ( pos == -1 )
			break;
		closed[pos] = open[pos];
		c_graph_matrix_set( open, pos, 0, -1 );
		for ( int idx = 0; idx < graph->vertex_num; idx++ )
		{
			if ( graph->edge[pos][idx] )
			{
				int weight = c_graph_distance( graph->vertex, begin, idx, end );
				if ( open[idx].link != -1 )
				{
					if ( open[idx].weight > weight )
					{
						c_graph_matrix_set( open, idx, weight, pos );
					}
				}else if ( closed[idx].link != -1 )
				{
					if ( closed[idx].weight > weight )
					{
						c_graph_matrix_set( open, idx, weight, pos );
						c_graph_matrix_set( closed, idx, 0, -1 );
					}
				}else{
					c_graph_matrix_set( open, idx, weight, pos );
				}
			}
		}
		if ( pos == end )
			break;
	}
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		path[idx] = closed[idx].link;
	}
}


void c_graph_matrix_set( c_astar *table, int pos, int weight, int link )
{
	table[pos].weight = weight, table[pos].link = link;
}


int c_graph_matrix_find( c_graph_matrix *graph, c_astar *table )
{
	int pos = -1, min = INF;
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		if ( table[idx].link != -1 && table[idx].weight < min )
		{
			pos = idx, min = table[idx].weight;
		}
	}
	return(pos);
}