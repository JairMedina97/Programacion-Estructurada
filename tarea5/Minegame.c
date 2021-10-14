#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Global values
unsigned short m, n, bombas;



int menu()
{
 printf("\n------------------------------\n");
 printf("\n----------1 para jugar--------\n");
 printf("\n----------0 para salir--------\n");
 printf("\n------------------------------\n");
 printf(" Please type: ");
 int boton = 0;
 scanf("%d", &boton);
 return boton;
}




int main()
{

 int boton = 0;
 srand((unsigned int)time(NULL));
 while (1)
 {
 boton = menu();
 if (boton == 1)
 {
    time_t start,end; // Variables para el timer
    double dif; 

  time (&start);  // Empezamos conteo
  game();       
  time (&end);    // Termina conteo
  dif = difftime (end,start);
  printf("\n------------------------------\n");
  printf ("Your game took %.2lf seconds to run.\n", dif );
  printf("\n------------------------------\n");
 }
 else if (boton == 0)
 {
 printf(" Adios!\n");
 break;
 }
 else
 {
 printf(" Error, Ingresa 0 o 1! \n");
 }
 }
 system("Bye");
 return 0;
} 

  
  
  
  
  
  
  
  
void game(){
 printf("Enter the row dimension of the matrix: ");
 scanf("%hu", &m);
 printf("Enter the column dimension of the matrix: ");
 scanf("%hu", &n);
  printf("How many bombs are ? ");
 scanf("%hu", &bombas);
 if(bombas > (m*n)){
    printf("\n------------------------------\n");
    printf("You typed more bombs than game dimensions \n");
    main();
 }
 char mapa_muestra[m][n];
 char mapa_bombas[m][n];
 Init(mapa_muestra, mapa_bombas); 
 int conteo_espacio = 0;
 while (1){
// Imprimirmapa(mapa_bombas);
 printf("\n");
 Imprimirmapa(mapa_muestra);
 // Coordenadas   
 int i = 0;
 int j = 0;
 printf("Coordinate of row = \n"); 
 scanf("%hu",&i); 
 printf("Coordinate of column = \n");    
 scanf("%hu",&j);  
 if (i < 0 || i >= m || j < 0 || j >= n)
 {
 printf("Error de coordenada, ingresa de nuevo \n");
 continue; 
 }
 if (mapa_muestra[i][j] != '#')
 {
 // Coordenada que ya se ingreso
 printf(" La coordenada ya fue abierta, ingresa otra \n");
 continue;
 }
 // Es una bomba
 if (mapa_bombas[i][j] == '1')
 {
 Imprimirmapa(mapa_bombas);
 printf("\n------------------------------\n");
 printf("\nCoordenada [%hu][%hu] es una bomba \n", i, j); 
 printf("\n Game over !\n");
 break;
 }
 conteo_espacio++;
 // Victoria !
 if (conteo_espacio == m * n - bombas)
 {
  printf("\n------------------------------\n");
  printf("\n-------Cheers you won !-------\n");
  printf("\n-------Cheers you won !-------\n");
  printf("\n------------------------------\n");
 break;
 }
 //Actualizar el mapa
 actualizarmapa(mapa_muestra, mapa_bombas, i, j);
 }
}
 
 
 
 
 
 
 
 
 
 
 
void Init(char mapa_muestra[m][n], char mapa_bombas[m][n])
{
 //El mapa principal  *
 for (int i = 0; i < m; i++)
 {
 for (int j = 0; j < n; j++)
 {
 mapa_muestra[i][j] = '#';
 }
 }
 //El mapa de minas
 for (int i = 0; i < m; i++)
 {
 for (int j = 0; j < n; j++)
 {
 mapa_bombas[i][j] = '0';
 }
 }
 //Generar al azar numero de bombas
 int conteo_mina = bombas;
 while (conteo_mina > 0)
 {
 // Coordenadas random para las bombas en el mapa_bombas
 int i = rand() % m;
 int j = rand() % n;
 if (mapa_bombas[i][j] == '1')
 {
 continue;
 }
 mapa_bombas[i][j] = '1';
 --conteo_mina;
 }
}













void Imprimirmapa(char map[m][n])
{
 //Coordenadas 
 printf(" |");
 for (int j = 0; j < n; j++)
 {
 printf(" %d", j);
 }
 printf("\n");
 //Lineas de separacion
 for (int j = 0; j < n; j++)
 {
 printf("---");
 }
 printf("\n");
 //columnas 
 for (int i = 0; i < m; i++)
 {
 printf(" %d|", i);
 for (int j = 0; j < n; j++)
 {
 printf(" %c", map[i][j]);
 }
 printf("\n");
 }
}










void actualizarmapa(char mapa_muestra[m][n], char mapa_bombas[m][n], int i, int j)
{
 // La posicion i, j para calcular las posiciones con respecto a las bombas
 int conteo = 0;
 if (i - 1 >= 0 && j - 1 >= 0 && mapa_bombas[i - 1][j - 1] == '1') 
 { 
 conteo++;
 }
 if (i - 1 >= 0 && mapa_bombas[i - 1][j] == '1')
 {
 conteo++;
 }
 if (i - 1 >= 0 && j + 1 < n && mapa_bombas[i - 1][j + 1] == '1')
 {
 conteo++;
 }
 if (j - 1 >= 0 && mapa_bombas[i][j - 1] == '1')
 {
 conteo++;
 }
 if (j + 1 < n && mapa_bombas[i][j + 1] == '1')
 {
 conteo++;
 }
 if (i + 1 < m && j - 1 >= 0 && mapa_bombas[i + 1][j - 1] == '1')
 {
 conteo++;
 }
 if (i + 1 < m && mapa_bombas[i + 1][j] == '1')
 {
 conteo++;
 }
 if (i + 1 < m && j + 1 < n && mapa_bombas[i + 1][j + 1] == '1')
 {
 conteo++;
 }
 //Agregar el conteo al mapa de las bombas
 mapa_muestra[i][j] = conteo + '0';
}
