
#include "radix.h"

void c_array_radix( int *arr, int len )
{
	int max = c_array_limit( arr, len, 1 );
	for ( int idx = 1; max / idx > 0; idx *= 10 )
		c_radix_fixup( arr, len, idx );
}


void c_radix_fixup( int *arr, int len, int pivot )
{
	int	bucket[10]	= { 0 };
	int	*tmp		= (int *) malloc( len * sizeof(int) );
	for ( int idx = 0; idx < len; idx++ )
		bucket[arr[idx] / pivot % 10]++;
	for ( int idx = 1; idx < len; idx++ )
		bucket[idx] += bucket[idx - 1];
	for ( int idx = len - 1; idx >= 0; idx-- )
	{
		tmp[bucket[arr[idx] / pivot % 10] - 1] = arr[idx];
		bucket[arr[idx] / pivot % 10]--;
	}
	for ( int idx = 0; idx < len; idx++ )
		arr[idx] = tmp[idx];
	free( tmp );
}