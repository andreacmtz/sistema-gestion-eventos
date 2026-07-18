//evento.c
#include "evento.h" //libreria creada
#include <string.h>
#include <math.h>

//defino constantes
#define VIATICOS 10.0
//arreglo unidimensional
float tarifas[3]={3000.0, 5000.0, 7000.0}; //arreglo unidimensional que definira el precio de la tarifa por hora
//variable global
float tarifa_base;

//declaro estructuras
typedef struct {
	char nombre_evento[40]; //almacenar el nombre del evento
	char hora[6]; //hora del evento en formato (ej. 9:30, 18:30, etc.)
	char nombre_cliente[20];
	char fecha[12];
	char apellido_cliente[35];
	int personastotales; //dependiendo de cuantas personas habra en el evento se cobrara la hora
	char categoria[30]; //se hara una categoria del tipo de evento que se registrara (publico(concierto), privado u otro)
	float km; //km que se recorren hacia el evento
	float abono; //abono dado por el cliente
	int horascontratadas; //horas contratadas del evento
	float saldopendiente; //precio restado al costo total
	float costototal;
}evento;

evento *numeventos = NULL; //puntero a numeventos
int cantidad = 0; //declaro estas dos variables globales, y doy valor null a numeventos (la variable int cantidad la asigna el usuario)

//funciones de archivos
//archivos de texto
void guardar_archivotexto(evento *numeventos, int cantidad){ //esta funcion parametrizada guardara, leera y mostrara los registros de datos en archivo de texto
	FILE*archivo = fopen("agenda_eventos.txt","a");//a creara el archivo y almacenara sin eliminarlo de nuevo
	int i;
	
	if(archivo == NULL){
		printf("ERROR, no se pudo crear el archivo de texto\n");
		return; //salimos de la sentencia
	}
	
	for(i= 0; i<cantidad; i++){ /*este ciclo es el que registrara todos los datos de la estructura anterior, 
	y el uso de i es para registrar la cantidad de veces que se guardaron esos datos*/
		fprintf(archivo, "%f %s %s %s %s %d %f %s %s %d %f %f \n",numeventos[i].abono, numeventos[i].apellido_cliente,
			numeventos[i].categoria, numeventos[i].fecha, numeventos[i].hora, numeventos[i].horascontratadas, numeventos[i].km,
			numeventos[i].nombre_cliente, numeventos[i].nombre_evento, numeventos[i].personastotales, numeventos[i].saldopendiente, numeventos[i].costototal); 
			//guardo en el archivo todos los elementos de la estructura	
	}
	
	fclose(archivo); //cerrar archivo
	printf("Se han guardado los datos en el archivo de texto\n");
}

void leer_archivotexto(){
	system("cls");
	int regresar;
	FILE *archivo = fopen("agenda_eventos.txt", "r"); //como primero creamos el archivo con a, ahora con r leemos el mismo archivo
	int numero = 1;
	 evento eve; //eve es como llamamos a esa estructura
	 int contador =1; //servira para contar las veces que se repite la sentencia
	 
	 if(archivo == NULL){
	 	printf("No hay archivo de texto, o agenda vacia\n");//este if nos ayudara a que si el archivo a registrar no contiene nada, volver de nuevo
	 	return;
	 }
	 
	 //imprimir datos
	 printf("Lectura de registro de eventos en archivo de texto\n");
	 while(fscanf(archivo, "%f %s %s %s %s %d %f %s %s %d %f %f", &eve.abono, eve.apellido_cliente, //leera desde el archivo
	 eve.categoria, eve.fecha, eve.hora, &eve.horascontratadas, &eve.km, eve.nombre_cliente,
	 eve.nombre_evento, &eve.personastotales, &eve.saldopendiente, &eve.costototal) ==12){
	 	printf("\nEvento guardado #%d\n",numero++); //aqui imprimire toda la informacion del evento
	 	printf("Cliente: %s %s\n",eve.nombre_cliente,eve.apellido_cliente);
	 	printf("Evento: %s\n",eve.nombre_evento);
	 	printf("Categoria: %s\n",eve.categoria);
	 	printf("Fecha y hora: %s, %s\n",eve.fecha,eve.hora);
	 	printf("Cantidad de personas: %d\n",eve.personastotales);
	 	printf("Costo total del evento: %.2f\n",eve.costototal);
	 	printf("Abono: %.2f\n",eve.abono);
	 	printf("Saldo pendiente: %.2f\n",eve.saldopendiente);	
	 }
	 
	do{ //esta sentencia es la que habilitara regresar al menu principal usando 9
			printf("\nPresiona 9 para regresar al menu principal: \n");
			scanf("%d",&regresar);
			
		if (regresar != 9){
			printf("Opcion no valida, intenta de nuevo\n");
		}
			
	}while(regresar!=9); //este do-while se repetira si el usuario presiona un numero diferente a 9
	 
	 fclose(archivo); //cerrar el programa
}
	//archivos binarios
