#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>


double static a0 = 1.0; //para guardar 1
double static a1 = 0.3333333333333; // para guardar 1/3
double static a2 = 0.2;             // para guardar 1/5
double static a3 = 0.1428571428571; // para guardar 1/7
double static a4 = 0.1111111111111; // para guardar 1/9
double static a5 = 0.090909090909; // para guardar 1/11
double static a6 = 0.076923076923; // para guardar 1/13

//funcion ln para esta segunda mejora
double ln(double n){
  	double y,c; //y para guardar el ln de n 
	c = (n-1)/(n+1); 
	y = 2*(a0*c+       //representacion de la serie de taylor 
	a1*c*c*c+ 
	a2*c*c*c*c*c+ 
	a3*c*c*c*c*c*c*c+ 
	a4*c*c*c*c*c*c*c*c*c+ 
	a5*c*c*c*c*c*c*c*c*c*c*c+ 
	a6*c*c*c*c*c*c*c*c*c*c*c*c*c); 
	return y;
} 
    

//funcion principal
int main(int argc, char **argv){ 
	extern char *optarg;			//arreglo definido por getopt
	int opcion, error = 0;				// variables para el switch (opcion que se elige) y para un posible error respectivamente
	int esta_i =0, esta_n=0;			// iniciamos variables para detectar si estan o no i y n en la linea de comando
	int iteraciones = 0,i;		//iniciamos las variables iteraciones e i
	float numero = 0;		//iniciamos la variable numero
	while((opcion = getopt(argc, argv, "i:n:"))!=-1) // while para recibir los argumento del argv
		switch (opcion){			
			case 'i':
				//en el caso de encontrar una i en la linea de comando				
				esta_i =1;	//registramos que había una i para las iteraciones
				iteraciones = atoi(optarg);  //atoi para transformar la cadena de caracteres recibidos en un int y guardarlo en iteraciones
				break;
			case 'n':
				//en el caso de encontrar una n en la linea de comando	
				esta_n =1; 	//registramos que había un n para el numero
				numero = atof(optarg); //atoi para transformar la cadena de caracteres recibidos en un int y guardarlo en numero
				break;
			case '?':
				// en otro caso 
				error = 1;		//marcamos que hubo un error en la sintaxis de entrada
				break;
			
	}

	if (esta_i == 0){		// en caso de que falte el parametro iteraciones en la linea de comando
		printf("falta ingresar iteraciones \n");
	}
	if (esta_n == 0){		// en caso de que falte n en la linea de comando
		printf("falta ingresar numero \n");
	}


	if (error == 1){		// si encontramos algun error en la sintaxis
		printf("error de sintaxis");	
	}
	
	//para calcular el ln 
	double a = 0; 			//iniciamos un double para guardar el numero
	for(i=0;i<iteraciones;i++){ 	// for para repetir el proceso de calculo en iteraciones
		a = ln(numero); 	// llamamos a la funcion ln para el numero y la guardamos en a
	} 
	printf("%f\n", a); 		//devolver el valor del ln
}
