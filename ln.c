#include <stdio.h>

double ln(double n){
	double y,a,b,c;			//y para guardar el ln de n
	a = n-1;
	b = n+1;
	c = a/b;
	y = c +
	c*c*c/3+
	c*c*c*c*c/5+
	c*c*c*c*c*c*c/7+
	c*c*c*c*c*c*c*c*c/9+
	c*c*c*c*c*c*c*c*c*c*c/11+
	c*c*c*c*c*c*c*c*c*c*c*c*c/13;
	return 2*y;
	}
	

int main(){
	double numero;
	int i,iteraciones;
	printf("ingrese un numero: ");
 	scanf("%lf",&numero);
	printf("ingrese cantidad de iteraciones: ");
 	scanf("%i",&iteraciones);
		
	double a;
	for (i=0; i < iteraciones; i++){
		a = ln(numero);
	}

	printf("el ln del numero es: %f\n", a);
	}


