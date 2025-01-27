



#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <iomanip>

#include <complex>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

//Se declaran las variables
int conta, pasos;
complex<double>  h1, h2, p1, p2, p0, p2f1, f2, b, d1, d2, e, h, p, f1;
double tolerancia;

//Función a evaluar
complex<double> fun(complex<double> x)
{
	complex<double> y = pow(x,4) - complex<double>(3,0) * pow(x,3) + pow(x,2) + x + complex<double>(1,0);
	return y;
}

int main(int argc, char** argv){
	//Declaramos las variables
	//Varaible para la cuenta de las iteraciones
	conta = 3;
	//cantidad de pasos máximos
	pasos = 0;
		
	//Se declara la tolerancia
	//double tolerancia = 0.000000000000000000000001;
	tolerancia = 0;
	//cout << "Ingrese la tolerancia: " << endl;
	//cin >> tolerancia; 
	cout << "Metodo de muller para la resolucion funcion x^4-3x^3+x^2+x+1=0" << endl;
	
	//Se pide la cantidad máxima de pasos
	cout << "Ingrese la cantidad maxima de pasos del programa" << endl;
	cin >> pasos;
	
	//Se le pide al usuario la tolerancia
	cout << "Ingrese la tolerancia" << endl;
	cin >> tolerancia;
	//Declaramos una variable para almacenar el valor anterior de p1
	p1 = complex<double>(-0.5,0);
	//double k2 = 0;

	//Declaramos la variable para almacenar el valor anterior de p0
	p0 = complex<double>(0.5,0);
	
	//Declaramos el valor de p2
	p2 = complex<double>(0,0);
	
	//variable f1
	f1 = complex<double>(0,0);
	
	//variable f2
	f2 = complex<double>(0,0);
	
	//recta h1 
	h1 = p1 - p0;
	
	//recta h2
	h2 = p2 - p1;
	
	//Sacamos el punto medio de la función evaluada en p0 y p1
	f1 = (fun(p1) - fun(p0)) / h1;
	
	//Sacamos el punto medio de la función evaluada en p1 y p2
	f2 = (fun(p2) - fun(p1)) / h2;
	
	//Obtenemos el valor del coeficiente de la variable de grado dos de la parabola
	d1 = (f2 - f1) / (h2 + h1);

	//Se da la cabeza de la tabla
	cout << "|i      |      p         |      f(p)      " << fixed << setprecision(12) << endl;
	cout << "------------------------------------------" << endl;
	
	//se pone el ciclo de aproximaciones, si en un momento se da con el número exacto terminaría, igual si se alcanza un error interior a la tolerancia
	while(conta <= pasos)	
	{
		//Obtenemos el valor del coeficiente de la variable grado 1 de la parábola
		b = f2 + h2*d1;
		
		//obtenemos el valor de la raiz
		d2 =  sqrt(pow(b,2) - complex<double>(4,0)*fun(p2)*d1);
		
		//Se determina el signo a usar
		if(abs(b - d2) < abs(b + d2))
		{
			e = b + d2;
		}
		else
		{
			e = b - d2;
		}
		
		//Se obtiene la parte que correspondría a la fórmula general despejada
		h = (complex<double>(-2,0)*fun(p2)) / e;
		
		//se calcula el  punto p
		p = p2 + h;
		
		if((abs(h)) < tolerancia)
		{
			if(imag(p) < 0)
			{
				//Si el valor que imag regresa es negativo, la parte imaginaria será negativa
				cout << "|" << conta << "     |" << real(p) << " + " << -1*imag(p) << "i" << "   |";
			}
			else
			{
				//si devuelve positivo es que sería negativo
				cout << "|" << conta << "     |" << real(p) << " - " << imag(p) << "i" << "   |";
			}
			if(imag(fun(p)) < 0)
			{
				cout << real(fun(p)) << " + " << -1*imag(fun(p)) << "i" << endl;
			}
			else
			{
				cout << real(fun(p)) << " - " << imag(fun(p)) << "i" << endl;
			}
			cout << endl;
			//Se da un resumen final de todo
			if(imag(p) < 0)
			{
				cout << "p: " << std::fixed << std::setprecision(17) << real(p) << " + " << -1*imag(p) << "i" << endl;
			}
			else
			{
				cout << "p: " << std::fixed << std::setprecision(17) << real(p) << " - " << imag(p) << "i" << endl;
			}
			cout << "Iter: " << conta << endl;
			cout << "Err: " << abs(h) << endl;
			break;
		}		
		
		//Se crea una fila nueva en cada iteración para formar la tabla
		if(imag(p) < 0)
		{
			//Si el valor que imag regresa es negativo, la parte imaginaria será negativa
			cout << "|" << conta << "     |" << real(p) << " + " << -1*imag(p) << "i" << "   |";
		}
		else
		{
			//si devuelve positivo es que sería negativo
			cout << "|" << conta << "     |" << real(p) << " - " << imag(p) << "i" << "   |";
		}
		if(imag(fun(p)) < 0)
		{
			cout << real(fun(p)) << " + " << -1*imag(fun(p)) << "i" << endl;
		}
		else
		{
			cout << real(fun(p)) << " - " << imag(fun(p)) << "i" << endl;
		}
		
		//Se redifinen los puntos, funciones y rectas, además se cuenta las iteraciones
		p0 = p1;
		p1 = p2;
		p2 = p;
		h1 = p1 - p0;
		h2 = p2 - p1;
		f1 = (fun(p1) - fun(p0)) / h1;	
		f2 = (fun(p2) - fun(p1)) / h2;
		d1 = (f2 - f1) / (h2 + h1);
		conta++;
	}
	//En caso de n poder encontrarlo reporta su error
	if(conta >= pasos)
	{
		cout << "El programa fallo en encontrar la solucion";
	}
	return 0;
}



