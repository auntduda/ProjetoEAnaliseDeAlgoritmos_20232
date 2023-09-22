#include <iostream>
 
using namespace std;
 
long long merge(int arr[], int start, int mid, int end) {
    int aux_size = end - start + 1;
    int aux[aux_size];
    
    long long swaps = 0;
    
    int pos_aux, pos_firstarray = start, pos_secondarray = mid + 1;
 
    // compara os valores das duas arrays e coloca o menor primeiro na array auxiliar
    for (pos_aux = 0; pos_aux < aux_size; pos_aux++) {
        if (pos_firstarray > mid or pos_secondarray > end) break;
        if (arr[pos_firstarray] <= arr[pos_secondarray]) {
            aux[pos_aux] = arr[pos_firstarray];
            pos_firstarray++;
        }
        else {
            aux[pos_aux] = arr[pos_secondarray];
            pos_secondarray++;
            swaps += mid - pos_firstarray + 1;
        }
    }
    
    // coloca os elementos que tiverem sobrado de alguma array
    if (pos_firstarray > mid) {
        for (int i = pos_secondarray; i <= end; i++) {
            aux[pos_aux] = arr[i];
            pos_aux++;
        }
    }
    
    else {
        for (int i = pos_firstarray; i <= mid; i++) {
            aux[pos_aux] = arr[i];
            pos_aux++;
        }
    }
    
    // coloca os valores da array auxiliar na array principal
    int counter = 0;
    for (int i = start; i <= end; i++) {
        arr[i] = aux[counter];
        counter++;
    }
    
    return swaps;
}
 
long long mergesort(int arr[], int start, int end) {
    long long swaps = 0;
    if (start >= end) return 0;
    int mid = start + (end - start) / 2;
    swaps += mergesort(arr, start, mid);
    swaps += mergesort(arr, mid + 1, end);
    swaps += merge(arr, start, mid, end);
    
    return swaps;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int arr [n];
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        cout << mergesort(arr, 0, n - 1) << '\n';
    }
    
    return 0;
}
