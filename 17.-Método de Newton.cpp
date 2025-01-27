
#include<math.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <iomanip>
#include <cmath>

using namespace std;


int main(int argc, char** argv){
	//Declaramos las variables
	//variable para el límite inferior
	double infer = 0;
	//Varaible para la cuenta de las iteraciones
	int conta = 1;
	//Variable para el límite superior
	double super = 0;
	//Declarar cantidad de pasos máximos
	int pasos = 0;
		
	//Se declara la tolerancia
	double tolerancia = 0.000000001;
	//double tolerancia = 0;
	//cout << "Ingrese la tolerancia: " << endl;
	//cin >> tolerancia; 
	cout << "Metodo de Newton para la resolucion funcion x^3 + 4*x^2 - 10=0" << endl;
	
	//Se pide la cantidad máxima de pasos
	cout << "Ingrese la cantidad maxima de pasos del programa" << endl;
	cin >> pasos;
	
	//Declaramos una variable para almacenar el valor anterior de k
	double k2 = 1;
	
	//Declaramos la variable f, que es la función, y le damos su valor
	double f = 0;
	
	//DEclaramos la variable fp, que es la derivada de f, y le damos valor
	double fp = 0;
	
	//Declaramos k
	double k = 0;
	
	//Se da la cabeza de la tabla
	cout << "|n      |      pn      |      pn-1    |      f(pn)      " << fixed << setprecision(10) << endl;
	cout << "------------------------------------------" << endl;
	
	//se pone el ciclo de aproximaciones, si en un momento se da con el número exacto terminaría, igual si se alcanza un error interior a la tolerancia
	while(conta <= pasos){
		//Le damos su valor a f
		f = (pow(k2,3)) + (4*(pow(k2,2))) - 10;
		
		//Le damos su valor a fp
		fp = 3*(pow(k2,2)) + (8*(k2));
		
		//Se recalcula k
		k = k2 - f/fp;

		
		if((abs(k-k2)/abs(k)) <= tolerancia)
		{
			cout << "|" << conta << "     |" << k << "   |" << k2 << "   |" << f << endl;
			cout << endl;
			//Se da un resumen final de todo
			cout << "K: " << std::fixed << std::setprecision(17) << k << endl ;
			cout << "Iter: " << conta << endl;
			cout << "Err: " << abs(k-k2)/abs(k) << endl;
			break;
		}		
		
		//Se crea una fila nueva en cada iteración para formar la tabla
		cout << "|" << conta << "     |" << k << "   |" << k2 << "   |" << f << endl;
		k2 = k;
		//se cuenta la iteracion
		conta++;
	}
	//En caso de n poder encontrarlo reporta su error
	if(conta >= pasos)
	{
		cout << "El programa falló en encontrar la solucion";
	}
	return 0;
}
