
#include "rb.h"

bool c_rb_insert( c_node **root, c_node **pos, c_node *parent, int key, c_data data )
{
	if ( !(*pos) )
	{
		(*pos) = (c_node *) malloc( sizeof(c_node) );
		if ( !(*pos) )
			return(false);
		(*pos)->key	= key;
		(*pos)->data	= data;
		(*pos)->bf	= 1;
		(*pos)->left	= NULL;
		(*pos)->right	= NULL;
		(*pos)->parent	= parent;
		return(true);
	}
	if ( key < (*pos)->key )
	{
		c_rb_insert( root, &(*pos)->left, (*pos), key, data );
		c_rb_insert_fixup( root, (*pos)->left, (*pos) );
		return(true);
	}
	if ( key > (*pos)->key )
	{
		c_rb_insert( root, &(*pos)->right, (*pos), key, data );
		c_rb_insert_fixup( root, (*pos)->right, (*pos) );
		return(true);
	}
	(*pos)->data = data;
	return(true);
}


bool c_rb_delete( c_node **root, int key )
{
	c_node *pos = c_btree_search( *root, key );
	if ( !pos )
		return(false);
	int	bf	= pos->bf;
	c_node	*child	= NULL;
	c_node	*parent = NULL;
	if ( !pos->left )
	{
		child	= pos->right;
		parent	= pos->parent;
		c_rb_transplant( root, pos, child );
		goto fixup;
	}
	if ( !pos->right )
	{
		child	= pos->left;
		parent	= pos->parent;
		c_rb_transplant( root, pos, child );
		goto fixup;
	}
	if ( pos->left && pos->right )
	{
		c_node *hook = c_rb_left_minimum( pos->right );
		bf			= hook->bf;
		child			= hook->right;
		parent			= hook->parent;
		hook->bf		= pos->bf;
		hook->left		= pos->left;
		hook->left->parent	= hook;
		if ( parent == pos )
		{
			parent = hook;
		}else{
			c_rb_transplant( root, hook, child );
			hook->right		= pos->right;
			hook->right->parent	= hook;
		}
		c_rb_transplant( root, pos, hook );
		goto fixup;
	}
fixup:
	if ( !bf )
		c_rb_delete_fixup( root, child, parent );
	free( pos );
	return(true);
}


void c_rb_insert_fixup( c_node **root, c_node *pos, c_node *parent )
{
	(*root)->bf = 0;
	if ( parent && parent->bf )
	{
		c_node *grand = parent->parent;
		if ( parent == grand->left )
		{
			c_node *uncle = grand->right;
			/* 情况1：z的叔节点y是红色的。 */
			if ( uncle && uncle->bf )
			{
				parent->bf = 0, uncle->bf = 0, grand->bf = 1;
				c_rb_insert_fixup( root, grand, grand->parent );
				return;
			}
			/* 情况2：z的叔节点y是黑色的且z是一个左孩子。 */
			if ( pos == parent->left )
			{
				parent->bf = 0, grand->bf = 1;
				c_rb_right_rotate( root, grand );
				return;
			}
			/* 情况3：z的叔节点y是黑色的且z是一个右孩子。 */
			if ( pos == parent->right )
			{
				c_rb_left_rotate( root, parent );
				c_rb_insert_fixup( root, parent, grand );
				return;
			}
		}
		if ( parent == grand->right )
		{
			c_node *uncle = grand->left;
			/* 情况1：z的叔节点y是红色的。 */
			if ( uncle && uncle->bf )
			{
				parent->bf = 0, uncle->bf = 0, grand->bf = 1;
				c_rb_insert_fixup( root, grand, grand->parent );
				return;
			}
			/* 情况2：z的叔节点y是黑色的且z是一个左孩子。 */
			if ( pos == parent->left )
			{
				c_rb_right_rotate( root, parent );
				c_rb_insert_fixup( root, parent, grand );
				return;
			}
			/* 情况3：z的叔节点y是黑色的且z是一个右孩子。 */
			if ( pos == parent->right )
			{
				parent->bf = 0, grand->bf = 1;
				c_rb_left_rotate( root, grand );
				return;
			}
		}
	}
	(*root)->bf = 0;
}


