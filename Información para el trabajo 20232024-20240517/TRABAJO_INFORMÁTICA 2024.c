#include <stdio.h>
#include <math.h>
#include <locale.h>


typedef struct {
    int hora;
    char Hora[5];
    int NO2;
    char no2[5];
    float PM25;
    char pm25[5];
    float PM10;
    char pm10[5];
    char cal_aire[30];
    char calidades[20];
}TMendezAlvaro;

typedef struct {
    int hora;
    char Hora[5];
    float T;
    char temperatura[15];
    int HR;
    char humedad[10];
}TEscuelasAguirre;


//FUNCIONES MOSTRAR FICHEROS Y MENUS
int mostrarArchivo1(TMendezAlvaro vectorMA[]);
int mostrarArchivo2(TMendezAlvaro vectorMA[]);
int mostrarArchivo3(TMendezAlvaro vectorMA[]);
int mostrarArchivo4(TEscuelasAguirre vectorEA[]);
int mostrarArchivo5(TEscuelasAguirre vectorEA[]);
int mostrarArchivo6(TEscuelasAguirre vectorEA[]);
void mostrarMenuMA(TMendezAlvaro vectorMA[], int size);

//FUNCIONES INFORMACIÓN
void mostrarBOE_1(char *BOE_calidaddeaire);
void mostrarBOE_2(char *BOE_recomendaciones);
void mostrarBOE_3(char *BOE_accesibilidad);

//FUNCIONES ESTADÍSTICAS
void calculomediasMA(TMendezAlvaro vectorMA[], int i);
void calculoNO2max(TMendezAlvaro vectorMA[], int contador);
void calculoPM25max(TMendezAlvaro vectorMA[], int contador);
void calculoPM10max(TMendezAlvaro vectorMA[], int contador);
void calculoNO2min(TMendezAlvaro vectorMA[], int contador);
void calculoPM25min(TMendezAlvaro vectorMA[], int contador);
void calculoPM10min(TMendezAlvaro vectorMA[], int contador);
void calculoMedianaMA(TMendezAlvaro vectorMA[], int contador);

void calculomediasEA(TEscuelasAguirre vectorEA[], int i);
void calculoTmax(TEscuelasAguirre vectroEA[], int contador);
void calculoHRmax(TEscuelasAguirre vectorEA[], int contador);
void calculoTmin(TEscuelasAguirre vectorEA[], int contador);
void calculoHRmin(TEscuelasAguirre vectorEA[], int contador);
void calculoMedianaEA(TEscuelasAguirre vectorMA[], int contador);

void Modano2( TMendezAlvaro vectorMA[], int contador);
void ModaPM25(TMendezAlvaro vectorMA[], int contador);
void ModaPM10(TMendezAlvaro vectorMA[], int contador);
void ModaT(TEscuelasAguirre vectorEA[], int contador);
void ModaHR(TEscuelasAguirre vectorEA[], int contador);

//FUNCIONES COMPARACIÓN
void fordTEA(TEscuelasAguirre vectorEA[], int contador);
void fordT2EA(TEscuelasAguirre vectorEA[], int contador);
void fordHR2EA(TEscuelasAguirre vectorEA[], int contador);
void fordHREA(TEscuelasAguirre vectorEA[], int contador);
void fordMA(TMendezAlvaro vectorMA[], int contador);
void ford2MA(TMendezAlvaro vectorMA[], int contador);

void fcompararME(TMendezAlvaro vectorMA[], int contador);
void fcompararEA(TEscuelasAguirre vectorEA[], int contador);
																												//Marcos: Buscar por horas
void DatosHoraME(TMendezAlvaro vectorMA[], int contador); 


