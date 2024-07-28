#include <iostream>
using namespace std; 


int main(){
	int opcion;

	cout<<"\n----BIENVENIDOS AL HOTEL EL 'TELO'----\n" << endl;
	
	while(opcion!=3){ //Impresion del menu en la pantalla
	
	    cout<<"Seleccione una opcion:"<<endl;
	    cout<<"1) Huespedes y habitaciones"<<endl;
	    cout<<"2) Trabajadores" << endl;
	    cout<<"3) Salir del programa" << endl;
	    cout<<"Opcion: ";
	    cin>>opcion;
	    cout<<endl;
	    
	    switch(opcion){
	    	case 1:
	    	
	    		break;
	    	case 2:
	    	
	    		break;
	    	case 3:
	    		cout << "Saliendo...";
	    		break;
	    	default:
	    			cout<<"ERROR: Alternativa no valida, intente de nuevo..."<<endl<<endl;
	    		break;
	    	
		}
    }
    return 0;
}
