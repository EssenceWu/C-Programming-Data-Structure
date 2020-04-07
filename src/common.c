
#include "common.h"


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

