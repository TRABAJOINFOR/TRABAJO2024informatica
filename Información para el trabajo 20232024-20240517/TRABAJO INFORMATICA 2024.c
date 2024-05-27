#include <stdio.h>
#include <math.h>
#include <string.h>
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

//FUNCIONES PARA LA MEDIANA 



//FUNCIONES MOSTRAR FICHEROS Y MENUS
int mostrarArchivo1(TMendezAlvaro vectorMA[]);
int mostrarArchivo2(TMendezAlvaro vectorMA[]);
int mostrarArchivo3(TMendezAlvaro vectorMA[]);
int mostrarArchivo4(TEscuelasAguirre vectorEA[]);
int mostrarArchivo5(TEscuelasAguirre vectorEA[]);
int mostrarArchivo6(TEscuelasAguirre vectorEA[]);
void mostrarMenuMA(TMendezAlvaro vectorMA[], int size);

//FUNCIONES ESTAD�STICAS
void calculomediasMA(TMendezAlvaro vectorMA[], int i);
void calculoNO2max(TMendezAlvaro vectorMA[], int contador);
void calculoPM25max(TMendezAlvaro vectorMA[], int contador);
void calculoPM10max(TMendezAlvaro vectorMA[], int contador);
void calculoNO2min(TMendezAlvaro vectorMA[], int contador);
void calculoPM25min(TMendezAlvaro vectorMA[], int contador);
void calculoPM10min(TMendezAlvaro vectorMA[], int contador);

void calculomediasEA(TEscuelasAguirre vectorEA[], int i);
void calculoTmax(TEscuelasAguirre vectroEA[], int contador);
void calculoHRmax(TEscuelasAguirre vectorEA[], int contador);
void calculoTmin(TEscuelasAguirre vectorEA[], int contador);
void calculoHRmin(TEscuelasAguirre vectorEA[], int contador);

//FUNCIONES COMPARACI�N
void fordTEA(TEscuelasAguirre vectorEA[], int contador);
void fordT2EA(TEscuelasAguirre vectorEA[], int contador);
void fordHR2EA(TEscuelasAguirre vectorEA[], int contador);
void fordHREA(TEscuelasAguirre vectorEA[], int contador);
void fordMA(TMendezAlvaro vectorMA[], int contador);
void ford2MA(TMendezAlvaro vectorMA[], int contador);

