//sequential SEarch

int sequentialSearch(int arr[], int n, int target){
    for(int i = 0; i< n; i++){
        if(arr[i] == target){
            return i;
        }
    }
}

//Insertion Sort

int insertionSort(int arr[], int n){
    for(int i = 0; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key){
            int temp =  arr[j+1]; arr[j+1] = arr[j]; arr[j] =  temp;
            j--;
        }
        arr[j+1] = key;
    }
}


//QuickSort
int partition(int arr[], int lo, int hi){
    int pivot = arr[lo];
    int i = lo + 1;
    for(int j = lo +1; j<=hi; j++){
        if(arr[j] > pivot){
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            i++;
        }
        int temp =  arr[i-1]; arr[i-1] = arr[lo]; arr[lo] = temp;
        return i-1;
    }
}
void quicksort(int arr[], int lo, int hi){
    if(lo>=hi)return;
    int pivotIndex = partition(arr,lo,hi);
    quicksort(arr,lo,pivotIndex -1);
    quicksort(arr, pivotIndex +1, hi);
}