void guardar_binario(evento *numeventos, int cantidad){
	FILE *archivo = fopen("agenda_eventos.bin", "ab"); // esta es la sintaxis para CREAR un archivo
	
	if(archivo ==NULL){ //seguimos esto parecido a la declaracion de las funciones de archivo de texto
	printf("ERROR, No se pudo crear el archivo \n");
	return;
	}
	
	fwrite(numeventos, sizeof(evento), cantidad, archivo); //guarda en el archivo binario
	
	fclose(archivo); //cerrar archivo
	printf("Registro binario guardado completamente\n");
}

void leer_binario(){
	system("cls");
	int numero = 1;
	int regresar;
	FILE *archivo = fopen("agenda_eventos.bin", "rb"); //dato. rb contiene b por "binario"
	evento eve;
	int contador =1;
	
	if (archivo ==NULL){
		printf("AVISO, No hay archivo binario o agenda vacia\n");
		return;
	}
	
	printf("Lectura de archivos binarios del programa\n");
		while(fread(&eve, sizeof(evento), 1, archivo)==1){ //esta es una secuencia que guardara todos los eventos registrados en el programa como archivo binario
		printf("\nEvento guardado #%d\n",numero++); //aqui imprimire toda la informacion del evento
	 	printf("Cliente: %s %s\n",eve.nombre_cliente,eve.apellido_cliente);
	 	printf("Evento: %s\n",eve.nombre_evento);
	 	printf("Categoria: %s\n",eve.categoria);
	 	printf("Fecha y hora: %s, %s\n",eve.fecha,eve.hora);
	 	printf("Cantidad de personas: %d\n",eve.personastotales);
	 	printf("Costo total del evento: %f\n",eve.costototal);
	 	printf("Abono: %f\n",eve.abono);
	 	printf("Saldo pendiente: %f\n",eve.saldopendiente);
		}
		
		do{ //esta sentencia es la que habilitara regresar al menu principal usando 9
		printf("\nPresiona 9 para regresar al menu principal: \n");
		scanf("%d",&regresar);
			
		if (regresar != 9){
			printf("Opcion no valida, intenta de nuevo\n");
		}
			
		}while(regresar!=9); //este do-while se repetira si el usuario presiona un numero diferente a 9
		
		fclose(archivo); //cerrar archivo
	}
		

