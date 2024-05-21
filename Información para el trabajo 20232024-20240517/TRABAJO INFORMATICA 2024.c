#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#define TAM 500

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
} TMendezAlvaro;

typedef struct {
    int hora;
    char Hora[5];
    float T;
    char temperatura[15];
    int HR;
    char humedad[10];
} TEscuelasAguirre;

int calculoNO2max(TMendezAlvaro vectorMendezAlvaro[], int contador);
float calculoPM25max(TMendezAlvaro vectorMendezAlvaro[], int contador);
float calculoPM10max(TMendezAlvaro vectorMendezAlvaro[], int contador);
void calculomediasMA(TMendezAlvaro vectorMendezAlvaro[], int i);
int mostrarArchivo1(TMendezAlvaro vectorMendezAlvaro[]);
void mostrarMenuMA(TMendezAlvaro vectorMendezAlvaro[], int size);


int main() {
    setlocale(LC_CTYPE, "spanish"); // para que el compilador reconozca las ñ y tildes 
    int archivo, opcion, contador = 0;
    TMendezAlvaro vectorMendezAlvaro[TAM];
    TEscuelasAguirre vectorEscuelasAguirre[TAM];
    
    while (1) {
		
		printf ("\nIndique el archivo con el que quiera trabajar:\n 1.\tMendez Álvaro 20-12-2023\n 2.\tMendez Álvaro 31-01-2024\n 3.\tMendez Álvaro 21-02-2024\n 4.\tEscuelas Aguirre 20-12-2023\n 5.\tEscuelas Aguirre 31-01-2024\n 6.\tEscuelas Aguirre 21-02-2024\n");
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
			contador = mostrarArchivo1(vectorMendezAlvaro);
			
			do{
				mostrarMenuMA(vectorMendezAlvaro, TAM);
				scanf("%d", &opcion);
				
				if (opcion == 1){
				
				} else if (opcion == 2){
					int NO2max = calculoNO2max(vectorMendezAlvaro, contador);
					float PM25max = calculoPM25max(vectorMendezAlvaro, contador);
					float PM10max = calculoPM10max(vectorMendezAlvaro, contador);
					int Opcion;
				
					do { 
    				printf("Elige una opción que desee\n");
    				printf("\t1: Media \n");
    				printf("\t2: Mediana \n");
    				printf("\t3: Mínimos valores \n");
    				printf("\t4: Máximos valores \n");
    				printf("\t5: Moda \n");
    				printf("\t6: Salir de estadísticas.\n");
    				scanf("%d", &Opcion);
					//otro switch case dentro
					switch(Opcion){
						case(1): {
						calculomediasMA(vectorMendezAlvaro, contador);
					
							break;
						}
						case(4): {
							
							printf("NO2 máximo: %i\n", NO2max );
							printf("PM25 máximo: %.3f\n", PM25max);
							printf("PM10 máximo: %.3f\n", PM10max);
							break;
						}
					}
    				} while (Opcion != 6);
    		
				} else if (opcion == 3){
					//FUNCION 3
				} else if (opcion == 4){
					//FUNCION 4
				} else if (opcion == 5){
					//FUNCION 5
				}
			} while (opcion <= 6);
			
				if(opcion == 7){
					printf("-HASTA PRONTO-\n");
					return 0;
				}
				
			break;
		}
		
		case (2):{
			int i;
			contador = mostrarArchivo2(vectorMendezAlvaro);
			
			do{
				mostrarMenuMA(vectorMendezAlvaro, TAM);
				scanf("%d", &opcion);
				
				if (opcion == 1){
					//FUNCION 1
				} else if (opcion == 2){
					int NO2max = calculoNO2max(vectorMendezAlvaro, contador);
					float PM25max = calculoPM25max(vectorMendezAlvaro, contador);
					float PM10max = calculoPM10max(vectorMendezAlvaro, contador);
					int Opcion;
				
					do { 
    				printf("Elige una opción que desee\n");
    				printf("\t1: Media \n");
    				printf("\t2: Mediana \n");
    				printf("\t3: Mínimos valores \n");
    				printf("\t4: Máximos valores \n");
    				printf("\t5: Moda \n");
    				printf("\t6: Salir de estadísticas.\n");
    				scanf("%d", &Opcion);
					//otro switch case dentro
					switch(Opcion){
						case(1): {
						calculomediasMA(vectorMendezAlvaro, contador);
					
							break;
						}
						case(4): {
							
							printf("NO2 máximo: %i\n", NO2max );
							printf("PM25 máximo: %.3f\n", PM25max);
							printf("PM10 máximo: %.3f\n", PM10max);
							break;
						}
					}
    				} while (Opcion != 6);
				} else if (opcion == 3){
					//FUNCION 3
				} else if (opcion == 4){
					//FUNCION 4
				} else if (opcion == 5){
					//FUNCION 5
				}
			} while (opcion <= 6);
			
				if(opcion == 7){
					printf("-HASTA PRONTO-\n");
					return 0;
				}
			break;
		}
		
		case (3):{
			int i;
			contador = mostrarArchivo3(vectorMendezAlvaro);
			
			do{
				mostrarMenuMA(vectorMendezAlvaro, TAM);
				scanf("%d", &opcion);
				
				if (opcion == 1){
					//FUNCION 1
				} else if (opcion == 2){
					//FUNCION2
				} else if (opcion == 3){
					//FUNCION 3
				} else if (opcion == 4){
					//FUNCION 4
				} else if (opcion == 5){
					//FUNCION 5
				}
			} while (opcion <= 6);
			
				if(opcion == 7){
					printf("-HASTA PRONTO-\n");
					return 0;
				}
			break;
		}
		
		case (4):{
			int i;
			contador = mostrarArchivo4(vectorEscuelasAguirre);
			
			do{
				mostrarMenuMA(vectorMendezAlvaro, TAM);
				scanf("%d", &opcion);
				
				if (opcion == 1){
					//FUNCION 1
				} else if (opcion == 2){
					//FUNCION2
				} else if (opcion == 3){
					//FUNCION 3
				} else if (opcion == 4){
					//FUNCION 4
				} else if (opcion == 5){
					//FUNCION 5
				}
			} while (opcion <= 6);
			
				if(opcion == 7){
					printf("-HASTA PRONTO-\n");
					return 0;
				}
			break;
		}
		
		case (5):{
			int i;
			contador = mostrarArchivo5(vectorMendezAlvaro);
			
			do{
				mostrarMenuMA(vectorMendezAlvaro, TAM);
				scanf("%d", &opcion);
				
				if (opcion == 1){
					//FUNCION 1
				} else if (opcion == 2){
					//FUNCION2
				} else if (opcion == 3){
					//FUNCION 3
				} else if (opcion == 4){
					//FUNCION 4
				} else if (opcion == 5){
					//FUNCION 5
				}
			} while (opcion <= 6);
			
				if(opcion == 7){
					printf("-HASTA PRONTO-\n");
					return 0;
				}
			break;
		}
		
		case (6):{
			int i;
			contador = mostrarArchivo6(vectorMendezAlvaro);
			
			do{
				mostrarMenuMA(vectorMendezAlvaro, TAM);
				scanf("%d", &opcion);
				
				if (opcion == 1){
					//FUNCION 1
				} else if (opcion == 2){
					//FUNCION2
				} else if (opcion == 3){
					//FUNCION 3
				} else if (opcion == 4){
					//FUNCION 4
				} else if (opcion == 5){
					//FUNCION 5
				}
			} while (opcion <= 6);
			
				if(opcion == 7){
					printf("-HASTA PRONTO-\n");
					return 0;
				}
			break;
		}
	}
		
	
    
   
    //COMIENZA EL PROGRAMA:
	/*int a; 
	do{
		printf("           MENÚ PRINCIPAL           \n");
		printf("Seleccione una opcion:\n \t\t\t1-Ver informe\n \t\t\t2-Estadísticas\n \t\t\t3-Comparación\n \t\t\t4-Información\n \t\t\t5-Imprimir todos los datos por pantalla\n \t\t\t6-Salir\n\n");
		scanf("%d", &a);
		//desarrollamos los casos citados en el menú principal
		switch (a) {
			case(1): {
				//Declaramos las variables.
				int n=0, k;
				int x,b;
				do {
					n++;
					if(n>1) {
						printf("El valor intoducido es incorrecto, por favor introdúzcalo de nuevo\n");
					}
					printf("Ha seleccionado \n\n");
					printf("Si desea volver al menu principal, pulse 0\n");
					scanf("%d", &b);
				} while (b!=1 && b!=2 && b!=0); 
				if(b==0) {
					break;
				}
			}
			case(2): {
				//Declaramos las variables.
				int n=0;
				int NO2max = calculoNO2max(vectorMendezAlvaro, pgeos);
				int Opcion;
				int x,b;
				do {
					n++;
					if(n>1) {
						printf("El valor intoducido es incorrecto, por favor introdúzcalo de nuevo\n");
					}
					printf("Ha seleccionado ESTADÍSTICAS \n\n");
					printf("Si desea volver al menu principal, pulse 0, si no pulse 1\n");
					scanf("%d", &b);
				} while (b!=1 && b!=2 && b!=0); 
				if(b==0) {
					break;
				}
				do { 
    				printf("Elige una opción que desee\n");
    				printf("\t1: Ver todas las estadísticas\n");
    				printf("\t2: Media \n");
    				printf("\t3: Mediana \n");
    				printf("\t4: Mínimo \n");
    				printf("\t5: Máximo \n");
    				printf("\t6: Moda \n");
    				printf("\t7: Salir de estadísticas.\n");
    				scanf("%d", &Opcion);
					//otro switch case dentro
					switch(opcion){
						case(2): {
							calculomediasMA( vectorMendezAlvaro, i);
							break;
						}
						case(5): {
							//int NO2max = calculoNO2max(vectorMendezAlvaro, y);
							printf("NO2 maximo: %i\n", NO2max );
							break;
						}
						case (1): {
							printf("hola\n");
							break;
						}
					}
    			} while (Opcion != 7);	
					break; 				
			}
			case(3): {
				//Declaramos las variables.
				int n=0, k;
				int x,b;
				do {
					n++;
					if(n>1) {
						printf("El valor intoducido es incorrecto, por favor introdúzcalo de nuevo\n");
					}
					printf("Ha seleccionado \n\n");
					printf("Si desea volver al menu principal, pulse 0\n");
					scanf("%d", &b);
				} while (b!=1 && b!=2 && b!=0); 
				if(b==0) {
					break;
				}
			}
			case(4): {
				//Declaramos las variables.
				int opcion;
				int n=0, k;
				int x,b;
				do {
					n++;
					if(n>1) {
						printf("El valor intoducido es incorrecto, por favor introdúzcalo de nuevo\n");
					}
					printf("Ha seleccionado INFORMACIÓN\n\n");
					printf("Si desea volver al menu principal, pulse 0\n");
					scanf("%d", &b);
				} while (b!=1 && b!=2 && b!=0); 
				if(b==0) {
					break;
				}
				do { 
    				printf("Elige una opción que desee\n");
    				printf("\t1: PM10\n");
    				printf("\t2: PM2,5 \n");
    				printf("\t3: Ozono Troposférico \n");
    				printf("\t4: Dióxido de nitrógeno \n");
    				printf("\t5: Dióxido de azufre \n");
    				printf("\t6: Salir de estadísticas.\n");
    				scanf("%d", &opcion);
    			} while (opcion != 6);	
					break;
			}
			case(5): {
				//Declaramos las variables.
				int n=0, k;
				int x,b;
				do {
					n++;
					if(n>1) {
						printf("El valor intoducido es incorrecto, por favor introdúzcalo de nuevo\n");
					}
					printf("Ha seleccionado 1 \n\n");
					printf("Si desea volver al menu principal, pulse 0\n");
					scanf("%d", &b);
				} while (b!=1 && b!=2 && b!=0); 
				if(b==0) {
					break;
				}
			}
			default: {
				printf("El valor introducido es incorrecto, por favor vuelva a introducirlo: \n");
				break;
			}
		}
	}while(a!=6);*/
	printf("Hasta la próxima\n"); 
	printf("FIN DEL PROGRAMA"); 
	
	
    return 0;
}






