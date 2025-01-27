#include<iostream>
#include<conio.h>
#include <iomanip>
#include <cmath>
#include<stdlib.h>
#include<cstdlib>
#include<stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	
	
		int n, x, y,a,i,w;
	float error=.01;
	float z;
	i = 1;
	cout<<"Para este programa es necesario que la matriz ingresada tenga los coeficientes mas altos en la diagonal"<<endl;
	cout<<"Ingrese la cantida de variables a encontrar (cantidad de ecuaciones)" << endl;
	cin>> n;
	
	float A[n][n];
	float B[n];	
	float sig[n];
	float ant[n];
	float auxa[n];
	float auxb=0;
	float b[n];
	
		for (x = 0; x < n; x++){ // CREA 0 en aux
			auxa[x]=0;
			sig[x]=0;
			ant[x]=0;
			b[x]=0;
		}
	
	for (x = 0; x < n; x++){ //llena matriz A
			cout<< "Ingrese los elementos del renglon " << x+1 <<" de la matriz de coeficientes"<<endl;
		for(y = 0; y < n; y++){
			cin>> A[x][y];
		}
	}
		cout<<"Ingrese la matriz de resultados: "<<endl;
	for (x = 0; x < n; x++){ // llena matriz B de resultados
		cin>>B[x];
	}
	cout<<"Ingrese cantidad maxima de iteraciones"<<endl;
	cin>>w;
	cout<<"Ingrese error de convergencia"<<endl;
	cin>>error;
		cout<<"MATRIZ INGRESADA"<<endl;
	for (x = 0; x < n; x++){ //MUESTRA LA MATRIZ INGRESADA
		for(y = 0; y < n; y++){
			cout<<A[x][y]<<"\t";
		}
		cout<<"| "<<B[x]<<endl;
		}
	for (x = 0; x < n; x++){ //QUITA 0 DE LA DIAGONAL CAMBIANDO RENGLONES
		if (A[x][x] == 0){
			for (y = x; y < n ; y++){
				if (A[y][x] == 0){
				}
				else {
					for (a = 0; a < n; a++){
					auxa[a]=A[y][a];
					A[y][a]=A[x][a];
					A[x][a]=auxa[a];
				}
				auxb=B[y];
				B[y]=B[x];
				B[x]=auxb;
				}
			}
			
		}
	}

	for(x = 0; x<n ; x++){
		z=A[x][x];
		for(y = 0; y<n ; y++){
		A[x][y]=(A[x][y])/(-z);
		}
		A[x][x]=0;
		B[x]=B[x] / z;
	}
	for(a = 0; a<n ; a++){ //hace el primer paso
		for (y = 0; y<n ; y++){
		sig[a]=sig[a]+(ant[y]*A[a][y]);
		}
		sig[a]=sig[a]+B[a];
		ant[a]=sig[a];
		}
	for (x = 0; x<n ; x++){
		while (abs(sig[x]-b[x]) > error && w>i){ //Hace los pasos hasta que el error sea menor a error
			for (y = 0; y<n ;y++){
				b[y]=sig[y];
			}
		for(a = 0; a<n ; a++){
				sig[a]=0;
				for (y = 0; y<n ; y++){
				sig[a]=sig[a]+(ant[y]*A[a][y]);
			}
			sig[a]=sig[a]+B[a];
			ant[a]=sig[a];
		}
		i++;	
		}
}
if(i > w){
	cout<<"No el error no converge a "<<error<<" en "<<w<<" iteraciones"<<endl;
}
else{
cout<<endl<<" Se llego a los resultados en "<<i+1<<" iteraciones\n\n";
cout<<" Los valores de las variables son: \n\n";
for(x = 0; x<n ; x++){
	cout<<"X"<<x<<" = "<<sig[x]<</*"	Converge a = "<<round(sig[x])<<*/endl;
}
}

	
	return 0;
}
