/* Autor: Oscar Eduardo Fletes Ixta, 24/03/2022
	PRograma que las calififcaciones de un alumno y sus faltas
	para un grupo de 10 alumnos 
	El programa tendra las siguinetes opciones:
		0.Salir
		1.Introducir datos del alumno (calif. y faltas)
		2.Imprimir
		3Promedio del grupo
		4.Cuantos aprobaron
		5.Porcentaje de asistencia de cada alumno (32 asistencias)
		
	Programa en lengaje c que almacena las calificaciones y faltas de varios alumnos, calcula el prpmedio del grupo,
	los aprobados y el porcentaje de asistencias por alumno, con el uso de funciones, protitipos de funciones, ciclo do-while,
	ciclo for, switch, condiciones y operaciones aritemticas.
	
	Autor: Oscar Eduardo Fletes Ixta
	Escuela: UVM Campus Lomas Verdes
	Materia: Programcion Estructurada
	CICLO: 01/2022

	Programa en lenguaje c que muestra el uso de:
		* Declaracion de variables 
		* Variables del tipo int, float
		* Operaciones aritmeticas 
		* Funciones
		* Prototipos de funciones
		* Uso de parametros para llamar a la funcion 
		* Uso del ciclo for
		* Uso del ciclo do-while
		* Uso de condiciones
		* Validacion de datos
		* printf para monstrar los valroes de las variables

	Objetivo:
	Mostrar el uso de variables enteras y flotantes, como declararlas, usar funciones, prototipos de funciones, 
	llamar a las funciones con parametros, usar el ciclo for, usar el ciclo do-while, condiciones, validar datos, 
	realizar operaciones aritmeticas e imprimirla.

	Breve descripcion:
	El programa  pide como entrada seleccionar la opcion 1 del menu para agrergar los datos, del tipo int y float 
	(calificacion, faltas), luego de insertar puede elegir cualquiera de las demas opciones disponibles
	El programa almacena las edades de los alumnos de un salón de 10 alumnos y el programa calcula la Media, varianza, 
	desviacion estandar, la Media y ordena las edades de menor a mayor
	*/

#include<stdio.h>//libreria para c
#include<stdlib.h>//libreria para prototipos de funciones, codigo ascii, entre otras mas funciones
#define MAX 10 //macros
//Prototipos
int menu();//funcion
float validarFlotantes(float inferior, float superior);//funcion
int validarEnteros(int inferior, int superior);//funcion
void llenar(float x[], int y[]);//funcion
void imprimir(float x[], int y[]);//funcion
void promedio(float x[]);//funcion
void aprobados(float x[], int y[])//funcion;
void asistencias(int y[]);//funcion
///Principal
int main (){
	float cal[MAX];//Variables con decimal
	int faltas[MAX];//Variables enteras
	int opcion, centinela=0;//Variables enteras
	do{//ciclo do-while
		opcion=menu();//llamar a la funcion menu 
		switch(opcion){//aswitch
			case 0: printf("Nos vemos...\n");//imprime mensaje
					break;
			case 1: llenar(cal, faltas);//ejecuta la funcion llenar con los parametros
					centinela=1;//centinela identifica que los datos sean llenados 
					break;//Es para que termine la iteraccion en ejecucuion y volver al principio, para realizar otra iteraccion 
			case 2: if(centinela==1){//condicion, si centinela tiene datos (igual 1) 
						imprimir(cal,faltas);//ejecuta la funcion imprimir con sus parametros 
					}else{//si no se cumple...
						printf("Primero debes llenar los datos. \n");//imprime mensaje 
					}
					break;//Es para que termine la iteraccion en ejecucuion y volver al principio, para realizar otra iteraccion
			case 3: if(centinela==1){//condicion, si centinela tiene datos (igual 1)
						promedio(cal);//ejecuta la funcion promedio con sus parametros 
					}else{//si no se cumple...
						printf("Primero debes llenar los datos. \n");//imprime mensaje 
					} 
					break;//Es para que termine la iteraccion en ejecucuion y volver al principio, para realizar otra iteraccion
			case 4: if(centinela==1){//condicion, si centinela tiene datos (igual 1)
						aprobados(cal,faltas);//ejecuta la funcion aprobados con sus parametros
					}else{//si no se cumple...
						printf("Primero debes llenar los datos. \n");
					} 
					break;//Es para que termine la iteraccion en ejecucuion y volver al principio, para realizar otra iteraccion
			case 5: if(centinela==1){//condicion, si centinela tiene datos (igual 1)
						asistencias(faltas);//ejecuta la funcion asistencias con sus parametros
					}else{//si no se cumple...
						printf("Primero debes llenar los datos. \n");
					} 
		}//fin del switch
	}while(opcion!=0);//do-while termina cuando la opcion sea diferente de 0
	
	return 0;
}