void registrar_evento (){ //funcion no parametrizada para registrar el evento
	char respuesta[4]; 

	printf("Hola, Cuantos eventos quieres almacenar? \n");

	int i; //para llevar la cuenta de eventos
	int j; //esta variable sera para comparar con la i al momento de verificar disponibilidad de horario
	int horario_repetido;
	int regresar;
	scanf("%d",&cantidad);
	if(numeventos != NULL){
		free(numeventos);
	}
	
	numeventos=(evento*)malloc(cantidad* sizeof(evento));//hago uso de la memoria dinamica

	for(i = 0; i<cantidad; i++){
		system("cls"); //limpiar pantalla
		
		printf("\nIngresa tu nombre: \n"); //nombre del cliente
		scanf("%s",numeventos[i].nombre_cliente);
		
		printf("\nIngresa tu apellido: \n"); //apellido del cliente
		scanf("%s",numeventos[i].apellido_cliente);
	
		printf("\nIngrese el nombre del evento (Sin espacios): \n"); 
		scanf(" %s",numeventos[i].nombre_evento); //se guarda el nombre del evento 	
	
		do{ 
			horario_repetido = 0; //si el horario no esta ocupado da 0
			
			printf("\nIngresa la hora del evento (ej. 9:30, 18:30): \n");
			scanf(" %s",numeventos[i].hora); //hora del evento
	
			printf("\nIngresa la fecha del evento (ej. 21/6/2026): \n");
			scanf(" %s", numeventos[i].fecha); //fecha del evento
			
			for ( j = 0; j < i; j++){ //este for sera el que comparara fechas y horas y verificara si estan disponibles
			
			if(strcmp(numeventos[i].hora, numeventos[j].hora) == 0){ //compara horas usando strcmp  ya que son caracteres
				if(strcmp(numeventos[i].fecha, numeventos[j].fecha) == 0){
					printf("ERROR, fecha y hora no disponible, ya ha sido utilizada \n");
					horario_repetido = 1; //como la fecha esta ocupada, horario_repetido es igual a 1
					break; 
				}	
			}
				
			}
		}while(horario_repetido == 1); //si el horario es repetido se vuelve a repetir la asignasion de fecha y hora del evento
	
		printf("\nIngresa los kilometros que se recorreran hacia el lugar del evento (solo el numero): \n");
		scanf(" %f", &numeventos[i].km); //km recorridos
		
		printf("\nIngresa el numero de horas a contratar (1, 2, 3, etc.): \n"); //horas contratadas
		scanf("%d",&numeventos[i].horascontratadas);
		
		printf("\nIngresa la categoria del evento (publico, privado u otro): \n");  //categoria del evento
		scanf(" %s",numeventos[i].categoria);
		
		printf("\nIngresa la cantidad de personas que asistiran al evento: \n"); //dependiendo de la cantidad de personas se establecera la tarifa base
		scanf("%d",&numeventos[i].personastotales);
			if(numeventos[i].personastotales<100){
			tarifa_base = tarifas[0];	//hago uso de los arreglos unidimensionales definidos anteriormente
			}
			else if(numeventos[i].personastotales<=1000){
			tarifa_base = tarifas[1];
			}
			else{
			tarifa_base = tarifas[2];
			}
		
		numeventos[i].costototal = calcularcosto_evento(numeventos[i].horascontratadas, tarifa_base, numeventos[i].km, VIATICOS);
		printf("\nEl total del evento es: %.2f\n",numeventos[i].costototal); 
		
		do{ //sentencia para descartar un abono con cantidades negativas
		printf("\nIngresa el abono proporcionado por el cliente (si no dio abono, escribir 0): \n");
		scanf(" %f", &numeventos[i].abono);
			if(numeventos[i].abono<0){
			printf("Error, cantidad negativa \n");	
			}
		}while(numeventos[i].abono<0); //solo se ejecutara si abono < 0
		
		numeventos[i].saldopendiente = calcularsaldo_restante(numeventos[i].costototal, numeventos[i].abono);
		printf("Saldo pendiente: %f",numeventos[i].saldopendiente);
		
		printf("\nEVENTO REGISTRADO CON EXITO! (la informacion del evento se encuentra en consultar agenda). \n\n");
			
		system("pause"); //utilizo la funcion de pausa como mejora del sistema	
		}
		printf("\nDesea guardar los archivos de texto y binario?(si/no) \n");
		scanf("%s",respuesta);
			if (strcmp(respuesta, "si") == 0){
			guardar_archivotexto(numeventos, cantidad); //LLAMO las funciones que guardaran la informacion en archivo
			guardar_binario(numeventos, cantidad);
			printf("\nGuardado correctamente\n");
		}
		
		do{ //esta sentencia es la que habilitara regresar al menu principal usando 9
			printf("\nPresiona 9 para regresar al menu principal: \n");
			scanf("%d",&regresar);
			
			if (regresar != 9){
				printf("Opcion no valida, intenta de nuevo\n");
			}
			
		} while(regresar!=9); //este do-while se repetira si el usuario presiona un numero diferente a 9
		
}

