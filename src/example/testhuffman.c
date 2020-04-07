
#include "../tree/huffman.h"

void c_huffman_print( c_node *btree );


int main( void )
{
	char	ch[5]		= { 'a', 'b', 'c', 'd', 'e' };
	int	weight[5]	= { 7, 9, 5, 6, 12 };
	c_node	*btree		= c_huffman_create( ch, weight, 5 );
	printf( "\nhuffman code: " );
	c_huffman_print( btree );
	printf( "\n\n" );
	return(0);
}


void c_huffman_print( c_node *btree )
{
	if ( btree )
	{
		if ( btree->data )
		{
			int	idx = 0;
			int	code[MAXSIZE];
			c_node	*tmp = btree;
			while ( tmp->parent )
			{
				if ( tmp == tmp->parent->left )
					code[idx++] = 0;
				if ( tmp == tmp->parent->right )
					code[idx++] = 1;
				tmp = tmp->parent;
			}
			printf( "%c:", (*(char *) btree->data) );
			for ( int jdx = idx - 1; jdx >= 0; jdx-- )
				printf( "%d", code[jdx] );
			printf( " " );
		}
		c_huffman_print( btree->left );
		c_huffman_print( btree->right );
	}
}