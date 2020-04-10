
#include "../graph/edge.h"

void c_graph_vertex_init( c_graph_edge *graph, char *filename );


void c_graph_edge_init( c_graph_edge *graph, char *filename );


void c_graph_edge_kruskal_example( c_graph_edge *graph );


int main( int argc, char *argv[] )
{
	c_graph_edge *graph = (c_graph_edge *) malloc( sizeof(c_graph_edge) );
	for ( int idx = 0; idx < MAXSIZE; idx++ )
	{
		graph->edge[idx].begin = graph->edge[idx].end = 0;
	}
	graph->vertex_num = graph->edge_num = 0;

	c_graph_vertex_init( graph, argv[1] );
	c_graph_edge_init( graph, argv[2] );

	c_graph_edge_kruskal_example( graph );

	free( graph );
	return(0);
}


void c_graph_vertex_init( c_graph_edge *graph, char *filename )
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


void c_graph_edge_init( c_graph_edge *graph, char *filename )
{
	FILE *fp = fopen( filename, "r" );
	if ( !fp )
	{
		printf( "File error\n" );
		exit( 0 );
	}
	int idx = 0, begin, end, weight;
	while ( !feof( fp ) )
	{
		fscanf( fp, "%d%d%d", &begin, &end, &weight );
		graph->edge[idx].begin		= begin;
		graph->edge[idx].end		= end;
		graph->edge[idx].weight	= weight;
		idx++;
	}
	graph->edge_num = idx;
	fclose( fp );
}


void c_graph_edge_kruskal_example( c_graph_edge *graph )
{
	printf( "\nKruskal: \n" );
	c_graph_edge_kruskal( graph );
	printf( "\n" );
}