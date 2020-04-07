
#include "../graph/list.h"

void c_graph_vertex_init( c_graph_list *graph, char *filename );


void c_graph_edge_init( c_graph_list *graph, char *filename );


void c_graph_list_sort_example( c_graph_list *graph );


int main( int argc, char *argv[] )
{
	c_graph_list *graph = (c_graph_list *) malloc( sizeof(c_graph_list) );
	graph->vertex_num = graph->edge_num = 0;

	c_graph_vertex_init( graph, argv[1] );
	c_graph_edge_init( graph, argv[2] );

	c_graph_list_sort_example( graph );

	free( graph );
	return(0);
}


void c_graph_vertex_init( c_graph_list *graph, char *filename )
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
		fscanf( fp, "%s%lf%lf", graph->vertex[idx].station.name, &graph->vertex[idx].station.lat, &graph->vertex[idx].station.lng );
		graph->vertex[idx].in_degree = 0;
		graph->vertex[idx].next = NULL;
		idx++;
	}
	graph->vertex_num = idx;
	fclose( fp );
}


void c_graph_edge_init( c_graph_list *graph, char *filename )
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
		c_edge *edge = (c_edge *) malloc( sizeof(c_edge) );
		fscanf( fp, "%d%d%d", &begin, &end, &weight );
		edge->adjvex			= end;
		edge->weight			= weight;
		edge->right			= graph->vertex[begin].next;
		graph->vertex[begin].next	= edge;
		graph->vertex[end].in_degree++;
		idx++;
	}
	graph->edge_num = idx;
	fclose( fp );
}


void c_graph_list_sort_example( c_graph_list *graph )
{
	printf( "\nSort result: \n\n" );
	printf( "\n\nIt's aov? %s\n\n", c_graph_list_sort( graph ) ? "yes" : "no" );
}