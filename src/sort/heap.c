
#include "heap.h"

void c_array_heap( int *arr, int len )
{
	for ( int idx = len / 2 - 1; idx >= 0; idx-- )
	{
		c_heap_adjust( arr, len, idx );
	}
	for ( int idx = len - 1; idx >= 0; idx-- )
	{
		c_array_swap( arr, 0, idx );
		c_heap_adjust( arr, idx, 0 );
	}
}


void c_heap_adjust( int *arr, int len, int pivot )
{
	for ( int idx = pivot * 2 + 1; idx < len; idx = pivot * 2 + 1 )
	{
		if ( idx + 1 < len && arr[idx] < arr[idx + 1] )
			idx++;
		if ( arr[idx] > arr[pivot] )
		{
			c_array_swap( arr, idx, pivot );
			pivot = idx;
		}else{
			break;
		}
	}
}
