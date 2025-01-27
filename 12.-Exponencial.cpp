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
	
	
	int n,i,j,a,k;
	
	cout<<"Cuantos pares de datos seran ingresados?"<<endl;
	cin>>n;
	float x[n],y[n],A[2][2],B[2],C[2][2],cof[2];
	float xt=0,yt=0,x2=0,logy=0,xy=0,w,z,q,r;
	
	cout<<"Ingrese los valores de x :"<<endl;
	for (i = 0 ; i<n ; i++){
		cout<<"x"<<i<<" = ";
		cin>>x[i];
		xt= xt +x[i];
		x2 = x2 + pow(x[i],2);
	}
	cout<<"Ingrese los valores de y :"<<endl;
	for (i = 0 ; i<n ; i++){
		cout<<"y"<<i<<" = ";
		cin>>y[i];
		yt = yt + y[i];
		logy = logy + log(y[i]);
		xy = xy + (x[i]*log(y[i]));
	}
	B[0]=logy;
	B[1]=xy;
	A[0][0]=n;
	A[0][1]=xt;
	A[1][0]=xt;
	A[1][1]=x2;

			for (j = 0; j < 2; j++){ // lllena matriz identidad
			for(i = 0; i < 2; i++){
				C[j][i]=0;
			}
			C[j][j]=1;
			}
	
	for (a = 0; a<2;a++){ 
		z=A[a][a];
		for (k = 0; k < 2; k++){
			A[a][k]=A[a][k] / z; // CONSIGUE EL 1 EN LA DIAGONAL
			C[a][k] = C[a][k] / z;
		}
		for (i=0; i < 2; i++){
			if(i == a){
			}
			else if (i != a){
				w = A[i][a];
				for (j = 0 ; j < 2 ; j++){	
					A[i][j]= (A[i][j])-(w * A[a][j]);
					C[i][j]= (C[i][j])-(w * C[a][j]);
				}
			}
		}	
	}
	cout<<"Coeficientes :"<<endl;
	for (a = 0; a < 2; a++){
		w = 0;
		for (k = 0; k < 2; k++){
			w = w + (B[k] * C[a][k]);	
		}
		cof[a]=exp(w);
	}
	cof[1]=w;
cout<<"a = "<<cof[0]<<"\t b = "<<cof[1]<<endl;
	for (j = 0; j < n; j++){
		r = cof[0]*exp(cof[1]*x[j]);
		r = r - y[j];
		q = q + pow(r,2);
	}
	cout<<"R^2 = " <<abs(1-q)<<endl;
	
	
	
	return 0;
}
