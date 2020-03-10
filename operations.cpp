#include <vector>
#include <string>
#include <iostream>
#include "operations.h"
#include "calculator.h"

using namespace std;



int sub(vector<string>& v) {
  int res = stoi(v[0])-stoi(v[1]);
  return res;
}

int mul(vector<string>& v) {
  return stoi(v[0])*stoi(v[1]);
}

int div(vector<string>& v) {
  return stoi(v[0])/stoi(v[1]);
}

void test() {
  cout << "test" << endl;
}
