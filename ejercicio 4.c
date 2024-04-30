#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//4) Modificar dicho programa de manera que me muestre los datos de
//manera ordenada
//Según se desee por nombre y apellido o por DNI
int main()
{
	FILE *fichero;
	fichero = fopen ("archivo4.txt", "a+");
			
	if (fichero == NULL)
    {
        printf("Error al abrir el archivo\n");
        return 1;
    }
            			
	int salida=0,opcion=0, encontrado=0,personas_ingresadas=0, salir=0;
	int dni,dni_buscado,dni_encontrado;
	char nombre[20], apellido[20];
	char nombre_buscado[20], nombre_encontrado[20];
	char apellido_buscado[20], apellido_encontrado[20];
	
	do 
	{
		do
		{
			printf("Elija una opcion: \n");
			printf("1. Ingresar datos\n");
			printf("2. Buscar por nombre y apellido\n");
			printf("3. Buscar por DNI y ordenado por dni\n");
			printf("4. Buscar ordenado por nombre\n");
			printf("5. Buscar ordenado por apellido\n");
			printf("6. salir\n");
			scanf("%d",&opcion);
		}while(opcion < 1 || opcion > 6);
		
		switch(opcion)
		{
			case 1:
				system("PAUSE");
				system("CLS");
				
				printf("Ingrese su DNI: \n");
				scanf("%d",&dni);
				
				fseek(fichero,0,SEEK_SET);
				
				salir=0;
				while(fscanf(fichero, "%d %s %s", &dni_encontrado, nombre, apellido) != EOF && salir <= personas_ingresadas)
				{
					encontrado=0;
				
						if(dni == dni_encontrado)
						{
							printf("Este dni ya esta ingresado\n\n");
							encontrado=1;
							break;
						}
						salir++;
				}	
					
				if(!encontrado) // ingresamos los datos de la persona en el fichero si es que no existe
				{
					fprintf(fichero, "\n%d", dni);
					
					printf("Ingrese su nombre: \n");
					scanf("%s",nombre);
					fputs(" ",fichero);
					fputs(nombre, fichero);	
				
					
					printf("Ingrese su apellido: \n");
					scanf("%s",apellido);
					fputs(" ",fichero);
					fputs(apellido, fichero);
					
					personas_ingresadas++;
				}
		
				break;
			case 2:
				system("PAUSE");
				system("CLS");
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
						printf("datos encontrados: \nDNI: %d\nApellido: %s\nNombre: %s\n\n",dni, nombre_encontrado, apellido_encontrado);
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
				system("PAUSE");
				system("CLS");
				printf("Ingrese el dni que quiera buscar: \n");
				scanf("%d",&dni_buscado);
				
				fseek(fichero,0,SEEK_SET);
				
				while(fscanf(fichero, "%d" "%s" "%s", &dni_encontrado, nombre, apellido ) != EOF)
				{
					encontrado=0;
						if(dni_buscado == dni_encontrado)
						{
							printf("datos encontrados: \nDNI: %d\nApellido: %s\nNombre: %s\n\n",dni_buscado, nombre, apellido);
							encontrado++;
							break;
						}
				}
				
				if(feof(fichero) && encontrado==0)
				{
					printf("Los datos buscados no fueron encontrados.\n");
				}
				break;
			case 4:
				system("PAUSE");
				system("CLS");
				
				printf("Ingrese el nombre que quiera buscar: \n");
				scanf("%s",nombre_buscado);
				
				fseek(fichero,0,SEEK_SET);
				
				while(fscanf(fichero, "%d" "%s" "%s", &dni, nombre_encontrado, apellido ) != EOF)
				{
					encontrado=0;
					if(strcmp(nombre_buscado, nombre_encontrado) == 0)
					{
						printf("datos encontrados: \nNombre: %s\nApellido: %s\nDNI: %d\n\n",nombre_encontrado,apellido,dni);
						encontrado++;
						break;
					}		
				}
				
				if(feof(fichero) && encontrado == 0) // Si se llegó al final del archivo sin encontrar los datos
				{
					printf("Los datos buscados no fueron encontrados.\n");
				}
				break;
			case 5:
				system("PAUSE");
				system("CLS");
				
				printf("Ingrese el apellido que quiera buscar: \n");
				scanf("%s",apellido_buscado);
				
				fseek(fichero,0,SEEK_SET);
				
				while(fscanf(fichero, "%d" "%s" "%s", &dni, nombre, apellido_encontrado ) != EOF)
				{
					encontrado=0;
					if(strcmp(apellido_buscado, apellido_encontrado) == 0 )
					{
						printf("datos encontrados: \nApellido: %s\nNombre: %s\nDNI: %d\n\n", apellido_encontrado, nombre_encontrado,dni);
						encontrado++;
						break;
					}		
				}
				
				if(feof(fichero) && encontrado == 0) // Si se llegó al final del archivo sin encontrar los datos
				{
					printf("Los datos buscados no fueron encontrados.\n\n");
				}
				break;	
			case 6:
				salida = 1;
				break;
		}
	}while(salida==0);	

		fclose (fichero);
	return 0;
}

