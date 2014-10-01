#include <stdio.h> 

double static a0 = 1.0; //para guardar 1
double static a1 = 0.3333333333333; // para guardar 1/3
double static a2 = 0.2;             // para guardar 1/5
double static a3 = 0.1428571428571; // para guardar 1/7
double static a4 = 0.1111111111111; // para guardar 1/9
double static a5 = 0.090909090909; // para guardar 1/11
double static a6 = 0.076923076923; // para guardar 1/13

double ln(double n){		//función de ln
  	double y,a,b,c; 	//y para guardar el ln de n 
	a = n-1; 
	b = n+1; 
	c = a/b; 
	y = a0*c+       	//representacion de la serie de taylor
	a1*c*c*c+ 
	a2*c*c*c*c*c+ 
	a3*c*c*c*c*c*c*c+ 
	a4*c*c*c*c*c*c*c*c*c+ 
	a5*c*c*c*c*c*c*c*c*c*c*c+ 
	a6*c*c*c*c*c*c*c*c*c*c*c*c*c; 
	return 2*y;
} 
    

int main(int argc, char **argv){		//funcion principal
  	extern char *optarg;
  	int opcion, error = 0;
  	int esta_i = 0, esta_n = 0;
  	int numero = 0, iteraciones = 0,i;
  	while((opcion = getopt(argc, argv, "i:n:"))!=-1)
  		switch (opcion){
  			case 'i':
  				esta_i = 1;
  				iteraciones = atoi(optarg);
  				break;
  			case 'n':
  				esta_n = 1;
  				numero = atoi(optarg);
  				break;
  			case '?':
  				error = 1;
  				break;
  		}
  	if (esta_i == 0){
  		printf("falta ingresar iteraciones \n");
  	}
  	if (esta_n == 0){
  		printf("falta ingresar numero \n");
  	}
  	if (error == 1){
  		printf("error de sintaxis");
  	}
  	double a = 0;				//definimos una variable a para guardar el numero
  	for(i=0;i<iteraciones;i++){		//ciclo for para realizar la cantidad de iteraciones que se ingresen
  		a = ln(numero);				//se llama a la función ln() para el numero y el resultado lo guardamos en a
	}
	printf("%f\n", a);  			//imprime resultado final del ln pedido
}
