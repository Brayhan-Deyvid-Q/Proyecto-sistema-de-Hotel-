
#include<iostream>
#include "trabajadores.h"

using namespace std; 

// Funci�n para verificar si una cadena contiene solo letras
bool soloLetras(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z') {
            return false;
        }
    }
    return true;
}

bool soloDigitos(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c < '0' || c > '9') {
            return false;
        }
    }
    return true;
}

void agregarTrabajador(Trabajador trabajadores[], int &numTrabajadores) {
    if (numTrabajadores >= MAX_TRABAJADORES) {
        cout << "No se pueden agregar m�s trabajadores. La lista est� llena." << endl;
        return;
    }

    Trabajador nuevoTrabajador;
    char tempNombre[MAX_NOMBRE_TRA];
    char tempCargo[MAX_CARGO_TRA];
    char tempID[10]; // Ajusta el tama�o seg�n sea necesario

    // Ingresar y validar el ID del trabajador
    cout << "Ingrese el ID del trabajador: ";
    cin >> tempID;

    while (!soloDigitos(tempID)) {
        cout << "Error: El ID debe ser un n�mero. Ingrese nuevamente: ";
        cin >> tempID;
    }
    nuevoTrabajador.id = 0;
    for (int i = 0; tempID[i] != '\0'; i++) {
        nuevoTrabajador.id = nuevoTrabajador.id * 10 + (tempID[i] - '0');
    }

    // Ingresar y validar el nombre del trabajador
    cout << "Ingrese el nombre del trabajador (m�x. " << MAX_NOMBRE_TRA - 1 << " caracteres): ";
    cin.ignore(); // Limpiar el buffer de entrada
    cin.getline(tempNombre, MAX_NOMBRE_TRA);

    while (!soloLetras(tempNombre)) {
        cout << "Error: El nombre solo puede contener letras. Ingrese nuevamente: ";
        cin.getline(tempNombre, MAX_NOMBRE_TRA);
    }
    // Copiar el nombre al trabajador
    for (int i = 0; i < MAX_NOMBRE_TRA - 1 && tempNombre[i] != '\0'; i++) {
        nuevoTrabajador.nombretra[i] = tempNombre[i];
    }
    nuevoTrabajador.nombretra[MAX_NOMBRE_TRA - 1] = '\0'; // Asegurar el final de la cadena

    // Ingresar el sueldo del trabajador
    cout << "Ingrese el sueldo del trabajador: ";
    cin >> nuevoTrabajador.sueldo;

    // Ingresar y validar el cargo del trabajador
    cout << "Ingrese el cargo del trabajador (m�x. " << MAX_CARGO_TRA - 1 << " caracteres): ";
    cin.ignore(); // Limpiar el buffer de entrada
    cin.getline(tempCargo, MAX_CARGO_TRA);

    // Copiar el cargo al trabajador
    for (int i = 0; i < MAX_CARGO_TRA - 1 && tempCargo[i] != '\0'; i++) {
        nuevoTrabajador.cargo[i] = tempCargo[i];
    }
    nuevoTrabajador.cargo[MAX_CARGO_TRA - 1] = '\0'; // Asegurar el final de la cadena

    // Agregar el nuevo trabajador al arreglo
    trabajadores[numTrabajadores] = nuevoTrabajador;
    numTrabajadores++;

    cout << "Trabajador agregado exitosamente." << endl;
}

void eliminarTrabajador(Trabajador trabajadores[], int &numTrabajadores) {
    int id;
    bool encontrado = false;

    cout << "Ingrese el ID del trabajador a eliminar: ";
    cin >> id;

    for (int i = 0; i < numTrabajadores; i++) {
        if (trabajadores[i].id == id) {
            // Encontramos al trabajador, lo eliminamos
            for (int j = i; j < numTrabajadores - 1; j++) {
                trabajadores[j] = trabajadores[j + 1];
            }
            numTrabajadores--;
            encontrado = true;
            cout << "Trabajador eliminado exitosamente." << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Trabajador con ID " << id << " no encontrado." << endl;
    }
}


void listarTrabajadores(Trabajador trabajadores[], int numTrabajadores) {
    if (numTrabajadores == 0) {
        cout << "No hay trabajadores para mostrar." << endl;
        return;
    }

    cout << "Lista de trabajadores:" << endl;
    for (int i = 0; i < numTrabajadores; i++) {
        cout << "ID: " << trabajadores[i].id << ", Nombre: " << trabajadores[i].nombretra
             << ", Sueldo: " << trabajadores[i].sueldo << ", Cargo: " << trabajadores[i].cargo << endl;
    }
}

void trabajadoresMenu(Trabajador trabajadores[], int &numTrabajadores) {
	int opcion;
		
    do {
    	cout << "\n" << endl;
        cout << "1. Agregar trabajador" << endl;
        cout << "2. Eliminar trabajador" << endl;
        cout << "3. Check de trabajadores" << endl;
        cout << "4. Regresar al menu principal" << endl << endl;
        cout << "opci�n: ";
        cin >> opcion;
        cout << endl;
        // SWITCH PARA SELECIONAR LAS DIFERENTES OPCIONES DEL MENU CARTA
        switch (opcion) {
            case 1:
                agregarTrabajador(trabajadores, numTrabajadores);
                break;
            case 2:
            	eliminarTrabajador(trabajadores, numTrabajadores);
                break;
            case 3:
            	listarTrabajadores(trabajadores, numTrabajadores);
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

