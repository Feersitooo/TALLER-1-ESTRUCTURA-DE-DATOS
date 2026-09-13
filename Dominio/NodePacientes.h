#include "Paciente.h"
#pragma once

class NodePacientes {
private:
    NodePacientes* next;
    Paciente* paciente;
public:
    NodePacientes(Paciente* p) {
        this->paciente = p;
        this-> next = nullptr;
    }
    Paciente* getPaciente() {
        return this->paciente;
    }
    void setNext(NodePacientes* siguiente) {
        this->next = siguiente;
    }
    NodePacientes* getNext() {
        return this->next;
    }
    int getSize() {
        if (this-> paciente);
    }
    ~NodePacientes() {
        delete paciente;
    }
};
