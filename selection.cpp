#include <iostream>
using namespace std;

template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i])
                swap(arr[i], arr[j]);
        }
    }
}

int main() {
    int intArr[] = {5, 3, 1, 4};
    float floatArr[] = {2.3, 1.2, 4.5, 3.1};

    selectionSort(intArr, 4);
    selectionSort(floatArr, 4);

    cout << "Sorted Integers: ";
    for (int i : intArr) cout << i << " ";

    cout << "\nSorted Floats: ";
    for (float f : floatArr) cout << f << " ";

    return 0;
}
