#ifndef HUESPEDES_H
#define HUESPEDES_H

struct Habitaciones {
    int num_habi;
    char tipo[20];
};

struct Huesped {
    char Nombre[30];
    char Telefono[10];
    char dni[10];
    struct Habitaciones hab;
};

void huespedesMenu();
	
#endif
