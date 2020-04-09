
#include "string.h"

int c_string_kmp( char *src, char *dst )
{
	int	idx		= 1, jdx = 1;
	int	next[MAXSIZE]	= { 0 };
	c_string_next( src, next );
	while ( idx <= strlen( dst ) && jdx <= strlen( src ) )
	{
		if ( jdx == 0 || dst[idx - 1] == src[jdx - 1] )
		{
			idx++;
			jdx++;
		}else{
			jdx = next[jdx];
		}
	}
	return(jdx > strlen( src ) ? idx - jdx : -1);
}


void c_string_next( char *src, int *next )
{
	int idx = 1, jdx = 0;
	next[idx] = 0;
	while ( idx < strlen( src ) )
	{
		if ( jdx == 0 || src[idx - 1] == src[jdx - 1] )
			next[++idx] = src[idx] == src[jdx] ? next[++jdx] : ++jdx;
		else
			jdx = next[jdx];
	}
}