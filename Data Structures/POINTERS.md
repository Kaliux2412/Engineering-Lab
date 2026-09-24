- & Indirection operation  *
- nos ayuda a hacer modular nuestro código
- Is used in Dynamic Memory , if you use "new int[n]" for example we get a pointer fot int n
*a = memory address
```
void swap(int *a, int *b){
	int temp = *a
	*a = *b;
	*b = temp;
}
swap(&z, &w)
```
Arrays can also be handled by pointers
arr[j] = *(arr+j)

# LISTS
Sequence of elements,
Operations:
- insert
- remove
- size
- traverse -> visit every element once
- find -> what position is an element
Differences between vector and array: 
- Array is a sequence in memory space, while the vector grows while the program runs.
- The array cannot change the size, once initialized the size is fixed.
**Linked lists:** The elements of the list are spread separately in the memory and they need to have pointers to access the info.       