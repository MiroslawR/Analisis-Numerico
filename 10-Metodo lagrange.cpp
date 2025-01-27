/*

	El programa crea una ecuación con una nube de puntos usando el método de lagrange
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include<conio.h>
#include "stdlib.h"
#include <iomanip>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	//Se abre el archivo
	ifstream hola;
	hola.open("Puntos.txt");
	/*
	int lin = 0;
	string tempn;
	for(tempn; getline(hola, tempn);)
	{
		lin++;
		cout << lin << endl;
	}
	lin++;
	*/
	//Se declaran las variables
	int lineax[1000];
	int lineay[1000];
	string temps;
	
	int conta = 0;
	//Se extraen los datos y se asigan a los arreglos
	while(hola >> lineax[conta] >> lineay[conta])
	{
		conta++;
	}
	//Se cierra el archivo
	hola.close();
	//Se muestra lo extraído
	for(int vu = 0;vu<conta;vu++)
	{
		cout << lineax[vu] << " " << lineay[vu] << endl;
	}
	//Se pide el punto X a calcular
	double x = 0;
	cout << "Datos cargados, por favor diga el punto que necesita calcular" << endl;
	cout << "punto x" << endl;
	cin >> x;
	double a = 0;
	//Se calcula la aproximación
	for (int alfa = 0; alfa < conta; alfa++)
	{
		double b = 1, c = 1;
		for(int beta = 0;beta < conta; beta++)
		{
			if(beta != alfa)
			{
				b = b*(x - lineax[beta]);
				c = c*(lineax[alfa] - lineax[beta]);
			}
		}
		a = a + ((b*lineay[alfa]) / (c));
	}
	//Se entrega la aproximación
	cout << "El valor de y para " << x << " es " << a << endl;
	return 0;
}
