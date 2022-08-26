/*
 ============================================================================
 Name        : intento.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	setbuf(stdout,NULL);
	int numeroIngresado;
	int contadorVueltas;
	int acumuladorPositivo;
	int acumMinimoPositivo;
	int acumuladorNegativo;
	int acumMaxNegativo;
	int flag;
	char respuesta;
	float promedioPositivos;
	float promedioNegativos;
	promedioPositivos=0;
	flag=0;
	contadorVueltas=0;
	acumuladorPositivo=0;
	acumuladorNegativo=0;
	acumMinimoPositivo=0;
	acumMaxNegativo=0;
	respuesta='s';

	while(respuesta=='s')
	{
		printf("Ingrese numero : ");
		scanf("%d",&numeroIngresado);
		if(numeroIngresado>=0)
		{
			acumuladorPositivo+=numeroIngresado;
			if(numeroIngresado<acumMinimoPositivo || flag==0)
			{
				acumMinimoPositivo=numeroIngresado;
				flag=1;
			}
		}
		if(numeroIngresado<=0)
		{
			acumuladorNegativo+=numeroIngresado;
			if(numeroIngresado<acumMaxNegativo)
			{
				acumMaxNegativo=numeroIngresado;
			}
		}
		contadorVueltas++;
		printf("Desea continuar ? S/N");
		fflush(stdin);
		scanf("%c",&respuesta);
		respuesta=tolower(respuesta);
		while(respuesta!='s'&& respuesta!='n')
		{
			printf("Desea continuar ? S/N");
			fflush(stdin);
			scanf("%c",&respuesta);
			respuesta=tolower(respuesta);
		}
	}
	promedioPositivos=(float)acumuladorPositivo/contadorVueltas;
	promedioNegativos=(float)acumuladorNegativo/contadorVueltas;
	printf("Promedio positivos acumulados : %.2f\n",promedioPositivos);
	printf("Numero positivo mas chico ingresado : %d\n",acumMinimoPositivo);
	printf("Promedio negativos acumulados : %.2f\n",promedioNegativos);
	printf("Numero negativo mas grande %d: ",acumMaxNegativo);

	return EXIT_SUCCESS;
}
