
#include "common.h"

void c_array_swap( int *arr, int src, int dst )
{
	int tmp = arr[src];
	arr[src]	= arr[dst];
	arr[dst]	= tmp;
}


int c_array_limit( int *arr, int len, int fmt )
{
	if (fmt) {
		for ( int idx = len / 2 - 1; idx >= 0; idx-- )
			c_array_max_heap( arr, len, idx );
	}else{
		for ( int idx = len / 2 - 1; idx >= 0; idx-- )
			c_array_min_heap( arr, len, idx );
	}
	return(arr[0]);
}


void c_array_min_heap( int *arr, int len, int pos )
{
	int tmp = arr[pos];
	for ( int idx = pos * 2 + 1; idx < len; idx = pos * 2 + 1 )
	{
		if ( (idx + 1) < len && arr[idx] > arr[idx + 1] )
			idx++;
		if ( arr[idx] >= tmp )
			break;
		arr[pos]	= arr[idx];
		pos		= idx;
	}
	arr[pos] = tmp;
}

void c_array_max_heap( int *arr, int len, int pos )
{
	int tmp = arr[pos];
	for ( int idx = pos * 2 + 1; idx < len; idx = pos * 2 + 1 )
	{
		if ( (idx + 1) < len && arr[idx] < arr[idx + 1] )
			idx++;
		if ( arr[idx] <= tmp )
			break;
		arr[pos]	= arr[idx];
		pos		= idx;
	}
	arr[pos] = tmp;
}


int c_graph_distance( c_vertex *vertex, int begin, int pos, int end )
{
	c_vertex a = vertex[begin], b = vertex[pos], c = vertex[end];
	return(c_degree_distance( a.lat, a.lng, b.lat, b.lng ) + c_degree_distance( b.lat, b.lng, c.lat, c.lng ) );
}


int c_degree_distance( double lat1, double lng1, double lat2, double lng2 )
{
	lat1 *= M_PI / 180.0, lng1 *= M_PI / 180.0, lat2 *= M_PI / 180.0, lng2 *= M_PI / 180.0;
	return(2 * asin( (sqrt( pow( sin( (lat1 - lat2) / 2 ), 2 ) + cos( lat1 ) * cos( lat2 ) * pow( sin( (lng1 - lng2) / 2 ), 2 ) ) ) ) * 6378.137);
}