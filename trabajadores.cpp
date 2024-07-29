
#include<iostream>
#include "trabajadores.h"

using namespace std; 


void agregarTrabajador(Trabajador trabajadores[], int &numTrabajadores) {
    if (numTrabajadores >= MAX_TRABAJADORES) {
        cout << "No se pueden agregar más trabajadores. La lista está llena." << endl;
        return;
    }

    Trabajador nuevoTrabajador;

    // Ingresar datos del trabajador
    cout << "Ingrese el ID del trabajador: ";
    cin >> nuevoTrabajador.id;

    cout << "Ingrese el nombre del trabajador (máx. " << MAX_NOMBRE_TRA - 1 << " caracteres): ";
    cin.ignore(); // Limpiar el buffer de entrada
    cin.getline(nuevoTrabajador.nombretra, MAX_NOMBRE_TRA);

    cout << "Ingrese el sueldo del trabajador: ";
    cin >> nuevoTrabajador.sueldo;

    cout << "Ingrese el cargo del trabajador (máx. " << MAX_CARGO_TRA - 1 << " caracteres): ";
    cin.ignore(); // Limpiar el buffer de entrada
    cin.getline(nuevoTrabajador.cargo, MAX_CARGO_TRA);

    // Agregar el nuevo trabajador al arreglo
    trabajadores[numTrabajadores] = nuevoTrabajador;
    numTrabajadores++;

    cout << "Trabajador agregado exitosamente." << endl;
}
//void eliminarTrabajador

//listarTrabajador

void trabajadoresMenu(Trabajador trabajadores[], int &numTrabajadores) {
	int opcion;
		
    do {
    	cout << "\n" << endl;
        cout << "1. Agregar trabajador" << endl;
        cout << "2. Eliminar trabajador" << endl;
        cout << "3. Check de trabajadores" << endl;
        cout << "4. Regresar al menu principal" << endl << endl;
        cout << "opción: ";
        cin >> opcion;
        cout << endl;
        // SWITCH PARA SELECIONAR LAS DIFERENTES OPCIONES DEL MENU CARTA
        switch (opcion) {
            case 1:
                agregarTrabajador(trabajadores, numTrabajadores);
                break;
            case 2:
            	//eliminarTrabajador 
                break;
            case 3:
            	//listarTrabajador
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

