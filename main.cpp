#include <iostream>

typedef struct alumno
{
    std::string nombre;
    int creditos;
    int semestre;

    alumno(std::string nombre, int creditos, int semestre)
    {
        this->nombre = nombre;
        this->creditos = creditos;
        this->semestre = semestre;
    }

    void imprimirAlumno(void)
    {
        std::cout << "Nombre: " << this->nombre << ", Creditos: " << this->creditos << ", Semestre: " << this->semestre << std::endl;
    }

} Alumno;
typedef Alumno *AlumnoPtr;

typedef struct nodo
{
    AlumnoPtr alumno;
    struct nodo *siguiente;

    nodo(AlumnoPtr nuevo)
    {
        this->alumno = nuevo;
        this->siguiente = NULL;
    }

    void imprimirLista(void){
        NodoPtr actual=&this;

        

    }

} Nodo;
typedef Nodo *NodoPtr;

int main(int argc, char const *argv[])
{
    AlumnoPtr alumnos[5];

    alumnos[0] = new Alumno("a", 1, 1);

    return 0;
}
