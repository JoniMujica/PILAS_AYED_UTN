// Idem ejercicio 1 pero retornando un parámetro con valor 'S' o 'N' según haya sido exitoso o no el requerimiento.
// (Definir parámetros y codificar).

#include <iostream>

using namespace std;

struct Nodo
{
	int dato;
	Nodo* siguiente;
};
char verificar(Nodo*&);
void push(Nodo*&, int);
int pop(Nodo*&);

int main() {
	Nodo* pila = NULL; //inicio la pila en NULL
	for (int i = 0; i < 2; i++)
	{
		cout << "elemento agregado a pila: " << i << endl;
		push(pila, i);
	}
	char res = verificar(pila);  //se guarda la variable de retorno (char) segun corresponda el return de la funcion 'verificar'
	cout << "resultado de la operacion: " << res << endl; // imprimo la variable de retorno

	return 0;
}

char verificar(Nodo*& pila) {
	for (int i = 0; i < 2; i++) // define cuantos elementos se va a quitar de la pila
	{
		if (pila != NULL)  //si la pila no es nula, sigue sacando
		pop(pila); //saca elemento de la pila
		else return 'N';  // si es NULL y no puede sacar mas pilas de lo definido en for, retorna N
	}
	return 'S'; //Si no es NULL y pudo sacar la cantidad de elementos indicado en el For, entonces retorna S
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