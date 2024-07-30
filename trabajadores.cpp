#include<iostream>
#include "trabajadores.h"

using namespace std; 

// Función para verificar si una cadena contiene solo letras
bool esLetra(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
bool esEspacio(char c) {
    return c == ' ';
}

bool soloLetrasYEspacios(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (!esLetra(c) && !esEspacio(c)) {
            return false;
        }
    }
    return true;
}

char aMayuscula(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

void convertirAMayusculas(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = aMayuscula(str[i]);
    }
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

bool soloDigitosYPunto(const char* str) {
    bool puntoEncontrado = false;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c == '.') {
            if (puntoEncontrado) {
                return false;  // Solo se permite un punto decimal
            }
            puntoEncontrado = true;
        } else if (c < '0' || c > '9') {
            return false;  // Caracter no válido
        }
    }
    return true;
}

float convertirASueldo(const char* str) {
    float resultado = 0.0f;
    float factor = 1.0f;
    bool puntoEncontrado = false;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c == '.') {
            puntoEncontrado = true;
            factor = 0.1f;
        } else if (c >= '0' && c <= '9') {
            if (puntoEncontrado) {
                resultado += (c - '0') * factor;
                factor *= 0.1f;
            } else {
                resultado = resultado * 10 + (c - '0');
            }
        }
    }
	return resultado;
}

void agregarTrabajador(Trabajador trabajadores[], int &numTrabajadores) {
    if (numTrabajadores >= MAX_TRABAJADORES) {
        cout << "No se pueden agregar mas trabajadores. La lista está llena." << endl;
        return;
    }

    Trabajador nuevoTrabajador;
    char tempNombre[MAX_NOMBRE_TRA];
    char tempCargo[MAX_CARGO_TRA];
    char tempID[10];
    char tempSueldo[20]; // Buffer para el sueldo como cadena

    // Ingresar y validar el ID del trabajador
    cout << "Ingrese el ID del trabajador: ";
    cin >> tempID;

    while (!soloDigitos(tempID)) {
        cout << "Error: El ID debe ser un numero. Ingrese nuevamente: ";
        cin >> tempID;
    }
    nuevoTrabajador.id = 0;
    for (int i = 0; tempID[i] != '\0'; i++) {
        nuevoTrabajador.id = nuevoTrabajador.id * 10 + (tempID[i] - '0');
    }

    // Limpiar el buffer de entrada después de leer el ID
    cin.ignore();

    // Ingresar y validar el nombre del trabajador
    cout << "Ingrese el nombre del trabajador (max. " << MAX_NOMBRE_TRA - 1 << " caracteres): ";
    cin.getline(tempNombre, MAX_NOMBRE_TRA);

    while (!soloLetrasYEspacios(tempNombre)) {
        cout << "Error: El nombre solo puede contener letras y espacios. Ingrese nuevamente: ";
        cin.getline(tempNombre, MAX_NOMBRE_TRA);
    }

    // Convertir el nombre a mayúsculas
    convertirAMayusculas(tempNombre);

    // Copiar el nombre al trabajador
    int i;
    for (i = 0; i < MAX_NOMBRE_TRA - 1 && tempNombre[i] != '\0'; i++) {
        nuevoTrabajador.nombretra[i] = tempNombre[i];
    }
    nuevoTrabajador.nombretra[i] = '\0';

    // Ingresar y validar el sueldo del trabajador
    cout << "Ingrese el sueldo del trabajador (numero positivo con hasta dos decimales): ";
    cin.getline(tempSueldo, 20);

    while (!soloDigitosYPunto(tempSueldo)) {
        cout << "Error: El sueldo debe ser un numero positivo con hasta dos decimales. Ingrese nuevamente: ";
        cin.getline(tempSueldo, 20);
    }

    // Convertir el sueldo de cadena a flotante
    nuevoTrabajador.sueldo = convertirASueldo(tempSueldo);

    // Ingresar y validar el cargo del trabajador
    cout << "Ingrese el cargo del trabajador (max. " << MAX_CARGO_TRA - 1 << " caracteres): ";
    cin.getline(tempCargo, MAX_CARGO_TRA);

    // Copiar el cargo al trabajador
    for (i = 0; i < MAX_CARGO_TRA - 1 && tempCargo[i] != '\0'; i++) {
        nuevoTrabajador.cargo[i] = tempCargo[i];
    }
    nuevoTrabajador.cargo[i] = '\0';

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
    float sumaSueldos = 0.0f; // Variable para almacenar la suma de sueldos

    for (int i = 0; i < numTrabajadores; i++) {
        cout << "ID: " << trabajadores[i].id
             << ", Nombre: " << trabajadores[i].nombretra
             << ", Sueldo: " << trabajadores[i].sueldo
             << ", Cargo: " << trabajadores[i].cargo << endl;
        
        sumaSueldos += trabajadores[i].sueldo; // Acumular el sueldo
    }

    cout << "Suma total de los sueldos de los trabajadores: " << sumaSueldos << endl;
}


void trabajadoresMenu(Trabajador trabajadores[], int &numTrabajadores) {
	int opcion;
		
    do {
    	cout << "\n" << endl;
        cout << "1. Agregar trabajador" << endl;
        cout << "2. Eliminar trabajador" << endl;
        cout << "3. Check de trabajadores" << endl;
        cout << "4. Regresar al menu principal" << endl << endl;
        cout << "Opcion: ";
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

