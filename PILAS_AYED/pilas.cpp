// Dada una pila y un valor X, desarrollar un procedimiento que inserte el valor X en la última posición de la pila y la retorne. (Definir parámetros y codificar).

#include <iostream>

using namespace std;

struct Nodo
{
	int dato;
	Nodo* siguiente;
};


void Ultimo(Nodo*&,Nodo*&);
void push(Nodo*&, int);
int pop(Nodo*&);

int main() {
	Nodo* pila = NULL;
	Nodo* pilaaux = NULL;
	int x;
	for (int i = 0; i < 10; i++)
	{
		push(pila, i);
		cout << "Elemento agregado: " << i << endl;
	}
	cout << "Ingrese un valor" << endl;
	cin >> x;
	push(pila, x);

	Ultimo(pila, pilaaux);


	while (pila != NULL) {
		int res = pop(pila);
		cout << "Elementos de la pila1: " << res << endl;
	}
	//Ultimo(pila, pilaaux);
	cout << endl << endl << endl;
	while (pilaaux != NULL) {
		int res = pop(pilaaux);
		cout << "Elementos de la pila2: " << res << endl;
	}
	return 0;
}

void Ultimo(Nodo*& pila ,Nodo*& pilaux) {
	int base = pop(pila);
	while (pila != NULL)
	{
		int elementos = pop(pila);
		push(pilaux, elementos);
	}
	push(pila, base);
	while (pilaux != NULL)
	{
		int element = pop(pilaux);
		push(pila, element);
	}
}

void push(Nodo*& pila, int dat) {
	Nodo* Nuevo_nodo = new Nodo(); //pido un espacio en memoria para la nueva pila (nuevo nodo)
	Nuevo_nodo->dato = dat; // cargo el valor dentro del nodo (campo 'dato')
	Nuevo_nodo->siguiente = pila; // //carga el puntero pila dentro del nodo (*siguiente) [ya que pila era null]
	pila = Nuevo_nodo; // asigna el nuevo nodo a pila
}

int pop(Nodo*& pila) { ////recibe la pila como par?metro y retorna el valor contenido en el primer nodo
	int aux; //el tipo de dato de la informaci?n para retornarlo
	Nodo* p = pila; //un puntero al comienzo de la estructura para luego eliminar ese nodo
	aux = pila->dato; //	conservar el valor del primer nodo para retornarlo
	pila = p->siguiente; //Avanzar con la pila un nodo para eliminar el nodo que estaba en el tope
	delete p;	 //eliminar el que era primero, la pila esta apuntando al que era segundo o a NULL
	return aux;
}