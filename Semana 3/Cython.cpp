#include <iostream>
#include <fstream>
#include <math.h>
#define _USE_MATH_DEFINES
#include <cmath>

double f(double x){
	
	double b = exp(-pow(x,2.));
	
	return b;
}

int main() {
	
	double dx = 0.01;
	
	double x0 = -20.;
	
	double x[4000];
	
	for(int i = 0; i<4000; i++){
		
		x[i] = x0;
		
		x0 += 0.01;
	} 
	
	
	std::ofstream *File;  //Acá definimos apuntador 
	
	File = new std::ofstream[2] ;    //Definición de espacio en memoria, es un array como de python

	File[0].open("MisDatos.dat", std::ofstream::trunc);    //Abrir y dejar listo para escribir
	File[0] << "X" << " , " << "D" << std::endl;
	
	for(int i = 0; i<=4000;i++) {
		
		if(i==0){
			
			double a = ( f(x[i+1])-f(x[i]) ) / dx;
			File[0] << x[i] << " , " << a << std::endl;
				
		}
		
		if(i!=0 && i<4000){
			
			double a = ( f(x[i+1])-f(x[i-1]) )/(2.*dx);
			
			File[0] << x[i] << " , " << a << std::endl;	
		}
		
		else{
			
			double a = ( f(x[i-1])-f(x[i]) ) / dx;
			File[0] << x[i] << " , " << a << std::endl;
		}
		
	}
	
	File[0].close();
	
	return 0; 
}