//Funciones 
//Funcion que muestra el menu, pide una opcion, la valdia y la rgresa 
int menu(){//funcion menu
	int opcion;//Variables enteras
	printf("-----------MENU PRINCIPAL-----------\n");//imprime mensaje 
	printf("0. Salir\n");//imprime mensaje 
	printf("1. Introducir datos\n");//imprime mensaje 
	printf("2. Imprimir\n");//imprime mensaje 
	printf("3. Promedio del grupo\n");//imprime mensaje 
	printf("4. Cuantos  aprovaron\n");//imprime mensaje 
	printf("5. Porcentaje de asistencia\n");//imprime mensaje 
	printf("------------------------------------\n");//imprime mensaje 
	printf("Selecciona uan opcion: ");//imprime mensaje 
	opcion=validarEnteros(0,5);//valida que solo las opciones dispotibles sean 0-5
	return opcion;
}

void llenar(float x[], int y[]){//funcion llenar(parametros)
	printf("Introducir datos de los alumnos\n");//imprime mensaje 
	for(int i=0;i<MAX;i++){//ciclo for 
		printf("Alumno #%d-------------\n",i);//imprime el numero de alumno
		printf("Calififcacion: ");//imprime mensaje 
		x[i]=validarFlotantes(0,10);//valida que la calificacion sea de 0-10
		printf("Faltas: ");//imprime mensaje 
		y[i]=validarEnteros(0,32);//Valida que las faltase sean de 0-32
	}
}

float validarFlotantes(float inferior, float superior){//funcion validar funcones(parametros)
	float valor;//Variables con decimal
	do{//ciclo do-while
		scanf("%f",&valor);//lee el numero insertado por el teclado
		if(valor<inferior || valor>superior){//condicon que si valor es menor que inferior o valor mayor que superior
			printf("Dato invalido!!! Debe estar entre (%.2f-%.2f). Vuelva a introducirlo: \n",inferior,superior);//imprime mensaje
			//inferior,superior lee los valores insertados en teclado (%.2f-%.2f)
		}
	}while(valor<inferior || valor>superior);//do-while termina con la misma condicon que if
	return valor;
}

int validarEnteros(int inferior, int superior){//funcion validar enteros(parametros)
	int valor;//Variables enteras
	do{//ciclo do-while
		scanf("%d",&valor);//lee el numero insertado por el teclado
		if(valor<inferior || valor>superior){//condicon que si valor es menor que inferior o valor mayor que superior
			printf("Dato invalido!!! Debe estar entre (%d-%d). Vuelva a introducirlo: \n",inferior,superior);//imprime mensaje
			//inferior,superior lee los valores insertados en teclado (%d-%d)
		}
	}while(valor<inferior || valor>superior);//do-while termina con la misma condicon que if
	return valor;
}

void imprimir(float x[], int y[]){//funcion imprimir(parametros)
	printf("DATOS DEL GRUPO\n");//imprime mensaje
	printf("-------------------------\n");//imprime mensaje
	printf("No.\tCal\tFaltas\n");//imprime mensaje
	printf("-------------------------\n");//imprime mensaje
	for(int i=0;i<MAX;i++){//ciclo for para contar los alumnos insertados 
		printf("%d\t%.1f\t%d \n", i,x[i],y[i]);//imprime el numero de alumno, calificacion, faltas
	}
	printf("-------------------------\n");//imprime mensaje
}

void promedio(float x[]){//funcion promedio(parametros)
	float suma=0,prom;//Variables con decimal
	for(int i=0;i<MAX;i++){//ciclo for, para almacenar todas las califcaciones 
		suma=suma+x[i];//Suma las calificaciones
	}
	prom=suma/MAX;//calcula el promedio
	printf("PROMEDIO DEL GRUPO\n");//imprime mensaje
	printf("-------------------------\n");//imprime mensaje
	printf("El promedio del grupo es %.1f\n",prom);//imprime el promedio del grupo
	printf("-------------------------\n");//imprime mensaje
}

void aprobados(float x[], int y[]){//funcion aprobados(parametros)
	int apro=0;//Variables enteras
	float porcentaje;//Variables con decimal
	for(int i=0;i<MAX;i++){//ciclo for para almacenar a los alumnos
		porcentaje=y[i]*100/32;//calcula el porcentaje de las faltas 
		if(x[i]>=7 && porcentaje<=10){//condicion, si las calificaciones son mayor o igual a 7 y porcentaje es menor o igual a 10
			apro++;//contador para los aprobados
		}
	}
	printf("TOTAL DE APROBADOS DEL GRUPO\n");//imprime mensaje
	printf("-------------------------\n");//imprime mensaje
	printf("Aprobados: %d\n",apro);//imprime los alumnos aprobados
	printf("-------------------------\n");//imprime mensaje
}

void asistencias(int y[]){
	int porcentaje;//Variables enteras
	printf("%% DE ASISTENCIA DEL GRUPO\n");//imprime mensaje
	printf("-------------------------\n");//imprime mensaje
	printf("No.\tAsistencias\n");//imprime mensaje
	printf("-------------------------\n");//imprime mensaje
	for(int i=0;i<MAX;i++){//ciclo for para almacenar los alumnos
		porcentaje=100-(y[i]*100/32);//calcula el porcentaje de las faltas  
		printf("%d\t%d%% \n", i,porcentaje);//imprime el numero del alumno y el porcentaje de faltas	
	}
	printf("-------------------------\n");//imprime mensaje
}