int main() {
    setlocale(LC_CTYPE, "spanish"); // para que el compilador reconozca las ñ y tildes 
    int archivo, opcion, contador = 0, TAM = 25;
    TMendezAlvaro vectorMA[TAM];
    TEscuelasAguirre vectorEA[TAM];
	int horaBuscada;
	int numHora=0;
    
    while (1) {
		printf("\t\t\t****** INDICE DE CALIDAD DEL AIRE ******\t\t\t\n");
		printf ("\nIndique el archivo con el que quiera trabajar:\n\n\t1.Mendez Álvaro 20-12-2023\n \t2.Mendez Álvaro 31-01-2024\n \t3.Mendez Álvaro 21-02-2024\n \t4.Escuelas Aguirre 20-12-2023\n \t5.Escuelas Aguirre 31-01-2024\n \t6.Escuelas Aguirre 21-02-2024\n");
		scanf ("%d", &archivo);
		
		if (archivo < 1 || archivo > 6) {
			printf ("Lo siento, pero tiene que introducir un número válido.\n");
		} else {
			break;
		}
	}
	
	switch (archivo){
		//archivo1
		case (1):{
			int i;
			contador = mostrarArchivo1(vectorMA);
			
			do{
				mostrarMenuMA(vectorMA, TAM);
				scanf("%d", &opcion);
				
				if (opcion == 1){
				
				} else if (opcion == 2){
					int Opcion;
				
					do { 
    				printf("\nElige una opción que desee\n");
    				printf("\t1: Media \n");
    				printf("\t2: Mediana \n");
    				printf("\t3: Moda \n");
    				printf("\t4: Mínimos valores \n");
    				printf("\t5: Máximos valores \n");
    				printf("\t6: Salir de estadísticas.\n");
    				scanf("%d", &Opcion);
					//otro switch case dentro
					switch(Opcion){
						case(1): {
							//MEDIA
						calculomediasMA(vectorMA, contador);
					
							break;
						}
						case(2):{
							//MEDIANA
						calculoMedianaMA(vectorMA, contador);
							break;
						}
						case(3):{
							//MODA
							Modano2(vectorMA, contador);
							ModaPM25(vectorMA, contador);
							ModaPM10(vectorMA, contador);
							break;
						}
						case(4):{
							calculoNO2min(vectorMA, contador);
							calculoPM25min(vectorMA, contador);
							calculoPM10min(vectorMA, contador);
							break;
						}
						case(5): {
							
							calculoNO2max(vectorMA, contador);
							calculoPM25max(vectorMA, contador);
							calculoPM10max(vectorMA, contador);
							break;
						}
					}
    				} while (Opcion != 6);
    		
				} else if (opcion == 3){
					//FUNCION 3
					int Opcion3;
					do { 
    				printf("\nElige una opción que desee\n");
    				printf("\t1: Buscar una fuente concreta \n");
    				printf("\t2: Valor mínimo entre ficheros\n");
    				printf("\t3: Ordenar de menor a mayor \n");
    				printf("\t4: Ordenar de mayor a menor \n");
    				printf("\t5: Comparar valores de 2 horas\n");
    				printf("\t6: Salir de comparaciones.\n");
    				scanf("%d", &Opcion3);
    				switch(Opcion3){
						case(1): {
							int horaBuscada;
							int numHora=0;
							DatosHoraME( vectorMA,  contador);
							break;
						}
						case(2): {
						
							break;
						}
						case(3):{
							fordMA(vectorMA, contador);

							break;
						}
						case(4): {
							ford2MA(vectorMA, contador);
							
							break;
						}
						case(5): {
								fcompararME(vectorMA, contador);
							break;
						}
					}
    				} while (Opcion3 != 6);
				} else if (opcion == 4){
					//FUNCION 4
					int Opcion4;
					do { 
    				printf("\nElige una opción que desee saber sobre la calidad del aire\n");
    				printf("\t1: ¿Qué es el índice de calidad? \n");
    				printf("\t2: Recomendaciones para la salud \n");
    				printf("\t3: ¿Dónde encontrar más información? \n");
    				printf("\t4: Salir de información.\n");
    				scanf("%d", &Opcion4);
    				switch(Opcion4){
						case(1): {
						//fichero BOE_calidaddeaire
							mostrarBOE_1("BOE_calidaddeaire.txt");
							break;
						}
						case(2): {
						//fichero BOE_recomendaciones
							mostrarBOE_2("BOE_recomendaciones.txt");	
							break;
						}
						case(3):{
						//fichero BOE_accesibilidad
							mostrarBOE_3("BOE_accesibilidad.txt");
							break;
						}
					}
    				} while (Opcion4 != 4);
				} else if (opcion == 5){
					//FUNCION 5
					float mediaNO2 = 0.0, mediaPM25 = 0.0, mediaPM10 = 0.0;
			
					int m, Opcion5;
					for (m = 0; m < contador; m++) {
						mediaNO2 += vectorMA[m].NO2;
						mediaPM25 += vectorMA[m].PM25;
						mediaPM10 += vectorMA[m].PM10;
					}
					
					mediaNO2 /=  contador;
					mediaPM25 /=  contador;
					mediaPM10 /= contador;
					
					printf("\nLímite diario NO2 = 40 microgramos/m^3\n");
					if(mediaNO2 < 40|| mediaNO2 >=37.5){
						printf("Como la media del NO2 es %.3f la calidad del aire con respecto a la concentración de NO2 es regular, debido a su cercanía con el valor límite\n", mediaNO2);
					} else if(mediaNO2 < 37.5){
						printf("Como la media del NO2 es %.3f la calidad del aire con respecto a la concentración de NO2 es buena, debido a que está muy por debajo del valor límite\n", mediaNO2);
					} else if(mediaNO2 == 40){
						printf("La media del NO2 es de %.3f\t¡¡¡ESTAS EN EL LÍMITE DIARIO!!!\n");
					} else if (mediaNO2 > 40){
						printf("Como la media es de %.3f la calidad del aire con respecto a la concentración de NO2 es bastante desfavorable", mediaNO2);
					}
					
					
						printf("\n¿Quieres saber las posibles consecuencias de superar el límite diario?\n");
						printf("1. Sí, quiero saber más\n2. Salir\n");
						scanf("%d", &Opcion5);
						
						if(Opcion5 == 1){
							printf("\nCONSECUENCIAS PARA EL SER HUMANO\n-Provocar enfermedades en el aparato respiratorio (Bronquitis, Pulmonía)\n-Afecciones directas en bebés recién nacidos (Bajo peso al nacer, mayor probabilidad de parto prematura)\n");
							printf("\nCONSECUENCIAS PARA EL MEDIOAMBIENTE\n-Aumento de la llúvia ácida\n-Formación de ozono y smog");
						} else if(Opcion5 == 2){
							printf("Volviendo al menú...");
						}
				}
				
			} while (opcion < 6);
			
				if(opcion == 6){
					printf("Hasta la próxima\n"); 
					printf("FIN DEL PROGRAMA");
					return 0;
				}
				
			break;
		}
		
		case (2):{
			int i;
			contador = mostrarArchivo2(vectorMA);
			
			do{
				mostrarMenuMA(vectorMA, TAM);
				scanf("%d", &opcion);
				
				if (opcion == 1){
					//FUNCION 1
				} else if (opcion == 2){
					int Opcion;
				
					do { 
    				printf("\nElige una opción que desee\n");
    				printf("\t1: Media \n");
    				printf("\t2: Mediana \n");
    				printf("\t3: Moda \n");
    				printf("\t4: Mínimos valores \n");
    				printf("\t5: Máximos valores \n");
    				printf("\t6: Salir de estadísticas.\n");
    				scanf("%d", &Opcion);
					//otro switch case dentro
					switch(Opcion){
						case(1): {
							//MEDIA
						calculomediasMA(vectorMA, contador);
					
							break;
						}
						case(2):{
							//MEDIANA
							calculoMedianaMA(vectorMA, contador);

							break;
						}
						case(3):{
							//MODA
							Modano2(vectorMA, contador);
							ModaPM25(vectorMA, contador);
							ModaPM10(vectorMA, contador);
							break;
						}
						case(4):{
							calculoNO2min(vectorMA, contador);
							calculoPM25min(vectorMA, contador);
							calculoPM10min(vectorMA, contador);

							break;
						}
						case(5): {
							calculoNO2max(vectorMA, contador);
							calculoPM25max(vectorMA, contador);
							calculoPM10max(vectorMA, contador);
							break;
						}
					}
    				} while (Opcion != 6);
				} else if (opcion == 3){
					//FUNCION 3
					int Opcion3;
					do { 
    				printf("\nElige una opción que desee\n");
    				printf("\t1: Valor máximo entre ficheros \n");
    				printf("\t2: Valor mínimo entre ficheros\n");
    				printf("\t3: Ordenar de menor a mayor \n");
    				printf("\t4: Ordenar de mayor a menor \n");
    				printf("\t5: Comparar valores de 2 horas\n");
    				printf("\t6: Salir de comparaciones.\n");
    				scanf("%d", &Opcion3);
    				switch(Opcion3){
						case(1): {
						
							break;
						}
						case(2): {
						
							break;
						}
						case(3):{
							fordMA(vectorMA, contador);

							break;
						}
						case(4): {
							ford2MA(vectorMA, contador);
							
							break;
						}case(5): {
							fcompararME(vectorMA, contador);
							break;
						}
					}
    				} while (Opcion3 != 6);
				} else if (opcion == 4){
					//FUNCION 4
					int Opcion4;
					do { 
    				printf("\nElige una opción que desee saber sobre la calidad del aire\n");
    				printf("\t1: ¿Qué es el índice de calidad? \n");
    				printf("\t2: Recomendaciones para la salud \n");
    				printf("\t3: ¿Dónde encontrar más información? \n");
    				printf("\t4: Salir de información.\n");
    				scanf("%d", &Opcion4);
    				switch(Opcion4){
						case(1): {
						//fichero BOE_calidaddeaire
							mostrarBOE_1("BOE_calidaddeaire.txt");
							break;
						}
						case(2): {
						//fichero BOE_recomendaciones
							mostrarBOE_2("BOE_recomendaciones.txt");	
							break;
						}
						case(3):{
						//fichero BOE_accesibilidad
							mostrarBOE_3("BOE_accesibilidad.txt");
							break;
						}
					}
    				} while (Opcion4 != 4);
				} else if (opcion == 5){
					//FUNCION 5
				}
			} while (opcion < 6);
			
				if(opcion == 6){
					printf("Hasta la próxima\n"); 
					printf("FIN DEL PROGRAMA");
					return 0;
				}
			break;
		}
		
		case (3):{
			int i;
			contador = mostrarArchivo3(vectorMA);
			
			do{
				mostrarMenuMA(vectorMA, TAM);
				scanf("%d", &opcion);
				
				if (opcion == 1){
					//FUNCION 1
				} else if (opcion == 2){
					int Opcion;
				
					do { 
    				printf("\nElige una opción que desee\n");
    				printf("\t1: Media \n");
    				printf("\t2: Mediana \n");
    				printf("\t3: Moda \n");
    				printf("\t4: Mínimos valores \n");
    				printf("\t5: Máximos valores \n");
    				printf("\t6: Salir de estadísticas.\n");
    				scanf("%d", &Opcion);
					//otro switch case dentro
					switch(Opcion){
						case(1): {
							//MEDIA
						calculomediasMA(vectorMA, contador);
					
							break;
						}
						case(2): {
							//MEDIANA
						calculoMedianaMA(vectorMA, contador);

							break;
						}
						case(3):{
							Modano2(vectorMA, contador);
							ModaPM25(vectorMA, contador);
							ModaPM10(vectorMA, contador);
							break;
						}
						case(4):{
							calculoNO2min(vectorMA, contador);
							calculoPM25min(vectorMA, contador);
							calculoPM10min(vectorMA, contador);
							

							break;
						}
						case(5): {
							calculoNO2max(vectorMA, contador);
							calculoPM25max(vectorMA, contador);
							calculoPM10max(vectorMA, contador);
							
							break;
						}
					}
    				} while (Opcion != 6);
				} else if (opcion == 3){
					//FUNCION 3
					int Opcion3;
					do { 
    				printf("\nElige una opción que desee\n");
    				printf("\t1: Valor máximo entre ficheros \n");
    				printf("\t2: Valor mínimo entre ficheros\n");
    				printf("\t3: Ordenar de menor a mayor \n");
    				printf("\t4: Ordenar de mayor a menor \n");
    				printf("\t5: Comparar valores de 2 horas\n");
    				printf("\t6: Salir de comparaciones.\n");
    				scanf("%d", &Opcion3);
    				switch(Opcion3){
						case(1): {
						
							break;
						}
						case(2): {
						
							break;
						}
						case(3):{
							fordMA(vectorMA, contador);

							break;
						}
						case(4): {
							ford2MA(vectorMA, contador);
							
							break;
						}case(5): {
							fcompararME(vectorMA, contador);
							break;
						}
					}
    				} while (Opcion3 != 6);
				} else if (opcion == 4){
					//FUNCION 4
					int Opcion4;
					do { 
    				printf("\nElige una opción que desee saber sobre la calidad del aire\n");
    				printf("\t1: ¿Qué es el índice de calidad? \n");
    				printf("\t2: Recomendaciones para la salud \n");
    				printf("\t3: ¿Dónde encontrar más información? \n");
    				printf("\t4: Salir de información.\n");
    				scanf("%d", &Opcion4);
    				switch(Opcion4){
						case(1): {
						//fichero BOE_calidaddeaire
							mostrarBOE_1("BOE_calidaddeaire.txt");
							break;
						}
						case(2): {
						//fichero BOE_recomendaciones
							mostrarBOE_2("BOE_recomendaciones.txt");	
							break;
						}
						case(3):{
						//fichero BOE_accesibilidad
							mostrarBOE_3("BOE_accesibilidad.txt");
							break;
						}
					}
    				} while (Opcion4 != 4);
				} else if (opcion == 5){
					//FUNCION 5
				}
			} while (opcion < 6);
			
				if(opcion == 6){
					printf("Hasta la próxima\n"); 
					printf("FIN DEL PROGRAMA");
					return 0;
				}
			break;
		}
		
		case (4):{
			int i, a;
			contador = mostrarArchivo4(vectorEA);
			
			do{
				mostrarMenuMA(vectorMA, TAM);
				scanf("%d", &opcion);
				
				if (opcion == 1){
					//FUNCION 1
				} else if (opcion == 2){
					int Opcion;
					do { 
    				printf("\nElige una opción que desee\n");
    				printf("\t1: Media \n");
    				printf("\t2: Mediana \n");
    				printf("\t3: Moda \n");
    				printf("\t4: Mínimos valores \n");
    				printf("\t5: Máximos valores \n");
    				printf("\t6: Salir de estadísticas.\n");
    				scanf("%d", &Opcion);
					//otro switch case dentro
					switch(Opcion){
						case(1): {
							//MEDIA
						calculomediasEA(vectorEA, contador);
					
							break;
						}
						case(2): {
							//MEDIANA
						calculoMedianaEA(vectorEA, contador);
							break;
						}
						case(3): {
							//MODA
							ModaT(vectorEA, contador);
							ModaHR(vectorEA, contador);
							break;
						}
						case(4):{
							calculoTmin(vectorEA, contador);
							calculoHRmin(vectorEA, contador);

							break;
						}
						case(5): {
							calculoTmax(vectorEA, contador);
							calculoHRmax(vectorEA, contador);						
							
							break;
						}
					}
    				} while (Opcion != 6);
				} else if (opcion == 3){
					//FUNCION 3
					int Opcion3;
					do { 
    				printf("\nElige una opción que desee\n");
    				printf("\t1: Valor máximo entre ficheros \n");
    				printf("\t2: Valor mínimo entre ficheros\n");
    				printf("\t3: Ordenar de menor a mayor \n");
    				printf("\t4: Ordenar de mayor a menor \n");
    				printf("\t5: Comparar valores de 2 horas\n");
    				printf("\t6: Salir de comparaciones.\n");
    				scanf("%d", &Opcion3);
    				switch(Opcion3){
						case(1): {
						
							break;
						}
						case(2): {
						
							break;
						}
						case(3):{
							printf("Temperatura 1 , humedad 2\n");
							scanf("%i",&a);
							if(a==1){
								fordTEA(vectorEA, contador);
							} else if (a==2) {
								fordHREA(vectorEA, contador);
							}

							break;
						}
						case(4): {
							printf("Temperatura 1 , humedad 2\n");
							scanf("%i",&a);
							if(a==1){
								fordT2EA(vectorEA, contador);
							} else if (a==2) {
								fordHR2EA(vectorEA, contador);
							}						
							
							break;
							
						}case(5): {
							fcompararEA(vectorEA, contador);
							break;
						}
					}
    				} while (Opcion3 != 6);
				} else if (opcion == 4){
					//FUNCION 4
					int Opcion4;
					do { 
    				printf("\nElige una opción que desee saber sobre la calidad del aire\n");
    				printf("\t1: ¿Qué es el índice de calidad? \n");
    				printf("\t2: Recomendaciones para la salud \n");
    				printf("\t3: ¿Dónde encontrar más información? \n");
    				printf("\t4: Salir de información.\n");
    				scanf("%d", &Opcion4);
    				switch(Opcion4){
						case(1): {
						//fichero BOE_calidaddeaire
							mostrarBOE_1("BOE_calidaddeaire.txt");
							break;
						}
						case(2): {
						//fichero BOE_recomendaciones
							mostrarBOE_2("BOE_recomendaciones.txt");	
							break;
						}
						case(3):{
						//fichero BOE_accesibilidad
							mostrarBOE_3("BOE_accesibilidad.txt");
							break;
						}
					}
    				} while (Opcion4 != 4);
				} else if (opcion == 5){
					//FUNCION 5
				}
			} while (opcion < 6);
			
				if(opcion == 6){
					printf("Hasta la próxima\n"); 
					printf("FIN DEL PROGRAMA");
					return 0;
				}
			break;
		}
		
		case (5):{
			int i, a;
			contador = mostrarArchivo5(vectorEA);
			
			do{
				mostrarMenuMA(vectorMA, TAM);
				scanf("%d", &opcion);
				
				if (opcion == 1){
					//FUNCION 1
				} else if (opcion == 2){
					int Opcion;
					do { 
    				printf("\nElige una opción que desee\n");
    				printf("\t1: Media \n");
    				printf("\t2: Mediana \n");
    				printf("\t3: Moda \n");
    				printf("\t4: Mínimos valores \n");
    				printf("\t5: Máximos valores \n");
    				printf("\t6: Salir de estadísticas.\n");
    				scanf("%d", &Opcion);
					//otro switch case dentro
					switch(Opcion){
						case(1): {
							//MEDIA
						calculomediasEA(vectorEA, contador);
					
							break;
						}
						case(2): {
							//MEDIANA
						calculoMedianaEA(vectorEA, contador);

							break;
						}
						case(3): {
							//MODA
							ModaT(vectorEA, contador);
							ModaHR(vectorEA, contador);
							break;
						}
						case(4):{
							calculoTmin(vectorEA, contador);
							calculoHRmin(vectorEA, contador);

							break;
						}
						case(5): {
							calculoTmax(vectorEA, contador);
							calculoHRmax(vectorEA, contador);						
							
							break;
						}
					}
    				} while (Opcion != 6);
				} else if (opcion == 3){
					//FUNCION 3
					int Opcion3;
					do { 
    				printf("\nElige una opción que desee\n");
    				printf("\t1: Valor máximo entre ficheros \n");
    				printf("\t2: Valor mínimo entre ficheros\n");
    				printf("\t3: Ordenar de menor a mayor \n");
    				printf("\t4: Ordenar de mayor a menor \n");
    				printf("\t5: Comparar valores de 2 horas\n");
    				printf("\t6: Salir de comparaciones.\n");
    				scanf("%d", &Opcion3);
    				switch(Opcion3){
						case(1): {
						
							break;
						}
						case(2): {
						
							break;
						}
						case(3):{
							printf("Temperatura 1 , humedad 2\n");
							scanf("%i",&a);
							if(a==1){
								fordTEA(vectorEA, contador);
							} else if (a==2) {
								fordHREA(vectorEA, contador);
							}

							break;
						}
						case(4): {
							printf("Temperatura 1 , humedad 2\n");
							scanf("%i",&a);
							if(a==1){
								fordT2EA(vectorEA, contador);
							} else if (a==2) {
								fordHR2EA(vectorEA, contador);
							}
							
							break;
						}case(5): {
							fcompararEA(vectorEA, contador);
							break;
						}
					}
    				} while (Opcion3 != 6);
				} else if (opcion == 4){
					//FUNCION 4
					int Opcion4;
					do { 
    				printf("\nElige una opción que desee saber sobre la calidad del aire\n");
    				printf("\t1: ¿Qué es el índice de calidad? \n");
    				printf("\t2: Recomendaciones para la salud \n");
    				printf("\t3: ¿Dónde encontrar más información? \n");
    				printf("\t4: Salir de información.\n");
    				scanf("%d", &Opcion4);
    				switch(Opcion4){
						case(1): {
						//fichero BOE_calidaddeaire
							mostrarBOE_1("BOE_calidaddeaire.txt");
							break;
						}
						case(2): {
						//fichero BOE_recomendaciones
							mostrarBOE_2("BOE_recomendaciones.txt");	
							break;
						}
						case(3):{
						//fichero BOE_accesibilidad
							mostrarBOE_3("BOE_accesibilidad.txt");
							break;
						}
					}
    				} while (Opcion4 != 4);
				} else if (opcion == 5){
					//FUNCION 5
					
				}
			} while (opcion < 6);
			
				if(opcion == 6){
					printf("Hasta la próxima\n"); 
					printf("FIN DEL PROGRAMA");
					return 0;
				}
			break;
		}
		
		case (6):{
			int i,a;
			contador = mostrarArchivo6(vectorEA);
			
			do{
				mostrarMenuMA(vectorMA, TAM);
				scanf("%d", &opcion);
				
				if (opcion == 1){
					//FUNCION 1
				} else if (opcion == 2){
					int Opcion;
					do { 
    				printf("\nElige una opción que desee\n");
    				printf("\t1: Media \n");
    				printf("\t2: Mediana \n");
    				printf("\t3: Moda \n");
    				printf("\t4: Mínimos valores \n");
    				printf("\t5: Máximos valores \n");
    				printf("\t6: Salir de estadísticas.\n");
    				scanf("%d", &Opcion);
					//otro switch case dentro
					switch(Opcion){
						case(1): {
							//MEDIA
						calculomediasEA(vectorEA, contador);
					
							break;
						}
						case(2): {
							//MEDIANA
						calculoMedianaEA(vectorEA, contador);

							break;
						}
						case(3): {
							//MODA
							ModaT(vectorEA, contador);
							ModaHR(vectorEA, contador);
							break;
						}
						case(4):{
							calculoTmin(vectorEA, contador);
							calculoHRmin(vectorEA, contador);

							break;
						}
						case(5): {
							calculoTmax(vectorEA, contador);
							calculoHRmax(vectorEA, contador);						
							
							break;
						}
					break;
					}
    				} while (Opcion != 6);
				} else if (opcion == 3){
					//FUNCION 3
					int Opcion3;
					do { 
    				printf("\nElige una opción que desee\n");
    				printf("\t1: Valor máximo entre ficheros \n");
    				printf("\t2: Valor mínimo entre ficheros\n");
    				printf("\t3: Ordenar de menor a mayor \n");
    				printf("\t4: Ordenar de mayor a menor \n");
    				printf("\t5: Comparar valores de 2 horas\n");
    				printf("\t6: Salir de comparaciones.\n");
    				scanf("%d", &Opcion3);
    				switch(Opcion3){
						case(1): {
						
							break;
						}
						case(2): {
						
							break;
						}
						case(3):{
							printf("Temperatura 1 , humedad 2\n");
							scanf("%i",&a);
							if(a==1){
								fordTEA(vectorEA, contador);
							} else if (a==2) {
								fordHREA(vectorEA, contador);
							}
							break;
						}
						case(4): {
							printf("Temperatura 1 , humedad 2\n");
							scanf("%i",&a);
							if(a==1){
								fordT2EA(vectorEA, contador);
							} else if (a==2) {
								fordHR2EA(vectorEA, contador);
							}						
							
							break;
						}case(5): {
							fcompararEA(vectorEA, contador);
							break;
						}
					}
    				} while (Opcion3 != 6);
				} else if (opcion == 4){
					//FUNCION 4
					int Opcion4;
					do { 
    				printf("\nElige una opción que desee saber sobre la calidad del aire\n");
    				printf("\t1: ¿Qué es el índice de calidad? \n");
    				printf("\t2: Recomendaciones para la salud \n");
    				printf("\t3: ¿Dónde encontrar más información? \n");
    				printf("\t4: Salir de información.\n");
    				scanf("%d", &Opcion4);
    				switch(Opcion4){
						case(1): {
						//fichero BOE_calidaddeaire
							mostrarBOE_1("BOE_calidaddeaire.txt");
							break;
						}
						case(2): {
						//fichero BOE_recomendaciones
							mostrarBOE_2("BOE_recomendaciones.txt");	
							break;
						}
						case(3):{
						//fichero BOE_accesibilidad
							mostrarBOE_3("BOE_accesibilidad.txt");
							break;
						}
					}
    				} while (Opcion4 != 4);
				} else if (opcion == 5){
					//FUNCION 5
				}
			} while (opcion < 6);
			
				if(opcion == 6){
					printf("Hasta la próxima\n"); 
					printf("FIN DEL PROGRAMA");
					return 0;
				}
			break;
		}
	}	
	
    return 0;
}






