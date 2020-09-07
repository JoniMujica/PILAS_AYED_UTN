//Dada una pila y dos valores X e Y, desarrollar un procedimiento que reemplace cada valor igual a X que se encuentre en la pila por el valor Y retornando la pila modificada. En caso de no haber ningún valor igual a X retornar la pila sin cambio. (Definir parámetros y codificar).

#include <iostream>

using namespace std;

struct Nodo
{
	int dato;
	Nodo* siguiente;
};
void CompChange(Nodo*&, int,int, int);
void push(Nodo*&, int);
int pop(Nodo*&);

int main() {
	Nodo* pila = NULL;
	int x, y, data;
	cout << "Ingrese el valor que quiere comprar" << endl;
	cin >> x;
	cout << "Ingrese el valor que desea reemplazar" << endl;
	cin >> y;

	cout << "Ingrese valores a la pila: " << endl;
	cin >> data;
	while (data >= 0) {
		cout << "Ingrese valores a la pila: " << endl;
		cin >> data;
		if (data >= 0)
		{
			push(pila, data);
			CompChange(pila, x, y, data);
		}
	}

	while (pila != NULL)
	{
		int res = pop(pila);
		cout << "Elementos de la pila modificada:  " << res << endl;
	}
	return 0;
}

void CompChange(Nodo*& pila, int x,int y, int data) {

	if (data == x)
	{
		pop(pila);
		if (data>=0)
		push(pila, y);
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