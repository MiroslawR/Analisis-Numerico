/*
	
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
	//Se abre el archibo
	ifstream hola;
	hola.open("Matriz.txt");
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
	//Se asigna el valor a los arreglos
	while(hola >> lineax[conta] >> lineay[conta])
	{
		conta++;
	}
	//SE cierra el archivo
	hola.close();
	//Se muestra lo recuperado
	for(int vu = 0;vu<conta;vu++)
	{
		cout << lineax[vu] << " " << lineay[vu] << endl;
	}
	int m = 0;
	//Se pide el grado e la ecuación
	cout << "Datos cargados, por favor diga el grado de su ecuación" << endl;
	cout << "grado" << endl;
	cin >> m;
	m++;
	double a[m + 1][m];
	//Se forma la matriz y su matriz aumentada
	for (int alfa = 0; alfa < m; alfa++)
	{
		//SE forma la matriz principal	
		for(int d = 0 + alfa; d < m + alfa; d++)
		{
			double sum1 = 0;
			for(int s = 0;s < conta; s++)
			{
				//Se hacen las sumatorias con la potencia que se pide
				sum1 = sum1 + pow(lineax[s],d);
			}
			a[alfa][d - alfa] = sum1;
		}
		//Se forma la matriz aumentada
		if(alfa != 0)
		{
			double sum1 = 0;
			for(int s = 0;s < conta; s++)
			{
				//Se incluye el x a la potencia necesaria
				sum1 = sum1 + lineay[s]*pow(lineax[s],alfa);
			}
			a[m][alfa] = sum1;
		}
		else
		{
			double sum1 = 0;
			for(int s = 0;s < conta; s++)
			{
				//No se incluye x
				sum1 = sum1 + lineay[s];
			}
			a[m][alfa] = sum1;
		}
	}
	//Se muestra la matriz y la matriz aumentada
	for(int d = 0;d < m;d++)
	{
		for(int f = 0; f < m+1;f++)
		{
			cout << a[f][d] << " ";
		}
		cout << endl;
	}
	//Se hace eliminación gauss jordan
	for(int d = 0;d < m;d++)
	{
		//Se almacena el primer valor diferente de cero en una variable extra
		double g = a[d][d];
		//Se divide todo el renglon entre el primer valor diferente de cero dejándolo normalizado
		for(int f = 0; f < m + 1;f++)
		{
			a[f][d] = a[f][d] / g;
		}
		//Se resta el renglon normalizado a todos los  demás
		for(int f = 0; f < m;f++)
		{
			//Se almacena el primer valor diferente de cero de cada uno de los renglones que a los que se les restará el renglón normalizado
			double gh = a[d][f];
			for(int w = 0;w < m + 1;w++)
			{
				//Se discrimina al renglon normalizado
				if(f != d)
				{
					a[w][f] = a[w][f] - gh*a[w][d];
				}
			}
		}
	}
	//Se muestra la matriz procesada
	for(int d = 0;d < m;d++)
	{
		for(int f = 0; f < m+1;f++)
		{
			cout << a[f][d] << " ";
		}
		cout << endl;
	}
	//Se muestra la ecuación limpia
	for(int alfa = 0; alfa < m;alfa++)
	{
		if(alfa == 0)
		{
			if(a[m][alfa] >= 0)
			cout << a[m][m - 1 - alfa] << " ";
			else
			cout << "- " << -1*a[m][m - 1 - alfa] << " ";
		}
		else 
		{
			if(a[m][alfa] >= 0)
			cout << "+ " << a[m][m - 1 - alfa] << "x^" << alfa << " ";
			else
			cout << "- " << -1*a[m][m - 1 - alfa] << "x^" << alfa << " ";
		}
	}
	//Se calcula Sr
	double sr = 0;
	for(int s = 0;s < conta;s++)
	{
		double d = lineay[s];
		for(int f =  0; f < m;f++)
		{
			d = d - a[m][f]*pow(lineax[s],f);
		}
		sr = sr + pow(d,2);
	}
	double st = 0, prom = 0;
	//Se calcula st
	for(int s = 0;s < conta;s++)
	{
		prom = prom + lineay[s];
	}
	prom = prom / conta;
	for(int s = 0;s < conta;s++)
	{
		st = st + pow((lineay[s] - prom), 2);
	}
	//Se calcula r^2 y r
	double r2 = (st - sr)/(st);
	cout << endl << "r^2: " << r2 << endl << "r: " << sqrt(abs(r2));
	return 0;
}