int mostrarArchivo1(TMendezAlvaro vectorMA[]) {
	
	FILE*fichero;
	int contador = 0;
	
	printf("\nHa seleccionado la opción 1\n");
   	fichero = fopen("20122023_MendezAlvaro.txt", "r");
   	
    if (fichero == NULL) {
        printf("\nError al abrir el archivo 20122023_MendezAlvaro.txt\n");
        return 0;
    } else{	       
   	 printf("Fichero de datos 20122023_MendezAlvaro.txt cargado exitosamente\n");
	}
    
    	int y = 0;
	while(fscanf(fichero, "%s %s %s %s %s", vectorMA[y].Hora, vectorMA[y].no2, vectorMA[y].pm25, vectorMA[y].pm10, vectorMA[y].calidades) != '\n'){
		printf("%s\t %s\t %s\t %s\t %s\n", vectorMA[y].Hora, vectorMA[y].no2, vectorMA[y].pm25, vectorMA[y].pm10, vectorMA[y].calidades);
		y++;
		break;
	}
			
	int i = 0;
	while (fscanf(fichero, "%d %d %f %f %s", &vectorMA[i].hora, &vectorMA[i].NO2, &vectorMA[i].PM25, &vectorMA[i].PM10, vectorMA[i].cal_aire) != EOF) {
		printf("%d\t %d\t %.3f\t %.3f\t %s\n", vectorMA[i].hora, vectorMA[i].NO2, vectorMA[i].PM25, vectorMA[i].PM10, vectorMA[i].cal_aire);
		i++;
	}
	
	contador = i;

	fclose(fichero);
	
	return contador;
}

