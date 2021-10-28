#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
// Structure of the employee
struct emp {
    char name[50];  
    int age;
    int id;
    float days;
    float wage; 
    float salary;
};
struct emp e;
  
// Size of structure
long int size = sizeof(e);

  
FILE *fp, *ft;
  
// Funcion para agregar records
void agregar()
{
    system("cls");
    fseek(fp, 0, SEEK_END);
    char another = 'y';
  
    while (another == 'y') {
        printf("\nIngresar nombre: ");
        scanf("%s", e.name);
  
        printf("\nEdad: ");
        scanf("%d", &e.age);

        printf("\nAgregar ID: ");
        scanf("%d", &e.id);

        printf("\nDias de trabajo: ");
        scanf("%f", &e.days);

        printf("\nSalario por dia: ");
        scanf("%f", &e.wage);

//        printf("\nIngresar salario: ");
//        scanf("%f", &e.salary);

        e.salary = e.wage*e.days; 
  
        fwrite(&e, size, 1, fp);
  
        printf("\nDeseas agregar otro (Y/N): ");
        fflush(stdin);
  
        scanf("%c", &another);
    }
    displayrecord();
}
  
// Funcion para eliminar los records
void eliminar()
{
    system("cls");
    char empname[50];
    char another = 'y';
  
    while (another == 'y') {
        displayrecord();
        printf("\nIngresar nombre de empleado: ");
        scanf("%s", empname);
  
        ft = fopen("temp.txt", "wb");
        rewind(fp);

        if (strcmp(e.name, empname) == 0){
            printf("\nEmployee does not match database "); 
        }

        while (fread(&e, size,1, fp)== 1) {
            if (strcmp(e.name, empname) != 0){
                fwrite(&e, size, 1, ft); 
        }                  
        }
  
        fclose(fp);
        fclose(ft);
        remove("data.txt");
        rename("temp.txt", "data.txt");
        fp = fopen("data.txt", "rb+");
  
        printf("\nDesea eliminar otro record (Y/N): ");
        fflush(stdin);
        another = getche();
    }
}
  
// Funcion para display la tabla
void displayrecord()
{
    system("cls");
  
    // sets pointer to start of the file
    rewind(fp);
  
    printf("\n===========================================================================================================");
    printf("\nNAME\t\tAGE\t\tID\t\t days\t\tWage/days\t\tSalary $\n", e.name, e.age, e.wage, e.id, e.days, e.salary);
    printf("===========================================================================================================\n");
  
    while (fread(&e, size, 1, fp) == 1)
        printf("\n%s\t\t%d\t%10d\t\t%6.0f\t\t%.2f\t\t\t%.2f", e.name, e.age, e.id, e.days, e.wage, e.salary);
        printf("\n\n\n\t");
    system("pause");
}
  
// Funcion para modificar
void modificar()
{
    system("cls");
    char empname[50];
    char another = 'y';
  
    while (another == 'y') {
        displayrecord();
        printf("\nIngrese nombre a modificar: ");
        scanf("%s", empname);
  
        rewind(fp);
         
//        if (strcmp(e.name, empname) == 0){
//            printf("\nEmployee does not match database "); 
//       }

        // While File is open        
        while (fread(&e, size, 1, fp) == 1) {
            // Compare the employee name with ename
            if (strcmp(e.name, empname) == 0) {
                printf("\nIngresar nuevo nombre: ");
                scanf("%s", e.name);
                printf("\nIngresar nueva edad: ");
                scanf("%d", &e.age);
                printf("\nIngresar nuevo ID: ");
                scanf("%d", &e.id);
                printf("\nIngresar dias: ");
                scanf("%f", &e.days);
                printf("\nSalario por dia: ");
                scanf("%f", &e.wage);
//                printf("\nIngresar salario: ");
//                scanf("%f", &e.salary);
                e.salary = e.wage*e.days; 
                fseek(fp, -size, SEEK_CUR);
                fwrite(&e, size, 1, fp);
                break;
            } 
        }
  
        // Agregar otro record
        printf("\nDesea modificar otro record (Y/N): ");
        fflush(stdin);
        scanf("%c", &another);
    }
}
  

int main()
{
    int choice;  
    // opening the file
    fp = fopen("data.txt", "rb+");
  
    // showing error if file is unable to open.
    if (fp == NULL) {
        fp = fopen("data.txt", "wb+");
        if (fp == NULL) {
            printf("\nCannot open file...");
            exit(1);
        }
    }  

    printf("\n\t\t\t\t=====================================================");
    printf("\n\t\t\t\t[                   HR database                  ]\t");
    printf("\n\t\t\t\t=====================================================\n");
  
    system("pause");
  
    while (1) {
        // Eliminar la consola y preguntar a usuario
        system("cls");

        printf("\n1. AGREGAR RECORD\n");

        printf("\n2. ELIMINAR RECORD\n");

        printf("\n3. DISPLAY RECORDS\n");

        printf("\n4. MODIFICAR RECORD\n");

        printf("\n5. EXIT\n");

        printf("\nSELECCIONAR...\n");
        fflush(stdin);
        scanf("%d", &choice);
  
        // Switch Case
        switch (choice) {
        case 1:
  
            // Agregar
            agregar();
            break;
  
        case 2:
  
            // Eliminar
            eliminar();
            break;
  
        case 3:
  
            // Display 
            displayrecord();
            break;
  
        case 4:
  
            // Modificar
            modificar();
            break;
  
        case 5:
            fclose(fp);
            exit(0);
            break;
  
        default:
            printf("\nERROR...\n");
        }
    }
  
    return 0;
}
