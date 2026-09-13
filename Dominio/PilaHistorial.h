#include "NodeHistorial.h"
#include <string>
using namespace std;
class PilaHistorial {
private:
    NodeHistorial* tope;
    int tamano;
public:
    PilaHistorial();
    bool empty();
    void push(string registro);
    void pop();
    string top();
    void clear();
    int size();
    void historial();
    ~PilaHistorial();
};