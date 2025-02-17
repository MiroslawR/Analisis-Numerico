#include<math.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <iomanip>
#include <cmath>
using namespace std;

int main ()
{
    int suma = 0;
    double inf = 0;
	double sup = 0;
	double base = 0;
	double error = 0;
    double num = 0;
  cout <<"¿cual es l limite inferior?"<<endl;
  cin>>inf;
  
   cout <<"¿cual es limite superior?"<<endl;
  cin>>sup;
  
   cout <<"ingresa la base "<<endl;
  cin>>base;
  
   cout <<"ingresa el marjen de error deseado"<<endl;
  cin>>error;

    double k = (sup + inf) / 2;
  
 
	cout << "Ingresa el numero  mayor a 0" << endl; // valor de x
	cin >> num;
	
	while (abs(num-pow(base,k))>error) 	{
		
		
		if(num < pow(base,k))
		{
			sup = k;
		}
		
		else
		{
			inf = k;
		}

		k = (sup + inf) / 2;
		suma++;
	}
		
	cout << "K: " << std::fixed << std::setprecision(17) << k << endl ;
	cout << "Err: " << abs(num - pow(base,k)) << endl;
    cout << "Iter: " << suma << endl;
	
	return 0;
}

