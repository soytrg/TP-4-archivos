#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//2) Modificar el programa anterior de manera que se puedan realizar
//búsquedas por Apellido y por nombre a la vez.

int main()
{
	FILE *fichero;
	fichero = fopen ("archivo2.txt", "a+");
			
	if (fichero == NULL)
    {
        printf("Error al abrir el archivo\n");
        return 1;
    }
            			
	int salida=0,opcion=0,dni,dni_buscado,dni_encontrado, encontrado=0;
	char nombre[20], apellido[20];
	char nombre_buscado[20], nombre_encontrado[20], apellido_buscado[20], apellido_encontrado[20];
	
	do 
	{
		do
		{
			printf("Elija una opcion: \n");
			printf("1. Ingresar datos\n");
			printf("2. Buscar por nombre y apellido\n");
			printf("3. Buscar por DNI\n");
			printf("4. salir\n");
			scanf("%d",&opcion);
		}while(opcion < 1 || opcion > 4);
		
		switch(opcion)
		{
			case 1:
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
				printf("Ingrese el nombre que quiera buscar: \n");
				scanf("%s",nombre_buscado);
				
				printf("Ingrese el apellido que quiera buscar: \n");
				scanf("%s",apellido_buscado);
				
				fseek(fichero,0,SEEK_SET);
				
				while(fscanf(fichero, "%d" "%s" "%s", &dni, nombre_encontrado, apellido_encontrado ) != EOF)
				{
					encontrado=0;
					if(strcmp(nombre_buscado, nombre_encontrado) == 0 && strcmp(apellido_buscado, apellido_encontrado) == 0 )
					{
						printf("datos encontrados: \nDNI: %d\nApellido: %s\nNombre: %s\n",dni, nombre_encontrado, apellido_encontrado);
						encontrado++;
						break;
					}		
				}
				
				if(feof(fichero) && encontrado == 0) // Si se llegó al final del archivo sin encontrar los datos
				{
					printf("Los datos buscados no fueron encontrados.\n");
				}
				break;
			case 3:
				printf("Ingrese el dni que quiera buscar: \n");
				scanf("%d",&dni_buscado);
				
				fseek(fichero,0,SEEK_SET);
				
				while(fscanf(fichero, "%d" "%s" "%s", &dni_encontrado, nombre, apellido ) != EOF)
				{
					encontrado=0;
						if(dni_buscado == dni_encontrado)
						{
							printf("datos encontrados: \nDNI: %d\nApellido: %s\nNombre: %s\n",dni_buscado, nombre, apellido);
							encontrado=1;
							break;
						}
				}
				
				if(feof(fichero) && encontrado==0)
				{
					printf("Los datos buscados no fueron encontrados.\n");
				}
				break;
			case 4:
				salida = 1;
				break;
		}
	}while(salida==0);	
	
		fclose (fichero);
	return 0;
}
