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
    float T;
    int HR;
} TEscuelasAguirre;

int calculoNO2max(TMendezAlvaro vectorMendezAlvaro[], int y);


int main() {
    setlocale(LC_CTYPE, "spanish"); // para que el compilador reconozca las � y tildes 
    
	int contador;
    TMendezAlvaro vectorMendezAlvaro[TAM];
    
    FILE *fichero;
    
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
	//	contador++;
	}
	
	contador = i;
	printf("%d\n", contador);
	fclose(fichero);
    //COMIENZA EL PROGRAMA:
	int a; 
	do{
		printf("           MEN� PRINCIPAL           \n");
		printf("Seleccione una opcion:\n \t\t\t1-B�squeda de datos\n \t\t\t2-Estad�sticas\n \t\t\t3-Comparaci�n\n \t\t\t4-Informaci�n\n \t\t\t5-Imprimir todos los datos por pantalla\n \t\t\t6-Salir\n\n");
		scanf("%d", &a);
		//desarrollamos los casos citados en el men� principal
		switch (a) {
			case(1): {
				//Declaramos las variables.
				int n=0, k;
				int x,b;
				do {
					n++;
					if(n>1) {
						printf("El valor intoducido es incorrecto, por favor introd�zcalo de nuevo\n");
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
				int NO2max = calculoNO2max(vectorMendezAlvaro, y);
				int opcion;
				int x,b;
				do {
					n++;
					if(n>1) {
						printf("El valor intoducido es incorrecto, por favor introd�zcalo de nuevo\n");
					}
					printf("Ha seleccionado ESTAD�STICAS \n\n");
					printf("Si desea volver al menu principal, pulse 0, si no pulse 1\n");
					scanf("%d", &b);
				} while (b!=1 && b!=2 && b!=0); 
				if(b==0) {
					break;
				}
				do { 
    				printf("Elige una opci�n que desee\n");
    				printf("\t1: Ver todas las estad�sticas\n");
    				printf("\t2: Media \n");
    				printf("\t3: Mediana \n");
    				printf("\t4: M�nimo \n");
    				printf("\t5: M�ximo \n");
    				printf("\t6: Moda \n");
    				printf("\t7: Salir de estad�sticas.\n");
    				scanf("%d", &opcion);
					//otro switch case dentro
					switch(opcion){
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
    			} while (opcion != 7);	
					break; 				
			}
			case(3): {
				//Declaramos las variables.
				int n=0, k;
				int x,b;
				do {
					n++;
					if(n>1) {
						printf("El valor intoducido es incorrecto, por favor introd�zcalo de nuevo\n");
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
						printf("El valor intoducido es incorrecto, por favor introd�zcalo de nuevo\n");
					}
					printf("Ha seleccionado INFORMACI�N\n\n");
					printf("Si desea volver al menu principal, pulse 0\n");
					scanf("%d", &b);
				} while (b!=1 && b!=2 && b!=0); 
				if(b==0) {
					break;
				}
				do { 
    				printf("Elige una opci�n que desee\n");
    				printf("\t1: PM10\n");
    				printf("\t2: PM2,5 \n");
    				printf("\t3: Ozono Troposf�rico \n");
    				printf("\t4: Di�xido de nitr�geno \n");
    				printf("\t5: Di�xido de azufre \n");
    				printf("\t6: Salir de estad�sticas.\n");
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
						printf("El valor intoducido es incorrecto, por favor introd�zcalo de nuevo\n");
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
	}while(a!=6);
	printf("Hasta la pr�xima\n"); 
	printf("FIN DEL PROGRAMA"); 
	
    
    return 0;
}


int calculoNO2max(TMendezAlvaro vectorMendezAlvaro[], int pgeos){
    int NO2max = 0; //vectorMendezAlvaro[0].NO2;
    int i;
    for (i = 0; i < pgeos; i++) {
        if (vectorMendezAlvaro[i].NO2 > NO2max) {
            NO2max = vectorMendezAlvaro[i].NO2;
        }
    }
    return NO2max;
}




