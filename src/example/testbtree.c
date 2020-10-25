
#include "../common.h"

void print( c_node *btree );


int main( void )
{
	int	arr[10] = { 3, 2, 1, 5, 4, 6, 9, 7, 8, 0 };
	c_node	*btree	= (c_node *) malloc( 10 * sizeof(c_node) );

	for ( int idx = 0; idx <= 9; idx++ )
	{
		btree[idx].data = &arr[idx];
		btree[idx].left = btree[idx].right = NULL;
	}

	for ( int idx = 0; idx <= 10 / 2 - 1; idx++ )
	{
		if ( 2 * idx + 1 <= 10 - 1 )
		{
			btree[idx].left = &btree[2 * idx + 1];
		}
		if ( 2 * idx + 2 <= 10 - 1 )
		{
			btree[idx].right = &btree[2 * idx + 2];
		}
	}

	print( btree );
	printf( "\n" );
    
	return(0);
}


void print( c_node *btree )
{
	if ( btree )
	{
		printf( "%d ", *(int *) btree->data );
		if ( btree->left )
			print( btree->left );
		if ( btree->right )
			print( btree->right );
	}
}