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
    ColaPacientes filaEspera;
    PilaHistorial historial;
    ServicioMedico* crearServicioMedico(const string& nombre);
public:
    Hospital();

    void agregarPaciente(Paciente* p);
    bool existeServicio(const string& nombre);
    void agregarServicioMedico(ServicioMedico* servicioMedico);
    bool existePaciente(const string& id);
    void crearPaciente(string linea);

    void atenderPacientes();
    void mostrarHistorial();
    ~Hospital();
};