#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

long long partirQuick(vector<long long> &arreglo, long long ini, long long fin){
    long long pivote = arreglo[fin];
    long long indice = ini-1;
    for(long long i=ini;i<fin;i++){
        if(arreglo[i]<pivote){
            indice++;
            swap(arreglo[i],arreglo[indice]);
        }
    }
    swap(arreglo[indice+1],arreglo[fin]);
    return (indice+1);
}

void quickSort(vector<long long> &arreglo , long long ini, long long fin){
    if(ini<fin){
        long long indice = partirQuick (arreglo,ini,fin);
        quickSort(arreglo,ini,indice-1);
        quickSort(arreglo,indice+1,fin);
    }
}
