#include "NodePacientes.h"
#include <ostream>
#include <iostream>
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

        delete temp->getPaciente();
        delete temp;
    }

    this->pacientes = nullptr;
}

     void mostrarPacientes() const {
         // pacientes
     }
    bool existePaciente(const string& id) const { // COMPROBAMOS SI EL PACIENTE EXISTE EN EL SERVICIO CORRESPONDIENTE
        NodePacientes* cursor = this-> pacientes;
        while (cursor != nullptr) {
            if (cursor -> getPaciente() != nullptr && cursor->getPaciente()-> getId() == id) {
                return true;
            }
            cursor = cursor->getNext();
        }
        return false;

    }
    virtual void agregarPaciente(Paciente * p) { // AQUI YA SE DERIVA EL PACIENTE AL SERVICIO
        if (p == nullptr) return;
        if (existePaciente(p->getId())) {
            std::cout << "El paciente " << p->getId() << " ya se encuentra como paciente" << endl;
            return;
        }
        NodePacientes* nuevo = new NodePacientes(p);
        if (this-> pacientes == nullptr) {
            this-> pacientes = nuevo;
        }
        else {
            NodePacientes* cursor = this-> pacientes;
            while (cursor->getNext() != nullptr) {
                cursor = cursor -> getNext();
            }
            cursor -> setNext(nuevo);
        }



    }

    NodePacientes* getPacientes() const {
        return this->pacientes;
    }



};
class Urgencias : public ServicioMedico {
public:
    Urgencias() : ServicioMedico("Urgencias") {};
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


