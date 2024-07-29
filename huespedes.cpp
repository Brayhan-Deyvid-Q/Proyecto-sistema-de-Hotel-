#include<iostream>
#include "huespedes.h"
#include <string.h>
using namespace std;



void validNumHabitacion(int &validar, int n_huesp, Huesped huespedes[]){
	int i=0;
	do{
		while(i<n_huesp){
			if (huespedes[i].hab.num_habi == validar || validar >30 || validar < 0){
				cout << "La habitación se encuentra ocupada o no existe seleccione otro número de habitación."<<endl;
				cin>> validar;
			}else if(huespedes[i].hab.num_habi != validar && i==n_huesp){
				cout << "Guardando cambios..."<<endl;
			}
			i++;	
		}
	}while(huespedes[i].hab.num_habi == validar || validar >30 || validar < 0);
}

void agregarHuesped(int &n_huesp, Huesped huespedes[], int Individual, int Doble, int Triple){
	int validar, long_dni;
	if (n_huesp<30){
	cout<<"Ingrese el nombre del nuevo huesped: ";
	cin.ignore(); 
	cin.getline(huespedes[n_huesp].Nombre, 30);
	cout<<"Ingrese su nÃºmero telefÃ³nico: ";
	cin.getline(huespedes[n_huesp].Telefono, 10);
	do{
	
	
	cout<<"Ingrese su nÃºmero de DNI: ";
	cin.getline(huespedes[n_huesp].dni,10);
	
	long_dni = strlen(huespedes[n_huesp].dni);
	
	if(long_dni != 8){
		cout << "DNI incorrecto. Vuelve a ingresar el dni. " << endl;
	}
	
	}while(long_dni !=8);

	cout<<"Ingrese el tipo de habitación(Individual, Doble, Triple): ";
    cin.getline(huespedes[n_huesp].hab.tipo, 20);
    

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
	validar = huespedes[n_huesp].hab.num_habi;
	validNumHabitacion(validar, n_huesp, huespedes);
	huespedes[n_huesp].hab.num_habi = validar;
	cout<<endl;
	n_huesp++;
	cout<<"Se ha agregado un nuevo cliente de forma exitosa..."<<endl;
	}else{
		cout<<"El hotel se encuentra lleno en este momento"<<endl;
	}
	
} 


void listarHuespedes(Huesped huespedes[30], int n_huesp){
	
	for (int i = 0; i<n_huesp; i++){

		cout << "Nombre: " << huespedes[i].Nombre << endl;
		cout << "Telefono: " << huespedes[i].Telefono << endl;
		cout << "DNI: " << huespedes[i].dni << endl;
		cout << "Numero de habitacion: " << huespedes[i].hab.num_habi << endl;
		cout << "Tipo de habitacion: " << huespedes[i].hab.tipo << endl << endl;
		cout << "------------------------------------" << endl;
	}
	
	
}

void eliminarHuesped(int &n_huesp, Huesped huespedes[], int indice,int &Individual, int &Doble, int &Triple){

	if (indice >= 0 && indice < n_huesp){
		if (huespedes[indice].hab.tipo == "Individual") {
            Individual--;
        } else if (huespedes[indice].hab.tipo == "Doble") {
            Doble--;
        } else if (huespedes[indice].hab.tipo == "Triple") {
            Triple--;
        }
		for(int i = indice; i < n_huesp-1; ++i){
			huespedes[i] = huespedes[i+1];
			
		}
		n_huesp--;
		cout << "Huesped eliminado..." << endl;
	} 
	
	
}
void huespedesMenu(Huesped* huespedes, int& n_huesp, int Individual, int Doble, int Triple){
	int opcion, indice;
	
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
            	listarHuespedes(huespedes, n_huesp);
            	cout << "Digite el indice del huesped  que desea eliminar: " << endl;
				cin >> indice;
				eliminarHuesped(n_huesp, huespedes, indice, Individual, Doble, Triple);

                break;
            case 3:
            	listarHuespedes(huespedes, n_huesp);
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

