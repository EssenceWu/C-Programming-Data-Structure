
#include "../graph/matrix.h"
#include "../queue.h"

void c_graph_vertex_init( c_graph_matrix *graph, char *filename );


void c_graph_edge_init( c_graph_matrix *graph, char *filename );


void c_graph_matrix_dfs_example( c_graph_matrix *graph );


void c_graph_matrix_bfs_example( c_graph_matrix *graph );


void c_graph_matrix_prim_example( c_graph_matrix *graph );


void c_graph_matrix_dijskra_example( c_graph_matrix *graph );


void c_graph_matrix_floyd_example( c_graph_matrix *graph );


void c_graph_matrix_astar_example( c_graph_matrix *graph );


int main( int argc, char *argv[] )
{
	c_graph_matrix *graph = (c_graph_matrix *) malloc( sizeof(c_graph_matrix) );

	for ( int idx = 0; idx < MAXSIZE; idx++ )
	{
		for ( int jdx = 0; jdx < MAXSIZE; jdx++ )
		{
			graph->edge[idx][jdx] = 0;
		}
	}
	graph->vertex_num = graph->edge_num = 0;

	c_graph_vertex_init( graph, argv[1] );
	c_graph_edge_init( graph, argv[2] );


	/*
	 * c_graph_matrix_dfs_example( graph );
	 * c_graph_matrix_bfs_example( graph );
	 */

	/* c_graph_matrix_prim_example( graph ); */

	c_graph_matrix_dijskra_example( graph );
	/* c_graph_matrix_floyd_example( graph ); */
	c_graph_matrix_astar_example( graph );

	free( graph );
	return(0);
}


void c_graph_vertex_init( c_graph_matrix *graph, char *filename )
{
	FILE *fp = fopen( filename, "r" );
	if ( !fp )
	{
		printf( "File error\n" );
		exit( 0 );
	}
	int idx = 0;
	while ( !feof( fp ) )
	{
		fscanf( fp, "%s%lf%lf", graph->vertex[idx].name, &graph->vertex[idx].lat, &graph->vertex[idx].lng );
		idx++;
	}
	graph->vertex_num = idx;
	fclose( fp );
}


void c_graph_edge_init( c_graph_matrix *graph, char *filename )
{
	FILE *fp = fopen( filename, "r" );
	if ( !fp )
	{
		printf( "File error\n" );
		exit( 0 );
	}
	int idx = 0, begin = 0, end = 0, weight = 0;
	while ( !feof( fp ) )
	{
		fscanf( fp, "%d%d%d", &begin, &end, &weight );
		graph->edge[begin][end] = weight;
		idx++;
	}
	graph->edge_num = idx;
	fclose( fp );
}


void c_graph_matrix_dfs_example( c_graph_matrix *graph )
{
	printf( "\nDfs result: \n\n" );
	c_graph_matrix_dfs( graph );
	printf( "\n" );
}


void c_graph_matrix_bfs_example( c_graph_matrix *graph )
{
	printf( "\nBfs result: \n\n" );
	c_graph_matrix_bfs( graph );
	printf( "\n" );
}


void c_graph_matrix_prim_example( c_graph_matrix *graph )
{
	printf( "\nPrim: " );
	char name[MAXSIZE];
	scanf( "%s", name );
	printf( "\nResult: \n" );
	int begin = -1;
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		if ( !strcmp( graph->vertex[idx].name, name ) )
			begin = idx;
	}
	if ( begin == -1 )
	{
		printf( "No found\n\n" );
		exit( 0 );
	}
	c_graph_matrix_prim( graph, begin );
	printf( "\n\n" );
}


