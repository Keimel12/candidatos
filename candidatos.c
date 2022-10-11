#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*
	1. Cree n numeros de cantidatos en STRUCTCANDIDATOS candidatos[n] y despues se tendra que rellenar todos
	los datos de estos.
	Cuando finalice, preguntar los distintos tipos de ordenamiento. Estos son...
		a) Mayor a menor votos
		b) Menor a mayor votos
		c) Alfabeticamente descendente (Nombre)
		d) Alfabeticamente ascendente (Nombre)
		e) Alfabeticamente descendente (Localidad)
		f) Alfabeticamente ascendente (Localidad)
*/

// Nota: No pongas mas de 1000 candidatos, no se crashea pero XDDDD

// Creamos una struct para añadir los diversos campos en los candidatos
struct STRUCTCANDIDATOS
{
	char name[20];
	char city[20];
	int vote;
} ;

void sort_vote_high(struct STRUCTCANDIDATOS *vote, int len);
void sort_vote_low(struct STRUCTCANDIDATOS *vote, int len);
void sort_name_desc(struct STRUCTCANDIDATOS *user, int len);
void sort_name_asc(struct STRUCTCANDIDATOS *user, int len);
void sort_place_desc(struct STRUCTCANDIDATOS *loc, int len);
void sort_place_asc(struct STRUCTCANDIDATOS *loc, int len);

int main()
{
	// Evitamos que se repita la misma secuencia de numeros aleatorios
	time_t t;
	srand((unsigned) time(&t));

	// Creamos dos matrices de string (Para no llenar a cada rato los datos uno por uno)
	char nombres[15][20] = {"Jose Alvarez", "Alan Martinez", "Hugo Vazquez", "Mateo Andres", "Jacinto Perez",
						"Leo libros", "Daniel Dhers", "Pato Lucas", "Pablo Augusto", "Bartolomeo Kuma",
						"Adriana Gil", "Agata Waterson", "Carmen Barbara", "Concepcion Bolivar", "Dora Dafne"};

	char ciudades[15][20] = {"Paris", "Milan", "Florencio", "Orlando", "Brooklyn",
						"Denver", "Sidney", "Andalucia", "Ciudad Bolivar", "Puerto Ordaz",
						"Zahar", "Villa Bahia", "Unare I", "San Felix", "Villa Acero"};

	int n; // Cantidad de datos a almacenar en el struct array
	int aux = 0; // auxiliar
	int opcion; // Dependiendo de la tecla presionada hara una accion distinta
	int choice; // Dependiendo de la tecla presionada hara una accion distinta
	bool value = false; // Permitira terminar el relleno de informacion de candidatos

	// Pedimos al usuario de elementos a tratar
	printf("Dime la cantidad de candidatos: "); scanf("%d", &n);
	struct STRUCTCANDIDATOS candidatos[n];	

	// Mientras value sea false se repetira el ciclo
	while(value == false)
	{
		// Pedimos al usuario que nos diga que hacer
		printf("a) Rellenar aleatoriamente las opciones de candidatos\n");
		printf("b) Introducir usted mismo los diversos campos de los candidatos\n");
		choice = getch();
			switch(choice)
			{
				// Al presionar la tecla "a" rellenara automaticamente los datos
				case 97:
					for (int i = 0; i < n; ++i)
					{
						aux = rand() % 14 + 1;
						strcpy(candidatos[i].name, nombres[aux]);
						strcpy(candidatos[i].city, ciudades[aux]);
						candidatos[i].vote = rand() % 400 + 10;
					}
					// Al terminar de rellenar, value tomara el valor de true y terminara el ciclo
					value = true;
					break;
				
				case 98:		
					// Al presionar la tecla "b" el usuario tendra que rellenar los datos por si mismo	
					for (int i = 0; i < n; i++)
					{
						fflush(stdin);
						printf("Nombre del candidato: ");
						fgets(candidatos[i].name, 20, stdin);
						printf("Localidad del candidato: ");
						fgets(candidatos[i].city, 20, stdin);
						printf("Cantidad de votos obtenidos: ");
						scanf("%d", &candidatos[i].vote);
						system("cls");
					}
					// Al terminar de rellenar, value tomara el valor de true y terminara el ciclo
					value = true;
					break;
			}
		system("cls");
	}

	// Ahora accedemos a otro bucle que se repetira si y solo si el usuario no teclea la tecla Esc del teclado
	while(opcion != 27)
	{
		// Pedimos al usuario que tipo de ordenamiento quiere segun los datos conseguidos
		printf("a) Mayor a menor votos\n");
		printf("b) Menor a mayor votos\n");
		printf("c) Alfabeticamente descendente (Nombre)\n");
		printf("d) Alfabeticamente ascendente (Nombre)\n");
		printf("e) Alfabeticamente descendente (Localidad)\n");
		printf("f) Alfabeticamente ascendente (Localidad)\n");
		printf("Presione la tecla ESC para salir\n");
		opcion = getch();
		switch(opcion)
		{
			case 97:
				printf("Haz decidido ordenar los votos de manera descendente (Mayor a menor)\n\n");
				sort_vote_high(candidatos, n);
				
				for (int i = 0; i < n; ++i)
				{
					printf("[%d] %s -- %s\n", candidatos[i].vote, candidatos[i].name, candidatos[i].city);
				}
				getch();
				system("cls");
				break;
			case 98:
				printf("Haz decidido ordenar los votos de manera ascendente (menor a mayor)\n");
				sort_vote_low(candidatos, n);

				for (int i = 0; i < n; ++i)
				{
					printf("[%d] %s -- %s\n", candidatos[i].vote, candidatos[i].name, candidatos[i].city);
				}
				getch();
				system("cls");
				break;
			case 99:
				printf("Haz decido ordenar los candidatos por nombre alfabeticamente descendente\n");
				sort_name_desc(candidatos, n);

				for (int i = 0; i < n; ++i)
				{
					printf("[%d] %s -- %s\n", candidatos[i].vote, candidatos[i].name, candidatos[i].city);
				}
				getch();
				system("cls");
				break;
			case 100:
				printf("Haz decido ordenar los candidatos por nombre alfabeticamente ascendente\n");
				sort_name_asc(candidatos, n);

				for (int i = 0; i < n; ++i)
				{
					printf("[%d] %s -- %s\n", candidatos[i].vote, candidatos[i].name, candidatos[i].city);
				}
				getch();
				system("cls");
				break;
			case 101:
				printf("Haz decido ordenar los candidatos por localidad alfabeticamente descendente\n");
				sort_place_desc(candidatos, n);

				for (int i = 0; i < n; ++i)
				{
					printf("[%d] %s -- %s\n", candidatos[i].vote, candidatos[i].name, candidatos[i].city);
				}
				getch();
				system("cls");
				break;
			case 102:
				printf("Haz decido ordenar los candidatos por localidad alfabeticamente descendente\n");
				sort_place_asc(candidatos, n);

				for (int i = 0; i < n; ++i)
				{
					printf("[%d] %s -- %s\n", candidatos[i].vote, candidatos[i].name, candidatos[i].city);
				}
				getch();
				system("cls");
				break;
			case 27:
				printf("Haz salido del programa\n");
			default:
				printf("Opcion invalida\n");
				system("cls");
		}
	}
	getch();
	return 0;
}


