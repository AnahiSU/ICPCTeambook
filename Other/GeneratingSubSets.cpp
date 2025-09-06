#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const double EPS = 1e-9;

void search(int k){
   if(k == n+1){
   //hacer algo aaa
   }else{
      subset.push_back(k);
      search(k+1);
      subset.pop_back();
      search(k+1);
   }
}
