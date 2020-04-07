
#include "common.h"

typedef struct c_stack_node
{
	double	weight;
	c_data	data;
} c_stack_node;

typedef struct c_stack
{
	c_stack_node	queue[MAXSIZE];
	int		length;
} c_stack;

c_stack *c_stack_create( void );


int c_stack_length( c_stack *stack );


bool c_stack_push( c_stack *stack, double weight, c_data data );


c_data c_stack_pop( c_stack *stack, int fmt );


bool c_stack_close( c_stack *stack );


void c_stack_heap( c_stack *stack, int pos, int fmt );