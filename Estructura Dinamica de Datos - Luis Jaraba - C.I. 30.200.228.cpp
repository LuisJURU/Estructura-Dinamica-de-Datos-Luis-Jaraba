#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Persona {

 char nombre[30];
 char clave[30];
 int edad;
};


struct Nodo {

    Persona p;
 Nodo *siguiente;

};

void menu();
void pedir_datos(Persona &p);
void agregar_datos(Nodo *&frente, Nodo *&fin, Persona p);
bool cola_vacia(Nodo *frente);
void elimiar_cola(Nodo *&frente, Nodo *&fin, Persona &da);

Nodo *frente = NULL;
Nodo *fin = NULL;
Persona p;

int main(){

 menu();


 _getch();
 return 0;
}

void menu() {

 int obcion;
 char respuesta;
 do {

  cout << "1) Agregar clientes" << endl;
  cout << "2) Mostrar clientes" << endl;
  cout << "3) salir" << endl;
  cout << "obcion: ";
  cin >> obcion;
  system("cls");
  switch (obcion) {

  case 1:
   do {
    pedir_datos(p);
    agregar_datos(frente, fin, p);
    cout << "Continuar[S/N]: ";
    cin >> respuesta;
    rewind(stdin);
    system("cls");
   } while (respuesta != 'N' && respuesta != 'n');
    break;
  case 2:cout << "\n\n**Lista de clientes***\n\n";

   while (frente != NULL) {
   elimiar_cola(frente, fin, p);
   cout << "Nombre: " << p.nombre << endl;
   cout << "Cedula: " << p.edad << endl;

   cout << "\n";
    }
   system("pause");
   break;
  }

  system("cls");
 } while (obcion != 3);

}


void pedir_datos(Persona &p) {

 rewind(stdin);
 cout << "Ingrese su nombre: ";
 cin.getline(p.nombre, 20, '\n');

 cout << "Ingrese su cedula: ";
 cin >> p.edad;

}

void agregar_datos(Nodo *&frente, Nodo *&fin, Persona p) {

  Nodo *nuevo_nodo = new Nodo();
  nuevo_nodo->p = p;
  nuevo_nodo->siguiente = NULL;

  if (cola_vacia(frente)) {
   frente = nuevo_nodo;
  }
  else {
   fin->siguiente = nuevo_nodo;
  }

  fin = nuevo_nodo;

}

bool cola_vacia(Nodo *frente) {
 return (frente == NULL) ? true : false;
}

void elimiar_cola(Nodo *&frente, Nodo *&fin, Persona &p) {
 p = frente->p;
 Nodo *aux = frente;

 if (frente == fin) {
  frente = NULL;
  fin = NULL;
 }
 else {
  frente = frente->siguiente;
 }

 delete aux;

}
