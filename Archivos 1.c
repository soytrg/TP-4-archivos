#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1) Realizar un programa en el cual se ingresen los siguientes datos
//Nombre, Apellido y DNI
//a) Crear un menu donde se ingresen los datos y los guarde en un
//archivo
//b) Otro ítem donde se pueda realizar una búsqueda por DNI y
//devuelva los datos de Nombre y apellido
//c) Salir del mismo
int main()
{
	FILE *fichero;
	fichero = fopen ("archivo1.txt", "a+");
		
	int exit=0,opcion=0,dni,dni_encontrado,dni_buscado,encontrado=0;
	char nombre[20], apellido[20];
	
	do 
	{
		do
		{
		printf("Elija una opcion: \n");
		printf("1. Ingresar datos\n");
		printf("2. Buscar\n");
		printf("3. salir\n");
		scanf("%d",&opcion);
		}while(opcion > 3 || opcion < 1);
		
		switch(opcion)
		{
			case 1:
			
				if (fichero == NULL)
	            {
	                printf("Error al abrir el archivo\n");
	                return 1;
	            }
				
				printf("Ingrese su DNI: \n");
				scanf("%d",&dni);
				fprintf(fichero, "\n%d", dni);
				
				printf("Ingrese su nombre: \n");
				scanf("%s",nombre);
				fputs(" ",fichero);
				fputs(nombre, fichero);
				
				printf("Ingrese su apellido: \n");
				scanf("%s",apellido);
				fputs(" ",fichero);
				fputs(apellido, fichero);				
			
				break;
			
			case 2:
				
				printf("Ingrese el dni que quiera buscar: \n");
				scanf("%d",&dni_buscado);
				
				fseek(fichero,0,SEEK_SET);
				
				while(fscanf(fichero, "%d" "%s" "%s", &dni_encontrado, nombre, apellido ) != EOF)
				{
					encontrado=0;
						if(dni_buscado == dni_encontrado)
						{
							printf("datos encontrados: \nDNI: %d\nApellido: %s\nNombre: %s\n",dni_buscado, nombre, apellido);
							encontrado++;
							break;
						}
				}
				
				if(feof(fichero) && encontrado==0)
				{
					printf("Los datos buscados no fueron encontrados.\n");
				}
		
				break;
			case 3:
				exit = 1;
				break;
		}
	}while(exit==0);	
	
	fclose (fichero);
	return 0;
}
