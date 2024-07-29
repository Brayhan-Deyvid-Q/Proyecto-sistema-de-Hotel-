#include <iostream>
#include "trabajadores.h"
#include "huespedes.h"

using namespace std;

// Inicialización de arreglos
Huesped huespedes[30] = {
    {"Franco Avalos", "982827837", "73728372", {22, "individual"}},
    {"Daniela Alvarez", "992932892", "48548934", {3, "doble"}},
    {"Camila Roque", "938438231", "00565623", {1, "triple"}},
    {"David Mamani", "918229385", "67232718", {2, "doble"}},
    {"Mariela Herrera", "912718328", "15843498", {11, "doble"}},
    {"Diego Rivera", "928382891", "23923390", {6, "indivi"}},
    {"Martina Benitez", "986594342", "54894383", {9, "indivi"}},
    {"Alexander Chicaya", "992382831", "10120193", {8, "triple"}}
};

Trabajador trabajadores[MAX_TRABAJADORES] = {
    {210, "Carlos Torres", 2500.0, "Recepcion"},
    {211, "Andres Leyva", 2500.0, "Recepcion"},
    {212, "Mario Roque", 3400.0, "Mantenimiento"},
    {213, "Kevin Ramirez", 3400.0, "Mantemiento"},
    {214, "Diego Salazar", 2700.0, "Pisos"},
    {215, "Laura Montes", 2700.0, "Pisos"},
    {216, "Manuela Linares", 3000.0, "Hosteleria"},
    {217, "Maria Ortega", 3000.0, "Hosteleria"}
};

int numTrabajadores = 8;

int main() {
    int opcion;
    int Individual = 3; // contador de habitaciones individuales
    int Doble = 3; // contador de habitaciones dobles
    int Triple = 2; // contador de habitaciones triples
    int n_huesp = 8; // contador de huespedes

    cout << "\n----BIENVENIDOS AL HOTEL EL 'TELO'----\n" << endl;

    while (opcion != 3) { // Impresión del menú en la pantalla
        cout << "Seleccione una opción:" << endl;
        cout << "1) Huespedes y habitaciones" << endl;
        cout << "2) Trabajadores" << endl;
        cout << "3) Salir del programa" << endl;
        cout << "Opción: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case 1:
                huespedesMenu(huespedes, n_huesp, Individual, Doble, Triple);
                break;
            case 2:
                trabajadoresMenu(trabajadores, numTrabajadores);
                break;
            case 3:
                cout << "Saliendo...";
                break;
            default:
                cout << "ERROR: Alternativa no válida, intente de nuevo..." << endl << endl;
                break;
        }
    }
    return 0;
}

