
#ifndef __COMMON__
#define __COMMON__
#define INF	65535
#define MAXSIZE 1000
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef void *c_data;

typedef struct c_node
{
	int		key;
	c_data		data;
	int		bf;
	struct c_node	*left;
	struct c_node	*right;
	struct c_node	*parent;
} c_node;

typedef int c_array[MAXSIZE][MAXSIZE];

typedef struct c_vertex
{
	char	name[MAXSIZE];
	double	lat;
	double	lng;
} c_vertex;

typedef struct c_astar
{
	int	weight;
	int	link;
} c_astar;

void c_array_swap( int *arr, int src, int dst );


int c_array_limit( int *arr, int len, int fmt );


void c_array_min_heap( int *arr, int len, int pos );


void c_array_max_heap( int *arr, int len, int pos );


int c_graph_distance( c_vertex *vertex, int begin, int pos, int end );


int c_degree_distance( double lat1, double lng1, double lat2, double lng2 );


#endif