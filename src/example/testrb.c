
#include "../tree/rb.h"

int main( void )
{
	c_node	*root	= NULL;
	int	arr[10] = { 4, 2, 1, 3, 9, 5, 6, 8, 7, 0 };
	for ( int idx = 0; idx < 10; idx++ )
		c_rb_insert( &root, &root, NULL, arr[idx], NULL );

	printf( "\nlevel order: \n" );
	c_btree_level( root );
	printf( "\ndepath: %d\n", c_btree_depth( root ) );

	c_rb_delete( &root, 4 );
	printf( "\nlevel order: \n" );
	c_btree_level( root );
	printf( "\ndepath: %d\n", c_btree_depth( root ) );

	c_rb_delete( &root, 8 );
	printf( "\nlevel order: \n" );
	c_btree_level( root );
	printf( "\ndepath: %d\n", c_btree_depth( root ) );

	c_rb_delete( &root, 2 );
	printf( "\nlevel order: \n" );
	c_btree_level( root );
	printf( "\ndepath: %d\n", c_btree_depth( root ) );

	c_rb_delete( &root, 9 );
	printf( "\nlevel order: \n" );
	c_btree_level( root );
	printf( "\ndepath: %d\n", c_btree_depth( root ) );

	printf( "\n" );
	return(0);
}