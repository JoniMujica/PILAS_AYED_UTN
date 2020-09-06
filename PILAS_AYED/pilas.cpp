//1) Dada una pila de n?meros enteros y un valor entero que llamamos X, desarrollar un
//procedimiento que elimine los 2 primeros elementos de la pila y deje el valor X como
//primero.
#include <iostream>

using namespace std;

struct Nodo
{
	int dato;
	Nodo* siguiente;
};

void push(Nodo*&, int);
int pop(Nodo*&);

int main() {
	Nodo* pila = NULL; // inicializo la variable PILA como NULL
	for (int i = 0; i < 10; i++)
	{
		push(pila, i);  //cargo la pila de 10 elementos
		cout << "Elemnto cargado: " << i << endl;
	}

	cout << "Pilas cargadas correctamente!!" << endl;
	cout << "----------------------------" << endl;
	cout << "Elementos de la pila" << endl;
	while (pila != NULL) //Voy sacando elementos mientras el puntero PILA  no sea NULL
	{
		int a = pop(pila); //saco los elementos de la pila para que muestre el valor de cada uno de ellas (variable del return)
		cout << "Obtengo el Elemento de la pila: " << a << endl;  // Muestro en consola la variable que devuelve la funcion
	}


	return 0;
}


//Pone un nodo en la pila
void push(Nodo*& pila, int dat) { //se invoca con la pila, que siempre se modifica, y el valor a guardar dat
	Nodo* Nuevo_nodo = new Nodo(); //pido un espacio en memoria para la nueva pila (nuevo nodo)
	Nuevo_nodo->dato = dat; // cargo el valor dentro del nodo (campo 'dato')
	Nuevo_nodo->siguiente = pila; // //carga el puntero pila dentro del nodo (*siguiente) [ya que pila era null]
	pila = Nuevo_nodo; // asigna el nuevo nodo a pila
}

//Elimina un nodo de la pila y retorna el valor alli guardado
int pop(Nodo*& pila) { ////recibe la pila como par?metro y retorna el valor contenido en el primer nodo
	int aux; //el tipo de dato de la informaci?n para retornarlo
	Nodo* p = pila; //un puntero al comienzo de la estructura para luego eliminar ese nodo
	aux = pila->dato; //	conservar el valor del primer nodo para retornarlo
	pila = p->siguiente; //Avanzar con la pila un nodo para eliminar el nodo que estaba en el tope
	delete p;	 //eliminar el que era primero, la pila esta apuntando al que era segundo o a NULL
	return aux;
}