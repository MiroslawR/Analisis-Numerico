#include <fstream>
#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	
int A [5][5];
char sim = true;
int T[5][5];
ifstream inf;
inf.open("Matriz1.txt");
if(!inf){//check to see if file opened 
cerr <<"could not open file!"<< endl;
return EXIT_FAILURE;


}


		for(int i=0; i<5; ++i){
		
	for (int j=0; j<5; ++j){
	
	
	inf >> A [i][j];
	cout << A [i][j];}
	cout << endl;}	
	
	
	//Comprobando si la matriz es simétrica.
 

 //genero la traspuesta
  for(int i=0;i<5;i++)
   for(int j=0;j<5;j++)
    T[i][j]=A[j][i];
     
  
  //muestro la traspuesta
  cout<<"\n La Matriz  traspuesta es  :"<<endl;
  for(int i=0;i<5;i++){//mientras haya filas
   for(int j=0;j<5;j++){//muestro elementos
    cout<<"\t "<<T[i][j]; 
   }
   cout<<"\n ";
  }
  cout<<"\n";
   
    //compruebo igualdad con la traspuesta elem a elem
for(int i=0;i<5;i++)
   for(int j=0;j<5;j++)
    if(T[i][j]!=A[i][j]) {sim=false;}

if (sim=true)
	cout << "La matriz es simetrica" << endl;
	

else

	cout <<"La matriz no es simetrica" << endl;
    
    	return EXIT_SUCCESS;
		
    }
    
          


    
        
        
            
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
        
        
        
   
 
