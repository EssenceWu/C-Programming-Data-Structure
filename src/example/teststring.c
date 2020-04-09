
#include "../string.h"

int main( void )
{
	char	src[MAXSIZE]	= "ababaaaba";
	char	dst[MAXSIZE]	= "abcdefababaaaba";
	int	pos		= c_string_kmp( src, dst );
	printf( "\n%s at %s: %d\n\n", src, dst, pos );
	return(0);
}