int mostrarArchivo1(TMendezAlvaro vectorMendezAlvaro[]) {
	
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
	while(fscanf(fichero, "%s %s %s %s %s", vectorMendezAlvaro[y].Hora, vectorMendezAlvaro[y].no2, vectorMendezAlvaro[y].pm25, vectorMendezAlvaro[y].pm10, vectorMendezAlvaro[y].calidades) != '\n'){
		printf("%s\t %s\t %s\t %s\t %s\n", vectorMendezAlvaro[y].Hora, vectorMendezAlvaro[y].no2, vectorMendezAlvaro[y].pm25, vectorMendezAlvaro[y].pm10, vectorMendezAlvaro[y].calidades);
		y++;
		break;
	}
			
	int i = 0;
	while (fscanf(fichero, "%d %d %f %f %s", &vectorMendezAlvaro[i].hora, &vectorMendezAlvaro[i].NO2, &vectorMendezAlvaro[i].PM25, &vectorMendezAlvaro[i].PM10, vectorMendezAlvaro[i].cal_aire) != EOF) {
		printf("%d\t %d\t %.3f\t %.3f\t %s\n", vectorMendezAlvaro[i].hora, vectorMendezAlvaro[i].NO2, vectorMendezAlvaro[i].PM25, vectorMendezAlvaro[i].PM10, vectorMendezAlvaro[i].cal_aire);
		i++;
	}
	
	contador = i;

	fclose(fichero);
	
	return contador;
}

