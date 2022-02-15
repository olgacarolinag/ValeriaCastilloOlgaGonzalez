#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <fstream>

using namespace std;

double function(double x){

    return (exp((pow(-x, 2))));

}

double CentralDerivative(double x, double h){

    double d = 0.;

    if(h!=0){
         d = (function(x+h) - function(x-h))/(2*h);
    }

    return (d);

}

int main(){

    double h = 0.01;

    double X[4000];

    for(int i = 0; i < 4001; i+= 1){

        X[i] = -20+(i)*(h);
    }



    std::ofstream *File; // Definimos apuntador

	File = new std::ofstream[2]; // Reservamos memoria

	File[0].open( "Derivaditas.dat", std::ofstream::trunc ); // Abrir y dejar listo para escribir

	std::cout << File  << std::endl;

	for(int i = 0; i < 4000; i++){
		File[0] << X[i] << " " << CentralDerivative(X[i], h) << std::endl;
		//std::cout << i << std::endl;
	}


	File[0].close();

	return 0;

}
