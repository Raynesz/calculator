#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "calculator.h"
#include "operations.h"


using namespace std;

int main() {
  test();
  string str;
  vector<string> v;
  enum operation {_add='+', _sub='-', _mul='*', _div='/'}op;
  int res;
  cout << "Please type in the calculation that you would like to perform and then press Enter." << endl << "->";
  getline(cin, str);
  cout << str << endl;
  if (str.find('+') != std::string::npos) {
    split(str, v, op=_add);
    res=add(v);
  } else if (str.find('-') != std::string::npos) {
    split(str, v, op=_sub);
    res=sub(v);
  } else if (str.find('*') != std::string::npos) {
    split(str, v, op=_mul);
    res=mul(v);
  } else if (str.find('/') != std::string::npos) {
    split(str, v, op=_div);
    if (stoi(v[1]) == 0) {
      cout << "Denominator can't be 0.";
    } else res=div(v);
  }
  cout << res << endl;
  //system("PAUSE");
  return 0;
}


void split(string& str, vector<string>& v, char delim) {
  stringstream ss(str);
  string token;
  while (getline(ss, token, delim)) {
    v.push_back(token);
  }
}

int add(vector<string>& v) {
  return stoi(v[0])+stoi(v[1]);
}
