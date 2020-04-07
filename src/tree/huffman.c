
#include "huffman.h"

c_node *c_huffman_create( char *ch, int *weight, int length )
{
	c_node	*btree	= NULL;
	c_stack *stack	= c_stack_create();
	for ( int idx = 0; idx < length; idx++ )
	{
		c_node *node = malloc( sizeof(c_node) );
		node->data	= &ch[idx];
		node->bf	= weight[idx];
		node->left	= NULL;
		node->right	= NULL;
		node->parent	= NULL;
		c_stack_push( stack, weight[idx], node );
	}
	while ( c_stack_length( stack ) )
	{
		c_node	*left	= c_stack_pop( stack, 0 );
		c_node	*right	= c_stack_pop( stack, 0 );
		if ( left && right )
		{
			c_node *node = malloc( sizeof(c_node) );
			node->data	= NULL;
			node->bf	= left->bf + right->bf;
			node->left	= left;
			node->right	= right;
			node->parent	= NULL;
			left->parent	= node;
			right->parent	= node;
			c_stack_push( stack, node->bf, node );
		}
		btree = left;
	}
	return(btree);
}