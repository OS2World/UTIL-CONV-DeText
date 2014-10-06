/* Reverse the effects of a LF -> CR/LF translation
 * Written by Brian Havard <brianh@kheldar.apana.org.au>
 */

#include <stdio.h>
#include <string.h>

void main( int argc, char *argv[] )
{
  int ch, peeked = -1;

  if ( argc > 3 )
    return;
    
  FILE *InFile;
  FILE *OutFile;
  
  if ( argc < 2 || strcmp( argv[1], "-" ) == 0 )
    InFile = stdin;
  else
    InFile = fopen( argv[1], "rb" );

  if ( argc < 3 || strcmp( argv[2], "-" ) == 0 )
    OutFile = stdout;
  else
    OutFile = fopen( argv[2], "wb" );

  while ( ch = peeked < 0 ? fgetc( InFile ) : peeked, ch != EOF ) {
    peeked = -1;
    
    if ( ch == '\r' ) {
      peeked = fgetc( InFile );

      if ( peeked == '\n' )
        continue;
    }
    
    fputc( ch, OutFile );
  }

  fclose( InFile );
  fclose( OutFile );
}
