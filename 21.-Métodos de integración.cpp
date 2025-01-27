
//metodo demetodos de integracion
#include<iostream>
#include<conio.h>
#include <iomanip>
#include <cmath>
#include<stdlib.h>
using namespace std;


double fun (double x) //declaramos la funcion a evaluar dentro de la integral
{
     double y = 1/x;
    return y;
}
double integ(double x)//declaramos la funcion a evaluar que es resultado de la integral
{
    //Se escribe la integral de la ecuación
    return (log (x));
}



float nc38[10],ep38[10],di38[10],cn3=0.0,c1nc38=0.0,c2nc38=0.0,scnc38=0.0,	mnc38ep381=0.0,mnc38ep382=0.0,snc38ep38=0.0,snc38=0.0,sep38=0.0,Vep38=0.0,mnc38di381=0.0,mnc38di382=0.0,snc38di38=0.0,sdi38=0.0,Vdi38=0.0,de38=0.675;
int 	j2=0;


int main (){

    int M= 0;
    double a= 0;
    double b= 0;
double sum1=0;
double sum2=0;
double h=0;
    cout << "elija el metodo por el cual desea resolver la  integral precionando el numero de este " << endl;
         //estipulamos los casos
     cout << "1).metodo del trapecio " << endl;
     cout << "2).metodo de simson 1/3 " << endl;
     cout << "3).metodo de simsin 3/8 " << endl;
      cin>>M;

         //desarrollamos el primer caso mediante un condicional
      if (M==1){

          int N=0; //almacenamos el valor de las diviciones

  cout << "introdusca el numero de  diviciones del intervalo " << endl;
      cin>>N;
   /*  b= 0.8;
     a=0;*/
      b= 4;
      a=1;

 h = (b-a)/N;

double sum=fun(a);
float iter =a;

for (int i = 1; i < N ; i++)
      {
iter+=h;
    sum = sum + (2 * fun(iter));
}
  sum = sum + fun(b);

  double tra=(sum*h)/2;

cout<<"el area es:"<<tra<<endl;



double in = integ(b) - integ(a);
double err = fabs(in - tra);

cout << "El error relativo  es: " << err <<endl;

      }



      if (M==2){                   //sompson 1/3
              int N=0;
              cout << "eintrodusca el valor de n, este deve ser multiplo de 3 o de lo contrario sera incorrecta la aproximacion " << endl;
                  cin>>N;
                 /* b= 0.8;
                  a=0;*/
                  b= 4;
                  a= 1;

        double h = (b-a)/N; // generamos los intervalos

double iter=a; //almacenara el valor del primer intervalo

if(N%2==0){ // usamos el residuo para activar el condicional  dependiendo de si es o no par

for (int i = 1; i <N; i++) { //estipulamos la suma

 iter += h; //almacenara el valor de los intervalos

 if(i%2==0){// usamos el condicional  par
     double sum2=0;
      sum2 += fun(iter);
 }

 else{ //si es impar
     double sum1=0;
     sum1 += fun(iter);
 }

    }
double simp=0;//variable que almacena el resultado
simp  = (h/3)*(fun(a)+ fun(b) + 4*(sum1 ) + 2*( sum2 ) );//sumamos todos los resultados y los dividimos

cout<<"el area es"<<simp<<endl;//imprimimos resultado

double in = integ(b) - integ(a);
cout<<"El error relativo es: "<<fabs(in - simp)<<endl;//imprimimos el error calculado
}

else{
cout<<" n necesita ser par."<<endl; //condicion en caso de no ser
}

      }




      if (M==3){ //entramos en el tercer caso si se cumple la cndicion
              int N=0;

                 cout <<"n debe ser un multiplo de 3" << endl;
                 cin>>N;//almac3enamos el valor de los inrevalos
                 int n,i,c;//declaramos valiablees a usar
                  float a,b,h,s1,s2,simp;

                   b=4;
                   a=1;
                  h=(b-a)/N;
                  i=0;
                  s2=0;//suma numerro dos

                  for (i=1;i<N-1;i++)//construimos la sumatoria
                  {
                      c= i%3;

                       if (c==0) //se activa la condicion si el resudui de tres es cero  lo cual indica multiplo de tres

                        s1=s1+2*fun(a+i*h); // sumatoria uno
                        else
                        s2=s2+3*fun(a+i*h);//sumatoria dos
                  }
                   simp=(((3*h)/8)*(fun(a)+s1+s2+fun(b)));//resusltado de la sumatoria de todo

                      cout<<"el area es:"<<simp<< endl;

                      double in = integ(b) - integ(a);
                      cout<<"El error relativo es: "<<fabs(in - simp)<<endl; // imprimimos el resultado  del error calcul<ado
                      return 0;
                   }
}
