
#include "count.h"

void c_array_count( int *arr, int len )
{
	int	max	= c_array_max( arr, len );
	int	*tmp	= (int *) malloc( (max + 1) * sizeof(int) );
	for ( int idx = 0; idx < len; idx++ )
	{
		tmp[arr[idx]]++;
	}
	for ( int idx = 0; idx <= max; idx++ )
	{
		for ( int jdx = 0; jdx < tmp[idx]; jdx++ )
		{
			arr[idx + jdx] = idx;
		}
	}
	free( tmp );
}