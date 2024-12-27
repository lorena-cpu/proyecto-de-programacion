#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SuperClase {
protected:
    string mensaje;
public:
    SuperClase(string msg = "Mensaje de la SuperClase") : mensaje(msg) {}
    virtual void mostrarMensaje() const {
        cout << "SuperClase: " << mensaje << endl;
    }

    friend class ClaseAmiga;
};

class Hija : public SuperClase {
public:
    Hija(string msg = "Mensaje de la Hija") : SuperClase(msg) {}

    void mostrarMensaje() const override {
        cout << "Hija: " << mensaje << endl;
    }
};

class ClaseAmiga {
public:
    void modificarMensaje(SuperClase &superClase, const string &nuevoMensaje) {
        superClase.mensaje = nuevoMensaje;
    }

    void mostrarMensaje(const SuperClase &superClase) const {
        cout << "ClaseAmiga mostrando: " << superClase.mensaje << endl;
    }
};

class Alumno {
private:
    string nombre;
    string numero;
    string dni;
    string colegio;

public:
    Alumno(string n, string num, string d, string col) 
        : nombre(n), numero(num), dni(d), colegio(col) {}

    void mostrarDatos() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Numero de telefono: " << numero << endl;
        cout << "DNI: " << dni << endl;
        cout << "Colegio: " << colegio << endl;
    }

    string getNombre() const {
        return nombre;
    }
};

class SistemaAlumnos {
private:
    vector<Alumno> alumnos;

public:
    void agregarAlumno() {
        string nombre, numero, dni, colegio;

        cout << "Ingrese los datos del alumno:" << endl;
        cout << "Nombre: ";
        getline(cin, nombre);
        cout << "Numero de telefono: ";
        getline(cin, numero);
        cout << "DNI: ";
        getline(cin, dni);
        cout << "Colegio: ";
        getline(cin, colegio);

        Alumno nuevoAlumno(nombre, numero, dni, colegio);
        alumnos.push_back(nuevoAlumno);
        cout << "Alumno agregado exitosamente!" << endl;
    }

    void mostrarAlumnos() const {
        cout << "\n--- Lista de Alumnos ---" << endl;
        for (const auto& alumno : alumnos) {
            alumno.mostrarDatos();
            cout << "------------------------" << endl;
        }
    }

    void buscarAlumno() const {
        string nombreBuscado;
        cout << "Ingrese el nombre del alumno a buscar: ";
        getline(cin, nombreBuscado);

        bool encontrado = false;
        for (const auto& alumno : alumnos) {
            if (alumno.getNombre() == nombreBuscado) {
                alumno.mostrarDatos();
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            cout << "Alumno no encontrado." << endl;
        }
    }

    void bienvenida() const {
        cout << "Bienvenido " << endl;
        cout << "A continuacion, vamos a tomar sus datos. " << endl;
    }

    void menu() {
        int opcion;
        do {
            cout << "\n--- Menu ---" << endl;
            cout << "1. Agregar Alumno" << endl;
            cout << "2. Mostrar Alumnos" << endl;
            cout << "3. Buscar Alumno" << endl;
            cout << "4. Salir" << endl;
            cout << "Seleccione una opcion: ";
            cin >> opcion;
            cin.ignore();

            switch (opcion) {
                case 1:
                    agregarAlumno();
                    break;
                case 2:
                    mostrarAlumnos();
                    break;
                case 3:
                    buscarAlumno();
                    break;
                case 4:
                    cout << "Saliendo del programa..." << endl;
                    break;
                default:
                    cout << "Opcion inv\u00e1lida, intente de nuevo." << endl;
            }
        } while (opcion != 4);
    }
};

int main() {
    SistemaAlumnos sistema;
    sistema.bienvenida();
    sistema.menu();

    SuperClase superClase("Mensaje original de la SuperClase");
    Hija hija("Mensaje inicial de la Hija");

    superClase.mostrarMensaje();
    hija.mostrarMensaje();

    ClaseAmiga claseAmiga;
    claseAmiga.modificarMensaje(superClase, "Nuevo mensaje modificado por ClaseAmiga");
    claseAmiga.mostrarMensaje(superClase);

    return 0;
}

