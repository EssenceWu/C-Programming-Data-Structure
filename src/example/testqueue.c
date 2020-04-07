
#include "../queue.c"

int main( void )
{
	int array[10] = { 100, 200, 300, 400, 500, 600, 700, 800, 900 };

	c_queue *queue = c_queue_create();

	printf( "lpush lpop: " );
	c_queue_lpush( queue, &array[0] );
	c_queue_lpush( queue, &array[1] );
	c_queue_lpush( queue, &array[2] );
	c_queue_lpush( queue, &array[3] );
	c_queue_lpush( queue, &array[4] );
	c_queue_lpush( queue, &array[5] );
	c_queue_lpush( queue, &array[6] );
	c_queue_lpush( queue, &array[7] );
	c_queue_lpush( queue, &array[8] );
	while ( c_queue_length( queue ) )
	{
		printf( "%d ", *( (int *) c_queue_lpop( queue ) ) );
	}

	printf( "\nrpush rpop: " );
	c_queue_rpush( queue, &array[0] );
	c_queue_rpush( queue, &array[1] );
	c_queue_rpush( queue, &array[2] );
	c_queue_rpush( queue, &array[3] );
	c_queue_rpush( queue, &array[4] );
	c_queue_rpush( queue, &array[5] );
	c_queue_rpush( queue, &array[6] );
	c_queue_rpush( queue, &array[7] );
	c_queue_rpush( queue, &array[8] );
	while ( c_queue_length( queue ) )
	{
		printf( "%d ", *( (int *) c_queue_rpop( queue ) ) );
	}

	printf( "\nlpush rpop: " );
	c_queue_lpush( queue, &array[0] );
	c_queue_lpush( queue, &array[1] );
	c_queue_lpush( queue, &array[2] );
	c_queue_lpush( queue, &array[3] );
	c_queue_lpush( queue, &array[4] );
	c_queue_lpush( queue, &array[5] );
	c_queue_lpush( queue, &array[6] );
	c_queue_lpush( queue, &array[7] );
	c_queue_lpush( queue, &array[8] );
	while ( c_queue_length( queue ) )
	{
		printf( "%d ", *( (int *) c_queue_rpop( queue ) ) );
	}

	printf( "\nrpush lpop: " );
	c_queue_rpush( queue, &array[0] );
	c_queue_rpush( queue, &array[1] );
	c_queue_rpush( queue, &array[2] );
	c_queue_rpush( queue, &array[3] );
	c_queue_rpush( queue, &array[4] );
	c_queue_rpush( queue, &array[5] );
	c_queue_rpush( queue, &array[6] );
	c_queue_rpush( queue, &array[7] );
	c_queue_rpush( queue, &array[8] );
	while ( c_queue_length( queue ) )
	{
		printf( "%d ", *( (int *) c_queue_lpop( queue ) ) );
	}

	printf( "\nmulti  pop: " );
	c_queue_lpush( queue, &array[0] );
	c_queue_lpush( queue, &array[1] );
	printf( "%d ", *( (int *) c_queue_rpop( queue ) ) );
	c_queue_lpush( queue, &array[2] );
	printf( "%d ", *( (int *) c_queue_rpop( queue ) ) );
	printf( "%d ", *( (int *) c_queue_lpop( queue ) ) );
	c_queue_rpush( queue, &array[3] );
	c_queue_lpush( queue, &array[4] );
	c_queue_rpush( queue, &array[5] );
	while ( c_queue_length( queue ) )
	{
		printf( "%d ", *( (int *) c_queue_lpop( queue ) ) );
	}

	c_queue_rpush( queue, &array[6] );
	c_queue_rpush( queue, &array[7] );
	c_queue_lpush( queue, &array[8] );
	while ( c_queue_length( queue ) )
	{
		printf( "%d ", *( (int *) c_queue_lpop( queue ) ) );
	}

	printf( "\n" );

	c_queue_close( queue );

	return(0);
}