
#include "radix.h"

void c_array_radix( int *arr, int len )
{
	int max = c_array_max( arr, len );
	for ( int idx = 1; max / idx > 0; idx *= 10 )
	{
		c_radix_adjust( arr, len, idx );
	}
}


void c_radix_adjust( int *arr, int len, int pivot )
{
	int	bucket[10]	= { 0 };
	int	*tmp		= (int *) malloc( len * sizeof(int) );
	for ( int idx = 0; idx < len; idx++ )
	{
		bucket[arr[idx] / pivot % 10]++;
	}
	for ( int idx = 1; idx < len; idx++ )
	{
		bucket[idx] += bucket[idx - 1];
	}
	for ( int idx = len - 1; idx >= 0; idx-- )
	{
		tmp[bucket[arr[idx] / pivot % 10] - 1] = arr[idx];
		bucket[arr[idx] / pivot % 10]--;
	}
	for ( int idx = 0; idx < len; idx++ )
	{
		arr[idx] = tmp[idx];
	}
	free( tmp );
}