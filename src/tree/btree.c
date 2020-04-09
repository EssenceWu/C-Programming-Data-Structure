
#include "btree.h"


void c_btree_pre( c_node *pos )
{
	if ( !pos )
		return;
	printf( "->%d(%d)", pos->key, pos->bf );
	c_btree_pre( pos->left );
	c_btree_pre( pos->right );
}


void c_btree_in( c_node *pos )
{
	if ( !pos )
		return;
	c_btree_pre( pos->left );
	printf( "->%d(%d)", pos->key, pos->bf );
	c_btree_pre( pos->right );
}


void c_btree_post( c_node *pos )
{
	if ( !pos )
		return;
	c_btree_pre( pos->left );
	c_btree_pre( pos->right );
	printf( "->%d(%d)", pos->key, pos->bf );
}


void c_btree_level( c_node *pos )
{
	if ( !pos )
		return;
	c_stack *stack = c_stack_create();
	c_stack_push( stack, 0, pos );
	while ( c_stack_length( stack ) )
	{
		pos = c_stack_pop( stack, 0 );
		printf( "->%d(%d)", pos->key, pos->bf );
		if ( pos->left )
			c_stack_push( stack, 0, pos->left );
		if ( pos->right )
			c_stack_push( stack, 0, pos->right );
	}
}


int c_btree_depth( c_node *pos )
{
	if ( !pos )
		return(0);
	int	a	= c_btree_depth( pos->left );
	int	b	= c_btree_depth( pos->right );
	return(a > b ? a + 1 : b + 1);
}


c_node *c_btree_search( c_node *pos, int key )
{
	if ( !pos )
		return(NULL);
	if ( key < pos->key )
		return(c_btree_search( pos->left, key ) );
	if ( key > pos->key )
		return(c_btree_search( pos->right, key ) );
	return(pos);
}


void c_btree_delete( c_node *pos )
{
	if ( !pos )
		return;
	if ( pos->left )
		c_btree_delete( pos->left );
	if ( pos->right )
		c_btree_delete( pos->right );
	free( pos );
}