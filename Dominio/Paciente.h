#include <string>
using namespace std;
class Paciente {
private:
    string id;
    string nombre;
    int edad;
    string servicio;
public:
    Paciente(string id, string nombre, int edad, string servicio) {
        this->id = id;
        this->nombre = nombre;
        this->edad = edad;
        this->servicio = servicio;
    }
    string getId() {
        return this->id;
    }
    string getNombre() {
        return this->nombre;
    }
    int getEdad() {
        return this->edad;
    }
    string getServicio() {
        return this->servicio;
    }
    ~Paciente() {}
};
