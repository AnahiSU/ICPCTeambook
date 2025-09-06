
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

void partir(vector<long long> &arreglo, long long ini,long long medio,long long fin){
    long long tamano1;
    long long tamano2;
    tamano1 = medio-ini+1;
    tamano2 = fin-medio;
    vector<long long> izquierdo(tamano1,0);
    vector<long long> derecha(tamano2,0);
    for(long long i=0;i<tamano1;i++){
        izquierdo[i] = arreglo[ini+i]; 
    }
    for(long long i=0;i<tamano2;i++){
        derecha[i] = arreglo[medio + 1+ i];
    }
    long long j=0;
    long long k=0;
    long long indiceArregloOriginal=ini;
    while(j<tamano1 && k<tamano2){
        if(izquierdo[j]<=derecha[k]){
            arreglo[indiceArregloOriginal] = izquierdo[j];
            j++;
        }
        else{
            arreglo[indiceArregloOriginal] = derecha[k];
            k++;
        }
        indiceArregloOriginal++;
    }
    while(j<tamano1){
        arreglo[indiceArregloOriginal]=izquierdo[j];
        indiceArregloOriginal++;
        j++;
    }
    
    while(k<tamano2){
        arreglo[indiceArregloOriginal]=derecha[k];
        indiceArregloOriginal++;
        k++;
    }
}


void mergeSort (vector<long long> &arreglo, long long ini, long long fin){
    if(ini<fin){
        long long medio =ini+(fin-ini)/2;
        mergeSort(arreglo,ini,medio);
        mergeSort(arreglo,medio+1,fin);
        partir(arreglo,ini,medio,fin); 
    }
}