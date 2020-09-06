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
	for (int i = 0; i < 10; i++)
	{
		push(pila, i);
		cout << "Elemento agregado: " << i << endl; //cargo la pila de elementos
	}
	
	Ultimo(pila, pilaaux); // realiza el intercambio de 'pila' a 'pilaaux' e inserta la variable 'x' a la ultima posicion

	while (pila != NULL) { //mientras pila sea distinto de NULL, imprime
		int res = pop(pila); //trae todos los valores de la pila y se lo asigna a la variable
		cout << "Elementos de la pila1: " << res << endl; //imprime cada elemento de la pila
	}
	return 0;
}

void Ultimo(Nodo*& pila ,Nodo*& pilaux) {
	int x;
	cout << "Ingrese un valor" << endl;
	cin >> x; // pido al usuario el elemento para agregarlo a la pila
	push(pila, x); // agrego la variable en la pila 'pila'


	int base = pop(pila); // guardo el ultimo elemento de la pila 
	while (pila != NULL)
	{
		int elementos = pop(pila);  //guardo los elementos de la pila temporalmente
		push(pilaux, elementos); // envio los elementos guardado a la otra pila 'pilaux'
	}
	push(pila, base);  //inserto el elemento guardado anterior mente de la pila para que quede ultimo
	while (pilaux != NULL)
	{
		int element = pop(pilaux); // guardo temporalmente los elementos de 'pilaux' en la variable
		push(pila, element); //envio los elementos a la pila 'pila'
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