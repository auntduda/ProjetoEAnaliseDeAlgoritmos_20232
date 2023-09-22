#include <bits/stdc++.h>

using namespace std;

// saido direto da wikipedia

void merge(int *saida, int *auxiliar, int inicio, int meio, int fim){
    int i, j, k;
    i = inicio;
    j = meio + 1;
    k = inicio;
    while(i <= meio && j <= fim){
        if(auxiliar[i] < auxiliar[j]){
            saida[k] = auxiliar[i];
            i++;
        }
        else{
            saida[k] = auxiliar[j];
            j++;
        }
        k++;
    }

    while(i <= meio){
        saida[k] = auxiliar[i];
        i++;
        k++;
    }

    while(j <= fim){
        saida[k] = auxiliar[j];
        j++;
        k++;
    }
    //Copia os elementos que foram ordenados para o auxiliar
    for(int p = inicio; p <= fim; p++)
        auxiliar[p] = saida [p];
}



void mergeSort(int *saida, int *auxiliar, int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;
        mergeSort(saida, auxiliar, inicio, meio);
        mergeSort(saida, auxiliar, meio + 1, fim);
        merge(saida, auxiliar, inicio, meio, fim);
    }
}

int main()
{
    int n; vector<int> a;
    
    while(cin >> n) a.push_back(n);
    
    int v[a.size()]; int ans[a.size()];
    
    for(int i=0; i<a.size(); i++) v[i] = a[i];

    mergeSort(ans, v, 0, a.size()-1);
    
    for(int i=0; i<a.size(); i++)
    {
        cout << ans[i] << " ";
    } cout << "\n";
    
    return 0;
    
}
