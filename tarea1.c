#include <stdio.h> 
int main() { 
  char c;
  int True;
  True=1;
  printf("Texto para convertir headers y barspace: \n"); 
  while (True) { 
    c = getchar(); 
    if (c == EOF) {  // Ctrl+D EOF o Ctrl+C to stop
    } else if (c == '<') {  // Cambia < por_
      printf("_"); 
    } 
   else if (c == '>') {     // Cambia < por_
      printf("_"); 
    }
   else if (c == ' ') {  // Cambia espacio por un /b
     printf("/b"); 
    }
    else { 
      printf("%c", c);     
    }  
  }   
  return 0;
} 

/* Intento numero 1 de codigo, falta agregar que reciba un codigo html y un output .txt con el texto nuevo impreso
