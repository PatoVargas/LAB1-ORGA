#include <stdio.h> 

double static a0 = 1.0; //para guardar 1
double static a1 = 0.3333333333333; // para guardar 1/3
double static a2 = 0.2;             // para guardar 1/5
double static a3 = 0.1428571428571; // para guardar 1/7
double static a4 = 0.1111111111111; // para guardar 1/9
double static a5 = 0.090909090909; // para guardar 1/11
double static a6 = 0.076923076923; // para guardar 1/13

double ln(double n){
  	double y,a,b,c; //y para guardar el ln de n 
	c = (n-1)/(n+1); 
	y = a0*c+       //representacion de la serie de taylor
	a1*c*c*c+ 
	a2*c*c*c*c*c+ 
	a3*c*c*c*c*c*c*c+ 
	a4*c*c*c*c*c*c*c*c*c+ 
	a5*c*c*c*c*c*c*c*c*c*c*c+ 
	a6*c*c*c*c*c*c*c*c*c*c*c*c*c; 
	return 2*y;
} 
    

int main(){
  	double numero;
  	int i,iteraciones;
  	printf("ingrese un numero: ");
  	scanf("%lf",&numero);
  	printf("ingrese cantidad de iteraciones: ");
  	scanf("%i",&iteraciones);
  	double a = 0;
  	for(i=0;i<iteraciones;i++){		//ciclo for para realizar la cantidad de iteraciones que se ingresen
  	a = ln(numero);
	}
	printf("el ln del numero es: %f\n", a);  //imprime resultado final del ln pedido
}
