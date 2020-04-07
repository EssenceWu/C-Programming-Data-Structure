
#include "queue.h"

c_queue *c_queue_create( void )
{
	c_queue *queue = (c_queue *) malloc( sizeof(c_queue) );
	if ( !queue )
		return(NULL);
	queue->length	= 0;
	queue->left	= queue->right = NULL;
	return(queue);
}


int c_queue_length( c_queue *queue )
{
	return(queue->length);
}


bool c_queue_lpush( c_queue *queue, c_data data )
{
	c_node *node = (c_node *) malloc( sizeof(c_node) );
	if ( !queue || !node )
		return(false);
	node->data = data;
	queue->length++;
	if ( queue->left == NULL && queue->right == NULL )
	{
		node->left	= node->right = node;
		queue->left	= queue->right = node;
	}else{
		node->left		= queue->right;
		node->right		= queue->left;
		queue->left->left	= node;
		queue->right->right	= node;
		queue->left		= node;
	}
	return(true);
}


bool c_queue_rpush( c_queue *queue, c_data data )
{
	c_node *node = (c_node *) malloc( sizeof(c_node) );
	if ( !queue || !node )
		return(false);
	node->data = data;
	queue->length++;
	if ( queue->left == NULL && queue->right == NULL )
	{
		node->left	= node->right = node;
		queue->left	= queue->right = node;
	}else{
		node->left		= queue->right;
		node->right		= queue->left;
		queue->left->left	= node;
		queue->right->right	= node;
		queue->right		= node;
	}
	return(true);
}


c_data c_queue_lpop( c_queue *queue )
{
	if ( !queue || !queue->left )
		return(false);
	c_node	*node	= queue->left;
	c_data	data	= node->data;
	if ( queue->left == queue->right )
	{
		queue->length	= 0;
		queue->left	= queue->right = NULL;
	}else{
		queue->length--;
		node->right->left	= node->left;
		node->left->right	= node->right;
		queue->left		= node->right;
	}
	free( node );
	return(data);
}


c_data c_queue_rpop( c_queue *queue )
{
	if ( !queue || !queue->right )
		return(false);
	c_node	*node	= queue->right;
	c_data	data	= node->data;
	if ( queue->left == queue->right )
	{
		queue->length	= 0;
		queue->left	= queue->right = NULL;
	}else{
		queue->length--;
		node->right->left	= node->left;
		node->left->right	= node->right;
		queue->right		= node->left;
	}
	free( node );
	return(data);
}


bool c_queue_close( c_queue *queue )
{
	while ( c_queue_length( queue ) )
	{
		c_queue_lpop( queue );
	}
	free( queue );
	queue = NULL;
	return(true);
}