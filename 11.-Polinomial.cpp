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
	float x[n],y[n],xx[6]={0},A[4][4],B[4],C[4][4],cof[4];
	float xt=0,yt=0,xy=0,x2y=0,x3y=0,w,z,q,r;
	
	cout<<"Ingrese los valores de x :"<<endl;
	for (i = 0 ; i<n ; i++){
		cout<<"x"<<i<<" = ";
		cin>>x[i];
		xx[0] = xx[0]+x[i];
	}
	cout<<"Ingrese los valores de y :"<<endl;
	for (i = 0 ; i<n ; i++){
		cout<<"y"<<i<<" = ";
		cin>>y[i];
		yt = yt+y[i];
		xy = xy + (y[i]*x[i]);
		x2y = x2y + (y[i]*pow(x[i],2));
		x3y = x3y + (y[i]*pow(x[i],3));
	}
	B[0]=yt;
	B[1]=xy;
	B[2]=x2y;
	B[3]=x3y;
	for (j = 1; j<6 ; j++){
	for (i = 0; i<n ; i++){
		xx[j]= xx[j]+ pow(x[i],(j+1));
	}
	}
	for (j = 0; j<4 ; j++){
		for (i = 0; i<4;i++){
			A[j][i]=xx[j-1+i];
		} 
	}
	A[0][0]=n;
	
		for (j = 0; j < 4; j++){ // lllena matriz identidad
		for(i = 0; i < 4; i++){
			C[j][i]=0;
		}
		C[j][j]=1;
	}
	
	for (a = 0; a<4;a++){ 
		z=A[a][a];
		for (k = 0; k < 4; k++){
			A[a][k]=A[a][k] / z; // CONSIGUE EL 1 EN LA DIAGONAL
			C[a][k] = C[a][k] / z;
		}
		for (i=0; i < 4; i++){
			if(i == a){
			}
			else if (i != a){
				w = A[i][a];
				for (j = 0 ; j < 4 ; j++){	
					A[i][j]= (A[i][j])-(w * A[a][j]);
					C[i][j]= (C[i][j])-(w * C[a][j]);
				}
			}
		}	
	}
	cout<<"Coeficientes :"<<endl;
	for (a = 0; a < 4; a++){
		w = 0;
		for (k = 0; k < 4; k++){
			w = w + (B[k] * C[a][k]);	
		}
		cof[a]=w;
		cout<<"coeficiente "<<a<<" = "<<cof[a]<<endl;
	}
	
	for (j = 0; j < n; j++){
		r = cof[0]+(cof[1]*x[j])+(cof[2]*pow(x[j],2))+(cof[3]*pow(x[j],3));
		r = r - y[j];
		q = q + pow(r,2);
	}
	cout<<"R^2 = " <<abs(1-q)<<endl;
	
	
	
	
	
	
	return 0;
}