void consultar_agenda(){
	int i;
	system("cls");
	int regresar;
	FILE *archivo = fopen("agenda_eventos.txt", "r"); //como primero creamos el archivo con a, ahora con r leemos el mismo archivo
	int numero = 1;
	 evento eve; //eve es como llamamos a esa estructura
	 int contador =1; //servira para contar las veces que se repite la sentencia
	 
	 if(archivo == NULL){
	 	printf("No hay archivo, agenda vacia\n");//este if nos ayudara a que si el archivo a registrar no contiene nada, volver de nuevo
	 	return;
	 }
	 
	 //imprimir datos
	 printf("AGENDA DE EVENTOS PROGRAMADOS\n");
	 while(fscanf(archivo, "%f %s %s %s %s %d %f %s %s %d %f %f", &eve.abono, eve.apellido_cliente, //leera desde el archivo
	 eve.categoria, eve.fecha, eve.hora, &eve.horascontratadas, &eve.km, eve.nombre_cliente,
	 eve.nombre_evento, &eve.personastotales, &eve.saldopendiente, &eve.costototal) ==12){
	 	printf("\nEvento guardado #%d\n",numero++); //aqui imprimire toda la informacion del evento
	 	printf("Cliente: %s %s\n",eve.nombre_cliente,eve.apellido_cliente);
	 	printf("Evento: %s\n",eve.nombre_evento);
	 	printf("Categoria: %s\n",eve.categoria);
	 	printf("Fecha y hora: %s, %s\n",eve.fecha,eve.hora);
	 	printf("Cantidad de personas: %d\n",eve.personastotales);
	 	printf("Costo total del evento: %.2f\n",eve.costototal);
	 	printf("Abono: %.2f\n",eve.abono);
	 	printf("Saldo pendiente: %.2f\n",eve.saldopendiente);	
	 }
	 
	do{ //esta sentencia es la que habilitara regresar al menu principal usando 9
			printf("\nPresiona 9 para regresar al menu principal: \n");
			scanf("%d",&regresar);
			
		if (regresar != 9){
			printf("Opcion no valida, intenta de nuevo\n");
		}
			
	}while(regresar!=9); //este do-while se repetira si el usuario presiona un numero diferente a 9
	 
	 fclose(archivo); //cerrar el programa
}

 
int main(){
	int opcion;
	
		do{ //estructura repetitiva
		opcion = indice();
		
			switch(opcion){ //uso de estructura selectiva switch
			
		case 1:
			registrar_evento();
			break;
		case 2:
			consultar_agenda();
			system("pause"); //haciendo uso de las sugerencias
			break;
		case 3:
			leer_archivotexto(); //leer el archivo de tipo texto
			system("pause");
			break;
		case 4:
			leer_binario(); //leer el archivo en binario
			system("pause");
			break;
		case 0:
			printf("Gracias por utilizar el sistema:) \n");

			free(numeventos);
			system("pause"); //de nuevo utiliando una sugerencia para el programa
			break;
		default:
			printf("Opcion no disponible, vuelve a intentarlo. \n");
			break;
		}
	}while(opcion!=0);
	
	return 0;
}
	