void sort_vote_high(struct STRUCTCANDIDATOS *vote, int len)
{
	struct STRUCTCANDIDATOS temp;

	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if(vote[j].vote > vote[j + 1].vote)
			{
				temp = vote[j];
				vote[j] = vote[j + 1];
				vote[j + 1] = temp;				
			}
		}
	}
}

void sort_vote_low(struct STRUCTCANDIDATOS *vote, int len)
{
	struct STRUCTCANDIDATOS temp;
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if(vote[j].vote < vote[j + 1].vote)
			{
				temp = vote[j];
				vote[j] = vote[j + 1];
				vote[j + 1] = temp;
			}
		}
	}
}

void sort_name_desc(struct STRUCTCANDIDATOS *user, int len)
{
	struct STRUCTCANDIDATOS temp;

	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if(strcmp(user[j].name, user[j + 1].name) > 0)
			{
				temp = user[j];
				user[j] = user[j + 1];
				user[j + 1] = temp;				
			}

		}
	}
}

void sort_name_asc(struct STRUCTCANDIDATOS *user, int len)
{
	struct STRUCTCANDIDATOS temp;

	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if(strcmp(user[j].name, user[j + 1].name) < 0)
			{
				temp = user[j];
				user[j] = user[j + 1];
				user[j + 1] = temp;
			}
		}
	}
}

void sort_place_desc(struct STRUCTCANDIDATOS *loc, int len)
{
	struct STRUCTCANDIDATOS temp;

	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if(strcmp(loc[j].city, loc[j + 1].city) > 0)
			{
				temp = loc[j];
				loc[j] = loc[j + 1];
				loc[j + 1] = temp;
			}
		}
	}
}

void sort_place_asc(struct STRUCTCANDIDATOS *loc, int len)
{
	struct STRUCTCANDIDATOS temp;

	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if(strcmp(loc[j].city, loc[j + 1].city) < 0)
			{
				temp = loc[j];
				loc[j] = loc[j + 1];
				loc[j + 1] = temp;
			}
		}
	}
}