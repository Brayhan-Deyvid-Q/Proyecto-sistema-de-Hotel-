#include<iostream>
#include "huespedes.h"

using namespace std;



//void validNumHabitacion(){
	
//}

void agregarHuesped(int &n_huesp, Huesped huespedes[], int Individual, int Doble, int Triple){
	if (n_huesp<30){
	cout<<"Ingrese el nombre del nuevo huesped: ";
	cin>>huespedes[n_huesp].Nombre;
	cout<<"Ingrese su nÃºmero telefÃ³nico: ";
	cin>>huespedes[n_huesp].Telefono;
	cout<<"Ingrese su nÃºmero de DNI: ";
	cin>>huespedes[n_huesp].dni;
	cout<<"Ingrese el tipo de habitación: ";
	cin>>huespedes[n_huesp].hab.tipo;
	if (huespedes[n_huesp].hab.tipo=="Individual"){
		if(Individual > 15){
			cout << "Los habitaciones individuales se encuentran llenas.";
		}else{
		Individual++;
		}
	}else if(huespedes[n_huesp].hab.tipo=="Doble"){
		if(Doble > 10){
			cout << "Los habitaciones dobles se encuentran llenas.";
		}else{
		Doble++;
		}
	}else if(huespedes[n_huesp].hab.tipo=="Triple"){
		if(Triple > 5){
			cout << "Los habitaciones triples se encuentran llenas.";
		}else{
		Triple++;
		}
	}
	cout<<"Ingrese el número de la habitación: ";
	cin>>huespedes[n_huesp].hab.num_habi;
	//validNumHabitacion()
	
	cout<<endl;
	n_huesp++;
	cout<<"Se ha agregado un nuevo cliente de forma exitosa..."<<endl;
	}else{
		cout<<"El hotel se encuentra lleno en este momento"<<endl;
	}
	
} 

void huespedesMenu(Huesped huespedes[], int &n_huesp, int Individual, int Doble, int Triple){
	int opcion;
		
    do {
    	cout << "\n" << endl;
        cout << "1. Agregar huesped" << endl;
        cout << "2. Eliminar huesped" << endl;
        cout << "3. Lista de huespedes" << endl;
        cout << "4. Regresar al menu principal" << endl << endl;
        cout << "opción: ";
        cin >> opcion;
        cout << endl;
        // SWITCH PARA SELECIONAR LAS DIFERENTES OPCIONES DEL MENU CARTA
        switch (opcion) {
            case 1:
            	agregarHuesped(n_huesp, huespedes, Individual, Doble, Triple); 
                break;
            case 2:
            	
                break;
            case 3:
            
                break;
            case 4:
                cout << "Regresando al menu inicial" << endl;
                break;
            default:
                cout << "Valor ingresado incorrecto, vuelva a ingresar otro valor" << endl;
                break;
        }
        
    } while (opcion != 4); //EN CASO SELECCIONAR EL NUMERO 4 REGRESA AL MENU ANTERIOR
}
