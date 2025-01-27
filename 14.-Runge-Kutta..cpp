#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	
	
		int i,a;
	float xi,xf,h,k,y,k1,k2,k3,k4;
	
	cout<<"Ingrese valor inicial de x : \nx0 = ";
	cin>>xi;
	cout<<"Ingrese valor final de x : \nxf =";
	cin>>xf;
	cout<<"Ingrese valor inicial de y : \ny =";
	cin>>y;
	cout<<"Ingrese numero de iteraciones : \ni =";
	cin>>i;
	h = (xf - xi)/i;
	cout<<"\nh = "<<h<<endl;
	cout<<"0  |x= "<<xi<<"  y= "<<y;
	k1 = (xi*y);
	k2 = (xi+(h/3))*(y+((h/3)*k1));
	k3 = (xi+(2*h/3))*(y+(h*k2)-((h/3)*k1));
	k4 = (xi+h)*(y+(h*k3)-(h*k2)+(h*k1));
	
	cout<<"  k1= "<<k1<<"  k2= "<<k2<<"  k3= "<<k3<<"  k4= "<<k4<<endl;
	k = xi+h;
	for(a = 1; a<=i ; a++)
	{
		y = y + ((h/8)*(k1+(3*k2)+(3*k3)+k4));
		k1 = (k*y);
		k2 = (k+(h/3))*(y+((h/3)*k1));
		k3 = (k+(2*h/3))*(y+(h*k2)-((h/3)*k1));
		k4 = (k+h)*(y+(h*k3)-(h*k2)+(h*k1));
		
		cout<<a<<"  |x= "<<k<<"  y= "<<y<<"  k1= "<<k1<<"  k2= "<<k2<<"  k3= "<<k3<<"  k4= "<<k4<<endl;
		k=k+h;
	}
	cout<<"\nEl resultado es : \n\ty = "<<y<<endl;
	return 0;
}
