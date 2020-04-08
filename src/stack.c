
#include "stack.h"

c_stack *c_stack_create( void )
{
	c_stack *stack = malloc( sizeof(c_stack) );
	if ( !stack )
		return(NULL);
	stack->length = 0;
	return(stack);
}


int c_stack_length( c_stack *stack )
{
	return(stack->length);
}


bool c_stack_push( c_stack *stack, double weight, c_data data )
{
	stack->queue[stack->length].weight	= weight;
	stack->queue[stack->length++].data	= data;
	return(true);
}


c_data c_stack_pop( c_stack *stack, int fmt )
{
	if ( !stack->length )
		return(NULL);
	for ( int idx = stack->length / 2 - 1; idx >= 0; idx-- )
		c_stack_fixup( stack, idx, fmt );
	c_data data = stack->queue[0].data;
	stack->queue[0] = stack->queue[--stack->length];
	return(data);
}


bool c_stack_close( c_stack *stack )
{
	free( stack );
	stack = NULL;
	return(true);
}


void c_stack_fixup( c_stack *stack, int pos, int fmt )
{
	c_stack_node tmp = stack->queue[pos];
	for ( int idx = pos * 2 + 1; idx < stack->length; idx = pos * 2 + 1 )
	{
		if ( fmt )
		{
			if ( (idx + 1) < stack->length && stack->queue[idx].weight < stack->queue[idx + 1].weight )
				idx++;
			if ( stack->queue[idx].weight <= tmp.weight )
				break;
		}else{
			if ( (idx + 1) < stack->length && stack->queue[idx].weight > stack->queue[idx + 1].weight )
				idx++;
			if ( stack->queue[idx].weight >= tmp.weight )
				break;
		}
		stack->queue[pos]	= stack->queue[idx];
		pos			= idx;
	}
	stack->queue[pos] = tmp;
}