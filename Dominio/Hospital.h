#include "NodeServicios.h"
#include "ServicioMedico.h"
#include "ColaPacientes.h"
#include "PilaHistorial.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
class Hospital {
private:
    NodeServicios* servicios;
    ColaPacientes* filaEspera;
    PilaHistorial* historial;
    ServicioMedico* crearServicioMedico(const string& nombre);
    static const string* getServiciosValidos(int& n);
    bool esServicioValido(const string& nombre);

public:
    Hospital();

    void agregarPaciente(Paciente* p);
    bool existeServicio(const string& nombre);
    void agregarServicioMedico(ServicioMedico* servicioMedico);
    bool existePaciente(const string& id);
    void crearPaciente(string linea);
    void buscarPaciente(const string& id);
    void mostrarPacientes(); // ESTA FUNCION ES PARA MOSTRAR LOS PACIENTES Y SELECCIONAR CUANTOS QUIERE ATENDER
    ServicioMedico * buscarServicioMedico(const string & string);
    void mostrarDepartamentos();
    void verDepartamento(int opcion);
    void atenderPacientes(int opcion); // AQUI YA LOS ATENDEMOS
    void mostrarHistorial();


    ~Hospital();
};