int mostrarArchivo2(TMendezAlvaro vectorMendezAlvaro[]) {
	
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
	while(fscanf(fichero, "%s %s %s %s %s", vectorMendezAlvaro[y].Hora, vectorMendezAlvaro[y].no2, vectorMendezAlvaro[y].pm25, vectorMendezAlvaro[y].pm10, vectorMendezAlvaro[y].calidades) != '\n'){
		printf("%s\t %s\t %s\t %s\t %s\n", vectorMendezAlvaro[y].Hora, vectorMendezAlvaro[y].no2, vectorMendezAlvaro[y].pm25, vectorMendezAlvaro[y].pm10, vectorMendezAlvaro[y].calidades);
		y++;
		break;
	}
			
	int i = 0;
	while (fscanf(fichero, "%d %d %f %f %s", &vectorMendezAlvaro[i].hora, &vectorMendezAlvaro[i].NO2, &vectorMendezAlvaro[i].PM25, &vectorMendezAlvaro[i].PM10, vectorMendezAlvaro[i].cal_aire) != EOF) {
		printf("%d\t %d\t %.3f\t %.3f\t %s\n", vectorMendezAlvaro[i].hora, vectorMendezAlvaro[i].NO2, vectorMendezAlvaro[i].PM25, vectorMendezAlvaro[i].PM10, vectorMendezAlvaro[i].cal_aire);
		i++;
	}
	
	contador = 1;
	fclose(fichero);
	
	return contador;
}

