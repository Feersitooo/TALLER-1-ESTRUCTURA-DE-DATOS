#include "NodePacientes.h"
#pragma once
class ServicioMedico {
protected:
    string nombre;
    NodePacientes* pacientes;
public:
    ServicioMedico(string nombre) {
        this->nombre = nombre;
        this->pacientes = nullptr;
    };
    string getNombre() const{
        return this->nombre;
    }
    virtual ~ServicioMedico() {
        NodePacientes* cursor = this->pacientes;
        while (cursor != nullptr) {
            NodePacientes* temp = cursor;
            cursor = cursor->getNext();
            delete temp;
        }
    }
     void mostrarPacientes() const {
         // pacientes
     }

};
class Urgencia : public ServicioMedico {
public:
    Urgencia() : ServicioMedico("Urgencia") {};
};

class MedicinaGeneral : public ServicioMedico {
public:
    MedicinaGeneral() : ServicioMedico("Medicina General") {};
};

class Cardiologia : public ServicioMedico {
public:
    Cardiologia() : ServicioMedico("Cardiologia") {};
};

class Neurologia : public ServicioMedico {
public:
    Neurologia() : ServicioMedico("Neurologia") {};
};

class Traumatologia : public ServicioMedico {
public:
    Traumatologia() : ServicioMedico("Traumatologia") {};
};
class Cirugia : public ServicioMedico {
public:
    Cirugia() : ServicioMedico("Cirugia") {};
};
class Pediatria : public ServicioMedico {
public:
    Pediatria() : ServicioMedico("Pediatria") {};
};
class Hospitalizacion : public ServicioMedico {
public:
    Hospitalizacion() : ServicioMedico("Hospitalizacion") {};
};


