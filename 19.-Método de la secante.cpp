#include<math.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <iomanip>
#include <cmath>

using namespace std;
const double pi = 3.141592653589793238462643383279502884197;
//Se declaran las variables
int conta, pasos;
double tolerancia, k2, f, fp, k, k3;

int main(int argc, char** argv){
	//Declaramos las variables
	//Varaible para la cuenta de las iteraciones
	conta = 0;
	//cantidad de pasos máximos
	pasos = 0;
		
	//Se declara la tolerancia
	//double tolerancia = 0.000000000000000000000001;
	tolerancia = 0;
	//cout << "Ingrese la tolerancia: " << endl;
	//cin >> tolerancia; 
	cout << "Metodo de la secante "<< endl;
	
	//Se pide la cantidad máxima de pasos
	cout << "Ingrese la cantidad maxima de pasos del programa" << endl;
	cin >> pasos;
	
	//Se le pide al usuario la tolerancia
	cout << "Ingrese la tolerancia" << endl;
	cin >> tolerancia;
	
	//Declaramos una variable para almacenar el valor anterior de k
	k2 = pi/4;
	//double k2 = 0;
		
	//Le pedimos al usuario el punto inicial 1
	//cout << "Ingrese el punto inicial 1 para el programa" << endl;
	//cin >> k2;
	
	//Le pedimos al usuario el punto inicial 0
	//cout << "Ingrese el punto inicial 0 para el programa" << endl;
	//cin >> k3;
	//Declaramos la variable para almacenar el valor anterior de k2
	k3 = 0.5;
	
	//variable f, que es la función, y le damos su valor
	f = 0;
	
	//variable fp, que es la función en el lugar anterior, y le damos valor
	fp = 0;
	
	//Variable k, el valor del punto donde está
	k = 0;
	
	//Se da la cabeza de la tabla
	cout << "|n      |      pn        |      pn-1       |      pn-2       |      f(pn)      " << fixed << setprecision(12) << endl;
	cout << "------------------------------------------" << endl;
	
	//se pone el ciclo de aproximaciones, si en un momento se da con el número exacto terminaría, igual si se alcanza un error interior a la tolerancia
	while(conta <= pasos){
		//Le damos su valor a f
		f = cos(k2);//cos(pn-1)
		//f = (pow(k2,3)) + (4*(pow(k2,2))) - 10;
		
		//Le damos su valor a fp
		fp = cos(k3); //cos(pn-2)
		
		
		//Se recalcula k
		//k = k2 - f*((k2-k3)/(f-fp));
		k = k2 - ((k2-k3)*(f-k2))/((f-k2)-(fp-k3));
		
		if((abs(k-k2)) <= tolerancia)
		{
			cout << "|" << conta << "     |" << k << "   |" << k2 << "   |" << k3 << "   |" << f << endl;
			cout << endl;
			//Se da un resumen final de todo
			cout << "K: " << std::fixed << std::setprecision(17) << k << endl ;
			cout << "Iter: " << conta << endl;
			cout << "Err: " << abs(k-k2) << endl;
			break;
		}		
		
		//Se crea una fila nueva en cada iteración para formar la tabla
		cout << "|" << conta << "     |" << k << "   |" << k2  << "   |" << k3 << "   |" << f << endl;
		k3 = k2;
		k2 = k;
		//se cuenta la iteracion
		conta++;
	}
	//En caso de n poder encontrarlo reporta su error
	if(conta >= pasos)
	{
		cout << "El programa fallo en encontrar la solucion";
	}
	return 0;
}
