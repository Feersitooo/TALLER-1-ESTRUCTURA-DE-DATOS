#include <iostream>
#include <fstream>
#include <string>
#include "../Dominio/Hospital.h"
using namespace std;
void leerArchivo(Hospital* h) {
    ifstream arch("pacientes.txt");
    if (!arch.is_open()) {
        cerr<<"Error al abrir el archivo"<<endl;
        return;
    }
    string linea;
    while (getline(arch,linea)) {
        h->crearPaciente(linea);

    }

}
void MenuServicio(Hospital* h) {
    int opcion1 = -10;
    while (opcion1 != 9){
        cout << "=== DEPARTAMENTOS/SERVICIOS ===" << endl;
        cout << "1. Urgencias" << endl;
        cout << "2. Medicina General" << endl;
        cout << "3. Cardiologia" << endl;
        cout << "4. Neurologia" << endl;
        cout << "5. Traumatologia" << endl;
        cout << "6. Cirugia" << endl;
        cout << "7. Pediatria" <<endl;
        cout << "8. Hospitalizacion" <<endl;
        cout << "9. Salir " << endl;
        cin >> opcion1;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        switch (opcion1) {
            case 1:
                h->mostrarPacientesServicio("Urgencias");
                break;
            case 2:
                h->mostrarPacientesServicio("Medicina General");
                break;
            case 3:
                h->mostrarPacientesServicio("Cardiologia");
                break;
            case 4 :
                h->mostrarPacientesServicio("Neurologia");
                break;
            case 5 :
                h->mostrarPacientesServicio("Traumatologia");
                break;
            case 6 :
                h->mostrarPacientesServicio("Cirugia");
                break;
            case 7 :
                h->mostrarPacientesServicio("Pediatria");
                break;
            case 8 :
                h->mostrarPacientesServicio("Hospitalizacion");
                break;
            case 9:
                cout<<"Saliendo del programa..."<<endl;
                break;
            default:
                cout << "Opcion no valida..." << endl;
                break;
        }
    }

}

void menu(Hospital* h) {
    int opcion = 0;
    while (opcion != 4) {
        cout<<"=== HOSPITAL MARMAJA ===" << endl;
        cout<<"1. Atender pacientes"<<endl;
        cout<<"2. Ver departamento"<<endl;
        cout<<"3. Revisar historial de atencion"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"Ingresar opcion: ";
        cin>>opcion;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        switch (opcion) {
            case 1:
                int opcion;
                h-> mostrarPacientes();

                if (!h->existeGente() ) {

                    break;
                }
                cout << "Cuantos pacientes quiere atender: ";
                cin >> opcion;
                if (cin.fail()) {
                    cout<<"Opcion incorrecta"<<endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                h->atenderPacientes(opcion);
                break;
            case 2:
                MenuServicio(h);
                break;
            case 3:
                h->mostrarHistorial();
                break;
            case 4:
                cout << "Adios... :D" << endl;
                break;
            default:
                cout << "Opcion no valida!" << endl;
                break;
        }
    }
}
int main() {
    Hospital* hospital = new Hospital();
    leerArchivo(hospital);
    menu(hospital);


    delete hospital;
    return 0;
}