int mostrarArchivo2(TMendezAlvaro vectorMA[]) {
	
	FILE*fichero;
	int contador = 0;
	
	printf("\nHa seleccionado la opción 2\n");
   	fichero = fopen("31012024_MendezAlvaro.txt", "r");
   	
    if (fichero == NULL) {
        printf("\nError al abrir el archivo 31012024_MendezAlvaro.txt\n");
        return 0;
    } else{	       
   	 printf("Fichero de datos 31012024_MendezAlvaro.txt cargado exitosamente\n");
	}
    
    	int y = 0;
	while(fscanf(fichero, "%s %s %s %s %s", vectorMA[y].Hora, vectorMA[y].no2, vectorMA[y].pm25, vectorMA[y].pm10, vectorMA[y].calidades) != '\n'){
		printf("%s\t %s\t %s\t %s\t %s\n", vectorMA[y].Hora, vectorMA[y].no2, vectorMA[y].pm25, vectorMA[y].pm10, vectorMA[y].calidades);
		y++;
		break;
	}
			
	int i = 0;
	while (fscanf(fichero, "%d %d %f %f %s", &vectorMA[i].hora, &vectorMA[i].NO2, &vectorMA[i].PM25, &vectorMA[i].PM10, vectorMA[i].cal_aire) != EOF) {
		printf("%d\t %d\t %.3f\t %.3f\t %s\n", vectorMA[i].hora, vectorMA[i].NO2, vectorMA[i].PM25, vectorMA[i].PM10, vectorMA[i].cal_aire);
		i++;
	}
	
	contador = i;
	fclose(fichero);
	
	return contador;
}

int mostrarArchivo3(TMendezAlvaro vectorMA[]) {
	
	FILE*fichero;
	int contador = 0;
	
	printf("\nHa seleccionado la opción 3\n");
   	fichero = fopen("21022024_MendezAlvaro.txt", "r");
   	
    if (fichero == NULL) {
        printf("\nError al abrir el archivo 21022024_MendezAlvaro.txt\n");
        return 0;
    } else{	       
   	 printf("Fichero de datos 21022024_MendezAlvaro.txt cargado exitosamente\n");
	}
    
    	int y = 0;
	while(fscanf(fichero, "%s %s %s %s %s", vectorMA[y].Hora, vectorMA[y].no2, vectorMA[y].pm25, vectorMA[y].pm10, vectorMA[y].calidades) != '\n'){
		printf("%s\t %s\t %s\t %s\t %s\n", vectorMA[y].Hora, vectorMA[y].no2, vectorMA[y].pm25, vectorMA[y].pm10, vectorMA[y].calidades);
		y++;
		break;
	}
			
	int i = 0;
	while (fscanf(fichero, "%d %d %f %f %s", &vectorMA[i].hora, &vectorMA[i].NO2, &vectorMA[i].PM25, &vectorMA[i].PM10, vectorMA[i].cal_aire) != EOF) {
		printf("%d\t %d\t %.3f\t %.3f\t %s\n", vectorMA[i].hora, vectorMA[i].NO2, vectorMA[i].PM25, vectorMA[i].PM10, vectorMA[i].cal_aire);
		i++;
	}
	
	contador = i;
	fclose(fichero);
	
	return contador;
}

int mostrarArchivo4(TEscuelasAguirre vectorEA[]) {
	
	FILE*fichero;
	int contador = 0;
	
	printf("\nHa seleccionado la opción 4\n");
   	fichero = fopen("20122023_EscuelasAguirre.txt", "r");
   	
    if (fichero == NULL) {
        printf("\nError al abrir el archivo 20122023_EscuelasAguirre.txt\n");
        return 0;
    } else{	       
   	 printf("Fichero de datos 20122023_EscuelasAguirre.txt cargado exitosamente\n");
	}
    
    	int y = 0;
	while(fscanf(fichero, "%s %s %s", vectorEA[y].Hora, vectorEA[y].temperatura, vectorEA[y].humedad) != '\n'){
		printf("%s\t %s\t %s\n", vectorEA[y].Hora, vectorEA[y].temperatura, vectorEA[y].humedad);
		y++;
		break;
	}
			
	int i = 0;
	while (fscanf(fichero, "%d %f %d", &vectorEA[i].hora, &vectorEA[i].T, &vectorEA[i].HR) != EOF) {
		printf("%d\t %.1f\t %d\n", vectorEA[i].hora, vectorEA[i].T, vectorEA[i].HR);
		i++;
	}
	
	contador = i;
	fclose(fichero);
	
	return contador;
}