int main() {
    setlocale(LC_CTYPE, "spanish"); // para que el compilador reconozca las � y tildes 
    int archivo, opcion, contador = 0, TAM = 25;
    TMendezAlvaro vectorMA[TAM];
    TEscuelasAguirre vectorEA[TAM];
    
    while (1) {
		
		printf ("\nIndique el archivo con el que quiera trabajar:\n \t1.Mendez �lvaro 20-12-2023\n \t2.Mendez �lvaro 31-01-2024\n \t3.Mendez �lvaro 21-02-2024\n \t4.Escuelas Aguirre 20-12-2023\n \t5.Escuelas Aguirre 31-01-2024\n \t6.Escuelas Aguirre 21-02-2024\n");
		scanf ("%d", &archivo);
		
		if (archivo < 1 || archivo > 6) {
			printf ("Lo siento, pero tiene que introducir un n�mero v�lido.\n");
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
    				printf("\nElige una opci�n que desee\n");
    				printf("\t1: Media \n");
    				printf("\t2: Mediana \n");
    				printf("\t3: M�nimos valores \n");
    				printf("\t4: M�ximos valores \n");
    				printf("\t5: Salir de estad�sticas.\n");
    				scanf("%d", &Opcion);
					//otro switch case dentro
					switch(Opcion){
						case(1): {
						calculomediasMA(vectorMA, contador);
					
							break;
						}
						case(2):{
							//MEDIANA
				
							break;
						}
						case(3):{
							calculoNO2min(vectorMA, contador);
							calculoPM25min(vectorMA, contador);
							calculoPM10min(vectorMA, contador);
							break;
						}
						case(4): {
							
							calculoNO2max(vectorMA, contador);
							calculoPM25max(vectorMA, contador);
							calculoPM10max(vectorMA, contador);
							break;
						}
					}
    				} while (Opcion != 5);
    		
				} else if (opcion == 3){
					//FUNCION 3
					int Opcion3;
					do { 
    				printf("\nElige una opci�n que desee\n");
    				printf("\t1: Valor m�ximo entre ficheros \n");
    				printf("\t2: Valor m�nimo entre ficheros\n");
    				printf("\t3: Ordenar de menor a mayor \n");
    				printf("\t4: Ordenar de mayor a menor \n");
    				printf("\t5: Salir de comparaciones.\n");
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
						}
					}
    				} while (Opcion3 != 5);
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
		//archivo 2
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
    				printf("\nElige una opci�n que desee\n");
    				printf("\t1: Media \n");
    				printf("\t2: Mediana \n");
    				printf("\t3: M�nimos valores \n");
    				printf("\t4: M�ximos valores \n");
    				printf("\t5: Salir de estad�sticas.\n");
    				scanf("%d", &Opcion);
					//otro switch case dentro
					switch(Opcion){
						case(1): {
						calculomediasMA(vectorMA, contador);
					
							break;
						}
						case(2):{
							//MEDIANA
							break;
						}
						case(3):{
							calculoNO2min(vectorMA, contador);
							calculoPM25min(vectorMA, contador);
							calculoPM10min(vectorMA, contador);

							break;
						}
						case(4): {
							calculoNO2max(vectorMA, contador);
							calculoPM25max(vectorMA, contador);
							calculoPM10max(vectorMA, contador);
							break;
						}
					}
    				} while (Opcion != 5);
				} else if (opcion == 3){
					//FUNCION 3
					int Opcion3;
					do { 
    				printf("\nElige una opci�n que desee\n");
    				printf("\t1: Valor m�ximo entre ficheros \n");
    				printf("\t2: Valor m�nimo entre ficheros\n");
    				printf("\t3: Ordenar de menor a mayor \n");
    				printf("\t4: Ordenar de mayor a menor \n");
    				printf("\t5: Salir de comparaciones.\n");
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
						}
					}
    				} while (Opcion3 != 5);
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
		//archivo 3
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
    				printf("\nElige una opci�n que desee\n");
    				printf("\t1: Media \n");
    				printf("\t2: Mediana \n");
    				printf("\t3: M�nimos valores \n");
    				printf("\t4: M�ximos valores \n");
    				printf("\t5: Salir de estad�sticas.\n");
    				scanf("%d", &Opcion);
					//otro switch case dentro
					switch(Opcion){
						case(1): {
						calculomediasMA(vectorMA, contador);
					
							break;
						}
						case(2): {
							//MEDIANA
							break;
						}
						case(3):{
							calculoNO2min(vectorMA, contador);
							calculoPM25min(vectorMA, contador);
							calculoPM10min(vectorMA, contador);

							break;
						}
						case(4): {
							calculoNO2max(vectorMA, contador);
							calculoPM25max(vectorMA, contador);
							calculoPM10max(vectorMA, contador);
							
							break;
						}
					}
    				} while (Opcion != 5);
				} else if (opcion == 3){
					//FUNCION 3
					int Opcion3;
					do { 
    				printf("\nElige una opci�n que desee\n");
    				printf("\t1: Valor m�ximo entre ficheros \n");
    				printf("\t2: Valor m�nimo entre ficheros\n");
    				printf("\t3: Ordenar de menor a mayor \n");
    				printf("\t4: Ordenar de mayor a menor \n");
    				printf("\t5: Salir de comparaciones.\n");
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
						}
					}
    				} while (Opcion3 != 5);
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
		//archivo 4
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
    				printf("\nElige una opci�n que desee\n");
    				printf("\t1: Media \n");
    				printf("\t2: Mediana \n");
    				printf("\t3: M�nimos valores \n");
    				printf("\t4: M�ximos valores \n");
    				printf("\t5: Salir de estad�sticas.\n");
    				scanf("%d", &Opcion);
					//otro switch case dentro
					switch(Opcion){
						case(1): {
						calculomediasEA(vectorEA, contador);
					
							break;
						}
						case(2): {
							//MEDIANA
							break;
						}
						case(3):{
							calculoTmin(vectorEA, contador);
							calculoHRmin(vectorEA, contador);

							break;
						}
						case(4): {
							calculoTmax(vectorEA, contador);
							calculoHRmax(vectorEA, contador);						
							
							break;
						}
					}
    				} while (Opcion != 5);
				} else if (opcion == 3){
					//FUNCION 3
					int Opcion3;
					do { 
    				printf("\nElige una opci�n que desee\n");
    				printf("\t1: Valor m�ximo entre ficheros \n");
    				printf("\t2: Valor m�nimo entre ficheros\n");
    				printf("\t3: Ordenar de menor a mayor \n");
    				printf("\t4: Ordenar de mayor a menor \n");
    				printf("\t5: Salir de comparaciones.\n");
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
						}
					}
    				} while (Opcion3 != 5);
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
		//archivo 5
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
    				printf("\nElige una opci�n que desee\n");
    				printf("\t1: Media \n");
    				printf("\t2: Mediana \n");
    				printf("\t3: M�nimos valores \n");
    				printf("\t4: M�ximos valores \n");
    				printf("\t5: Salir de estad�sticas.\n");
    				scanf("%d", &Opcion);
					//otro switch case dentro
					switch(Opcion){
						case(1): {
						calculomediasEA(vectorEA, contador);
					
							break;
						}
						case(2): {
							//MEDIANA
							break;
						}
						case(3):{
							calculoTmin(vectorEA, contador);
							calculoHRmin(vectorEA, contador);

							break;
						}
						case(4): {
							calculoTmax(vectorEA, contador);
							calculoHRmax(vectorEA, contador);						
							
							break;
						}
					}
    				} while (Opcion != 5);
				} else if (opcion == 3){
					//FUNCION 3
					int Opcion3;
					do { 
    				printf("\nElige una opci�n que desee\n");
    				printf("\t1: Valor m�ximo entre ficheros \n");
    				printf("\t2: Valor m�nimo entre ficheros\n");
    				printf("\t3: Ordenar de menor a mayor \n");
    				printf("\t4: Ordenar de mayor a menor \n");
    				printf("\t5: Salir de comparaciones.\n");
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
						}
					}
    				} while (Opcion3 != 5);
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
		//arvhivo 6
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
    				printf("\nElige una opci�n que desee\n");
    				printf("\t1: Media \n");
    				printf("\t2: Mediana \n");
    				printf("\t3: M�nimos valores \n");
    				printf("\t4: M�ximos valores \n");
    				printf("\t5: Salir de estad�sticas.\n");
    				scanf("%d", &Opcion);
					//otro switch case dentro
					switch(Opcion){
						case(1): {
						calculomediasEA(vectorEA, contador);
					
							break;
						}
						case(2): {
							//MEDIANA
							break;
						}
						case(3):{
							calculoTmin(vectorEA, contador);
							calculoHRmin(vectorEA, contador);

							break;
						}
						case(4): {
							calculoTmax(vectorEA, contador);
							calculoHRmax(vectorEA, contador);						
							
							break;
						}
					}
    				} while (Opcion != 5);
				} else if (opcion == 3){
					//FUNCION 3
					int Opcion3;
					do { 
    				printf("\nElige una opci�n que desee\n");
    				printf("\t1: Valor m�ximo entre ficheros \n");
    				printf("\t2: Valor m�nimo entre ficheros\n");
    				printf("\t3: Ordenar de menor a mayor \n");
    				printf("\t4: Ordenar de mayor a menor \n");
    				printf("\t5: Salir de comparaciones.\n");
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
						}
					}
    				} while (Opcion3 != 5);
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

	printf("Hasta la pr�xima\n"); 
	printf("FIN DEL PROGRAMA"); 
	
	
    return 0;
}






