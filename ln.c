#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>


//Esta es la primera version de nuestro programa
double ln(double n){
	double y,a,b,c;			//y para guardar el ln de n
	a = n-1;			
	b = n+1;
	c = a/b;
	y = c +				//realizaremos solo parte de la serie de taylor, para i = 0 hasta 7
	c*c*c/3+
	c*c*c*c*c/5+
	c*c*c*c*c*c*c/7+
	c*c*c*c*c*c*c*c*c/9+
	c*c*c*c*c*c*c*c*c*c*c/11+
	c*c*c*c*c*c*c*c*c*c*c*c*c/13;
	return 2*y;
	}
	

//funcion principal
int main(int argc, char **argv){ 
	extern char *optarg;			//arreglo definido por getopt
	int opcion, error = 0;				// variables para el switch (opcion que se elige) y para un posible error respectivamente
	int esta_i =0, esta_n=0;			// iniciamos variables para detectar si estan o no i y n en la linea de comando
	int numero = 0, iteraciones =0,i;		//iniciamos las variables numero iteraciones e i
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
				numero = atoi(optarg); //atoi para transformar la cadena de caracteres recibidos en un int y guardarlo en numero
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
