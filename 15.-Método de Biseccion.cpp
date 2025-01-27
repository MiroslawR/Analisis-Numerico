#include<math.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <iomanip>
#include <cmath>

using namespace std;


int main(int argc, char** argv){
	//Declaramos las variables
	int i=1;
	double a=0.0,b=0.0,tol=0.0,pi=0.0,pi2=0.0;
	
	
	//Pedimos el límite superior y lo guardamos en la variable super
	cout << "Ingrese el valor de a ( limite inferior)" << endl;
	cin >> a;
	
	//Ingresamos el límite inferior y lo guardamos en la variable infer
	cout << "Ingrese el valor de b(limite superior" << endl;	
	cin >> b;
	
	 pi = (a + b) / 2;

	
	//pi2 almacena el valor anterior de k
	pi2= pi;
	cout << "|n      |        an         |        bn        |      pn      |      f(pn)      " << endl;
	cout << "|" << i << "     |" << a << "   |" << b << "    |" << pi << "   |" << cos(pi) << endl;
	while((abs(pi-pi2)/abs(pi)) > tol|| cos(pi) > tol){
		pi2 =pi;
		if(cos(pi) > 0)
		{
			b= pi;
		}
		
		else
		{
			a = pi;
		}
		
		pi= (a + b) / 2;
		i++;
		
		cout << "|" << i << "     |" << a << "   |" << b << "    |" << pi << "   |" << cos(pi)<< endl;
	}
	cout << "pi: " << std::fixed << std::setprecision(17) << pi << endl ;
	cout << "Iter: " << i<< endl;
	cout << "Err: " << abs(pi-pi2)/abs(pi) << endl;
	
	

system("Pause");
EXIT_SUCCESS;
}
