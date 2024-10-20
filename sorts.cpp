#include <iostream>
using namespace std;
const int SIZE = 7;

void show(int array[])
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void bsort(int array[]) // bubble
{
    bool flag = false;
    for (int i = 0, n = SIZE; i < n - i; i++) {
        flag = true;
        for (int j = 0, n = SIZE; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                flag = false;
            }

        }
        if (flag)break;
    }
}

void isort(int array[]) // insertion
{ 
    
    for (int i = 1; i < SIZE; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (array[j] < array[j - 1])
            {
                swap(array[j], array[j - 1]);

            }
            else
            {
                break;
            }
        }
    }
}

void qsort (int array[], int low, int high) // quick
{

    if (low < high) {
        int pivot = array[high]; 
        int i = low - 1; 

        for (int j = low; j < high; j++) {
            if (array[j] <= pivot) {
                i++; 
                swap(array[i], array[j]); 
            }
        }
        swap(array[i + 1], array[high]); 
        int pi = i + 1; 
        qsort(array, low, pi - 1);
        qsort(array, pi + 1, high);
    }
}

int binary(int ar[], int size, int target) //Бинарный поиск
{
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; 

        if (ar[mid] == target) { 
            return mid; 
        }

        if (ar[mid] < target) {
            left = mid + 1; 
        }
        else { 
            right = mid - 1; 
        }
    }

    return -1; 
}

void mergeSort(int ar[], int size) { 
    if (size < 2) return; 
    int mid = size / 2; 
    int* L = new int[mid];
    int* R = new int[size - mid]; 
    for (int i = 0; i < mid; i++) L[i] = ar[i];
    for (int j = mid; j < size; j++) R[j - mid] = ar[j]; 
    mergeSort(L, mid);
    mergeSort(R, size - mid);
    int i = 0, j = 0, k = 0; 
    while (i < mid && j < size - mid) { 
        if (L[i] <= R[j]) ar[k++] = L[i++];
        else ar[k++] = R[j++];
    }

    // Копируем оставшиеся элементы, если есть
    while (i < mid) ar[k++] = L[i++]; // Копируем остаток из L
    while (j < size - mid) ar[k++] = R[j++]; // Копируем остаток из R

    delete[] L; // Освобождаем память для L
    delete[] R; // Освобождаем память для R
}

int main()
{
    setlocale(LC_ALL, "rus");
    int array[] = { 10,23,7,34,12,55,99 };
    show(array);
    mergeSort(array, SIZE);
    show(array);
}