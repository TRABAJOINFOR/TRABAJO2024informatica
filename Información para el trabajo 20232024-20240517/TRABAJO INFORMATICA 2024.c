#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>

typedef struct {
    int hora;
    int NO2;
    float PM25;
    float PM10;
    char cal_aire[20];
} TMendezAlvaro;

typedef struct {
    int hora;
    float T;
    int HR;
} TEscuelasAguirre;



int main() {
	setlocale(LC_CTYPE, "spanish"); // para que el compilador reconozca las � y tildes 
    int TAM = 30;
    TMendezAlvaro vectorMendezAlvaro[TAM];
    TEscuelasAguirre vectorEscuelasAguirre[TAM];
    
    FILE *fichero;
    
    fichero = fopen("20122023_MendezAlvaro.txt", "r");
    
    if (fichero == NULL) {
        printf("\nError al abrir el archivo\n");
        return 0;
    }
            
    //printf("Fichero de datos cargado exitosamente\n");
    
    int y = 0;
    while (fscanf(fichero, "%d %d %f %f %s", &vectorMendezAlvaro[y].hora, &vectorMendezAlvaro[y].NO2, &vectorMendezAlvaro[y].PM25, &vectorMendezAlvaro[y].PM10, vectorMendezAlvaro[y].cal_aire) != EOF) {
        //printf("%d %d %.2f %.2f %s\n", vectorMendezAlvaro[y].hora, vectorMendezAlvaro[y].NO2, vectorMendezAlvaro[y].PM25, vectorMendezAlvaro[y].PM10, vectorMendezAlvaro[y].cal_aire);
        y++;
        if (y >= TAM) break; 
    }
    
    fclose(fichero);
    
    FILE *fichero2;
    
    fichero2 = fopen("20122023_EscuelasAguirre.txt", "r");
    
    if (fichero2 == NULL) {
        printf("\nError al abrir el archivo\n");
        return 0;
    }
            
    //printf("Fichero de datos cargado exitosamente\n");
    
    int i = 0;
    while (fscanf(fichero2, "%d %f %d", &vectorEscuelasAguirre[i].hora, &vectorEscuelasAguirre[i].T, &vectorEscuelasAguirre[i].HR) != EOF) {
        //printf("%d %.1f %d\n", vectorEscuelasAguirre[i].hora, vectorEscuelasAguirre[i].T, vectorEscuelasAguirre[i].HR);
        i++;
        if (i >= TAM) break; 
    }
    
    fclose(fichero2);
    //COMIENZA EL PROGRAMA:
	int a, contador=0; 
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
				int opcion;
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

