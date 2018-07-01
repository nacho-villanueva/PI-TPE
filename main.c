#include <stdlib.h>
#include <stdio.h>
#include "ListADT.h"

// TEST NACHO

//	Definiciones
#define MAX_TEXT 128


//	Prototipos
int verifyYear (const char * date, int yearGiven);
void getDate (const char * date, int * day, int * month, int * year);
int dateToDayOfWeek (const char * date, int * dayCode, int * monthCode, int * yearCode);


int
main (int argCount, int *argGiven[]){

	// Recibe el año como argumento y ve si es valido, si no lo es da un mensaje de error y aborta
	int yearGiven;

	if (argCount == 1){

	    if (2014 <= *(argGiven[0]) && *(argGiven[0]) <= 2018)
			yearGiven = *(argGiven[0]);
		else {
			printf("ERROR: El año tiene que estar entre 2014 y 2018.\n");
			exit(1);
		}

	} else if (argCount > 1){
		printf("ERROR: Fueron ingresados demasiados argumentos.\n");
		exit(1);
	} else {
		printf("ERROR: Se espera un argumento.\n");
		exit(1);
	}

	/*
	**	Cantidad de movimientos por los dias de la semana
	**	Indices:	Domingo = 0 , Lunes = 1 , ... , Sabado = 6
	*/
	int movPerDay[7] = {0};

	/*
	**	Codigos de los dias para el pase de fecha a dia
	**	Indices:	Domingo = 0 , Lunes = 1 , ... , Sabado = 6
	*/
	int dayCode[7] = {0, 1, 2, 3, 4, 5, 6};
	/*
	**	Codigos de los meses para el pase de fecha a dia
	**	Indices:	Enero = 0 , Febrero = 1 , ... , Diciembre = 11
	*/
	int monthCode[12] = {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	/*
	**	Codigos de los años para el pase de fecha a dia
	**	Indices:	2014 = 0 , 2015 = 1 , ... , 2018 = 4
	*/
	int yearCode[5] = {3, 4, 6, 0, 1};

}

//	Verifica si el año que recibio de los vuelos es el año que queremos. Devuelve 1 si lo es, 0 si no lo es.
int
verifyYear (const char * date, int yearGiven){

	int year;

	int args = sscanf(date, "%*d/%*d/%4d", &year);

	return year == yearGiven;
}

//	Extrae dia, mes y año a partir de la fecha
void
getDate (const char * date, int * day, int * month, int * year){

	int args = sscanf(date, "%2d/%2d/%4d", day, month, year);
	return;
}

//	Dada una fecha, calcula el dia de la semana y lo devuelve como un indice para el array movPerDay[]
int
dateToDayOfWeek (const char * date, int * dayCode, int * monthCode, int * yearCode){

	int day, month, year;
	getDate(date, &day, &month, &year);

	int dayOfWeekIndex = dayCode[day % 7] + monthCode[month - 1] + yearCode[year - 2014];

	return dayOfWeekIndex % 7;
}


/*
**	Funcion para procesar los datos de los vuelos
**	Valores de retorno:	0 - si todo funciono correctamente
**						1 - si hubo un error al tratar de abrir el archivo de vuelos
*/
int
movementsProcessing (int yearGiven, int * movPerDay, int * dayCode, int * monthCode, int * yearcode){

    //  Esto se encarga de abrir el archivo y manejarlo
    //  ------------------------------------------------------------------------------------------
	FILE * movementsFile;
	
	movementsFile = fopen("Dataset/archivoVuelos.csv", "r");
	if (movementsFile == NULL){
		printf("ERROR: El archivo archivoVuelos.csv no pudo ser abierto.\n");
		return 1;
	}
    //  ------------------------------------------------------------------------------------------

	
	char fileLine[MAX_TEXT];
	char separator[2] = ";";
	char * tokens[10];
	int counter;
	
	while (fgets(fileLine, MAX_TEXT, movementsFile) != NULL){

	    counter = 0;
        tokens[counter] = strtok(fileLine, separator);

        //  Si el año de ese movimiento es valido, corre esto
        if (verifyYear(tokens[counter], yearGiven)){

            //  Hace el pase a dia de la semana e incrementa el contador de ese dia
            movPerDay[dateToDayOfWeek(tokens[counter], dayCode, monthCode, yearcode)]++;

            //  Consigue el resto de los tokens de ese vuelo especifico
            while( tokens[counter] != NULL ) {
                tokens[++i] = strtok(NULL, s);
            }

        }

        /* walk through other tokens */
        while( tokens[i] != NULL ) {
            i++;
            //printf( " %s\n", tokens[i] );

            tokens[i] = strtok(NULL, s);

        }

	
	
	}
	
	


}
