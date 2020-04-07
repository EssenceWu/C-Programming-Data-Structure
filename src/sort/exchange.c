
#include "exchange.h"

void c_array_bubble( int *arr, int len )
{
	bool status = true;
	for ( int idx = 0; idx < len - 1 && status; idx++ )
	{
		status = false;
		for ( int jdx = 0; jdx < len - idx - 1; jdx++ )
		{
			status = true;
			if ( arr[jdx] > arr[jdx + 1] )
			{
				c_array_swap( arr, jdx, jdx + 1 );
			}
		}
	}
}


void c_array_quick( int *arr, int left, int right )
{
	if ( left >= right )
		return;
	int idx = left, jdx = right, pivot = arr[left];
	while ( idx < jdx )
	{
		while ( idx < jdx && arr[jdx] >= pivot )
			jdx--;
		arr[idx] = arr[jdx];
		while ( idx < jdx && arr[idx] <= pivot )
			idx++;
		arr[jdx] = arr[idx];
	}
	arr[idx] = pivot;
	c_array_quick( arr, left, idx - 1 );
	c_array_quick( arr, idx + 1, right );
}