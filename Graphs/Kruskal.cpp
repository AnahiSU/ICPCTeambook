#include <bits/stdc++.h>
#include <vector>
using namespace std;

using ll = long long;
//debe guardarse el grafo como (peso,v1,v2)
struct unionFind{
    vector<int> p;
    unionFind(int n) : p(n,-1){}
    int find(int x){
        if(p[x] == -1) return x;
        return p[x] = find(p[x]);
    }

    bool join(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y) return 0;
        p[y]=x;
        return 1;
    }
};
ll kruskal(vector<pair<ll,pair<ll,ll>>> ed, int n){
    //n es nro de vertices
    sort(ed.begin(),ed.end());
    unionFind dsu(n);
    int cntAristas = 0;
    ll res = 0;
    for(auto e: ed){
        ll peso = e.first;
        int u = e.second.first;
        int v = e.second.second;
        if(dsu.join(u,v)){
            cntAristas++;
            res+=peso;
        }
        if(cntAristas == n-1){
            return res;
        }
    }
    if(cntAristas < n-1){
        return -1;
    }
    return res;
}