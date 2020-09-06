

#include <iostream>

using namespace std;

struct Nodo
{
	int dato;
	Nodo* siguiente;
};

void intercambio(Nodo*&);
void push(Nodo*&, int);
int pop(Nodo*&);


int main() {
	Nodo* pila = NULL;
	int x;

	for (int i = 0; i < 5; i++)
	{
		push(pila, i); //cargo la pila de 2 elementos
		cout << "Elementos cargados en pila: " << i << endl; //verifico que se hayan cargado los elementos
	}
	for (int j = 0; j < 2; j++)
	{
		cout << "Ingrese un valor para agregar a la pila: " << endl;
		cin >> x;
		push(pila, x);
		cout << "Elemento " << x << " agregado correctamente a pila!!" << endl << endl;
 	}
	intercambio(pila);

	while (pila != NULL)
	{
		int elementos = pop(pila);
		cout << "Elementos de pila: " << elementos << endl;
	}
	 
	return 0;
}

void intercambio(Nodo*& pila) {
	int a = pop(pila);
	int b = pop(pila);
	push(pila, a);
	push(pila, b);
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