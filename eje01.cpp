#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Alumno {
    string nombre;
    string numero;
    string dni;
    string colegio;
};

void agregarAlumno(vector<Alumno>& alumnos) {
    Alumno nuevoAlumno;
    cout << "Ingrese los datos del alumno:" << endl;
    cout << "Nombre: ";
    cin.ignore(); // Para evitar conflictos con getline
    getline(cin, nuevoAlumno.nombre);
    cout << "Numero de telefono: ";
    getline(cin, nuevoAlumno.numero);
    cout << "DNI: ";
    getline(cin, nuevoAlumno.dni);
    cout << "Colegio: ";
    getline(cin, nuevoAlumno.colegio);

    alumnos.push_back(nuevoAlumno);
    cout << "Alumno agregado exitosamente!" << endl;
}

void mostrarAlumnos(const vector<Alumno>& alumnos) {
    cout << "\n--- Lista de Alumnos ---" << endl;
    for (const auto& alumno : alumnos) {
        cout << "Nombre: " << alumno.nombre << endl;
        cout << "Numero de telefono: " << alumno.numero << endl;
        cout << "DNI: " << alumno.dni << endl;
        cout << "Colegio: " << alumno.colegio << endl;
        cout << "------------------------" << endl;
    }
}

void buscarAlumno(const vector<Alumno>& alumnos) {
    string nombreBuscado;
    cout << "Ingrese el nombre del alumno a buscar: ";
    cin.ignore();
    getline(cin, nombreBuscado);

    bool encontrado = false;
    for (const auto& alumno : alumnos) {
        if (alumno.nombre == nombreBuscado) {
            cout << "Nombre: " << alumno.nombre << endl;
            cout << "Numero de telefono: " << alumno.numero << endl;
            cout << "DNI: " << alumno.dni << endl;
            cout << "Colegio: " << alumno.colegio << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Alumno no encontrado." << endl;
    }
}

void mostrarCursos() {
    cout << "1. Razonamiento Matematico" << endl
         << "2. Razonamiento Verbal" << endl
         << "3. Fisica" << endl
         << "4. Geometria" << endl
         << "5. Aritmetica" << endl
         << "6. Trigonometria" << endl
         << "7. Biologia" << endl
         << "8. Humanidades" << endl
         << "9. Algebra" << endl
         << "10. Quimica" << endl;
}

void inscribirse() {
    int eleccion;
    cout << "Seleccione el numero del ciclo que desea inscribirse (1, 2, 3): ";
    cin >> eleccion;

    switch (eleccion) {
        case 1:
            cout << "Te has matriculado en el ciclo 1" << endl;
            break;
        case 2:
            cout << "Te has matriculado en el ciclo 2" << endl;
            break;
        case 3:
            cout << "Te has matriculado en el ciclo 3" << endl;
            break;
        default:
            cout << "Opcion invalida. Intentalo de nuevo." << endl;
    }
}

void calcularPromedio() {
    int periodo;
    double nota1, nota2, nota3, nota4, promedio;

    cout << "Ingrese el periodo (1, 2, 3): ";
    cin >> periodo;

    if (periodo == 1) {
        cout << "Ingrese la nota 1: ";
        cin >> nota1;
        cout << "Ingrese la nota 2: ";
        cin >> nota2;
        cout << "Ingrese la nota 3: ";
        cin >> nota3;
        promedio = (nota1 * 0.3) + (nota2 * 0.3) + (nota3 * 0.4);
    } else if (periodo == 2 || periodo == 3) {
        cout << "Ingrese la nota 1: ";
        cin >> nota1;
        cout << "Ingrese la nota 2: ";
        cin >> nota2;
        cout << "Ingrese la nota 3: ";
        cin >> nota3;
        cout << "Ingrese la nota 4: ";
        cin >> nota4;
        promedio = (nota1 + nota2 + nota3) * 0.2 + nota4 * 0.4;
    } else {
        cout << "Periodo invalido." << endl;
        return;
    }

    if (promedio > 11) {
        cout << "Tienes nota aprobatoria: " << promedio << endl;
    } else {
        cout << "Tienes nota desaprobatoria: " << promedio << endl;
    }
}

int main() {
    vector<Alumno> alumnos;
    int opcion;

    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Agregar Alumno" << endl;
        cout << "2. Mostrar Alumnos" << endl;
        cout << "3. Buscar Alumno" << endl;
        cout << "4. Mostrar Cursos" << endl;
        cout << "5. Inscribirse" << endl;
        cout << "6. Calcular Promedio" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarAlumno(alumnos);
                break;
            case 2:
                mostrarAlumnos(alumnos);
                break;
            case 3:
                buscarAlumno(alumnos);
                break;
            case 4:
                mostrarCursos();
                break;
            case 5:
                inscribirse();
                break;
            case 6:
                calcularPromedio();
                break;
            case 7:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida, intente de nuevo." << endl;
        }
    } while (opcion != 7);

    return 0;
}


