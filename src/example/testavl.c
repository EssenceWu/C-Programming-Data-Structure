
#include "../tree/avl.h"

int main( void )
{
	c_node	*root	= NULL;
	int	arr[9]	= { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for ( int idx = 0; idx < 9; idx++ )
		c_avl_insert( &root, arr[idx], NULL );

	printf( "\nlevel order: \n" );
	c_btree_level( root );
	printf( "\ndepath: %d\n", c_btree_depth( root ) );

	printf( "\n" );
	return(0);
}