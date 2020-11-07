
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <queue>
using namespace std;

typedef struct node {
	int		data;
	struct node	*left;
	struct node	*right;
} node;
typedef struct node *bst;

bool search( bst tree, int key, bst f, bst *p );


bool insert( bst *tree, int key );


void pre_order( bst tree );


void in_order( bst tree );


void post_order( bst tree );


void level_order( bst tree );


int main( void )
{
	int	arr[9]	= { 8, 3, 10, 1, 6, 14, 4, 7, 13 };
	node	*tree	= NULL;
	for ( int idx = 0; idx < 9; idx++ ) {
	    insert( &tree, arr[idx] );
	}
	pre_order( tree );
	printf( "\n" );
	in_order( tree );
	printf( "\n" );
	post_order( tree );
	printf( "\n" );
	level_order( tree );
	printf( "\n" );
	return(0);
}


bool search( bst tree, int key, bst f, bst *p )
{
	if ( !tree )
	{
		*p = f;
		return(false);
	}
	if ( tree->data == key )
	{
		*p = tree;
		return(true);
	}else if ( tree->data < key )
	{
		return(search( tree->right, key, tree, p ) );
	}else{
		return(search( tree->left, key, tree, p ) );
	}
}


bool insert( bst *tree, int key )
{
	if ( !*tree )
	{
		(*tree)		= (node *) malloc( sizeof(node) );
		(*tree)->data	= key;
		(*tree)->left	= (*tree)->right = NULL;
		return(true);
	}else{
		node *p = NULL;
		if ( !search( *tree, key, NULL, &p ) )
		{
			node *n = (node *) malloc( sizeof(node) );
			n->data = key;
			n->left = n->right = NULL;
			if ( p->data < key )
			{
				p->right = n;
			}else{
				p->left = n;
			}
			return(true);
		}else{
			printf( "key exists\n" );
			return(false);
		}
	}
}


void pre_order( bst tree )
{
	if ( tree )
	{
		printf( "%d ", tree->data );
		pre_order( tree->left );
		pre_order( tree->right );
	}
}


void in_order( bst tree )
{
	if ( tree )
	{
		in_order( tree->left );
		printf( "%d ", tree->data );
		in_order( tree->right );
	}
}


void post_order( bst tree )
{
	if ( tree )
	{
		post_order( tree->left );
		post_order( tree->right );
		printf( "%d ", tree->data );
	}
}


void level_order( bst tree )
{
	queue <bst> Q;
	if ( tree )
	{
		Q.push( tree );
		while ( !Q.empty() )
		{
			bst tmp = Q.front();
			printf( "%d ", tmp->data );
			Q.pop();
			if ( tmp->left )
				Q.push( tmp->left );
			if ( tmp->right )
				Q.push( tmp->right );
		}
	}
}



