
#include "select.h"

void c_array_select( int *arr, int len )
{
	for ( int idx = 0; idx < len; idx++ )
	{
		int min = idx;
		for ( int jdx = idx + 1; jdx < len; jdx++ )
		{
			if ( arr[jdx] < arr[min] )
				min = jdx;
		}
		if ( idx != min )
			c_array_swap( arr, idx, min );
	}
}