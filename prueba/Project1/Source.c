#include<stdio.h>
#include<stdlib.h>

#define NULL 0

typedef int(*pCallback) (char *, char*, void *);


int parseCmdLine(int argc, char *argv[], pCallback p, void *userData);
int parseCallback(char *key, char *value, void *userData);

int parseCmdLine(int argc, char *argv[], pCallback p, void *userData)
{
	/*Esta funcion evalua los argumentos clasificando segun sea opcion o parametros.
	Devuelve un 1 si se pudo evaluar correctamente, al contrario un 0 */
	int counter = 1;
	int sum = 0;
	while (counter < argc) {
		if (*argv[counter] == '-') {
			if (!(((counter + 1) == argc) || ((*argv[counter + 1]) == '-'))) //evalua si se ingreso correctamente
			{
				if (pCallback(argv[counter] + 1, argv[counter + 1], NULL))  //NO SE QUE PASAR EN USER DATA
				{
					sum++;
					counter += 2;
				}
				else
					return -1;  //devuelve -1 si no es lo pedido.

			}
			else
				return -1;				//devuelve -1 si no se ingreso correctamente

		}
		else {
			if (pCallback(NULL, argv[counter], NULL))
			{
				sum++;
				counter++;
			}
		}

	}
	return sum;							//devuelve la suma de las opciones y los parametros.

}

