#include <stdio.h>
#include <stdlib.h>

typedef struct alumno
{
    char const *nombre;
    int creditos;
    int semestre;

    alumno(char const *nombre, int creditos, int semestre)
    {
        this->nombre = nombre;
        this->creditos = creditos;
        this->semestre = semestre;
        printf("Alumno creado en %p\n", this);
    }

    void imprimirAlumno()
    {
        printf("Nombre: %s, Creditos: %d, Semestre: %d\n",
               this->nombre, this->creditos, this->semestre);
    }

} Alumno;

typedef Alumno *AlumnoPtr;

typedef struct nodo
{
    Alumno *alumnoPtr;
    struct nodo *siguiente;

    nodo(AlumnoPtr alumno)
    {
        this->alumnoPtr = alumno;
        this->siguiente = nullptr;
        printf("Nodo creado en %p\n", this);
    }

} Nodo;

typedef Nodo *NodoPtr;

typedef struct lista
{

    NodoPtr cabeza;

    lista(NodoPtr cabeza)
    {
        this->cabeza = cabeza;
    }

    void imprimirLista()
    {
        if (this == nullptr)
        {
            printf("Lista vacia!");
            return;
        }

        NodoPtr actual = this->cabeza;
        while (actual != nullptr)
        {
            actual->alumnoPtr->imprimirAlumno();
            actual = actual->siguiente;
        }
    }

    void insertarNodoOrdenadoCreditos(AlumnoPtr nuevoAlumno)
    {
        NodoPtr anterior = nullptr,
                actual = this->cabeza,
                nuevo = new Nodo(nuevoAlumno);

        while (actual != nullptr && nuevo->alumnoPtr->creditos < actual->alumnoPtr->creditos)
        {
            anterior = actual;
            actual = actual->siguiente;
        }

        if (anterior == nullptr)
        {
            nuevo->siguiente = this->cabeza;
            this->cabeza = nuevo;
        }
        else
        {
            anterior->siguiente = nuevo;
            nuevo->siguiente = actual;
        }
    }

} Lista;

typedef Lista *ListaPtr;

int main(int argc, char const *argv[])
{
    // crear 5 instancias de estructuras Alumno
    AlumnoPtr alumnos[5];
    alumnos[0] = new Alumno("Walter White", 100, 1);
    alumnos[1] = new Alumno("Raul Magana", 200, 2);
    alumnos[2] = new Alumno("David Torres", 300, 3);
    alumnos[3] = new Alumno("Guadalupe Rios", 400, 4);
    alumnos[4] = new Alumno("Ml chispa", 500, 5);
    // crear la lista con las 5 instancias de Alumno
    ListaPtr lista = new Lista(nullptr);

    // insertar de forma ordenada de acuerdo al número de créditos (descendente)
    lista->insertarNodoOrdenadoCreditos(alumnos[0]);
    lista->insertarNodoOrdenadoCreditos(alumnos[1]);
    lista->insertarNodoOrdenadoCreditos(alumnos[2]);
    lista->insertarNodoOrdenadoCreditos(alumnos[3]);
    lista->insertarNodoOrdenadoCreditos(alumnos[4]);

    // imprimir la lista
    printf("\nImpresion de la lista descendente: \n");
    lista->imprimirLista();

    return 0;
}