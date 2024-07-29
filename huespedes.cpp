#include<iostream>
#include "huespedes.h"

using namespace std;


void huespedesMenu(){
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
