THERE ARE TWO TYPES THAT WE ARE GOING TO USE:
- SEARCH
- SORT

## *SEARCH:*

- ~ **Sequential or Linear Search**: **Revisa los elementos uno por uno**, desde el principio hasta encontrar el valor que buscamos.
	Se usa cuando:
	 - ~El arreglo no está ordenado
	 - Es de pocos elementos 
	 - No importa ordenar los datos antes
	 - @ **Revisa los elementos uno por uno**
	Código básico:
```
	int sequentialSearch(int arr[], int n, int target) {

    for (int i = 0; i < n; i++) {

        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}
```
	Complejidad:
	-Mejor caso: O(1) -> Que caiga a la primera osea que este al inicio
	-Promedio: O(n)
	-Peor caso: O(n)

- ~ **Binary Search**: Busqueda binaria, es más eficiente, pero requiere que **LOS DATOS ESTEN ORDENADOS**. En este caso parte del mero centro y descarta si el valor que estamos buscando es menor o mayor al del centro eliminando toda la otra **mitad**.
	- Ej: [2, 5, 8, 12, 17, 21, 30] Buscamos el 17 entonces se elimina todo antes del 12 [2,5,8,12] y solo queda [17,21,30], luego evalúa con el 21, este es mayor entonces se elimina el 21 y el 30 y queda el 17  encontrado.
	- @ Binary requiere de datos ordenados para luego dividir el problema a la mitad hasta encontrar el resultado.
	Código común:
```
	int binarySearch(int arr[], int n, int target) {

    int left = 0;
    int right = n - 1;

    while (left <= right) {

        int middle = left + (right - left) / 2;

        if (arr[middle] == target) {
            return middle;
        }

        if (arr[middle] < target) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }

    return -1;
}
```
	Complejidad:
	-Mejor caso: O(1)
	-Promedio: O(log n)
	-Peor: O(log n)

## SORT:

- ~ **Bubble Sort**: Es de los más sencillos (según chat)
	Compara los elementos vecinos y los intercambia si están en el orden incorrecto.
	Ej. [5,2,8,1] ->  5 >2 -> swap [2,5,8,1] ->  5 < 8 -> nada -> [2,5,8,1] -> 8 >1 -> swap -> [2,5,1,8]
	Aquí primero se ordena el mayor hasta el final, luego se van acomodando a partir de ese, en este caso el 8 ya se quedaría fijo y se evaluarían los 3 números restantes.
- @ Se usa cuando: Hay arreglos pequeños, pero no es muy eficiente. Bubble Sort... compara vecinos e intercambia.

```
	void bubbleSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {

                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```
	Complejidad: 
	- Mejor caso: O(n)
	- Promedio: O(n²)
	- Peor: O(n²)

- ~ **Selection Sort**: Selecciona el elemento más pequeño  y lo coloca en la posición correcta.
	- Ej. [5,3,8,1,2], busca el menor, encuentra 1 y lo pone al inicio [1,3,8,5,2] y pone el otro valor en donde antiguamente estaba el 1. Ahora se ignora la posición del 1, va agarrando el que es menor, lo compara con los demás y si no encuentra ninguno menor que el seleccionado entonces lo coloca después del primer valor que encontró en este caso 1.
	- @ Busca el mínimo y lo coloca al inicio.
```
void selectionSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {

        int minIndex = i;

        for (int j = i + 1; j < n; j++) {

            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}
```
	Complejidad: 
	- Mejor caso: O(n²)
	- Promedio: O(n²)
	- Peor: O(n²)

- ~ **Insertion Sort**: Aqui inicia tomando como referencia que el primer valor ya esta ordenado entonces lo compara con el segundo valor y si es menor lo intercambia y continua con el siguiente, los va recorriendo, no los intercambia como el Bubble, si no que se van recorriendo dependiendo de si son menores o no.
- @ Usar cuando son pocos elementos y estan casi ordenados, si no si es un poco lento. Insertion Toma un elemento y lo coloca donde corresponde dentro de la parte ordenada.
```
	void insertionSort(int arr[], int n) {

    for (int i = 1; i < n; i++) {

        int key = arr[i];

        int j = i - 1;

        while (j >= 0 && arr[j] > key) {

            arr[j + 1] = arr[j];

            j--;
        }

        arr[j + 1] = key;
    }
}
```
	Complejidad: 
	- Mejor caso: O(n)
	- Promedio: O(n²)
	- Peor: O(n²)
	
- ~ **Merge Sort**: Este es uno de los mejores algoritmos y lo usan mucho en ICPC y estructuras complejas. Usa la estructura Divide and Conquer, significa que divide, resuelve en partes y combina.
- Ej. Tenemos [8, 3, 5, 2, 9, 1], Dividimos [8, 3, 5]    [2, 9, 1], Luego más pequeño hasta que quedan puros mini arreglos [8],[3],[5],[2],[9],[1], luego se combinan ordenadamente de la mitad a la izquierda una parte y de la derecha otra de forma ordenada osea [3,5,8] y [1,2,9], para después hacer el merge final en dónde se acomodan estos dos últimos arreglos.
- Podemos decir que se divide en dos partes mergeSort para dividir y merge para combinar.
- @ El proceso es dividir hasta llegar a mini arreglos -> después ordenar en dos arreglos -> hacer el merge o combinación de los dos arreglos.
```
- void merge(int arr[], int left, int middle, int right) {

    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right) {

    if (left >= right)
        return;

    int middle = left + (right - left) / 2;

    mergeSort(arr, left, middle);

    mergeSort(arr, middle + 1, right);

    merge(arr, left, middle, right);
}
```
Es el tipo de algoritmo más largo de vista y para escribir pero es muy eficiente.
	Complejidad:
	-Mejor caso: O(n log n)
	- Promedio O(n log n)
	-Peor caso: O(n log n)