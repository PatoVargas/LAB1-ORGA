#include <stdio.h> 

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
