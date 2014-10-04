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

double ln(double n){
  	double y,c,c1,c2,c3,c4,c5,c6; //y para guardar el ln de n 
	c = (n-1)/(n+1);
	c1 = c*c;
	c2 = c*c*c*c;
	c3 = c*c*c*c*c*c;
	c4 = c*c*c*c*c*c*c*c;
	c5 = c*c*c*c*c*c*c*c*c*c;
	c6 = c*c*c*c*c*c*c*c*c*c*c*c;
	y = 2*(c*(a0+ a1*c1+ a2*c2+ a3*c3+ a4*c4+ a5*c5+ a6*c6));
	return y;
} 

int main(int argc, char **argv){		//funcion principal
  	extern char *optarg;			//arreglo definido por getopt
  	int opcion, error = 0;			// variables para el switch (opcion que se elige) y para un posible error respectivamente
  	int esta_i = 0, esta_n = 0;		// iniciamos variables para detectar si estan o no i y n en la linea de comando
  	int iteraciones = 0,i;		//iniciamos las variables iteraciones e i
	float numero = 0;		//iniciamos la variable numero
  	while((opcion = getopt(argc, argv, "i:n:"))!=-1)	// while para recibir los argumento del argv
  		switch (opcion){
  			case 'i':
  				esta_i = 1;	//registramos que había una i para las iteraciones
  				iteraciones = atoi(optarg);	//atoi para transformar la cadena de caracteres recibidos en un int y guardarlo en iteraciones
  				break;		
  			case 'n':
  				esta_n = 1;	//registramos que había un n para el numero
  				numero = atof(optarg);	//atoi para transformar la cadena de caracteres recibidos en un int y guardarlo en numero
  				break;
  			case '?':
  				error = 1;	//marcamos que hubo un error en la sintaxis de entrada
  				break;
  		}
  	if (esta_i == 0){			// en caso de que falte el parametro iteraciones en la linea de comando
  		printf("falta ingresar iteraciones \n");
  	}
  	if (esta_n == 0){			// en caso de que falte n en la linea de comando
  		printf("falta ingresar numero \n");
  	}
  	if (error == 1){			// si encontramos algun error en la sintaxis
  		printf("error de sintaxis");
  	}
  	double a = 0;				//definimos una variable a para guardar el numero
  	for(i=0;i<iteraciones;i++){		//ciclo for para realizar la cantidad de iteraciones que se ingresen
  		a = ln(numero);				//se llama a la función ln() para el numero y el resultado lo guardamos en a
	}
	printf("%f\n", a);  			//imprime resultado final del ln pedido
    
}
