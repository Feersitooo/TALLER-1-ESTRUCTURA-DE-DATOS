#include "../Dominio\Hospital.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Hospital::Hospital() {
    this-> pacientes = nullptr;
    this -> servicios = nullptr;
}
ServicioMedico* Hospital::crearServicioMedico(const string& nombre) {
    if (nombre == "Urgencia") return new Urgencia();
    if (nombre == "Medicina General") return new MedicinaGeneral();
    if (nombre == "Cardiologia") return new Cardiologia();
    if (nombre == "Neurologia") return new Neurologia();
    if (nombre == "Traumatologia") return new Traumatologia();
    if (nombre == "Cirugia") return new Cirugia();
    if (nombre == "Pediatria") return new Pediatria();
    if (nombre == "Hospitalizacion") return new Hospitalizacion();

    return new ServicioMedico(nombre);
}

void Hospital::agregarPaciente(Paciente *p) {
    NodePacientes* nuevo = new NodePacientes(p);
    if (this-> pacientes == nullptr) {
        this-> pacientes = nuevo;
    }
    else {
        NodePacientes* cursor = pacientes;
        while (cursor->getNext() != nullptr){
            cursor = cursor->getNext();
        }
        cursor->setNext(nuevo);
    }
}

bool Hospital::existeServicio(const string &nombre) {
    if (this->servicios == nullptr) {
        return false;
    }
    NodeServicios* cursor = this-> servicios;
    while (cursor != nullptr) {
        if (cursor->getServicio()->getNombre() == nombre) {
            return true;
        }
        cursor = cursor->getNext();
    }
    return false;
}

void Hospital::agregarServicioMedico(ServicioMedico *servicioMedico) {
    NodeServicios* nuevo = new NodeServicios(servicioMedico);
    if (this->servicios == nullptr) {
        this-> servicios = nuevo;
    }

    else {
        NodeServicios* cursor = this-> servicios;
        while (cursor->getNext() != nullptr) {

            cursor = cursor->getNext();
        }
        cursor->setNext(nuevo);
    }
}

bool Hospital::existePaciente(const string &id) {
    if (this-> pacientes == nullptr) {
        return false;
    }
    NodePacientes* cursor = this-> pacientes;
    while (cursor != nullptr) {
        if (cursor->getPaciente()->getId() == id) {
            return true;
        }
        cursor = cursor->getNext();
    }
    return false;
}

void Hospital::crearPaciente(string linea) {
    stringstream ss(linea);
    string id, nombre, edadString, servicio;
    getline(ss,id,';');
    getline(ss,nombre,';');
    getline(ss,edadString,';');
    getline(ss,servicio,';');
    int edad = stoi(edadString);

    bool existeS = existeServicio(servicio);
    if (!existeS) {
        ServicioMedico* servicioMedico = crearServicioMedico(servicio);
        agregarServicioMedico(servicioMedico);
    }
    bool existeP = existePaciente(id);
    if (!existeP) {
        Paciente* paciente = new Paciente(id, nombre, edad);
        agregarPaciente(paciente);
    }
}
Hospital::~Hospital() {
    NodePacientes* actualP = this-> pacientes;
    while (actualP != nullptr) {
        NodePacientes* temp = actualP;
        actualP = actualP->getNext();
        delete temp;
    }
    NodeServicios* actualS= this-> servicios;
    while (actualS != nullptr) {
        NodeServicios* temp = actualS;
        actualS = actualS->getNext();
        delete temp;
    }
}