int mostrarArchivo3(TMendezAlvaro vectorMendezAlvaro[]) {
	
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
	while(fscanf(fichero, "%s %s %s %s %s", vectorMendezAlvaro[y].Hora, vectorMendezAlvaro[y].no2, vectorMendezAlvaro[y].pm25, vectorMendezAlvaro[y].pm10, vectorMendezAlvaro[y].calidades) != '\n'){
		printf("%s\t %s\t %s\t %s\t %s\n", vectorMendezAlvaro[y].Hora, vectorMendezAlvaro[y].no2, vectorMendezAlvaro[y].pm25, vectorMendezAlvaro[y].pm10, vectorMendezAlvaro[y].calidades);
		y++;
		break;
	}
			
	int i = 0;
	while (fscanf(fichero, "%d %d %f %f %s", &vectorMendezAlvaro[i].hora, &vectorMendezAlvaro[i].NO2, &vectorMendezAlvaro[i].PM25, &vectorMendezAlvaro[i].PM10, vectorMendezAlvaro[i].cal_aire) != EOF) {
		printf("%d\t %d\t %.3f\t %.3f\t %s\n", vectorMendezAlvaro[i].hora, vectorMendezAlvaro[i].NO2, vectorMendezAlvaro[i].PM25, vectorMendezAlvaro[i].PM10, vectorMendezAlvaro[i].cal_aire);
		i++;
	}
	
	contador = i;
	fclose(fichero);
	
	return contador;
}

int mostrarArchivo4(TEscuelasAguirre vectorEscuelasAguirre[]) {
	
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
	while(fscanf(fichero, "%s %s %s", vectorEscuelasAguirre[y].Hora, vectorEscuelasAguirre[y].temperatura, vectorEscuelasAguirre[y].humedad) != '\n'){
		printf("%s\t %s\t %s\n", vectorEscuelasAguirre[y].Hora, vectorEscuelasAguirre[y].temperatura, vectorEscuelasAguirre[y].humedad);
		y++;
		break;
	}
			
	int i = 0;
	while (fscanf(fichero, "%d %f %d", &vectorEscuelasAguirre[i].hora, &vectorEscuelasAguirre[i].T, &vectorEscuelasAguirre[i].HR) != EOF) {
		printf("%d\t %.1f\t %d\n", vectorEscuelasAguirre[i].hora, vectorEscuelasAguirre[i].T, vectorEscuelasAguirre[i].HR);
		i++;
	}
	
	contador = i;
	fclose(fichero);
	
	return contador;
}

