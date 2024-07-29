#ifndef TRABAJADORES_H
#define TRABAJADORES_H

const int MAX_TRABAJADORES = 20; // Asegúrate de que este valor sea suficiente para tu uso

const int MAX_NOMBRE_TRA = 30;
const int MAX_CARGO_TRA = 30;

struct Trabajador {
    int id;
    char nombretra[MAX_NOMBRE_TRA];
    float sueldo;
    char cargo[MAX_CARGO_TRA];
};

void trabajadoresMenu(Trabajador trabajadores[], int &numTrabajadores);

#endif

