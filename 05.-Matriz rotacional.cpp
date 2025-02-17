#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,i,j;
	
	cout <<"Ingrese la dimension de la matriz nxn"	<< endl;	
cin>>n;
	int Matriz[n][n], MatrizT[n][n],MatrizV[n][n],Matriz90[n][n],MatrizH[n][n],Matriz180[n][n],	MatrizD[n][n],Matriz360[n][n],Matriz270[n][n];
		
ifstream inf;
inf.open("Matriz.txt");
ofstream T,V,H,D,M90,M180,M360,M270;
T.open("MatrizTranspuesta.txt");
V.open("MatrizVertical.txt");
H.open("MatrizHorizontal.txt");
D.open("MatrizDiagonal.txt");
M90.open("Matriznoventa.txt");
M180.open("Matrizcientochenta.txt");
M270.open("MatrizDoscieentossetenta.txt");
M360.open("Matriztrescientossesenta.txt");
if (! inf){
	cerr << "could not open file" << endl;
	return EXIT_FAILURE;
}
	
for(int i=0; i<n; ++i){
		
	for (int j=0; j<n; ++j){
	
	
	inf >> Matriz [i][j];
	cout <<"\t"<< Matriz [i][j]  ;}
	cout << endl;}	
	//Generar la matriz Trnspesta 
	
	// Traspuesta
  for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
    MatrizT[i][j]=Matriz[j][i];
     
  
  //muestro la traspuesta
  cout<<"\n La Matriz  traspuesta es  :"<<endl;
  
	for (int i=0; i<n; i++)
    {for (int j=0; j<n; j++)
       { MatrizT[i][j]=0;
          {MatrizT[i][j]=Matriz[j][i];
          cout<<" ";
        
           cout<<MatrizT[i][j] ;
             cout<<" ";
          
           T<< MatrizT[i][j]<< " ";
          }
        
       }
       T<<endl;
           cout<<endl;   
    }
   cout<<endl;
	

	
		 
 
T.close();


//Matriz Vertical 

    for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  MatrizV[j][i]=Matriz[i][n-1-j];
  
  //muestro 
  cout<<"\n La Matriz vertical es  :"<<endl;
 		for (int i=0; i<n; i++)
    {for (int j=0; j<n; j++)
       { MatrizV[i][j]=0;
          {MatrizV[j][i]=Matriz[i][n-1-j];
          cout<<" ";
        
           cout<<MatrizV[j][i] ;
             cout<<" ";
          
           V<< MatrizV[j][i]<< " ";
          }
        
       }
       V<<endl;
           cout<<endl;   
    }
   cout<<endl;
	
	
		 
 
V.close();

	//Matriz de 90 grados  
	
	  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  Matriz90
  [i][j]=Matriz[i][n-1-j];
  
 cout<<"\n La Matriz de 90 grados es  :"<<endl;
 	for (int i=0; i<n; i++)
    {for (int j=0; j<n; j++)
       { Matriz90[i][j]=0;
          {Matriz90[i][j]=Matriz[i][n-1-j];
          cout<<" ";
        
           cout<<Matriz90[j][i] ;
             cout<<" ";
          
           M90<< Matriz90[j][i]<< " ";
          }
        
       }
       M90<<endl;
           cout<<endl;   
    }
   cout<<endl;
	
		 
 
M90.close();

		//Matriz Horizontal  
	
	  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  MatrizH[j][i]=Matriz[n-1-i][j];
  
  //muestro 
   cout<<"\n La Matriz Horizontal es  :"<<endl;
 	for (int i=0; i<n; i++)
    {for (int j=0; j<n; j++)
       { MatrizH[j][i]=0;
          {MatrizH[j][i]=Matriz[n-1-i][j];
          cout<<" ";
        
           cout<<MatrizH[j][i] ;
             cout<<" ";
          
           H<< MatrizH[j][i]<< " ";
          }
        
       }
       H<<endl;
           cout<<endl;   
    }
   cout<<endl;
	
		 
 
H.close();
	
	//Matriz de 180 grados 
	
	  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  Matriz180[i][j]=Matriz[n-1-i][j];
  
  //muestro 
  cout<<"\n La Matriz de 180 grados es  :"<<endl;
 	for (int i=0; i<n; i++)
    {for (int j=0; j<n; j++)
       { Matriz180[i][j]=0;
          {Matriz180[i][j]=Matriz[n-1-i][j];
          cout<<" ";
        
           cout<<Matriz180[i][n-1-j] ;
             cout<<" ";
          
           M180<< Matriz180[i][n-1-j]<< " ";
          }
        
       }
       M180<<endl;
           cout<<endl;   
    }
   cout<<endl;
	
	
		 
 
M180.close();

		
//Matriz Diagonal  
	
	  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  MatrizD[j][i]=Matriz[n-1-i][j];
  
  //muestro 
   cout<<"\n La Matriz Diagonal es  :"<<endl;
 	for (int i=0; i<n; i++){
	
    for (int j=0; j<n; j++){
     
	 
	      D<< MatrizD[n-1-i][j]<<" ";
        	cout <<"\t"<< MatrizD[n-1-i][j]  ;}
	cout << endl;}
	
		 
 
D.close();

	
		//Matriz de 360 grados 

	  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  Matriz360[i][j]=Matriz[n-1-i][j];
  
  //muestro 
 cout<<"\n La Matriz de 360 grados es  :"<<endl;
 	for (int i=0; i<n; i++){
	
    for (int j=0; j<n; j++){
     
	 
	      M360<< Matriz360[n-1-i][j]<<" ";
        	cout <<"\t"<< Matriz360[n-1-i][j]  ;}
	cout << endl;}
	
		 
 
M360.close();

		

	//Matriz de 270 grados 

	  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  Matriz270[i][j]=Matriz[j][n-1-i];
  
  //muestro 
  cout<<"\n La Matriz 270 grados es  :"<<endl;
  for(int i=0;i<n;i++){//mientras haya filas
   for(int j=0;j<n;j++){//muestro elementos
    cout<<"\t "<<Matriz270[n-1-i][j]; 
  
   }
   cout<<"\n ";
  }
  cout<<"\n";
		
	
inf.close();
	system ("Pause");
	return EXIT_SUCCESS;
}
