#include <iostream>

#include "ServicioMedico.h"

class NodeServicios {
private:
    NodeServicios* next;
    ServicioMedico* servicio;
public:
    NodeServicios(ServicioMedico* servicio){
        this-> servicio = servicio;
        this-> next = nullptr;
    }
    ServicioMedico* getServicio(){
        return this-> servicio;
    }
    NodeServicios* getNext(){
        return next;
    }
    void setNext(NodeServicios* siguiente){
        this-> next = siguiente;
    }
    ~NodeServicios() {
        delete servicio;
    }
};


