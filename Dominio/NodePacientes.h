#pragma once
#include "Paciente.h"

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
        if (this->getNext() == nullptr) {
            return 1;
        }
        int c = 0;
        NodePacientes* cursor = this;
        while (cursor != nullptr) {
            c++;
            cursor = cursor->getNext();
        }
        return c;
    }

    ~NodePacientes() {
        this-> next = nullptr;
    }
};
