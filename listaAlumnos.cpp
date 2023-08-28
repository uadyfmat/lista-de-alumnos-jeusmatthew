#include <stdio.h>
#include <stdlib.h>

typedef struct alumno
{
    char const *nombre;
    int creditos;
    int semestre;

    void imprimirAlumno()
    {
        printf("Nombre: %s, Creditos: %d, Semestre: %d\n",
               this->nombre, this->creditos, this->semestre);
    }

    void test(){
        printf("Direccion de esto: %p\nDireccion dereferencia: %p\n", this, (*this));

    }

} Alumno;

typedef struct nodo
{
    Alumno *alumnoPtr;
    struct nodo *siguiente;

    void imprimirLista()
    {
        if(this==nullptr){
            printf("Lista vacia!");
            return;
        }

        struct nodo* actual = this;
        while (actual != nullptr)
        {
            actual->alumnoPtr->imprimirAlumno();
            actual = actual->siguiente;
        }
    }

} Nodo;

typedef struct nodo *NodoPtr;
typedef struct alumno *AlumnoPtr;

// Prototipos de las funciones
// Elementales
Alumno *crearAlumno(char const *, int, int);
// void imprimirAlumno(AlumnoPtr);

NodoPtr crearNodo(AlumnoPtr);
void insertarNodoOrdenadoCreditos(NodoPtr *, AlumnoPtr);
// void imprimirLista(NodoPtr);

// Propias

int main(int argc, char const *argv[])
{
    // crear 5 instancias de estructuras Alumno
    AlumnoPtr *alumnos = (AlumnoPtr *)malloc(sizeof(AlumnoPtr) * 5);

    alumnos[0] = crearAlumno("Walter White", 100, 1);
    alumnos[0]->test();
    alumnos[1] = crearAlumno("Raul Magana", 200, 2);
    alumnos[2] = crearAlumno("David Torres", 300, 3);
    alumnos[3] = crearAlumno("Guadalupe Rios", 400, 4);
    alumnos[4] = crearAlumno("Ml chispa", 500, 5);
    // crear la lista con las 5 instancias de Alumno
    NodoPtr cabeza = nullptr;

    // insertar de forma ordenada de acuerdo al número de créditos (descendente)
    insertarNodoOrdenadoCreditos(&cabeza, alumnos[0]);
    insertarNodoOrdenadoCreditos(&cabeza, alumnos[1]);
    insertarNodoOrdenadoCreditos(&cabeza, alumnos[2]);
    insertarNodoOrdenadoCreditos(&cabeza, alumnos[3]);
    insertarNodoOrdenadoCreditos(&cabeza, alumnos[4]);

    // imprimir la lista
    printf("\nImpresion de la lista descendente: \n");
    cabeza->imprimirLista();

    return 0;
}

// Elementales
AlumnoPtr crearAlumno(char const *nombre, int creditos, int semestre)
{
    AlumnoPtr nuevo = (AlumnoPtr)malloc(sizeof(Alumno));

    nuevo->nombre = nombre;
    nuevo->creditos = creditos;
    nuevo->semestre = semestre;

    printf("Alumno creado en %p\n", nuevo);

    return nuevo;
}


NodoPtr crearNodo(AlumnoPtr alumnoPtr)
{
    NodoPtr nuevo = (NodoPtr)malloc(sizeof(Nodo));
    nuevo->alumnoPtr = alumnoPtr;
    nuevo->siguiente = nullptr;

    printf("Nodo creado en %p\n", nuevo);

    return nuevo;
}

void insertarNodoOrdenadoCreditos(NodoPtr *cabeza, AlumnoPtr nuevoAlumno)
{
    NodoPtr anterior = nullptr,
            actual = *cabeza,
            nuevo = crearNodo(nuevoAlumno);

    while (actual != nullptr && nuevo->alumnoPtr->creditos < actual->alumnoPtr->creditos)
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (anterior == nullptr)
    {
        nuevo->siguiente = *cabeza;
        *cabeza = nuevo;
    }
    else
    {
        anterior->siguiente = nuevo;
        nuevo->siguiente = actual;
    }
}



// Propias