int mostrarArchivo1(TMendezAlvaro vectorMA[]) {
	
	FILE*fichero;
	int contador = 0;
	
	printf("\nHa seleccionado la opci�n 1\n");
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
	
	printf("\nHa seleccionado la opci�n 2\n");
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
	
	contador = 1;
	fclose(fichero);
	
	return contador;
}

int mostrarArchivo3(TMendezAlvaro vectorMA[]) {
	
	FILE*fichero;
	int contador = 0;
	
	printf("\nHa seleccionado la opci�n 3\n");
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
	
	printf("\nHa seleccionado la opci�n 4\n");
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
	
	printf("\nHa seleccionado la opci�n 5\n");
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
	
	printf("\nHa seleccionado la opci�n 6\n");
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
	printf("\n           MEN� PRINCIPAL           \n");
		printf("Seleccione una opcion:\n \t\t\t1-Ver informe\n \t\t\t2-Estad�sticas\n \t\t\t3-Comparaci�n\n \t\t\t4-Informaci�n\n \t\t\t5-Imprimir todos los datos por pantalla\n \t\t\t6-Salir\n\n");
		
	return;
}

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
	
	printf("Concentraci�n media de NO2 en el aire: %.3f\n", mediaNO2);
	printf("Concentraci�n media de PM 2.5 en el aire: %.3f\n", mediaPM25);
	printf("Concentraci�n media de PM 10 en el aire: %.3f\n", mediaPM10);			
	
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
	
	printf("La concentraci�n m�xima de NO2 es de %d a las %d horas\n", vectorMA[masNO2].NO2, vectorMA[masNO2].hora);
	
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
	
	printf("La concentraci�n m�xima de PM 2,5 es de %.3f a las %d horas\n", vectorMA[masPM25].PM25, vectorMA[masPM25].hora);
	
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
	
	printf("La concentraci�n m�xima de PM 10 es de %.3f a las %d horas\n", vectorMA[masPM10].PM10, vectorMA[masPM10].hora);
	
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
	
	printf("La concentraci�n m�nima de NO2 es de %d a las %d horas\n", vectorMA[menosNO2].NO2, vectorMA[menosNO2].hora);
	
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
	
	printf("La concentraci�n m�nima de PM 2,5 es de %.3f a las %d horas\n", vectorMA[menosPM25].PM25, vectorMA[menosPM25].hora);
	
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
	
	printf("La concentraci�n m�nima de PM 10 es de %.3f a las %d horas\n", vectorMA[menosPM10].PM10, vectorMA[menosPM10].hora);
	
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
	
	printf("La temperatura m�xima en las Escuelas Aguirre es de %.2f a las %d horas\n", vectorEA[masT].T, vectorEA[masT].hora);
	
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
	
	printf("La humedad relativa m�xima en las Escuelas Aguirre es de %d a las %d horas\n", vectorEA[masHR].HR, vectorEA[masHR].hora);
	
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
	
	printf("La temperatura m�nima en las Escuelas Aguirre es de %.1f a las %d horas\n", vectorEA[menosT].T, vectorEA[menosT].hora);
	
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
	
	printf("La humedad relativa m�nima en las Escuelas Aguirre es de %d a las %d horas\n", vectorEA[menosHR].HR, vectorEA[menosHR].hora);
	
	return;
}

void fordTEA(TEscuelasAguirre vectorEA[], int contador){
	int i, j, z; 
	float aux1, aux2, aux3; 
	printf("Los datos de temperatura ordenados de menor a mayor son:\n" ); 
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
	printf("Los datos de temperatura ordenados de mayor a menor son:\n" ); 
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
	printf("Los datos de humedad ordenados de menor a mayor son:\n" ); 
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
	printf("Los datos de humedad ordenados de mayor a menor son:\n" ); 
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
	printf("Los datos de NO2 ordenados de menor a mayor son:\n" ); 
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
	printf("Los datos de PM2.5 ordenados de menor a mayor son:\n" ); 
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
	printf("Los datos de PM10 ordenados de menor a mayor son:\n" ); 
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
	printf("Los datos de NO2 ordenados de mayor a menor son:\n" ); 
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
	printf("Los datos de PM2.5 ordenados de mayor a menor son:\n" ); 
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
	printf("Los datos de PM10 ordenados de mayor a menor son:\n" ); 
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

//FUNCIONES PARA LA MEDIANA 


