#include<iostream> 
#include<cstdlib>
#include<math.h>
#include<fstream>


using namespace std;


int main(int argc, char*argv[]) {
	
	//MATRIZ 1
	ifstream a;
	
	a.open("Matriz1.txt");

	int m[3][3]; 
		
	for (int i=0; i<3; i++){
		
		for (int j=0; j<3; j++){
		      
		      a >> m[i][j];
		}
	}
	
   	a.close();
   	
		
	cout << " m es: " << endl << endl;
   
	for (int i=0; i<3; i++){
		
		for (int j=0; j<3; j++){
		      
		      cout << m[i][j] << " ";
		}
		
		cout << endl;	
   	}
	cout << endl;
	   
	 
	//MATRIZ 2
	ifstream b;
	
	b.open("Matriz2.txt");
	
	int p[3][3]; 
		
	for (int i=0; i<3; i++){
		
		for (int j=0; j<3; j++){
		      
		      b >> p[i][j];
		}
   	}
	
	b.close();
   
   	
   	cout << " p es: " << endl << endl;
   
	for (int i=0; i<3; i++){
		
		for (int j=0; j<3; j++){
		      
		      cout << p[i][j] << " ";
		}
		
		cout << endl;	
	}
		
   	cout << endl;
   	
  	
  	//SUMA
   	int e [3][3];	
	
	 for( int i=0;i<3;i++){
    	
		 for(int j=0;j<3;j++){
		 	
            	e[i][j]=m[i][j]+p[i][j];
        }
    }	
     	 
    cout << " La suma de las matrices m y p es: " << endl << endl;
    
    for( int i=0;i<3;i++){
    	
		 for(int j=0;j<3;j++){
		 	
            	cout << e[i][j] << " ";
        }
            
            cout << endl;
    }	 	 
	cout << endl;
     	 
	
	//MULTIPLICACION
	 int u [3][3];	
	
	 for( int i=0;i<3;i++){
    	
		 for(int j=0;j<3;j++){
		 		u[i][j]=0;
		 		for(int h=0;h<3;h++){
		 			
            		u[i][j]= (m[i][0]*p[0][j]) + (m[i][1]*p[1][j]) + (m[i][2]*p[2][j]);
            	}
        }
    }	
     	 
    cout << " La multiplicacion de las matrices m y p es: " << endl << endl;
    
    for( int i=0;i<3;i++){
    	
		 for(int j=0;j<3;j++){
		 	
            	cout << u[i][j] << " ";
        }
            
        cout << endl;
    }		 

  
return EXIT_SUCCESS; 
 
}