int mostrarArchivo5(TEscuelasAguirre vectorEA[]) {
	
	FILE*fichero;
	int contador = 0;
	
	printf("\nHa seleccionado la opción 5\n");
   	fichero = fopen("31012024_EscuelasAguirre.txt", "r");
   	
    if (fichero == NULL) {
        printf("\nError al abrir el archivo 31012024_EscuelasAguirre.txt\n");
        return 0;
    } else{	       
   	 printf("Fichero de datos 31012024_EscuelasAguirre.txt cargado exitosamente\n");
	}
    
    	int y = 0;
	while(fscanf(fichero, "%s %s %s", vectorEA[y].Hora, vectorEA[y].temperatura, vectorEA[y].humedad) != '\n'){
		printf("%s\t %s\t %s\n", vectorEA[y].Hora, vectorEA[y].temperatura, vectorEA[y].humedad);
		y++;
		break;
	}
			
	int i = 0;
	while (fscanf(fichero, "%d %f %d", &vectorEA[i].hora, &vectorEA[i].T, &vectorEA[i].HR) != EOF) {
		printf("%d\t %.1f\t %d\n", vectorEA[i].hora, vectorEA[i].T, vectorEA[i].HR);
		i++;
	}
	
	contador = i;
	fclose(fichero);
	
	return contador;
}

int mostrarArchivo6(TEscuelasAguirre vectorEA[]) {
	
	FILE*fichero;
	int contador = 0;
	
	printf("\nHa seleccionado la opción 6\n");
   	fichero = fopen("21022024_EscuelasAguirre.txt", "r");
   	
    if (fichero == NULL) {
        printf("\nError al abrir el archivo 21022024_EscuelasAguirre.txt\n");
        return 0;
    } else{	       
   	 printf("Fichero de datos 21022024_EscuelasAguirre.txt cargado exitosamente\n");
	}
    
    	int y = 0;
	while(fscanf(fichero, "%s %s %s", vectorEA[y].Hora, vectorEA[y].temperatura, vectorEA[y].humedad) != '\n'){
		printf("%s\t %s\t %s\n", vectorEA[y].Hora, vectorEA[y].temperatura, vectorEA[y].humedad);
		y++;
		break;
	}
			
	int i = 0;
	while (fscanf(fichero, "%d %f %d", &vectorEA[i].hora, &vectorEA[i].T, &vectorEA[i].HR) != EOF) {
		printf("%d\t %.1f\t %d\n", vectorEA[i].hora, vectorEA[i].T, vectorEA[i].HR);
		i++;
	}
	
	contador = i;
	fclose(fichero);
	
	return contador;
}

void mostrarMenuMA(TMendezAlvaro vectorMA[], int size){
	printf("\n     *** MENÚ PRINCIPAL ***        \n");
		printf("Seleccione una opcion:\n \t\t\t1-Ver informe\n \t\t\t2-Estadísticas\n \t\t\t3-Comparación\n \t\t\t4-Información\n \t\t\t5-Consecuencias\n \t\t\t6-Salir\n\n");
		
	return;
}

//INFORMACIÓN
void mostrarBOE_1(char *BOE_calidaddeaire) {
	
	FILE*fichero;
	
	//printf("\nHa seleccionado la opción CALAIRE\n");
	fichero = fopen("BOE_calidaddeaire.txt", "r");
   	
    if (fichero == NULL) {
        printf("\nError al abrir el archivo BOE_calidaddeaire.txt\n");
        return;
    } //else{	       
	//	printf("Fichero de datos BOE_calidaddeaire.txt cargado exitosamente\n");
	//}
    
    int c; 
    while ((c = fgetc(fichero)) != EOF) {
        putchar(c); 
    }
    printf("\n");

	fclose(fichero);
	
	return;
}

void mostrarBOE_2(char *BOE_recomendaciones) {
	
	FILE*fichero;
	
	fichero = fopen("BOE_recomendaciones.txt", "r");
   	
    if (fichero == NULL) {
        printf("\nError al abrir el archivo BOE_recomendaciones.txt\n");
        return;
    }
	    
    int c; 
    while ((c = fgetc(fichero)) != EOF) {
        putchar(c); 
    }
    printf("\n");

	fclose(fichero);
	
	return;
}

