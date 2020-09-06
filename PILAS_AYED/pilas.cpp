//2) Dada una pila de n�meros enteros y un valor entero que llamamos X, desarrollar un
//procedimiento que inserte X como tercer elemento de la pila.

#include <iostream>

using namespace std;

struct Nodo
{
	int dato;
	Nodo* siguiente;
};
void TercerElemento(Nodo*&, int);
void push(Nodo*&, int);
int pop(Nodo*&);

int main() {
	Nodo* pila = NULL;

	for (int i = 0; i < 10; i++)
	{
		cout << "elemento cargado a la pila: " << i << endl;
		push(pila, i);
	}

	TercerElemento(pila, 750);

	cout << "--------------------------------" << endl;
	cout << "Elementos en pila!!!!!!!!!!" << endl;

	while (pila != NULL)
	{
		int a = pop(pila);
		cout << "Elementos de la pila: " << a << endl;
	}

	return 0;
}

void TercerElemento(Nodo*& pila, int dat) {
	int a = pop(pila);
	int b = pop(pila);
	push(pila, dat);
	push(pila, b);
	push(pila, a);
	
	return;
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