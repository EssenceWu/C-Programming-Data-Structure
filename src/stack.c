
#include "stack.h"

c_stack *c_stack_create( void )
{
	c_stack *stack = malloc( sizeof(c_stack) );
	if ( !stack )
		return(NULL);
	stack->begin = stack->end = 0;
	return(stack);
}


int c_stack_length( c_stack *stack )
{
	return(stack->end - stack->begin);
}


bool c_stack_push( c_stack *stack, double bf, c_data data )
{
	stack->queue[stack->end].bf	= bf;
	stack->queue[stack->end++].data = data;
	return(true);
}


c_data c_stack_pop( c_stack *stack, int fmt )
{
	int length = c_stack_length( stack );
	if ( !length )
	{
		stack->begin = stack->end = 0;
		return(NULL);
	}
	if ( fmt )
	{
		for ( int idx = length / 2 - 1; idx >= 0; idx-- )
			c_stack_max_heap( stack, idx );
	}else{
		for ( int idx = length / 2 - 1; idx >= 0; idx-- )
			c_stack_min_heap( stack, idx );
	}
	return(stack->queue[stack->begin++].data);
}


bool c_stack_close( c_stack *stack )
{
	free( stack );
	stack = NULL;
	return(true);
}


void c_stack_min_heap( c_stack *stack, int pos )
{
	int	length	= c_stack_length( stack );
	c_node	tmp	= stack->queue[stack->begin + pos];
	for ( int idx = pos * 2 + 1; idx < length; idx = pos * 2 + 1 )
	{
		if ( (idx + 1) < length && stack->queue[stack->begin + idx].bf > stack->queue[stack->begin + idx + 1].bf )
			idx++;
		if ( stack->queue[stack->begin + idx].bf >= tmp.bf )
			break;
		stack->queue[stack->begin + pos]	= stack->queue[stack->begin + idx];
		pos					= idx;
	}
	stack->queue[stack->begin + pos] = tmp;
}


void c_stack_max_heap( c_stack *stack, int pos )
{
	int	length	= c_stack_length( stack );
	c_node	tmp	= stack->queue[stack->begin + pos];
	for ( int idx = pos * 2 + 1; idx < length; idx = pos * 2 + 1 )
	{
		if ( (idx + 1) < length && stack->queue[stack->begin + idx].bf < stack->queue[stack->begin + idx + 1].bf )
			idx++;
		if ( stack->queue[stack->begin + idx].bf <= tmp.bf )
			break;
		stack->queue[stack->begin + pos]	= stack->queue[stack->begin + idx];
		pos					= idx;
	}
	stack->queue[stack->begin + pos] = tmp;
}