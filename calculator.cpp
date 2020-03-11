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
  string str;
  vector<string> v;
  enum operation {_add='+', _sub='-', _mul='*', _div='/'}op;
  double res;
  cout << "Please type in the calculation that you would like to perform and then press Enter. Type 'exit' to terminate the program." << endl << "->";
  getline(cin, str);
  while (str.compare("exit") != 0) {
    v.clear();
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
      if (stod(v[1]) == 0) {
        cout << "Denominator can't be 0.";
      } else res=div(v);
    }
    if (str.compare("")!=0) cout << res << endl;
    cout << "Please type in the calculation that you would like to perform and then press Enter. Type 'exit' to terminate the program." << endl << "->";
    getline(cin, str);
  }
  return 0;
}

void split(string& str, vector<string>& v, char delim) {
  stringstream ss(str);
  string token;
  while (getline(ss, token, delim)) {
    v.push_back(token);
  }
}
