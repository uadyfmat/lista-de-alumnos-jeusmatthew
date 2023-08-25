#include <iostream>

typedef struct alumno
{
    char const *nombre;
    int creditos;
    int semestre;
    struct alumno *siguiente;

    void imprimirAlumno(void);

} Alumno;

typedef struct nodo
{
    struct alumno *alumnoPtr;
    struct nodo *siguiente;

    void imprimirLista();
    int insertarNodoOrdenadoCreditos(Nodo *);
} Nodo;

// Prototipos de las funciones
Alumno *crearAlumno(char const *, int, int);
Nodo *crearNodo(Alumno *);

int main(int argc, char const *argv[])
{
    Alumno *alumnos[5];
    Nodo *listaAlumnos = nullptr;

    alumnos[0] = crearAlumno("pepeOG", 100, 9);
    alumnos[1] = crearAlumno("pepe2", 245, 9);
    alumnos[2] = crearAlumno("pepe3", 300, 9);
    alumnos[3] = crearAlumno("pepe4", 345, 9);
    alumnos[4] = crearAlumno("pepe5", 400, 9);

    // listaAlumnos = crearNodo(crearAlumno("Yoda", 400, 9));

    // listaAlumnos->imprimirLista();

    return 0;
}

Alumno *crearAlumno(char const *nombre, int creditos, int semestre)
{
    Alumno *nuevo = new Alumno;
    nuevo->nombre = nombre;
    nuevo->creditos = creditos;
    nuevo->semestre = semestre;
    nuevo->siguiente = nullptr;
    return nuevo;
}

void Alumno::imprimirAlumno(void)
{
    std::cout << "Nombre: " << this->nombre << ", Creditos Aprovados: " << this->creditos << ", Semestre Equivalente: " << this->semestre << std::endl;
}

Nodo *crearNodo(Alumno *alumnoPtr)
{
    Nodo *nuevo = new Nodo;
    nuevo->alumnoPtr = alumnoPtr;
    nuevo->siguiente = nullptr;
    return nuevo;
}

int nodo::insertarNodoOrdenadoCreditos(Nodo *nuevo)
{
    Alumno *anterior = nullptr, *actual = nullptr;
    actual = this->alumnoPtr;

    while (actual != nullptr && nuevo->alumnoPtr->creditos < actual->creditos)
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (anterior == this->alumnoPtr)
    {
        nuevo->siguiente = this;
        this->alumnoPtr = nuevo;
    }

    return 0;
}

void nodo::imprimirLista()
{
    Alumno *actual = this->alumnoPtr;

    std::cout << "\nImpresion de la lista de Alumnos (Ascendente)\n\n";
    while (actual != nullptr)
    {
        actual->imprimirAlumno();
        actual = actual->siguiente;
    }
}