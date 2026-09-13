#pragma once
#include <string>
using namespace std;
class NodeHistorial {
private:
    NodeHistorial* siguiente;
    string registro;
public:
    NodeHistorial(string registro) {
        this->registro = registro;
        this->siguiente = nullptr;
    }
    void setNext(NodeHistorial* siguiente) {
        this->siguiente = siguiente;
    }
    string getRegistro() {
        return this->registro;
    }
    NodeHistorial* getSiguiente() {
        return this->siguiente;
    }
    ~NodeHistorial() {}
};
