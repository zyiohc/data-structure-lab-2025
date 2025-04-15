#include <iostream>
using namespace std;


int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {

    int arr1[] = { 3, 7, 2, 9, 10, 5 };
    int arr2[] = { -10, -5, -3 };
    int arr3[] = { 100, 200, 300, 50, 400 };
    int arr4[] = { 0, 0, -2, 0 };
    int arr5[] = { 10000 };


    cout << findMax(arr1, 6) << endl;
    cout << findMax(arr2, 3) << endl;
    cout << findMax(arr3, 5) << endl;
    cout << findMax(arr4, 4) << endl;
    cout << findMax(arr5, 1) << endl;

    return 0;
}