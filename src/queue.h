
#include "common.h"

typedef struct c_queue
{
	int		length;
	struct c_node	*left;
	struct c_node	*right;
} c_queue;

c_queue *c_queue_create( void );


int c_queue_length( c_queue *queue );


bool c_queue_lpush( c_queue *queue, c_data );


bool c_queue_rpush( c_queue *queue, c_data );


c_data c_queue_lpop( c_queue *queue );


c_data c_queue_rpop( c_queue *queue );


bool c_queue_close( c_queue *queue );