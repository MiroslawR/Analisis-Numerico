
#include <fstream>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <complex>
#include <cstdlib>
using namespace std;

int main()
{
	
	
	
		int NE,i,j,k; //Declaramos las variables que usaremos para este programa
   		 cout.precision(4);  
   		 cout.setf(ios::fixed);
	
			cout<<"Ingrese el numero de ecuasiones a resolver"<<endl;
			cin>> NE;
	//Apertura de la matriz del usario desde un archivo txt
			double matrizA[NE][NE+1], x[NE];// matriz original donde n= numero de filas y n+1= numero de columnas 
	
			ifstream inf;
			inf.open("sistema.txt");
			ofstream onf;
			onf.open("solucion.txt");
			if(!inf){//check to see if file opened 
			cerr <<"could not open file!"<< endl;	
			return EXIT_FAILURE;
			
		
				
			return EXIT_FAILURE;


}
		
	for(int i=0; i<NE; ++i){
		
			for (int j=0; j<NE+1; ++j){
	
	
			inf >> matrizA [i][j]; 
			cout << "\t" << matrizA [i][j];} 
			cout << endl;}	
	
   // eliminacion de Gauss
   
      
    for (i=0;i<NE-1;i++)            
        for (k=i+1;k<NE;k++)
            {
                double m=matrizA[k][i]/matrizA[i][i]; //Divir los elementos de la matriz
                for (j=0;j<=NE;j++)
                    matrizA[k][j]=matrizA[k][j]-m*matrizA[i][j];    //Obterner el nuevo valor para los elementos en la diagonal inferior
            }
    
    cout<<"La matriz resultante \n";
    for (i=0;i<NE;i++)           
    {
        for (j=0;j<=NE;j++)
            cout<<matrizA[i][j]<<setw(16);
        cout<<"\n";
    }
    for (i=NE-1;i>=0;i--)   //Recorrer la matriz             
    {                        
	
        x[i]=matrizA[i][NE];                
		
        for (j=i+1;j<NE;j++)
            if (j!=i)           
                x[i]=x[i]-matrizA[i][j]*x[j]; // x= a nuetras variables 
        x[i]=x[i]/matrizA[i][i];       //Obtener los valores de las variables      
    }
    cout<<"\nResultado\n ";
    for (i=0;i<NE;i++)
        cout <<x[i]<<endl;    
	       
    return 0;
	
}
 
