#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Creamos el struct
struct STRUCTHTTP
{
	int statuscode;
	char* method;
	char* url;
};

/*
	void limit = Establecera un comienzo y un limite X para copiar lo que apareza en el string enviado
		
		PARAMETROS:
			@ int start = El punto inicial de donde copiar 
			@ int end = El punto final en donde terminar de copiar
			@ int len = Valor final que debe llegar un bucle for (usado para vaciar la variable cont)
			@ char str[] = El string que se va a copiar
			@ char cont[] = Contendra la cadena copiada de str
*/
void limit(int start, int end, int len, char str[], char cont[]);

/*
	void http = Retornara las posiciones en donde debera copiar el string 

		PARAMETROS:
			@ char str[] = El string  evaluar
			@ int arr[] = Almacenara las posiciones del string a copiar desde un punto X hasta otro punto Y
*/
void http(char str[], int arr[]);

int main(int argc, char const *argv[])
{
	// Redefinimos el struct
	struct STRUCTHTTP HTTP;

	char str[70]; // String que el usuario tecleara
	char cont[20]; // String que almacenara los valores de str
	char ran[20]; // String auxiliar
	int arr[6]; // Array de enteros que almacenara las posiciones a copiar 
	int aux = 1; // auxiliar
	int i = 0; // contador
	int len = sizeof(arr) / sizeof(arr[0]); // El tamaño del array de enteros
	
	// Pedimos al usuario que teclea el string
	printf("HTTP: "); fgets(str, sizeof(str), stdin);

	// Obtenremos las limites a copiar y los almacenamos en arr
	http(str, arr);

	while(i < len)
	{
		// Con los valores obtenidos de arr, los empleamos para copiar caracteres de la cadena str a cont
		limit(arr[i], arr[aux], 20, str, cont);	

		if(i == 0)
		{
			HTTP.statuscode = atoi(cont);
		}

		if(i == 2)
		{
			limit(arr[i], arr[aux], 20, str, ran);		
			HTTP.method = ran;			
		}

		if(i == 4)
		{
			HTTP.url = cont;
		}

		// aux e i se incrementen en 2 con cada iteracion
		aux += 2;
		i += 2;
	}	

	// Imprimimos resultados
	printf("statusCode: %d\n", HTTP.statuscode);
	printf("Method: %s\n", HTTP.method);
	printf("Url: %s\n", HTTP.url);
	
	getch();
	return 0;
}

void limit(int start, int end, int len, char str[], char cont[])
{
	int x = 0;

	for (int i = 0; i < len; ++i)
	{
		cont[i] = 0;
	}

	for (int i = start + 1; i < end; ++i)
	{
		cont[x] = str[i];
		x++;
	}
}

void http(char str[], int arr[])
{
	int x = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if(str[i] == '=' || str[i] == '/' || str[i] == ':' || str[i] == '\n')
		{
			arr[x] = i;
			x++;
		}
	}
}