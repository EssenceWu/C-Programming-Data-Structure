
#include "merge.h"

void c_array_merge( int *arr, int left, int right )
{
	if ( left >= right )
		return;
	int pos = (left + right) / 2;
	c_array_merge( arr, left, pos );
	c_array_merge( arr, pos + 1, right );
	c_merge_fixup( arr, left, pos, right );
}


void c_merge_fixup( int *arr, int left, int pos, int right )
{
	int	idx	= left, jdx = pos + 1, kdx = 0;
	int	*tmp	= (int *) malloc( (right - left + 1) * sizeof(int) );
	while ( idx <= pos && jdx <= right )
	{
		if ( arr[idx] <= arr[jdx] )
			tmp[kdx++] = arr[idx++];
		else
			tmp[kdx++] = arr[jdx++];
	}
	while ( idx <= pos )
		tmp[kdx++] = arr[idx++];
	while ( jdx <= right )
		tmp[kdx++] = arr[jdx++];
	for ( int idx = 0; idx < kdx; idx++ )
		arr[left + idx] = tmp[idx];
	free( tmp );
}