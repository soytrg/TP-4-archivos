#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//6) Realizar un programa que realice las siguientes acciones
//a. Guarde el registro del nombre y el puntaje de un jugador (solicitando el ingreso
//de los datos del usuario)
//b. Muestre el resultado de los 10 mejores jugadores ordenados por mayor
//puntaje.
//c. Realice y muestre una búsqueda de un Nombre y devuelva sus resultados
//NOTA: el registro debe permanecer aunque se apague la PC.

// Variables globales, que se pueden utilizar para las funciones y el codigo principal

struct jugador
{
	char nombre[20];
	int puntaje;
};

int puntaje, puntaje_encontrado;
char nombre[20], nombre_encontrado[20],nombre_buscado[20];
FILE *fichero;

struct jugador jugadores[20];

void menu();
void mostrar_top();
void ordenamiento(struct jugador jugadores[], int numjugadores);

int main()
{
	fichero = fopen ("archivo6.txt", "a+");
			
	if (fichero == NULL)
    {
        printf("Error al abrir el archivo\n");
        return 1;
    }
    
    int opcion,encontrado=0;
    do
    {
    	do
    	{
    		menu();
    		scanf("%d",&opcion);
		}while(opcion < 1 || opcion > 4);
		
		switch(opcion)
		{
			case 1:  // ingresamos los datos del jugador (Nombre y puntaje)
			
				system("PAUSE");
				system("CLS");
				
				printf("Ingrese el nombre del jugador:\n");
				scanf("%s",nombre);
				
				printf("Ingrese el puntaje del jugador:\n");
				scanf("%d",&puntaje);
					if(puntaje < 0)
					{
						printf("Ingrese un punto que sea mayor o igual a 0\n");
					}
					else
					{
						fputs(nombre, fichero);
						fprintf(fichero, " %d\n", puntaje); // ponemos los datos en el fichero, primero el nombre luego el puntaje
					}
				break;
				
			case 2:	
					rewind(fichero);
					
					int numjugadores=0;
					
					while(fscanf(fichero, "%s" "%d",jugadores[numjugadores].nombre, &jugadores[numjugadores].puntaje ) != EOF)
					{
						numjugadores++;
					}
					
					mostrar_top(numjugadores);
				break;
				
			case 3:
				system("PAUSE");
				system("CLS");
				
				printf("Ingrese el nombre que quiera buscar: \n");
				scanf("%s",nombre_buscado);
				
				fseek(fichero,0,SEEK_SET);
				
				while(fscanf(fichero, "%s %d",nombre_encontrado, &puntaje) != EOF)
				{
					encontrado=0;
					if(strcmp(nombre_buscado, nombre_encontrado) == 0)
					{
						printf("datos encontrados: \nNombre: %s\nPuntaje: %d\n",nombre_encontrado,puntaje);
						encontrado++;
						break;
					}		
				}
				
				if(feof(fichero) && encontrado == 0) // Si se llegó al final del archivo sin encontrar los datos
				{
					printf("Los datos buscados no fueron encontrados.\n");
				}
				break;
		}
		
	}while(opcion != 4);
    
    fclose(fichero);
	return 1;
}

void menu()
{
	printf("ingrese una opcion:\n");
	printf("1. Ingresar datos.\n");
	printf("2. Mostrar el top 10, desde el 1 hasta el 10\n");
	printf("3. Buscar por nombre.\n");
	printf("4. Salir.\n");
}

void ordenamiento(struct jugador jugadores[], int numjugadores)
{
	int x,y;
	struct jugador temp;
	
	for(x=0;x<numjugadores - 1;x++)
	{
		for(y=0;y<numjugadores - 1;y++)
		{
			if(jugadores[y].puntaje < jugadores[y+1].puntaje)
			{
				temp = jugadores[y];
				jugadores[y] = jugadores[y+1];
				jugadores[y+1] = temp;
			}
		}
	}
}

void mostrar_top(int numjugadores)
{
	fichero = fopen ("archivo6.txt", "a+");
	int x;
	
	ordenamiento(jugadores, numjugadores);
	
	printf("los 10 mejores: \n");
	for(x=0;x < numjugadores && x < 10;x++)
	{
		printf("%s - Puntaje: %d\n",jugadores[x].nombre, jugadores[x].puntaje);
	}
	
}