void mostrarBOE_3(char *BOE_accesibilidad) {
	
	FILE*fichero;
	
	fichero = fopen("BOE_accesibilidad.txt", "r");
   	
    if (fichero == NULL) {
        printf("\nError al abrir el archivo BOE_accesibilidad.txt\n");
        return;
    }
	    
    int c; 
    while ((c = fgetc(fichero)) != EOF) {
        putchar(c); 
    }
    printf("\n");

	fclose(fichero);
	
	return;
}
//ESTADISTICAS
		void calculomediasMA(TMendezAlvaro vectorMA[], int contador){
		    float mediaNO2 = 0.0, mediaPM25 = 0.0, mediaPM10 = 0.0;
			
			int m;
			for (m = 0; m < contador; m++) {
				mediaNO2 += vectorMA[m].NO2;
				mediaPM25 += vectorMA[m].PM25;
				mediaPM10 += vectorMA[m].PM10;
			}
			mediaNO2 /=  contador;
			mediaPM25 /=  contador;
			mediaPM10 /= contador;
			
			printf("Concentración media de NO2 en el aire: %.3f\n", mediaNO2);
			printf("Concentración media de PM 2.5 en el aire: %.3f\n", mediaPM25);
			printf("Concentración media de PM 10 en el aire: %.3f\n", mediaPM10);			
			
			return;
		}
		
		void calculoNO2max(TMendezAlvaro vectorMA[], int i) {
			int maximoNO2= vectorMA[0].NO2;
			int masNO2 = 0;
			
			int h;
			for(h=1; h<i; h++){
				if(vectorMA[h].NO2 > maximoNO2){
					maximoNO2 = vectorMA[h].NO2;
					masNO2 = h;
				}
			}
			
			printf("La concentración máxima de NO2 es de %d a las %d horas\n", vectorMA[masNO2].NO2, vectorMA[masNO2].hora);
			
			return;
		}
		
		void calculoPM25max(TMendezAlvaro vectorMA[], int i) {
			float maximoPM25= vectorMA[0].PM25;
			int masPM25 = 0;
			
			int t;
			for(t=1; t<i; t++){
				if(vectorMA[t].PM25 > maximoPM25){
					maximoPM25 = vectorMA[t].PM25;
					masPM25 = t;
				}
			}
			
			printf("La concentración máxima de PM 2,5 es de %.3f a las %d horas\n", vectorMA[masPM25].PM25, vectorMA[masPM25].hora);
			
			return;
		}
		
		void calculoPM10max(TMendezAlvaro vectorMA[], int i) {
			float maximoPM10 = vectorMA[0].PM10;
			int masPM10 = 0;
			
			int m;
			for(m=1; m<i; m++){
				if(vectorMA[m].PM10 > maximoPM10){
					maximoPM10 = vectorMA[m].PM10;
					masPM10 = m;
				}
			}
			
			printf("La concentración máxima de PM 10 es de %.3f a las %d horas\n", vectorMA[masPM10].PM10, vectorMA[masPM10].hora);
			
			return;
		}
		
		void calculoNO2min(TMendezAlvaro vectorMA[], int i) {
			int minimoNO2= vectorMA[0].NO2;
			int menosNO2 = 0;
			
			int r;
			for(r=1; r<i; r++){
				if(vectorMA[r].NO2 < minimoNO2){
					minimoNO2 = vectorMA[r].NO2;
					menosNO2 = r;
				}
			}
			
			printf("La concentración mínima de NO2 es de %d a las %d horas\n", vectorMA[menosNO2].NO2, vectorMA[menosNO2].hora);
			
			return;
		}
		
		void calculoPM25min(TMendezAlvaro vectorMA[], int i) {
			float minimoPM25= vectorMA[0].PM25;
			int menosPM25 = 0;
			
			int x;
			for(x=1; x<i; x++){
				if(vectorMA[x].PM25 < minimoPM25){
					minimoPM25 = vectorMA[x].PM25;
					menosPM25 = x;
				}
			}
			
			printf("La concentración mínima de PM 2,5 es de %.3f a las %d horas\n", vectorMA[menosPM25].PM25, vectorMA[menosPM25].hora);
			
			return;
		}
		
		void calculoPM10min(TMendezAlvaro vectorMA[], int i) {
			float minimoPM10= vectorMA[0].PM10;
			int menosPM10 = 0;
			
			int d;
			for(d=1; d<i; d++){
				if(vectorMA[d].PM10 < minimoPM10){
					minimoPM10 = vectorMA[d].PM10;
					menosPM10 = d;
				}
			}
			
			printf("La concentración mínima de PM 10 es de %.3f a las %d horas\n", vectorMA[menosPM10].PM10, vectorMA[menosPM10].hora);
			
			return;
		}
		
		void calculomediasEA(TEscuelasAguirre vectorEA[], int contador){
		    float mediaT = 0.0, mediaHR = 0.0;
			
			int n;
			for (n = 0; n < contador; n++) {
				mediaT += vectorEA[n].T;
				mediaHR += vectorEA[n].HR;
			}
			
			mediaT /=  contador;
			mediaHR /=  contador;
			
			
			printf("Temperatura media en las Escuelas Aguirre: %.2f\n", mediaT);
			printf("Humedad media en las Escuelas Aguirre: %.2f\n", mediaHR);
			
			return;
		}
		
		void calculoTmax(TEscuelasAguirre vectorEA[], int i) {
			float maximoT= vectorEA[0].T;
			int masT = 0;
			
			int w;
			for(w=1; w<i; w++){
				if(vectorEA[w].T > maximoT){
					maximoT = vectorEA[w].T;
					masT = w;
				}
			}
			
			printf("La temperatura máxima en las Escuelas Aguirre es de %.2f a las %d horas\n", vectorEA[masT].T, vectorEA[masT].hora);
			
			return;
		}
		
		void calculoHRmax(TEscuelasAguirre vectorEA[], int i) {
			int maximoHR= vectorEA[0].HR;
			int masHR = 0;
			
			int p;
			for(p=1; p<i; p++){
				if(vectorEA[p].HR > maximoHR){
					maximoHR = vectorEA[p].HR;
					masHR = p;
				}
			}
			
			printf("La humedad relativa máxima en las Escuelas Aguirre es de %d a las %d horas\n", vectorEA[masHR].HR, vectorEA[masHR].hora);
			
			return;
		}
		
		void calculoTmin(TEscuelasAguirre vectorEA[], int i) {
			float minimoT= vectorEA[0].T;
			int menosT = 0;
			
			int n;
			for(n=1; n<i; n++){
				if(vectorEA[n].T < minimoT){
					minimoT = vectorEA[n].T;
					menosT = n;
				}
			}
			
			printf("La temperatura mínima en las Escuelas Aguirre es de %.1f a las %d horas\n", vectorEA[menosT].T, vectorEA[menosT].hora);
			
			return;
		}
		
		void calculoHRmin(TEscuelasAguirre vectorEA[], int i) {
			int minimoHR= vectorEA[0].HR;
			int menosHR = 0;
			
			int f;
			for(f=1; f<i; f++){
				if(vectorEA[f].HR < minimoHR){
					minimoHR = vectorEA[f].HR;
					menosHR = f;
				}
			}
			
			printf("La humedad relativa mínima en las Escuelas Aguirre es de %d a las %d horas\n", vectorEA[menosHR].HR, vectorEA[menosHR].hora);
			
			return;
		}
		
		//Modas - Mendez Alvaro
		void Modano2(TMendezAlvaro vectorMA[], int contador) {
				    int i, j, cont1, cont2 = 0;
				   	int aux=0, repeticiones = 0;
					
				    for (i = 0; i < contador; i++) {
				    	cont1 = 0;
				        for (j = 0; j < contador; j++) {
				            if (vectorMA[i].NO2 == vectorMA[j].NO2 && i != j) {
				                cont1++;
				            }
				        }
				
				        if (cont1 > cont2) {
				            cont2 = cont1;
				            aux = vectorMA[i].NO2;
				            repeticiones = 1;
				            
				        }
				    }
					
					if (repeticiones == 0) {
		       			printf("No se repite ningun valor de NO2\n");
						}
					else{
						printf("El valor más repetido de NO2 es: %i. Se repite %i veces\n", aux, cont2+1);
						}
				
				    return;
				}
				
		void ModaPM25(TMendezAlvaro vectorMA[], int contador) {
				    int i, j, cont1, cont2 = 0;
				   	float aux=0, repeticiones = 0;
					
				    for (i = 0; i < contador; i++) {
				    	cont1 = 0;
				        for (j = 0; j < contador; j++) {
				            if (vectorMA[i].PM25 == vectorMA[j].PM25 && i != j) {
				                cont1++;
				            }
				        }
				
				        if (cont1 > cont2) {
				            cont2 = cont1;
				            aux = vectorMA[i].PM25;
				            repeticiones = 1;
				        }
				    }
					
					if (repeticiones == 0) {
		       			printf("No se repite ningun valor de PM2\n");
						}
					else{
						printf("El valor más repetido de PM2.5 es: %.3f. Se repite %i veces\n", aux, cont2+1);
						}	
				
				    return;
				}
		void ModaPM10(TMendezAlvaro vectorMA[], int contador) {
				    int i, j, cont1, cont2 = 0;
				   	float aux=0, repeticiones = 0;
					
				    for (i = 0; i < contador; i++) {
				    	cont1 = 0;
				        for (j = 0; j < contador; j++) {
				            if (vectorMA[i].PM10 == vectorMA[j].PM10 && i != j) {
				                cont1++;
				            }
				        }
				
				        if (cont1 > cont2) {
				            cont2 = cont1;
				            aux = vectorMA[i].PM10;
				            repeticiones = 1;
				        }
				    }
					
					if (repeticiones == 0) {
		       			printf("No se repite ningun valor de PM10\n");
						}
					else{
						printf("El valor más repetido de PM10 es: %.3f. Se repite %i veces\n", aux, cont2+1);
						}	
				
				    return;
				}	
	//Moda - Escueleas Aguirre
		void ModaT(TEscuelasAguirre vectorEA[], int contador) {
				    int i, j, cont1, cont2 = 0;
				   	float aux=0, repeticiones = 0;
					
				    for (i = 0; i < contador; i++) {
				    	cont1 = 0;
				        for (j = 0; j < contador; j++) {
				            if (vectorEA[i].T == vectorEA[j].T && i != j) {
				                cont1++;
				            }
				        }
				
				        if (cont1 > cont2) {
				            cont2 = cont1;
				            aux = vectorEA[i].T;
				            repeticiones = 1;
				        }
				    }
					
					if (repeticiones == 0) {
		       			printf("No se repite ningun valor de temperatura\n");
						}
					else{
						printf("El valor más repetido de temperatura es: %.1f. Se repite %i veces\n", aux, cont2+1);
						}	
				
				    return;
				}		
		
		void ModaHR(TEscuelasAguirre vectorEA[], int contador) {
				    int i, j, cont1, cont2 = 0;
				   	int aux=0, repeticiones = 0;
					
				    for (i = 0; i < contador; i++) {
				    	cont1 = 0;
				        for (j = 0; j < contador; j++) {
				            if (vectorEA[i].HR == vectorEA[j].HR && i != j) {
				                cont1++;
				            }
				        }
				
				        if (cont1 > cont2) {
				            cont2 = cont1;
				            aux = vectorEA[i].HR;
				            repeticiones = 1;
				            
				        }
				    }
					
					if (repeticiones == 0) {
		       			printf("No se repite ningun valor de HR\n");
						}
					else{
						printf("El valor más repetido de HR es: %i. Se repite %i veces\n", aux, cont2+1);
						}
				
				    return;
				}	
		
		
//COMPARACION

