#include <iostream>

using namespace std;

void merge(int a[], int s, int m, int e) {
    int i = s, j = m + 1, k = 0;
    int ar[e - s + 1];

    while (i <= m && j <= e) {
        if (a[i] <= a[j])
            ar[k++] = a[i++];
        else
            ar[k++] = a[j++];
    }

    while (i <= m)
        ar[k++] = a[i++];

    while (j <= e)
        ar[k++] = a[j++];

    for (i = 0; i < r; i++)
        a[s + i] = ar[i];
}

void mergeSort(int a[], int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(a, s, m);
        mergeSort(a, m + 1, e);
        merge(a, s, m, e);
    }
}

int main() {
    int a[] = {10, 8, 9, 2, 1, 3, 4, 6, 5, 7};
    mergeSort(a, 0, 9);
    
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    
    cout << endl;
}