#include <stdio.h> // Solo utilizar standard input and output stdio.h
#define ON 1
#define OFF 0

int digitos(){     // Hice varios intentos comparando al char con este M[ 10 ] 
  int j;           // If el char coincidia con digitos then cambiar por X
  int M[ 10 ];  
   for ( j = 0; j < 10; j++ ) {
      M[ j ] = j + 1; 
   }
   M[9] = 0;
  return M[10];
}

int main() {
  char c;
  int a, b, d, e;


printf("Texto para cambiar : \n");
  while ((c = getchar()) != EOF) {
    a = OFF;
    d = OFF;
    switch (c) {

    case '&':
    case ',':
    case '.':
    case '!':
    case '?':
      d = ON;
      break;
    case '[':
    case '{':
    case '(':
    case '<':
      e = ON;
      break;
    case ')':
    case ']':
    case '}':
    case '>':
      e = OFF;
      break;
    }   // OR Brute Force, no recomendable pero no pude realizar la comparacion con M[ 10 ]
    if ((!e && c == '0') ||(!e && c == '1') || (!e && c == '2') || (!e && c == '3') || (!e && c == '4') ||(!e && c == '5') ||(!e && c == '6') ||(!e && c == '7') ||(!e && c == '8') ||(!e && c == '9') ) {
      b = ON;
    } else {
      if (b == ON) {
	putchar('x');
	a = ON;
      }
      b = OFF;
    }
    if (!a && !b && !d) {
      putchar(c);
    }
  }
    printf("\n");
  return 0;
}
