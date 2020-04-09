
#include "../stack.h"

int main( void )
{
	int	arr[10] = { 4, 2, 1, 3, 9, 5, 6, 8, 7, 0 };
	c_stack *stack	= c_stack_create();

	printf( "\nfrom small to big: " );
	for ( int idx = 0; idx < 10; idx++ )
		c_stack_push( stack, 0, &arr[idx] );

	while ( c_stack_length( stack ) > 2 )
		printf( "%d ", *( (int *) c_stack_pop( stack, 0 ) ) );

	printf( "\nfrom big to small: " );
	for ( int idx = 0; idx < 10; idx++ )
		c_stack_push( stack, 0, &arr[idx] );

	while ( c_stack_length( stack ) )
		printf( "%d ", *( (int *) c_stack_pop( stack, 1 ) ) );

	printf( "\n\n" );

	c_stack_close( stack );

	return(0);
}