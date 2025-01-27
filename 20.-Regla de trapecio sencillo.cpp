#include<iostream>
#include<conio.h>
#include <iomanip>
#include <cmath>
#include<stdlib.h>
#include<cstdlib>
#include<stdio.h>
using namespace std;

//Declaramos la fucnion

double funcion (double x)
{
	
	
     double y = 1/x;
    return y;
    
    
}
 





int main(int argc, char** argv) {
	double M=0.0,f1=0.0,tra=0.0,b=0.0,a=0.0,I=0.0,N=0.0,f2=0.0;

	
	//desarrollamos el primer caso mediante un condicional
      

      

  cout << "introdusca el numero de  diviciones del intervalo " << endl;
      cin>>N;
       cout << "introduzca el numero a " << endl;
       cin>>a;
      cout << "introduzca el numero b " << endl;
      cin>>b;
   /*  b= 0.8;
     a=0;*/
     


I=(b-a)*(funcion(a)+funcion(b))/N;
cout <<"el valor es "<<I<< endl;

	system("Pause");
return EXIT_SUCCESS;
}
