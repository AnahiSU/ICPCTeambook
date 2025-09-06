#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> dijkstra(vector<vector<pair<ll, ll>>> g, int n, int s) {
   vector<ll> dis(n, 4e18);
   dis[s] = 0;
   priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
   pq.push({0, s});
   while (!pq.empty()) {
      pair<ll, ll> menorD = pq.top();
      pq.pop();
      ll w = menorD.first;
      ll nodo = menorD.second;
      if (dis[nodo] < w) continue;

      for (auto n : g[nodo]) {
         ll v = n.first;
         ll cost = n.second;
         if (dis[nodo] + cost < dis[v]) {
            dis[v] = dis[nodo] + cost;
            pq.push({dis[v], v});
         }
      }
   }
   return dis;
}