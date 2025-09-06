#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const double EPS = 1e-9;

bool areRotations(string &s1, string &s2) {
  	s1 += s1;
  	return s1.find(s2) != string::npos;
}
   
