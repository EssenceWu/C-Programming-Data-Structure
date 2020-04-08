
#include "insert.h"

void c_array_insert( int *arr, int len, int gap )
{
	for ( int idx = gap; idx < len; idx++ )
	{
		int jdx = idx - gap, tmp = arr[idx];
		while ( jdx >= 0 && arr[jdx] > tmp )
		{
			arr[jdx + gap]	= arr[jdx];
			jdx		-= gap;
		}
		arr[jdx + gap] = tmp;
	}
}


void c_array_shell( int *arr, int len )
{
	int gap = c_array_gap( len );
	while ( gap > 0 )
	{
		c_array_insert( arr, len, gap );
		gap = gap / 3;
	}
}


int c_array_gap( int len )
{
	int gap = 1;
	while ( gap < len / 3 )
	{
		gap = gap * 3 + 1;
	}
	return(gap);
}