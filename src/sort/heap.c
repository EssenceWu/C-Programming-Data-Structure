
#include "heap.h"

void c_array_heap( int *arr, int len )
{
	for ( int idx = len / 2 - 1; idx >= 0; idx-- )
		c_array_max_heap( arr, len, idx );
	for ( int idx = len - 1; idx >= 0; idx-- )
	{
		c_array_swap( arr, 0, idx );
		c_array_max_heap( arr, idx, 0 );
	}
}
