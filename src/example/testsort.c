
#include "../sort/exchange.h"
#include "../sort/insert.h"
#include "../sort/select.h"
#include "../sort/heap.h"
#include "../sort/merge.h"
#include "../sort/radix.h"
#include "../sort/count.h"

void c_array_print( char *name, int *arr, int len );


int main( void )
{
	int arr[10] = { 4, 2, 1, 3, 9, 5, 6, 8, 7, 0 };
	c_array_bubble( arr, 10 );
	c_array_print( "bubble", arr, 10 );

	int arr2[10] = { 4, 2, 1, 3, 9, 5, 6, 8, 7, 0 };
	c_array_quick( arr2, 0, 9 );
	c_array_print( "quick", arr2, 10 );

	int arr3[10] = { 4, 2, 1, 3, 9, 5, 6, 8, 7, 0 };
	c_array_insert( arr3, 10, 1 );
	c_array_print( "insert", arr3, 10 );

	int arr4[10] = { 4, 2, 1, 3, 9, 5, 6, 8, 7, 0 };
	c_array_shell( arr4, 10 );
	c_array_print( "shell", arr4, 10 );

	int arr5[10] = { 4, 2, 1, 3, 9, 5, 6, 8, 7, 0 };
	c_array_select( arr5, 10 );
	c_array_print( "select", arr5, 10 );

	int arr6[10] = { 4, 2, 1, 3, 9, 5, 6, 8, 7, 0 };
	c_array_heap( arr6, 10 );
	c_array_print( "heap", arr6, 10 );

	int arr7[10] = { 4, 2, 1, 3, 9, 5, 6, 8, 7, 0 };
	c_array_merge( arr7, 0, 9 );
	c_array_print( "merge", arr7, 10 );

	int arr8[10] = { 4, 2, 1, 3, 9, 5, 6, 8, 7, 0 };
	c_array_radix( arr8, 10 );
	c_array_print( "radix", arr8, 10 );

	int arr9[10] = { 4, 2, 1, 3, 9, 5, 6, 8, 7, 0 };
	c_array_count( arr9, 10 );
	c_array_print( "count", arr9, 10 );

	return(0);
}


void c_array_print( char *name, int *arr, int len )
{
	printf( "%s sort: ", name );
	for ( int idx = 0; idx < len; idx++ )
	{
		printf( "%d ", arr[idx] );
	}
	printf( "\n" );
}