void fordTEA(TEscuelasAguirre vectorEA[], int contador){
			int i, j, z; 
			float aux1, aux2, aux3; 
			printf("\nLos datos de temperatura ordenados de menor a mayor son:\n" ); 
			for (i=0; i<contador; i++){
				for(j=i+1; j<contador; j++){
					if(vectorEA[i].T>vectorEA[j].T){
						aux1=vectorEA[i].T;
						aux2=vectorEA[i].HR;
						aux3=vectorEA[i].hora;
						vectorEA[i].T=vectorEA[j].T; 
						vectorEA[i].HR=vectorEA[j].HR;
						vectorEA[i].hora=vectorEA[j].hora;
						vectorEA[j].T=aux1; 
						vectorEA[j].HR=aux2;
						vectorEA[j].hora=aux3;
					}
				}
			} 
			for(z=0; z<contador; z++) {
				printf("Hora %d, Temperatura %.2f\n", vectorEA[z].hora, vectorEA[z].T);
			}
			return;
		}
		
		void fordT2EA(TEscuelasAguirre vectorEA[], int contador){
			int i, j, z; 
			float aux1, aux2, aux3; 
			printf("\nLos datos de temperatura ordenados de mayor a menor son:\n" ); 
			for (i=0; i<contador; i++){
				for(j=i+1; j<contador; j++){
					if(vectorEA[i].T<vectorEA[j].T){
						aux1=vectorEA[i].T;
						aux2=vectorEA[i].HR;
						aux3=vectorEA[i].hora;
						vectorEA[i].T=vectorEA[j].T; 
						vectorEA[i].HR=vectorEA[j].HR;
						vectorEA[i].hora=vectorEA[j].hora;
						vectorEA[j].T=aux1; 
						vectorEA[j].HR=aux2;
						vectorEA[j].hora=aux3;
					}
				}
			} 
			for(z=0; z<contador; z++) {
				printf("Hora %d, Temperatura %.2f\n", vectorEA[z].hora, vectorEA[z].T);
			}
			return;
		}
		
		void fordHREA(TEscuelasAguirre vectorEA[], int contador){
			int i, j, z; 
			float aux1, aux2, aux3; 
			printf("\nLos datos de humedad ordenados de menor a mayor son:\n" ); 
			for (i=0; i<contador; i++){
				for(j=i+1; j<contador; j++){
					if(vectorEA[i].HR>vectorEA[j].HR){
						aux1=vectorEA[i].T;
						aux2=vectorEA[i].HR;
						aux3=vectorEA[i].hora;
						vectorEA[i].T=vectorEA[j].T; 
						vectorEA[i].HR=vectorEA[j].HR;
						vectorEA[i].hora=vectorEA[j].hora;
						vectorEA[j].T=aux1; 
						vectorEA[j].HR=aux2;
						vectorEA[j].hora=aux3;
					}
				}
			} 
			for(z=0; z<contador; z++) {
				printf("Hora %d, Humedad %i\n", vectorEA[z].hora, vectorEA[z].HR);
			}
			return;
		}
		
		void fordHR2EA(TEscuelasAguirre vectorEA[], int contador){
			int i, j, z; 
			float aux1, aux2, aux3; 
			printf("\nLos datos de humedad ordenados de mayor a menor son:\n" ); 
			for (i=0; i<contador; i++){
				for(j=i+1; j<contador; j++){
					if(vectorEA[i].HR<vectorEA[j].HR){
						aux1=vectorEA[i].T;
						aux2=vectorEA[i].HR;
						aux3=vectorEA[i].hora;
						vectorEA[i].T=vectorEA[j].T; 
						vectorEA[i].HR=vectorEA[j].HR;
						vectorEA[i].hora=vectorEA[j].hora;
						vectorEA[j].T=aux1; 
						vectorEA[j].HR=aux2;
						vectorEA[j].hora=aux3;
					}
				}
			} 
			for(z=0; z<contador; z++) {
				printf("Hora %d, Humedad %.2f\n", vectorEA[z].hora, vectorEA[z].HR);
			}
			return;
		}
		
		void fordMA(TMendezAlvaro vectorMA[], int contador){
			int i, j, z; 
			float aux1, aux2, aux3, aux4; 
			char aux5;
			printf("\nLos datos de NO2 ordenados de menor a mayor son:\n" ); 
			for (i=0; i<contador; i++){
				for(j=i+1; j<contador; j++){
					if(vectorMA[i].NO2>vectorMA[j].NO2){
						aux1=vectorMA[i].NO2;
						aux2=vectorMA[i].PM25;
						aux3=vectorMA[i].hora;
						aux4=vectorMA[i].PM10;
						vectorMA[i].NO2=vectorMA[j].NO2; 
						vectorMA[i].PM25=vectorMA[j].PM25;
						vectorMA[i].hora=vectorMA[j].hora;
						vectorMA[i].PM10=vectorMA[j].PM10;
						vectorMA[j].NO2=aux1; 
						vectorMA[j].PM25=aux2;
						vectorMA[j].hora=aux3;
						vectorMA[j].PM10=aux4;
					}
				}
			}
			for(z=0; z<contador; z++) {
				printf("Hora %i, NO2 %i\n", vectorMA[z].hora, vectorMA[z].NO2);
			}
			printf("\nLos datos de PM2.5 ordenados de menor a mayor son:\n" ); 
			for (i=0; i<contador; i++){
				for(j=i+1; j<contador; j++){
					if(vectorMA[i].PM25>vectorMA[j].PM25){
						aux1=vectorMA[i].NO2;
						aux2=vectorMA[i].PM25;
						aux3=vectorMA[i].hora;
						aux4=vectorMA[i].PM10;
						vectorMA[i].NO2=vectorMA[j].NO2; 
						vectorMA[i].PM25=vectorMA[j].PM25;
						vectorMA[i].hora=vectorMA[j].hora;
						vectorMA[i].PM10=vectorMA[j].PM10;
						vectorMA[j].NO2=aux1; 
						vectorMA[j].PM25=aux2;
						vectorMA[j].hora=aux3;
						vectorMA[j].PM10=aux4;
					}
				}
			}
			for(z=0; z<contador; z++) {
				printf("Hora %i, PM2.5 %.2f\n", vectorMA[z].hora, vectorMA[z].PM10);
			}
			printf("\nLos datos de PM10 ordenados de menor a mayor son:\n" ); 
			for (i=0; i<contador; i++){
				for(j=i+1; j<contador; j++){
					if(vectorMA[i].PM10>vectorMA[j].PM10){
						aux1=vectorMA[i].NO2;
						aux2=vectorMA[i].PM25;
						aux3=vectorMA[i].hora;
						aux4=vectorMA[i].PM10;
						vectorMA[i].NO2=vectorMA[j].NO2; 
						vectorMA[i].PM25=vectorMA[j].PM25;
						vectorMA[i].hora=vectorMA[j].hora;
						vectorMA[i].PM10=vectorMA[j].PM10;
						vectorMA[j].NO2=aux1; 
						vectorMA[j].PM25=aux2;
						vectorMA[j].hora=aux3;
						vectorMA[j].PM10=aux4;
					}
				}
			}
			
			for(z=0; z<contador; z++) {
				printf("Hora %i, PM10 %.2f\n", vectorMA[z].hora, vectorMA[z].PM10);
			}
			return;
		}
		
		void ford2MA(TMendezAlvaro vectorMA[], int contador){
			int i, j, z; 
			float aux1, aux2, aux3, aux4; 
			char aux5;
			printf("\nLos datos de NO2 ordenados de mayor a menor son:\n" ); 
			for (i=0; i<contador; i++){
				for(j=i+1; j<contador; j++){
					if(vectorMA[i].NO2<vectorMA[j].NO2){
						aux1=vectorMA[i].NO2;
						aux2=vectorMA[i].PM25;
						aux3=vectorMA[i].hora;
						aux4=vectorMA[i].PM10;
						vectorMA[i].NO2=vectorMA[j].NO2; 
						vectorMA[i].PM25=vectorMA[j].PM25;
						vectorMA[i].hora=vectorMA[j].hora;
						vectorMA[i].PM10=vectorMA[j].PM10;
						vectorMA[j].NO2=aux1; 
						vectorMA[j].PM25=aux2;
						vectorMA[j].hora=aux3;
						vectorMA[j].PM10=aux4;
					}
				}
			}
			for(z=0; z<contador; z++) {
				printf("Hora %i, NO2 %i\n", vectorMA[z].hora, vectorMA[z].NO2);
			}
			printf("\nLos datos de PM2.5 ordenados de mayor a menor son:\n" ); 
			for (i=0; i<contador; i++){
				for(j=i+1; j<contador; j++){
					if(vectorMA[i].PM25<vectorMA[j].PM25){
						aux1=vectorMA[i].NO2;
						aux2=vectorMA[i].PM25;
						aux3=vectorMA[i].hora;
						aux4=vectorMA[i].PM10;
						vectorMA[i].NO2=vectorMA[j].NO2; 
						vectorMA[i].PM25=vectorMA[j].PM25;
						vectorMA[i].hora=vectorMA[j].hora;
						vectorMA[i].PM10=vectorMA[j].PM10;
						vectorMA[j].NO2=aux1; 
						vectorMA[j].PM25=aux2;
						vectorMA[j].hora=aux3;
						vectorMA[j].PM10=aux4;
					}
				}
			}
			for(z=0; z<contador; z++) {
				printf("Hora %i, PM2.5 %.2f\n", vectorMA[z].hora, vectorMA[z].PM10);
			}
			printf("\nLos datos de PM10 ordenados de mayor a menor son:\n" ); 
			for (i=0; i<contador; i++){
				for(j=i+1; j<contador; j++){
					if(vectorMA[i].PM10<vectorMA[j].PM10){
						aux1=vectorMA[i].NO2;
						aux2=vectorMA[i].PM25;
						aux3=vectorMA[i].hora;
						aux4=vectorMA[i].PM10;
						vectorMA[i].NO2=vectorMA[j].NO2; 
						vectorMA[i].PM25=vectorMA[j].PM25;
						vectorMA[i].hora=vectorMA[j].hora;
						vectorMA[i].PM10=vectorMA[j].PM10;
						vectorMA[j].NO2=aux1; 
						vectorMA[j].PM25=aux2;
						vectorMA[j].hora=aux3;
						vectorMA[j].PM10=aux4;
					}
				}
			}
			
			for(z=0; z<contador; z++) {
				printf("Hora %i, PM10 %.2f\n", vectorMA[z].hora, vectorMA[z].PM10);
			}
			return;
		}
		
	void calculoMedianaMA(TMendezAlvaro vectorMA[], int contador){
		int i, j; 
		float medianaNO2, medianaPM25, medianaPM10;
		int aux1;
		float aux2, aux3;
		
		for(i = 0; i < contador; i++){
			for(j = i+1; j < contador; j++){
				if(vectorMA[i].NO2 > vectorMA[j].NO2){
					aux1 = vectorMA[i].NO2;
				
					vectorMA[i].NO2 = vectorMA[j].NO2;
					
					vectorMA[j].NO2 = aux1;
				}
			}
		}
		
		for(i = 0; i < contador; i++){
			for(j = i+1; j < contador; j++){
				if(vectorMA[i].PM25 > vectorMA[j].PM25){
					aux2 = vectorMA[i].PM25;

					vectorMA[i].PM25 = vectorMA[j].PM25;
					
					vectorMA[j].PM25 = aux2;
				}
			}
		}
		
		for(i = 0; i < contador; i++){
			for(j = i+1; j < contador; j++){
				if(vectorMA[i].PM10 > vectorMA[j].PM10){
					aux3 = vectorMA[i].PM10;

					vectorMA[i].PM10 = vectorMA[j].PM10;
					
					vectorMA[j].PM10 = aux3;
				}
			}
		}
		
		if(i % 2== 0){
			medianaNO2 = (vectorMA[(i/2)- 1].NO2 + vectorMA[i/2].NO2) / 2.0;
			medianaPM25 = (vectorMA[(i/2) - 1].PM25 + vectorMA[i/2].PM25) / 2.0;
			medianaPM10 = (vectorMA[(i/2) - 1].PM10 + vectorMA[i/2].PM10) / 2.0;
		
		} else{
			medianaNO2 = vectorMA[i/2].NO2;
			medianaPM25 = vectorMA[i/2].PM25;
			medianaPM10 = vectorMA[i/2].PM10;
		}		
		
		printf("\nMediana NO2: %.3f\n", medianaNO2);
    	printf("\nMediana PM2.5: %.3f\n", medianaPM25);
    	printf("\nMediana PM10: %.3f\n", medianaPM10);
		
		return;
		}
		
		void calculoMedianaEA(TEscuelasAguirre vectorEA[], int contador){
		int i, j; 
		float medianaT, medianaHR;
		int aux1;
		float aux2;
		
		for(i = 0; i < contador; i++){
			for(j = i+1; j < contador; j++){
				if(vectorEA[i].T > vectorEA[j].T){
					aux1 = vectorEA[i].T;
				
					vectorEA[i].T = vectorEA[j].T;
					
					vectorEA[j].T = aux1;
				}
			}
		}
		
		for(i = 0; i < contador; i++){
			for(j = i+1; j < contador; j++){
				if(vectorEA[i].HR > vectorEA[j].HR){
					aux2 = vectorEA[i].HR;

					vectorEA[i].HR = vectorEA[j].HR;
					
					vectorEA[j].HR = aux2;
				}
			}
		}
		
		if(i % 2== 0){
			medianaT = (vectorEA[(i/2)- 1].T + vectorEA[i/2].T) / 2.0;
			medianaHR = (vectorEA[(i/2) - 1].HR + vectorEA[i/2].HR) / 2.0;
		
		} else{
			medianaT = vectorEA[i/2].T;
			medianaHR = vectorEA[i/2].HR;
		}		
		
		printf("\nMediana T: %.3f\n", medianaT);
    	printf("\nMediana HR: %.3f\n", medianaHR);
		
		return;
		}
		
	//COMPARARCIÓN ENTRE DOS HORAS	
		
		//MENDEZ ALVARO	
		void fcompararME(TMendezAlvaro vectorMA[], int contador){
			int i, j; 
				int hora1, hora2; 
				int No21=0, No22=0;
				float PM251=0, PM252=0;
				float PM101=0, PM102=0;

				do {
					printf ("Introduce la primera hora que quiera comparar, del 0 al 23 \n");
					scanf ("%i", &hora1);
					printf ("Introduce la segunda hora que quiera comparar, del 0 al 23 \n");
					scanf("%i", &hora2);	
				}while (hora1 < 0 || hora1 > 23 || hora2 < 0 || hora2 > 23);
			
				for (i=0; i<contador; i++) {
					if (vectorMA[i].hora == hora1) {
            		No21 = vectorMA[i].NO2;
					}
					if (vectorMA[i].hora == hora2) {
           		 	No22 = vectorMA[i].NO2;
					}
				}
				
				if (No21<No22) {
					printf("\nEl valor de NO2 = %i µg/m3 a la hora %i, es MENOR que el valor de NO2 = %i µg/m3 a la hora %i\n", No21,hora1,No22,hora2);
				} else if (No21>No22) {
					printf ("\nEl valor de NO2 = %i µg/m3 a la hora %i, es MAYOR que el valor de NO2 = %i µg/m3 a la hora %i\n", No21,hora1,No22,hora2);
				} else if (No21==No22) {
					printf ("\nLas horas %i y %i tienen IGUAL valor de NO2 = %i µg/m3\n",hora1,hora2, No21);
				}
				
				for (i=0; i<contador; i++) {
					if (vectorMA[i].hora == hora1) {
            		PM251 = vectorMA[i].PM25;
					}
					if (vectorMA[i].hora == hora2) {
           		 	PM252 = vectorMA[i].PM25;
					}
				}
				
				if (PM251<PM252) {
					printf("\nEl valor de PM2.5 = %.3f µg/m3 a la hora %i, es MENOR que el valor de PM2.5 = %.3f µg/m3 a la hora %i\n", PM251,hora1,PM252,hora2);
				} else if (PM251>PM252) {
					printf ("\nEl valor de PM2.5 = %.3f µg/m3 a la hora %i, es MAYOR que el valor de PM2.5 = %.3f µg/m3 a la hora %i\n", PM251,hora1,PM252,hora2);
				} else if (PM251==PM252) {
					printf ("\nLas horas %i y %i tienen IGUAL valor de PM2.5 = %.3f µg/m3\n",hora1,hora2, PM251);
					}
				
				for (i=0; i<contador; i++) {
					if (vectorMA[i].hora == hora1) {
            		PM101 = vectorMA[i].PM10;
					}
					if (vectorMA[i].hora == hora2) {
           		 	PM102 = vectorMA[i].PM10;
        			}
				}
				
				if (PM101<PM102) {
					printf("\nEl valor de PM10 = %.3f µg/m3 a la hora %i, es MENOR que el valor de PM10 = %.3f µg/m3 a la hora %i\n", PM101,hora1,PM102,hora2);
				} else if (PM101>PM102) {
					printf ("\nEl valor de PM10 = %.3f µg/m3 a la hora %i, es MAYOR que el valor de PM10 = %.3f µg/m3 a la hora %i\n", PM101,hora1,PM102,hora2);
				} else if (PM101==PM102) {
					printf ("\nLas horas %i y %i tienen IGUAL valor de PM1O = %.3f µg/m3 \n",hora1,hora2, PM101);
					}
		}	
		//ESCUELAS AGUIRRE
		void fcompararEA(TEscuelasAguirre vectorEA[], int contador){
			int i, j; 
				int hora1, hora2; 
				int HR1=0, HR2=0;
				float T1=0, T2=0;

				do {
					printf ("Introduce la primera hora que quiera comparar, del 0 al 23 \n");
					scanf ("%i", &hora1);
					printf ("Introduce la segunda hora que quiera comparar, del 0 al 23 \n");
					scanf("%i", &hora2);	
				}while (hora1 < 0 || hora1 > 23 || hora2 < 0 || hora2 > 23);
			
				for (i=0; i<contador; i++) {
					if (vectorEA[i].hora == hora1) {
            		T1 = vectorEA[i].T;
					}
					if (vectorEA[i].hora == hora2) {
           		 	T2 = vectorEA[i].T;
					}
				}
				
				if (T1<T2) {
					printf("\nLa temperatura = %.1f° a la hora %i, es MENOR que la temperatura = %.1f° a la hora %i\n", T1,hora1,T2,hora2);
				} else if (T1>T2) {
					printf("\nLa temperatura = %.1f° a la hora %i, es MAYOR que la temperatura = %.1f° a la hora %i\n", T1,hora1,T2,hora2);
				} else if (T1==T2) {
					printf ("\nLas horas %i y %i tienen IGUAL valor de temperatura = %.1f°\n",hora1,hora2, T1);
				}
				
				for (i=0; i<contador; i++) {
					if (vectorEA[i].hora == hora1) {
            		HR1 = vectorEA[i].HR;
					}
					if (vectorEA[i].hora == hora2) {
           		 	HR2 = vectorEA[i].HR;
					}
				}
				
				if (HR1<HR2) {
					printf("\nEl valor de HR = %i a la hora %i, es MENOR que el valor de HR = %i a la hora %i\n", HR1,hora1,HR2,hora2);
				} else if (HR1>HR2) {
						printf("\nEl valor de HR = %i a la hora %i, es MAYOR que el valor de HR = %i a la hora %i\n", HR1,hora1,HR2,hora2);
				} else if (HR1==HR2) {
					printf ("\nLas horas %i y %i tienen IGUAL valor de HR = %i \n",hora1,hora2, HR1);
				}
		
		}			

		//OBTENER DATOS DE UNA HORA
		void DatosHoraME(TMendezAlvaro vectorMA[], int contador){
		    int i, found = 0;
		    int hora1; 
			int No21=0, No22=0;
			float PM251=0, PM252=0;
			float PM101=0, PM102=0;
			char calidas[30];
		    do{
		    printf("Introduce la hora que quieras buscar: \n"); 
		    scanf("%i" ,&hora1);
			}while (hora1 < 0 || hora1 > 23);
		
		    for (i = 0; i < contador; i++) {
				if (vectorMA[i].hora == hora1) {
					No21 = vectorMA[i].NO2;
					PM251 = vectorMA[i].PM25;
					PM101 = vectorMA[i].PM10;
					calidas[30]= vectorMA[i].cal_aire;
				}
			}
		        printf("\nInformacion de la hora buscada '%i':\n", hora1);
		        printf("NO2: %.i\n", No21);
		        printf("PM2.5: %f\n", PM251);
		        printf("PM10: %f\n", PM101);
		        printf("Calidad del aire: %s\n", calidas);
		
		return;
				      
		}
