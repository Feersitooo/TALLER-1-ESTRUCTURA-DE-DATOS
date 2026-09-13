#include "NodeServicios.h"
#include "ServicioMedico.h"
#include "NodePacientes.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
class Hospital {
private:
    NodeServicios* servicios;
    NodePacientes* pacientes;
    ServicioMedico* crearServicioMedico(const string& nombre);
public:
    Hospital();

    void agregarPaciente(Paciente* p);
    bool existeServicio(const string& nombre);
    void agregarServicioMedico(ServicioMedico* servicioMedico);
    bool existePaciente(const string& id);
    void crearPaciente(string linea);
    void atenderPacientes();
    ~Hospital();
};