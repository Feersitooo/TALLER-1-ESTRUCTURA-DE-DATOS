#include <string>
using namespace std;
class Paciente {
private:
    string id;
    string nombre;
    int edad;
public:
    Paciente(string id, string nombre, int edad) {
        this->id = id;
        this->nombre = nombre;
        this->edad = edad;
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
    ~Paciente() {}
};
