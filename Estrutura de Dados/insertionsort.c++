#include <iostream>
using namespace std;
#define n 6

void insertionSort(int array[]) {
  for (int i = 1; i < n; i++) {
    int aux = array[i];
    int j = i - 1;

    while (j >= 0 && array[j] > aux) {
        array[j + 1] = array[j];
        j = j - 1;
    }
    array[j + 1] = aux;
  }
}

int main() {
  int array[] = {17, 38, 2, 7, 10, 9};

  insertionSort(array);

  for (int i = 0; i < n; ++i) {
    cout << array[i] << " ";
  }

  return 0;
}