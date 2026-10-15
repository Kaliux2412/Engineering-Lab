/*
 * Tarea: Act 1.2 - Search & Sorting algorithms
 * Karla Gabriela Morales Aguilar A01642979
 * Fecha: Septiembre 7, 2026
 *
 * Descripción:
 * En este programa se utilizan tres algoritmos de ordenamiento:
 * Bubble Sort, Selection Sort e Insertion Sort.
 * También se utilizan Sequential Search y Binary Search para busquedas de index.
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * Ordena los elementos del vector utilizando el método Bubble Sort.
 *
 * Parámetros:
 * data - Vector que contiene los elementos que queremos ordenar.
 *
 * Complejidad: O (n^2)
 * 
 * Regresa:
 * No regresa ningún valor, ya que ordena directamente el vector, más bien ordena el vector.
 */
template <typename T>
void bubbleSort(vector<T> &data) {
	int n = data.size();
	bool swapped = true;
	for (int pass = 0; pass < n - 1 && swapped; pass++) {
		swapped = false; 
		for (int j = 0; j < n - 1 - pass; j++) {
			if (data[j + 1] < data[j]) {   //comparacion de dos elementos consecutivos
				swap(data[j], data[j + 1]);
				swapped = true; //se cambia la posicion
			}
		}
	}
}

/*
 * Ordena los elementos del vector utilizando el método Selection Sort.
 *
 * Parámetros:
 * data - Vector que contiene los elementos que queremos ordenar.
 * 
 * Complejidad: O (n^2)
 *
 * Regresa:
 * No regresa ningún valor, ya que ordena directamente el vector.
 */
template <typename T>
void selectionSort(vector<T> &data) {
	int n = data.size();
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i; //variable que guarda posición donde creemos que está el elemento más chico.
		for (int j = i + 1; j < n; j++) {
			if (data[j] < data[minIndex]) {
				minIndex = j;  // se hace la comparacion y j se vuelve más pequeño si se cumple
			}
		}
		if (minIndex != i) {
			swap(data[i], data[minIndex]); //se intercambia el elemento actual con el min econtrado
		}
	}
}

/*
 * Ordena los elementos del vector utilizando el método Insertion Sort.
 *
 * Parámetros:
 * data - Vector que contiene los elementos que queremos ordenar.
 * 
 * Complejidad: O (n^2)
 *
 * Regresa:
 * No regresa ningún valor, ya que ordena directamente el vector.
 */
template <typename T>
void insertionSort(vector<T> &data) {
	int n = data.size();
	for (int i = 1; i < n; i++) {
		T key = data[i];
		int j = i - 1; //elemento anterior
		while (j >= 0 && data[j] > key) {
			data[j + 1] = data[j];
			j = j - 1; //mayores a key se mueven a la derecha
		}
		data[j + 1] = key;
	}
}

/*
 * Busca un elemento dentro del vector recorriéndolo de principio a fin.
 *
 * Parámetros:
 * data - Vector donde queremos realizar la búsqueda.
 * value - Elemento que estamos buscando.
 * 
 * Complejidad: O (n)
 *
 * Regresa:
 * La posición del elemento si lo encuentra; de lo contrario, regresa -1.
 */
template <typename T>
int sequentialSearch(vector<T> &data, T value) {
	int size = data.size();
	for (int i = 0; i < size; i++) {
		if (data[i] == value) {
			return i;
		}
	}
	return -1;
}

/*
 * Busca un elemento dentro de un vector que ya está ordenado.
 * En cada paso reduce la parte del vector donde necesita buscar.
 *
 * Parámetros:
 * data - Vector ordenado donde queremos realizar la búsqueda.
 * value - Elemento que estamos buscando.
 * 
 * Complejidad: O (log n)
 *
 * Regresa:
 * La posición del elemento si lo encuentra; de lo contrario, regresa -1.
 */
template <typename T>
int binarySearch(vector<T> &data, T value) {
	int size = data.size();
	int lo = 0;
	int hi = size - 1;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (data[mid] == value) {
			return mid;
		}
		if (data[mid] < value) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return -1;
}

/*
 * Aquí probamos los diferentes métodos de ordenamiento y búsqueda.
 * Al final mostramos en pantalla los resultados obtenidos.
 *
 * Parámetros: El vector que queremos ordenar o el número que queremos encontrar.
 *
 * Regresa:
 * 0 cuando el programa termina correctamente.
 * Regresa -1 en los casos de Search.
 */
int main() {
    //Inicialización de vectores que usaremos o lista que ordenaremos.
	vector<int> data1 = {2, 5, 4, 8, 9};
	vector<int> data2 = {13, 2, 24, 7, 5};
	vector<int> data3 = {12, 11, 13, 5, 6};
	vector<int> data4 = {23, 2, 9, 5, 4, 7, 3};
	vector<int> data5 = {34, 56, 2, 4, 12, 5, 6, 7, 1, 9, 3};

    // Valores que queremos buscar en las ultimas 2 listas respectivamente.
	int n1 = 7;
	int n2 = 56;

    //Ciclo de cout para imprimir cada valor una vez ordenado
	bubbleSort(data1);
	cout << "Vector ordenado Bubble Sort: ";
	for (int x : data1) {
		cout << x << " ";
	}
	cout << endl;

    //Ciclo para selectionSort
	selectionSort(data2);
	cout << "Vector ordenado Selection Sort: ";
	for (int x : data2) {
		cout << x << " ";
	}
	cout << endl;

    //Ciclo para insertionSort
	insertionSort(data3);
	cout << "Vector ordenado Insertion Sort: ";
	for (int x : data3) {
		cout << x << " ";
	}
	cout << endl;

    //Asignar a index la el indice que se obtiene de sequentialSearch
	int index = sequentialSearch(data4, n1);
	cout << "Indice por Sequential Search: " << index << endl;

    // Para el Binary Search los valores tienen que estar previamente ordenados asi
    //que se usa selectionSort para ordenar la lista y despues hacer el binarySearch
	selectionSort(data5);
	int binary = binarySearch(data5, n2);
	cout << "Indice por Binary Search: " << binary << endl;
	return 0;
}
