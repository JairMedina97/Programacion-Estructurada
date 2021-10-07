#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256 // 256-bit integers
double pila[MAX];
int altura; 

void insertar(double v)
{
	if (altura >= MAX) displaymsj("ERROR: Too many numbers\n");
	pila[altura++] = v;
}
 
double extraer()
{
	if (!altura) displaymsj("ERROR: Missing operand\n");
	return pila[--altura];
}
 
 
double rpn(char *s)
{
	double a, b;
	int i;
	char *e, *w = " \t\n\r\f";
    /* strtok The contents of this string are modified and broken into smaller strings (tokens) */
	for (s = strtok(s, w); s; s = strtok(0, w)) {
	/*  strtod Conversion, converts the string pointed to by the argument str to a floating-point number (type double) */
		a = strtod(s, &e);
		if (e > s)		printf(" > "), insertar(a);
#define operacion(x) printf("%c >", *s), b = extraer(), a = extraer(), insertar(x)
		else if (*s == '+')	operacion(a + b);
		else if (*s == '-')	operacion(a - b);
		else if (*s == '*')	operacion(a * b);
		else if (*s == '/')	operacion(a / b);
		else if (*s == '=')	operacion(a = b);

#undef operacion
		else {
			fprintf(stderr, "'%c'> ", *s);
			displaymsj("ERROR: Unknown operator (only +*-/ are known).\n");
		}
		for (i = altura; i-- || 0 * putchar('\n'); )
			printf(" %g", pila[i]);
	}
 
	if (altura != 1) displaymsj("ERROR: Too many operands\n");
 
	return extraer();
}


void displaymsj(const char *mensaje)
{
	fprintf(stderr, "%s", mensaje);
	abort();
}
 
 
int main(void)
{
   
	printf("Ingresar operacion en RPN: ");
	char s[MAX];
	gets(s);
	if(s != EOF){
	printf("%g\n", rpn(s));
	}
	return 0;
} 