void c_graph_matrix_dijskra_example( c_graph_matrix *graph )
{
	printf( "\nDijskra: " );
	char name1[MAXSIZE], name2[MAXSIZE];
	scanf( "%s%s", name1, name2 );
	printf( "\nResult: " );
	int tree[MAXSIZE], weight[MAXSIZE], begin = -1, end = -1;
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		if ( !strcmp( graph->vertex[idx].name, name1 ) )
			begin = idx;
		if ( !strcmp( graph->vertex[idx].name, name2 ) )
			end = idx;
	}
	if ( begin == -1 || end == -1 )
	{
		printf( "No found.\n\n" );
		exit( 0 );
	}
	c_graph_matrix_dijskra( graph, tree, weight, begin );
	if ( !weight[end] )
	{
		printf( "No line.\n\n" );
		exit( 0 );
	}
	int	pos	= end;
	c_queue *queue	= c_queue_create();
	while ( true )
	{
		c_queue_lpush( queue, &graph->vertex[pos].name );
		if ( pos == begin )
			break;
		pos = tree[pos];
	}
	int sum = c_queue_length( queue );
	while ( c_queue_length( queue ) )
		printf( "->%s", c_queue_lpop( queue ) );
	if ( weight[end] < 1000 )
		printf( "\n\nSum %dstop,distance about %dm.\n\n", sum, weight[end] );
	else
		printf( "\n\nSum %dstop,distance about %dkm.\n\n", sum, weight[end] / 1000 );
	c_queue_close( queue );
}


void c_graph_matrix_floyd_example( c_graph_matrix *graph )
{
	printf( "\nFloyd: " );
	char name1[MAXSIZE], name2[MAXSIZE];
	scanf( "%s%s", name1, name2 );
	printf( "\nResult: " );
	c_array tree, weight;
	int	begin = -1, end = -1;
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		if ( !strcmp( graph->vertex[idx].name, name1 ) )
			begin = idx;
		if ( !strcmp( graph->vertex[idx].name, name2 ) )
			end = idx;
	}
	if ( begin == -1 || end == -1 )
	{
		printf( "No found.\n\n" );
		exit( 0 );
	}
	c_graph_matrix_floyd( graph, &tree, &weight );
	if ( !weight[begin][end] )
	{
		printf( "No line.\n\n" );
		exit( 0 );
	}
	int pos = begin, sum = 0;
	while ( true )
	{
		printf( "->%s", graph->vertex[pos].name );
		sum++;
		if ( pos == end )
			break;
		pos = tree[pos][end];
	}
	if ( weight[begin][end] < 1000 )
		printf( "\n\nSum %dstop,distance about %dm.\n\n", sum, weight[begin][end] );
	else
		printf( "\n\nSum %dstop,distance about %dkm.\n\n", sum, weight[begin][end] / 1000 );
}


void c_graph_matrix_astar_example( c_graph_matrix *graph )
{
	printf( "\nAstar: " );
	char name1[MAXSIZE], name2[MAXSIZE];
	scanf( "%s%s", name1, name2 );
	printf( "\nResult: " );
	int path[MAXSIZE], begin = -1, end = -1;
	for ( int idx = 0; idx < graph->vertex_num; idx++ )
	{
		if ( !strcmp( graph->vertex[idx].name, name1 ) )
			begin = idx;
		if ( !strcmp( graph->vertex[idx].name, name2 ) )
			end = idx;
	}
	if ( begin == -1 || end == -1 )
	{
		printf( "No found.\n\n" );
		exit( 0 );
	}
	c_graph_matrix_astar( graph, path, begin, end );
	int	pos	= end, link = end, weight = 0;
	c_queue *queue	= c_queue_create();
	while ( true )
	{
		if ( pos == -1 )
		{
			printf( "No line.\n\n" );
			exit( 0 );
		}
		weight += graph->edge[pos][link];
		c_queue_lpush( queue, &graph->vertex[pos].name );
		if ( pos == begin )
			break;
		link = pos, pos = path[pos];
	}
	int sum = c_queue_length( queue );
	while ( c_queue_length( queue ) )
		printf( "->%s", c_queue_lpop( queue ) );
	if ( weight < 1000 )
		printf( "\n\nSum %dstop,distance about %dm.\n\n", sum, weight );
	else
		printf( "\n\nSum %dstop,distance about %dkm.\n\n", sum, weight / 1000 );
	c_queue_close( queue );
}