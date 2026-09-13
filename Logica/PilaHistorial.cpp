#include "../Dominio/PilaHistorial.h"

#include <iostream>
#include <ostream>

#include "../Dominio/NodePacientes.h"

PilaHistorial::PilaHistorial() {
    this-> tamano = 0;
    this-> tope = nullptr;
}
bool PilaHistorial::empty() {
    return this-> tope == nullptr;
}
void PilaHistorial::push(string registro) {
    NodeHistorial* nuevo = new NodeHistorial(registro);
    if (empty()) {
        this-> tope = nuevo;
    }
    else {
        nuevo->setNext(this->tope);
        this->tope = nuevo;
    }
    this->tamano++;
}
void PilaHistorial::pop() {
    if (this-> tope == nullptr) {
        return;
    }
    NodeHistorial* temp = this-> tope;
    this->tope = this-> tope -> getSiguiente();
    delete temp;
    this->tamano--;
}
string PilaHistorial::top() {
    if (this-> tope == nullptr) {
        return "";
    }
    return this-> tope -> getRegistro();
}

void PilaHistorial::clear() {
    if (!empty()) {
        pop();
    }
}
void PilaHistorial::historial() {
    if (this-> tope == nullptr) {
        cout << "No hay historial" << endl;
        return;
    };
    NodeHistorial* cursor = this-> tope;
    while (cursor != nullptr) {
        cout << "- " << cursor->getRegistro() << endl;
        cursor = cursor->getSiguiente();
    }
}
int PilaHistorial::size() {
    return this-> tamano;
}
PilaHistorial::~PilaHistorial() {
    clear();
}
