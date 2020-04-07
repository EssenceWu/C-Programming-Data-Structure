
#include "avl.h"

bool c_avl_insert( c_node **pos, int key, c_data data )
{
	if ( !(*pos) )
	{
		(*pos) = (c_node *) malloc( sizeof(c_node) );
		if ( !(*pos) )
			return(false);
		(*pos)->key	= key;
		(*pos)->data	= data;
		(*pos)->bf	= 0;
		(*pos)->left	= NULL;
		(*pos)->right	= NULL;
		(*pos)->parent	= NULL;
		return(true);
	}
	if ( key < (*pos)->key )
	{
		c_avl_insert( &(*pos)->left, key, data );
		switch ( (*pos)->bf )
		{
		case -1:
			c_avl_left_balance( pos );
			break;
		case 0:
			(*pos)->bf = -1;
			break;
		case 1:
			(*pos)->bf = 0;
			break;
		}
	}
	if ( key > (*pos)->key )
	{
		c_avl_insert( &(*pos)->right, key, data );
		switch ( (*pos)->bf )
		{
		case -1:
			(*pos)->bf = 0;
			break;
		case 0:
			(*pos)->bf = 1;
			break;
		case 1:
			c_avl_right_balance( pos );
			break;
		}
	}
	(*pos)->data = data;
	return(true);
}


void c_avl_left_balance( c_node **pos )
{
	c_node	*left	= (*pos)->left;
	c_node	*right	= left->right;
	switch ( left->bf )
	{
	case -1:
		left->bf = 0, (*pos)->bf = 0;
		c_avl_right_rotate( pos );
		break;
	case 1:
		switch ( right->bf )
		{
		case -1:
			left->bf = 0, (*pos)->bf = 1;
			break;
		case 0:
			left->bf = 0, (*pos)->bf = 0;
			break;
		case 1:
			left->bf = -1, (*pos)->bf = 0;
			break;
		}
		right->bf = 0;
		c_avl_left_rotate( &left );
		c_avl_right_rotate( pos );
	}
}


void c_avl_right_balance( c_node **pos )
{
	c_node	*right	= (*pos)->right;
	c_node	*left	= right->left;
	switch ( right->bf )
	{
	case 1:
		right->bf = 0, (*pos)->bf = 0;
		c_avl_left_rotate( pos );
		break;
	case -1:
		switch ( left->bf )
		{
		case -1:
			right->bf = 1, (*pos)->bf = 0;
			break;
		case 0:
			right->bf = 0, (*pos)->bf = 0;
			break;
		case 1:
			right->bf = 0, (*pos)->bf = -1;
			break;
		}
		left->bf = 0;
		c_avl_right_rotate( &right );
		c_avl_left_rotate( pos );
	}
}


void c_avl_left_rotate( c_node **pos )
{
	c_node *hook = (*pos)->right;
	(*pos)->right	= hook->left;
	hook->left	= (*pos);
	(*pos)		= hook;
}


void c_avl_right_rotate( c_node **pos )
{
	c_node *hook = (*pos)->left;
	(*pos)->left	= hook->right;
	hook->right	= (*pos);
	(*pos)		= hook;
}