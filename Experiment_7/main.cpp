#include <iostream>

using namespace std;

void adjustHeap(int a[], int i, int length) {
    int temp = a[i];
    for (int k = i * 2 + 1; k < length; k = k * 2 + 1) {
        if (k + 1 < length && a[k] > a[k + 1]) {
            k++;
        }
        if (a[k] < temp) {
            a[i] = a[k];
            i = k;
        } else {
            break;
        }
    }
    a[i] = temp;
}

void swap(int a[], int x, int y) {
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

void sort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        adjustHeap(a, i, n);
    }
    for (int j = n - 1; j > 0; j--) {
        swap(a, 0, j);
        adjustHeap(a, 0, j);
    }
}

int main() {
    int n;
    cout<<"Type in the number of elements:"<<endl;
    cin >> n;
    int a[n];
    cout<<"Type in the elements to be sorted. For example:"<<endl;
    cout<<"10 1 5 3 6 4"<<endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
