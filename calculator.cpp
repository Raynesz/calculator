//#define _GLIBCXX_USE_CXX11_ABI 0
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
  string str="";
  vector<string> v;
  enum operation {_add='+', _sub='-', _mul='*', _div='/'}op;
  string ops="+-*/";
  int i;
  string final;
  double res;
  bool isValid, isSplit;
  while (str.compare("exit") != 0 && str.compare("EXIT") != 0) {
    v.clear();
    isSplit = false;
    i=-1;
    final="";
    cout << "Please type in the calculation that you would like to perform and then press Enter. Type 'exit' to terminate the program." << endl << "->";
    getline(cin, str);
    while (!isSplit) {
      i++;
      split(str, v, ops[i]);
      if (v.size()==2) {
        switch (i) {
          case 0:
            add(v);
            break;
          case 1:
            sub(v);
            break;
          case 2:
            mul(v);
            break;
          case 3:
            div(v);
            break;
          }
        cout << res << endl;
        } else {
          continue;
        }
        }
      }
    }


    if (any_of(begin(str), end(str), isalpha)) {
      continue;
    } else {
      if (v.size() == 2) {
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
        final=to_string(res);
        if (str.compare("")!=0) cout << final << endl;
      }
    }
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