void c_rb_delete_fixup( c_node **root, c_node *pos, c_node *parent )
{
	if ( (!pos || !pos->bf) && pos != *root )
	{
		if ( pos == parent->left )
		{
			c_node *brother = parent->right;
			/* 情况1：x的兄弟节点w是红色的 */
			if ( brother->bf )
			{
				brother->bf = 0, parent->bf = 1;
				c_rb_left_rotate( root, parent );
				c_rb_delete_fixup( root, pos, parent );
				return;
			}
			/* 情况2：x的兄弟节点w是黑色的，而且w的两个子节点都是黑色的。 */
			if ( (!brother->left || !brother->left->bf) && (!brother->right || !brother->right->bf) )
			{
				brother->bf = 1;
				c_rb_delete_fixup( root, parent, parent->parent );
				return;
			}
			/* 情况3：x的兄弟节点w是黑色的，且w的右孩子是黑色的。 */
			if ( !brother->right || !brother->right->bf )
			{
				brother->left->bf = 0, brother->bf = 1;
				c_rb_right_rotate( root, brother );
				c_rb_delete_fixup( root, pos, parent );
				return;
			}
			/* 情况4：x的兄弟节点w是黑色的，且w的右孩子是红色的。 */
			if ( !brother->right || brother->right->bf )
			{
				brother->right->bf = 0, brother->bf = parent->bf, parent->bf = 0;
				c_rb_left_rotate( root, parent );
				return;
			}
		}
		if ( pos == parent->right )
		{
			c_node *brother = parent->left;
			/* 情况1：x的兄弟节点w是红色的 */
			if ( brother->bf )
			{
				brother->bf = 0, parent->bf = 1;
				c_rb_right_rotate( root, parent );
				c_rb_delete_fixup( root, pos, parent );
				return;
			}
			/* 情况2：x的兄弟节点w是黑色的，而且w的两个子节点都是黑色的。 */
			if ( (!brother->left || !brother->left->bf) && (!brother->right || !brother->right->bf) )
			{
				brother->bf = 1;
				c_rb_delete_fixup( root, parent, parent->parent );
				return;
			}
			/* 情况3：x的兄弟节点w是黑色的，且w的左孩子是黑色的。 */
			if ( !brother->left || !brother->left->bf )
			{
				brother->right->bf = 0, brother->bf = 1;
				c_rb_left_rotate( root, brother );
				c_rb_delete_fixup( root, pos, parent );
				return;
			}
			/* 情况4：x的兄弟节点w是黑色的，且w的左孩子是红色的。 */
			if ( !brother->left || brother->left->bf )
			{
				brother->left->bf = 0, brother->bf = parent->bf, parent->bf = 0;
				c_rb_right_rotate( root, parent );
				return;
			}
		}
	}
	if ( pos )
		pos->bf = 0;
}


c_node *c_rb_left_minimum( c_node *pos )
{
	while ( pos->left )
		pos = pos->left;
	return(pos);
}


c_node *c_rb_right_minimum( c_node *pos )
{
	while ( pos->right )
		pos = pos->right;
	return(pos);
}


void c_rb_left_rotate( c_node **root, c_node *pos )
{
	c_node *hook = pos->right;
	pos->right = hook->left;
	if ( pos->right )
		pos->right->parent = pos;
	c_rb_transplant( root, pos, hook );
	hook->left		= pos;
	hook->left->parent	= hook;
}


void c_rb_right_rotate( c_node **root, c_node *pos )
{
	c_node *hook = pos->left;
	pos->left = hook->right;
	if ( pos->left )
		pos->left->parent = pos;
	c_rb_transplant( root, pos, hook );
	hook->right		= pos;
	hook->right->parent	= hook;
}


void c_rb_transplant( c_node **root, c_node *src, c_node *dst )
{
	if ( src->parent )
	{
		if ( src == src->parent->left )
			src->parent->left = dst;
		if ( src == src->parent->right )
			src->parent->right = dst;
	}else{
		*root = dst;
	}
	if ( dst )
		dst->parent = src->parent;
}