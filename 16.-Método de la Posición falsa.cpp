
#include<math.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <iomanip>
#include <cmath>
using namespace std;

int main ()
{



 //declaramos variables a usar

    double b1= 0,tol = 0,i = 1,it = 2,b2=0,q1=0,q0=0,p1=0,p=0,q=0;
    const double pi=3.141592653589793238462643383279502884197;
  
  
   
   	cout << "Metodo de Newton con uso de la secante  para la resolucion funcion cos(x)-x = 0" << endl;
   	
    //  cout<<"¿cual es el valor uno?"<<endl; //pedimos el primer valor y lo guardamos en la variable bi
 //cin >> b1;
    b1=(0.5);
     // cout<<"¿cual es el valor dos?"<<endl; //pedimos el primer valor y lo guardamos en la variable b2
  //cin >> b2;
    b2=(pi/4);
    
    cout<<"¿cual es la tolerancia de error?"<<endl; //pedimos el limite inferior y lo guardamos en la variable ai
  cin >>tol;
  
  cout<<"¿cual es el numero maximo de iteraciones?"<<endl; //pedimos el limite inferior y lo guardamos en la variable ai
  cin >>it;
 
 
 
   cout << "|      n          |      pn-1       |     f(pn)      " << fixed << setprecision(12) << endl; // cabescera de la tabla 

	cout << "------------------------------------------" << endl;
      
while (i <= it){
	
	//ecuacion cos(x)-x
	q0 = cos(b1)-b1;
	
	q1=cos(b2)-b2;
       //p = p1 - q1( p1 - p0)/(q1 - q0)
   p = b2 - (q1*(b2-b1)/(q1 - q0));
   
  //f=cos(p)-p;
  


 
if((abs(p-b1) <= tol))
{
	cout << "|" << i << "     |" << b1 << "   |" << q0 << endl;
	
	
	cout << "p: " << std::fixed << std::setprecision(12) << p << endl ;
    cout << "Iter: " << i << endl;
	cout << "error: " << abs(p-b1) << endl;
	cout<<"la raiz encontrada es"<< p <<endl;	
break;
}
	cout << "|" << i << "     |" << b1 << "   |" << q0 << endl;

 i++; 

 q = cos(p)-p;

   if (q * q1 < 0){

b1 = b2;	
q0 = q1; 

}
b1 = p;
q1 = q;
  
}
 
 if (i > it){
cout<<"la raiz no puede ser encontrada"<<endl;	

}

	return 0;

}
