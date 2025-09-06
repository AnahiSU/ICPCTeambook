#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

void bubbleSort(vector<long long> &arreglo) {
    long long n = arreglo.size();
    
    for (long long i = 0; i < n - 1; i++) {
        bool desordenada = false;
        
        for (long long j = 0; j < n - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                swap(arreglo[j], arreglo[j + 1]);
                desordenada = true;
            }
        }
        
        if (!desordenada) {
            break;
        }
    }
}