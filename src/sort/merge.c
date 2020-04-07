
#include "merge.h"

void c_array_merge( int *arr, int left, int right )
{
	if ( left >= right )
		return;
	int pivot = (left + right) / 2;
	c_array_merge( arr, left, pivot );
	c_array_merge( arr, pivot + 1, right );
	c_merge_adjust( arr, left, pivot, right );
}


void c_merge_adjust( int *arr, int left, int pivot, int right )
{
	int	idx	= left, jdx = pivot + 1, kdx = 0;
	int	*tmp	= (int *) malloc( (right - left + 1) * sizeof(int) );
	while ( idx <= pivot && jdx <= right )
	{
		if ( arr[idx] <= arr[jdx] )
		{
			tmp[kdx++] = arr[idx++];
		}else{
			tmp[kdx++] = arr[jdx++];
		}
	}
	while ( idx <= pivot )
	{
		tmp[kdx++] = arr[idx++];
	}
	while ( jdx <= right )
	{
		tmp[kdx++] = arr[jdx++];
	}
	for ( int idx = 0; idx < kdx; idx++ )
	{
		arr[left + idx] = tmp[idx];
	}
	free( tmp );
}