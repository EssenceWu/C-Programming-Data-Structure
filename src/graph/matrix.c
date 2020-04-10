
#include "matrix.h"

void c_graph_matrix_dfs( c_graph_matrix *graph )
{
	int visit[MAXSIZE];
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
		visit[idx] = -1;
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		if ( visit[idx] == -1 )
			c_graph_matrix_visit( graph, visit, idx );
	}
}


void c_graph_matrix_visit( c_graph_matrix *graph, int *visit, int pos )
{
	printf( "->%s", graph->vertex[pos].name );
	visit[pos] = pos;
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		if ( graph->edge[pos][idx] && visit[idx] == -1 )
			c_graph_matrix_visit( graph, visit, idx );
	}
}


void c_graph_matrix_bfs( c_graph_matrix *graph )
{
	int visit[MAXSIZE];
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
		visit[idx] = -1;
	c_stack *stack = c_stack_create();
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		if ( visit[idx] == -1 )
		{
			printf( "->%s", graph->vertex[idx].name );
			visit[idx] = idx;
			c_stack_push( stack, 0, &visit[idx] );
			while ( c_stack_length( stack ) )
			{
				int *pos = c_stack_pop( stack, 0 );
				for ( int jdx = 0; jdx < graph->vertex_num; jdx++ )
				{
					if ( graph->edge[*pos][jdx] && visit[jdx] == -1 )
					{
						printf( "->%s", graph->vertex[jdx].name );
						visit[jdx] = jdx;
						c_stack_push( stack, 0, &visit[jdx] );
					}
				}
			}
		}
	}
	c_stack_close( stack );
}


void c_graph_matrix_prim( c_graph_matrix *graph, int pos )
{
	int tree[MAXSIZE], weight[MAXSIZE], visit[MAXSIZE];
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
		tree[idx] = pos, weight[idx] = 0, visit[idx] = -1;
	c_stack *stack = c_stack_create();
	visit[pos] = pos;
	c_stack_push( stack, 0, &visit[pos] );
	while ( c_stack_length( stack ) )
	{
		int *adjvex = c_stack_pop( stack, 0 );
		if ( *adjvex != pos )
			printf( "%s->%s(%d)\n", graph->vertex[tree[*adjvex]].name, graph->vertex[*adjvex].name, weight[*adjvex] );
		for ( int idx = 0; idx < graph->vertex_num; idx++ )
		{
			int a = graph->edge[*adjvex][idx];
			if ( a && (!weight[idx] || a < weight[idx]) && visit[idx] == -1 )
			{
				tree[idx] = *adjvex, weight[idx] = a, visit[idx] = idx;
				c_stack_push( stack, weight[idx], &visit[idx] );
			}
		}
	}
}


void c_graph_matrix_dijskra( c_graph_matrix *graph, int *tree, int *weight, int pos )
{
	int visit[MAXSIZE];
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
		tree[idx] = pos, weight[idx] = 0, visit[idx] = -1;
	c_stack *stack = c_stack_create();
	visit[pos] = pos;
	c_stack_push( stack, 0, &visit[pos] );
	while ( c_stack_length( stack ) )
	{
		int *adjvex = c_stack_pop( stack, 0 );
		for ( int idx = 0; idx < graph->vertex_num; idx++ )
		{
			int a = graph->edge[*adjvex][idx];
			if ( a && (!weight[idx] || (weight[*adjvex] + a) < weight[idx]) && visit[idx] == -1 )
			{
				tree[idx] = *adjvex, weight[idx] = weight[*adjvex] + a, visit[idx] = idx;
				c_stack_push( stack, weight[idx], &visit[idx] );
			}
		}
	}
}


void c_graph_matrix_floyd( c_graph_matrix *graph, c_array *tree, c_array *weight )
{
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		for ( int jdx = 0; jdx < graph->vertex_num; jdx++ )
			(*tree)[idx][jdx] = jdx, (*weight)[idx][jdx] = graph->edge[idx][jdx];
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
	int	visit[MAXSIZE];
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		c_graph_matrix_set( open, idx, 0, -1 );
		c_graph_matrix_set( closed, idx, 0, -1 );
		visit[idx] = -1;
	}
	c_stack *stack = c_stack_create();
	visit[begin] = begin;
	c_stack_push( stack, 0, &visit[begin] );
	while ( c_stack_length( stack ) )
	{
		int *pos = c_stack_pop( stack, 0 );
		closed[*pos] = open[*pos];
		c_graph_matrix_set( open, *pos, 0, -1 );
		for ( int idx = 0; idx < graph->vertex_num; idx++ )
		{
			if ( graph->edge[*pos][idx] )
			{
				int weight = c_graph_distance( graph->vertex, begin, idx, end );
				if ( open[idx].adjvex != -1 )
				{
					if ( weight < open[idx].weight )
					{
						c_graph_matrix_set( open, idx, weight, *pos );
						visit[idx] = idx;
						c_stack_push( stack, weight, &visit[idx] );
					}
				}else if ( closed[idx].adjvex != -1 )
				{
					if ( weight < closed[idx].weight )
					{
						c_graph_matrix_set( open, idx, weight, *pos );
						c_graph_matrix_set( closed, idx, 0, -1 );
						visit[idx] = idx;
						c_stack_push( stack, weight, &visit[idx] );
					}
				}else{
					c_graph_matrix_set( open, idx, weight, *pos );
					visit[idx] = idx;
					c_stack_push( stack, weight, &visit[idx] );
				}
			}
		}
		if ( *pos == end )
			break;
	}
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
		path[idx] = closed[idx].adjvex;
	c_stack_close( stack );
}


void c_graph_matrix_set( c_astar *table, int pos, double weight, int adjvex )
{
	table[pos].weight = weight, table[pos].adjvex = adjvex;
}