int mostrarArchivo5(TEscuelasAguirre vectorEscuelasAguirre[]) {
	
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
	while(fscanf(fichero, "%s %s %s", vectorEscuelasAguirre[y].Hora, vectorEscuelasAguirre[y].temperatura, vectorEscuelasAguirre[y].humedad) != '\n'){
		printf("%s\t %s\t %s\n", vectorEscuelasAguirre[y].Hora, vectorEscuelasAguirre[y].temperatura, vectorEscuelasAguirre[y].humedad);
		y++;
		break;
	}
			
	int i = 0;
	while (fscanf(fichero, "%d %f %d", &vectorEscuelasAguirre[i].hora, &vectorEscuelasAguirre[i].T, &vectorEscuelasAguirre[i].HR) != EOF) {
		printf("%d\t %.1f\t %d\n", vectorEscuelasAguirre[i].hora, vectorEscuelasAguirre[i].T, vectorEscuelasAguirre[i].HR);
		i++;
	}
	
	contador = i;
	fclose(fichero);
	
	return contador;
}

int mostrarArchivo6(TEscuelasAguirre vectorEscuelasAguirre[]) {
	
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
	while(fscanf(fichero, "%s %s %s", vectorEscuelasAguirre[y].Hora, vectorEscuelasAguirre[y].temperatura, vectorEscuelasAguirre[y].humedad) != '\n'){
		printf("%s\t %s\t %s\n", vectorEscuelasAguirre[y].Hora, vectorEscuelasAguirre[y].temperatura, vectorEscuelasAguirre[y].humedad);
		y++;
		break;
	}
			
	int i = 0;
	while (fscanf(fichero, "%d %f %d", &vectorEscuelasAguirre[i].hora, &vectorEscuelasAguirre[i].T, &vectorEscuelasAguirre[i].HR) != EOF) {
		printf("%d\t %.1f\t %d\n", vectorEscuelasAguirre[i].hora, vectorEscuelasAguirre[i].T, vectorEscuelasAguirre[i].HR);
		i++;
	}
	
	contador = i;
	fclose(fichero);
	
	return contador;
}

void mostrarMenuMA(TMendezAlvaro vectorMendezAlvaro[], int size){
	printf("\n           MENÚ PRINCIPAL           \n");
		printf("Seleccione una opcion:\n \t\t\t1-Ver informe\n \t\t\t2-Estadísticas\n \t\t\t3-Comparación\n \t\t\t4-Información\n \t\t\t5-Imprimir todos los datos por pantalla\n \t\t\t6-Salir\n\n");
		
	return;
}

int calculoNO2max(TMendezAlvaro vectorMendezAlvaro[], int contador){
    int NO2max = 0;
    int i;
    for (i = 0; i < contador; i++) {
        if (vectorMendezAlvaro[i].NO2 > NO2max) {
            NO2max = vectorMendezAlvaro[i].NO2;
        }
    }
    return NO2max;
}

float calculoPM25max(TMendezAlvaro vectorMendezAlvaro[], int contador){
    float PM25max = 0.0;
    int i;
    for (i = 0; i < contador; i++) {
        if (vectorMendezAlvaro[i].PM25 > PM25max) {
            PM25max = vectorMendezAlvaro[i].PM25;
        }
    }
    return PM25max;
}

float calculoPM10max(TMendezAlvaro vectorMendezAlvaro[], int contador){
    float PM10max = 0.0;
    int i;
    for (i = 0; i < contador; i++) {
        if (vectorMendezAlvaro[i].PM10 > PM10max) {
            PM10max = vectorMendezAlvaro[i].PM10;
        }
    }
    return PM10max;
}

void calculomediasMA(TMendezAlvaro vectorMendezAlvaro[], int contador){
    float mediaNO2 = 0.0, mediaPM25 = 0.0, mediaPM10 = 0.0;
	
	int m;
	for (m = 0; m <= contador; m++) {
		mediaNO2 += vectorMendezAlvaro[m].NO2;
		mediaPM25 += vectorMendezAlvaro[m].PM25;
		mediaPM10 += vectorMendezAlvaro[m].PM10;
	}
	mediaNO2 /=  contador;
	mediaPM25 /=  contador;
	mediaPM10 /= contador;
	
	printf("Concentración media de NO2 en el aire: %.3f\n", mediaNO2);
	printf("Concentración media de PM 2.5 en el aire: %.3f\n", mediaPM25);
	printf("Concentración media de PM 10 en el aire: %.3f\n", mediaPM10);			
	
	return;
}


