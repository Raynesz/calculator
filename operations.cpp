#include <vector>
#include <string>
#include "operations.h"

using namespace std;



int sub(vector<string>& v) {
  return stoi(v[0])-stoi(v[1]);
}

int mul(vector<string>& v) {
  return stoi(v[0])*stoi(v[1]);
}

int div(vector<string>& v) {
  return stoi(v[0])/stoi(v[1]);
}
