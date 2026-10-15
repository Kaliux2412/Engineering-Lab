#include <iostream>
#include <vector>
using namespace std;

//**** */
int sequetialSearch(int arr[], int n, int target){
    for(int i = 0; i < n; i++){
        if(arr[i] == target){
            return i;
        }
        
    }
    return -1;
}
/// IMPLEMENTACION QUIZ
int sequentialSearch(const vector<int>& data, int target) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == target) {
            return i;
        }
    }

    return -1;
}


int BinarySearch(int arr[], int n, int target){
    int right = n-1;
    int left = 0;
    while(left <=right){
        int middle = left + (right- left)/2;
        
        if (arr[middle] == target){
            return middle;
        }
        if(arr[middle] < target){
            left = middle +1;
        }
        else{
            right = middle -1;
        }
    }
    return -1;
    
}

void BubbleSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void SelectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int minindex = i;
        for(int j = i+1; j < n; j++){
            if  (arr[j]< arr[minindex]){
                minindex = j;
            }
        }
        swap(arr[i], arr[minindex]);
    }
}
//***** */
void InsertionSort(int arr[], int n){
    for (int i = 0; i <n; i++){
        int key = arr[i];
        int j = i -1;
        while (j>= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;

    }
}

//IMPLEMENTACION QUIZ
void insertionSort(vector<int>& data) {

    int n = data.size();

    for (int i = 1; i < n; i++) {

        int key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = key;
    }
}

//MERGESORT
void merge(int arr[], int left, int middle, int right){
    int temp[right - left +1];
    int i = left, j = middle +1, k =0;
    while (i <= middle && j <= right)
        temp[k++]= (arr[i] <= arr[j]) ? arr[i++]: arr[j++];
    while (i <= middle) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for(int x = 0; x <right - left +1; x++) arr[left + x] = temp[x];
}
void mergeSort(int arr[], int left, int right){
    if(left >= right) return;
    int mid = (left + right)/2;
    mergeSort(arr,left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

///**** */
//QUICK SORT
int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low + 1;
    for(int j = low+1; j <= high; j++){
        if (arr[j] < pivot){
            int temp =  arr[i]; arr[i] = arr[j]; arr[j] = temp;
             i++;
            //swap(arr[i], arr[j]);
        }
    }
    int temp = arr[low]; arr[low] =  arr[i -1]; arr[i -1] = temp;
    //swap(arr[i-1], arr[low]);
    return i - 1;
}
void quickSort(int arr[], int low, int high){
    if (low>=high) return;
    int pivotIndex = partition(arr,low, high);
    quickSort(arr, low, pivotIndex -1);
    quickSort(arr,pivotIndex +1, high);
}


//IMPLEMENTACION PARA QUIZ 
int partition(vector<int>& data, int low, int high) {
    int pivot = data[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (data[j] < pivot) {
            i++;
            // int temp = data[i]; data[i] = data[j]; data[j] = temp;
            swap(data[i], data[j]);
        }
    }
    // int temp = data[high]; data[high] = data[i+1]; data[i+1] = temp;
    swap(data[i + 1], data[high]);
    return i + 1;
}
void quickSort(vector<int>& data, int low, int high) {
    if (low >= high) {
        return;
    }
    int pivotIndex = partition(data, low, high);
    quickSort(data, low, pivotIndex - 1);
    quickSort(data, pivotIndex + 1, high);
}

// Wrapper para el test
void quickSort(vector<int>& data) {
    if (data.empty()) {
        return;
    }
    quickSort(data, 0, data.size() - 1);
}

