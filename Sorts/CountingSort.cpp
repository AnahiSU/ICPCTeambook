#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

void countSort(vector<long long> &arreglo){
    auto iterador = max_element(arreglo.begin(),arreglo.end());
    long long maximo = *iterador;
    vector<long long> frecuencias(maximo+1,0);
    for(long long i=0;i<arreglo.size();i++){
        long long pos = arreglo[i];
        frecuencias [pos]++;
    }
    long long indiceArregloOriginal=0;
    for(long long k=0;k<frecuencias.size();k++){
        while(frecuencias[k]>0){
            arreglo[indiceArregloOriginal]=k;
            frecuencias[k]--;
            indiceArregloOriginal++;
        }
    }
}