
#include "heap.h"

void c_array_heap( int *arr, int len )
{
	for ( int idx = len / 2 - 1; idx >= 0; idx-- )
		c_array_fixup( arr, len, idx, 1 );
	for ( int idx = len - 1; idx >= 0; idx-- )
	{
		c_array_swap( arr, 0, idx );
		c_array_fixup( arr, idx, 0, 1 );
	}
}
