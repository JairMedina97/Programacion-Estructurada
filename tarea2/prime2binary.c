#include <stdio.h>
int main(){
  int k, contar, c, m, j; 
  int i = 3; // Los numeros primos no tienen divisor exacto entre 3
  printf("Cuantos numeros primos quieres imprimir?: \n");
  scanf("%d", &k);
if(k >= 1) {
   printf("Los primeros k = %d numeros primos son:\n",k);
   printf("0000000010 Binario es el numero primo 2 \n");
}
    for (contar=2; contar <= k;){ // primer ciclo que cuenta de 2 hasta k
        for (c = 2; c <= i - 1; c++) //2do ciclo, de 2 hasta que c sea menor 
        {                           // o igual a i-1, suma c++
            if (i%c == 0) //% modulo, si el modulo de i con c
             break;       //es igual a cero, entonces no es # primo    
    }
    if (c == i) //si c es igual a i entonces si es primo entonces entramos a este ciclo
    {           //Para convertir el numero a binario
       for (m = 9; m >= 0; m--) //Aqui creamos los digitos del binario
  {
    j = i >> m; //Right shift Desplazamiento a la derecha
    if (j & 1) //Operador Bitwise AND
      printf("1");
    else
      printf("0");
  } 
      printf("%d\b Binario es el numero primo %d\n",j , i);
      contar++; // contamos +1 en el ciclo hasta llegar a k
      }
      i++;   //Aumentamos a i = i+1 
    }
// Tengo un error, me esta agregando ceros y unos cuando los digitos aumentan, falta resolver esta duda.  
    return 0;
}
