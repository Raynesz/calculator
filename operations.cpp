//#define _GLIBCXX_USE_CXX11_ABI 0
#include <vector>
#include <string>
#include "operations.h"

using namespace std;

double add(vector<string>& v) {
  return stod(v[0])+stod(v[1]);
}

double sub(vector<string>& v) {
  return stod(v[0])-stod(v[1]);
}

double mul(vector<string>& v) {
  return stod(v[0])*stod(v[1]);
}

double div(vector<string>& v) {
  return stod(v[0])/stod(v[1]);
}
