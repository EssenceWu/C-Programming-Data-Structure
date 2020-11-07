
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 100
typedef struct c_stack {
	int	arr[MAXSIZE];
	int	top;
} c_stack;

int check( char arr[], int length );


c_stack *init( void );


void push( c_stack *stack, int data );


int pop( c_stack *stack );


int main( void )
{
	char arr[6] = { 'I', 'O', 'O', 'O', 'I', 'I' };
	printf( "序列是否合法: %d", check( arr, 6 ) );
	c_stack *stack = init();
	for ( int idx = 0; idx < 6; idx++ )
	{
		if ( arr[idx] == 'I' )
		{
			push( stack, idx );
		}else{
			pop( stack );
		}
	}
	printf( "\n" );
	return(0);
}


int check( char arr[], int length )
{
	int num = 0;
	for ( int idx = 0; idx < length; idx++ )
	{
		arr[idx] == 'I' ? num++ : num--;
		if ( num < 0 )
			return(0);
	}
	return(1);
}


c_stack *init( void )
{
	c_stack *stack = (c_stack *) malloc( sizeof(c_stack) );
	stack->top = -1;
	return(stack);
}


bool empty( c_stack *stack )
{
	return(stack->top == -1);
}


bool full( c_stack *stack )
{
	return(stack->top == MAXSIZE - 1);
}


void push( c_stack *stack, int data )
{
	if ( full( stack ) )
	{
		printf( "\nstack overflow\n" );
		exit( 0 );
	}else{
		stack->arr[++stack->top] = data;
	}
}


int pop( c_stack *stack )
{
	if ( empty( stack ) )
	{
		printf( "\nstack underflow\n" );
		exit( 0 );
	}else{
		return(stack->arr[stack->top--]);
	}
}

