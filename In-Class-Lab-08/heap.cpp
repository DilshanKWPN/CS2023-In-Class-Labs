#include <iostream>

using namespace std;

//creating heap
void heapify(int arr[], int size, int root)
{
    int leftchild = 2 * root + 1;
    int rightchild = 2 * root + 2;
    int largest = root;

    if (leftchild < size && arr[leftchild] > arr[largest]) {
        largest = leftchild;
    }

    if (rightchild < size && arr[rightchild] > arr[largest]) {
        largest = rightchild;
    }

    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, size, largest);
    }
}
//heap sort 
void heapSort(int arr[], int size)
{
    int i = size / 2 - 1;
    while (i >= 0) {
        heapify(arr, size, i);
        i--;
    }

    int j = size - 1;
    while (j >= 0) {
        swap(arr[0], arr[j]);
        heapify(arr, j, 0);
        j--;
    }
}

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int heap_arr[] = { 4, 17, 3, 12, 9, 6 };
    int n = sizeof(heap_arr) / sizeof(heap_arr[0]);
    cout << "Input array" << endl;
    displayArray(heap_arr, n);

    heapSort(heap_arr, n);

    cout << "Sorted array" << endl;
    displayArray(heap_arr, n);
}
