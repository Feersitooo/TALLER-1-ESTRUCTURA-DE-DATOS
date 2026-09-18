#include "../Dominio/Hospital.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Hospital::Hospital() {
    this -> servicios = nullptr;
    this-> filaEspera = new ColaPacientes();
    this-> historial = new PilaHistorial();

}
ServicioMedico* Hospital::crearServicioMedico(const string& nombre) {
    if (nombre == "Urgencias") return new Urgencias();
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
    if (!existePaciente(p->getId())) {
        filaEspera->push(p);
    }
    else {
        cout << p->getId() << " ya se encuentra en la fila"<< endl;
    }
}
bool Hospital ::existeGente() {
    if (filaEspera->empty()) {
        return false;
    }
    return true;
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
    if (filaEspera->existe(id)) {
        return true;
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
        Paciente* paciente = new Paciente(id, nombre, edad, servicio);
        agregarPaciente(paciente);
    }
}
void Hospital::mostrarPacientes() {
    if (this -> filaEspera-> empty()) {
        cout << "No hay pacientes en fila " << endl;
        return;
    }
    NodePacientes* pacientes = filaEspera->getPacientes();
    int c = 1;
    while (pacientes != nullptr) {
        cout << c << " - " <<pacientes->getPaciente() ->getNombre() << endl;
        c++;
        pacientes = pacientes->getNext();
    }
}

ServicioMedico* Hospital::buscarServicioMedico(const string & servicio) {
    if (servicios == nullptr) return nullptr;
    NodeServicios* cursor = this-> servicios;
    while (cursor != nullptr) {
        if (cursor->getServicio()->getNombre() == servicio) {
            return cursor->getServicio();
        }
        cursor = cursor->getNext();
    }
    return nullptr;
}
void Hospital::atenderPacientes(int opcion) {
    if (this-> filaEspera->empty()) return;
    if (opcion < 1 || opcion > this-> filaEspera->size()) {
        cout << "Cantidad incorrecta" << endl;
        return;
    }

    for (int i = 0; i < opcion; i++) {
        Paciente* p = filaEspera->front(); //obtenemos paciente
        string servicio = p -> getServicio(); // obtenemos su atributo del servicio para derivarlo
        ServicioMedico* serv = buscarServicioMedico(servicio);
        if (serv != nullptr) {
            serv->agregarPaciente(p);
            filaEspera->pop(); // lo eliminamos de la fila espera pq ya esta siendo atendido
            cout << "" << endl;
            cout << " === ATENDIENDO PACIENTES ===" << endl;
            cout<< "ID: " << p->getId() << endl;
            cout << "Nombre: " << p->getNombre() << endl;
            cout << "Edad: " << p->getEdad() << endl;
            cout << "Servicio: " << p->getServicio() << endl;
            cout<< "" << endl;
            cout << "Paciente enviado a " << p->getServicio() << endl;

            string r = "Nombre: " + p->getNombre() + " | Edad: " + to_string(p->getEdad()) + " | Departamento: " + servicio; // creamos el registro para el historial

            historial->push(r);

        }
        else {
            cout << "ERROR, EL SERVICIO NO EXISTE" << endl;
        }
    }

}
void Hospital::mostrarHistorial() {
    cout << "HISTORIAL DE ATENCIONES " << endl;
    if (historial->empty()) {
        cout << "No hay atenciones registradas aun" << endl;
        return;
    }
    this->historial->historial();
}

void Hospital::mostrarPacientesServicio(const string& nombreServicio) {

    ServicioMedico* servicio = buscarServicioMedico(nombreServicio);

    if (servicio == nullptr) {
        cout << "A este servicio no llegara ningun paciente " << endl;
        return;
    }

    NodePacientes* cursor = servicio->getPacientes();

    if (cursor == nullptr) {
        cout << "No hay pacientes en " << nombreServicio << endl;
        return;
    }

    cout << "=== PACIENTES DE " << nombreServicio << " ===" << endl;

    while (cursor != nullptr) {

        Paciente* paciente = cursor->getPaciente();

        if (paciente != nullptr) {
            cout << "ID: " << paciente->getId() << endl;
            cout << "Nombre: " << paciente->getNombre() << endl;
            cout << "Edad: " << paciente->getEdad() << endl;
            cout << "Servicio: " << paciente->getServicio() << endl;
            cout << "------------------------" << endl;
        }

        cursor = cursor->getNext();
    }
}









void Hospital::MostrarAtencion() {
    cout << "HISTORIAL DE ATENCIONES " << endl;
    if (historial->empty()) {
        cout << "No hay atenciones registradas aun" << endl;
        return;
    }
    this->historial->historial();
}

Hospital::~Hospital() {
    NodeServicios* actualS= this-> servicios;
    while (actualS != nullptr) {
        NodeServicios* temp = actualS;
        actualS = actualS->getNext();
        delete temp;
    }
    delete this -> filaEspera;
    delete this -> historial;
}
