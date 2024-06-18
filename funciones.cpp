#include <iostream> 
#include <string.h>
#include "variables.h"

using namespace std;

USUARIO usuarios[MAX_REGISTERS]; //arreglo de estructuras de tipo USUARIO
int pos = 0; 

//funcion para agregar un usuario
int obtPos(char id);
void AgregarUsuario(USUARIO *u);
void editarUsuario(char id, USUARIO *u);
void eliminarUsuario(char id);
USUARIO buscarUsuario(char id);
int menu();
void principal();
void pedirDatos();
void mostrarDatos();
void showData(USUARIO &u);
void buscarxID();
void editarDatos();
void eliminarDatos();

void agregarUsuario(USUARIO *u){
    usuarios[pos]= *u;
    pos ++;
}

USUARIO buscarUsuario(char id){
    for (int i = 0; i < pos; i++)
    {
        if (id == usuarios[i].id)
        {
            return usuarios[i];
        }
    }
    USUARIO u;
    return u;
}

int obtPos(char id){
    for (int i = 0; i < pos; i++)
    {
        if (id == usuarios[i].id)
        {
            return i;
        }
    }
    return -1;
}
  
void editarUsuario(char id, USUARIO *u){
    int pos = obtPos(id);
    strcpy(usuarios[pos].nombres, u->nombres);
    strcpy(usuarios[pos].apellidos, u->apellidos);
    strcpy(usuarios[pos].telefono, u->telefono);
}

void eliminarUsuario(char id){
    int pos = obtPos(id);
    for (int i = pos; i < pos; i++)
    {
        usuarios[i] = usuarios[i+1];
    }
    pos --;
}

int menu(){
    int op;
    cout << "Menu de opciones: \n\n";
    cout << "1. Agregar usuario\n";
    cout << "2. Editar usuario\n";
    cout << "3. Eliminar usuario\n";
    cout << "4. Buscar usuario\n";
    cout << "5. Mostrar todo\n";
    cout << "6. Salir\n";
    cout << "Digite la opcion: ";
    cin >> op;
    return op;
}

void principal(){
    int op;
    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            pedirDatos();
            break;
        case 2:
            editarDatos();
            break;
        case 3:
            eliminarDatos();
            break;
        case 4:
            buscarxID();
            break;
        case 5:
            mostrarDatos();
            break;
        case 6:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opcion no valida\n";
            break;  
    }
    } while (op != 6);
}

void pedirDatos(){
    USUARIO usuarios;
    cout << "Datos del usuario\n";
    cout << "ID: ";
    scanf(" %[^\n]", &usuarios.id);
    if (obtPos(usuarios.id) != -1)
    {
        cout << "=========== EL USUARIO YA EXISTE ============ \n";
        return;
    }
    cout << "Nombres: ";
    scanf(" %[^\n]", usuarios.nombres);
    cout << "Apellidos: ";
    scanf(" %[^\n]", usuarios.apellidos);
    cout << "Telefono:\n";
    cin >> usuarios.telefono;
    agregarUsuario(&usuarios);
    cout << "============= USUARIO AGREGADO =============== \n";
}

void mostrarDatos(){
    for (int i = 0; i < pos; i++)
    {
        showData(usuarios[i]);
    }
    if(pos == 0){
        cout << "============ NO HAY REGISTROS ============\n";
        return;
    }
}

void buscarxID(){
    char id;
    cout << "Ingrese el ID del usuario a buscar\n";
    scanf(" %[^\n]", &id);
    if (obtPos(id) == -1){
        cout << "============ EL USUARIO NO EXISTE ============\n";
        return;
    }
    USUARIO u;
    u = buscarUsuario(id);
    showData(u);
}

void showData(USUARIO &u){
    cout << " ============================================ \n";
    cout << u.id << endl;
    cout << u.nombres << endl;
    cout << u.apellidos << endl;
    cout << u.telefono << endl;
    cout << " ============================================ \n";
}

void editarDatos()
{
    char id;
    cout << "Ingrese el ID del usuario a editar\n";
    scanf(" %[^\n]", &id);
    if (obtPos(id) == -1)
    {
        cout << "============ NO SE ENCONTRO REGISTRO    ============\n";
        return;
    }
    USUARIO u = buscarUsuario(id);
    showData(u);
    cout << "Datos actuales del usuario:" << endl;
    cout << "Nombres: ";
    scanf(" %[^\n]", u.nombres);
    cout << "Apellidos: ";
    scanf(" %[^\n]", u.apellidos);
    cout << "Telefono: ";
    cin >> u.telefono;
    editarUsuario(id, &u);
    cout << "============ USUARIO ACTUALIZADO ============\n";
}

void eliminarDatos(){
    char id;
    cout << "Usuario a eliminar\n";
    scanf(" %[^\n]", &id);
    if (obtPos(id) == -1)
    {
        cout << "============ NO SE ENCONTRO REGISTRO ============\n";
        return;
    }
    eliminarUsuario(id);
    cout << "============ USUARIO ELIMINADO ============\n";
}