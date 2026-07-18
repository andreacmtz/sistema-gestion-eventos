//LIBRERIA evento.h
#ifndef EVENTO //verifica si ya existe
#define EVENTO
#include <stdio.h>
#include <stdlib.h>

float calcularcosto_evento(int horas, float tarifa, float km, float viaticos_v); //funcion parametrizada para calcular el total del evento
	
float calcularsaldo_restante(float costototal, float abono); //segunda funcion parametrizada para calcular el costo restando el abono	

int indice(); //funcion para mostrar el menu principal


//funciones para calcular costos y ejecutar el indice del programa
float calcularcosto_evento(int horas, float tarifa, float km, float viaticos_v){ //funcion parametrizada para calcular el total del evento
	//operaciones
	float costototal = (horas * tarifa) + (km * viaticos_v);
		
	return costototal;
}

float calcularsaldo_restante(float costototal, float abono){ //segunda funcion parametrizada para calcular el costo restando el abono	
	float saldopendiente; 
	
	saldopendiente = costototal - abono;
	
	return saldopendiente;
}

int indice(){ //funcion para mostrar el menu principal
	
	int numero;
	system("cls"); //Limpiar pantalla
	printf("\nMENU DEL SISTEMA: \n");
	printf("Bienvenido de nuevo, este sistema tiene como objetivo ayudarte a organizar mejor tus eventos musicales, ");
	printf("ademas, podras generar cotizaciones y registrarlas en el sistema. Gracias por tu confianza. \n");
	printf("\n0: Salir del programa ");
	printf("\n1: Registrar evento ");
	printf("\n2: Consultar agenda ");
	printf("\n3: Leer archivo de texto ");
	printf("\n4: Leer archivo binario ");
	printf("\n\nSeleccione una opcion: \n");
	scanf(" %d",&numero);
	
	return numero;
}
#endif //fin del ifndef



