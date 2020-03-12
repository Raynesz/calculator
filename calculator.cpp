//#define _GLIBCXX_USE_CXX11_ABI 0
// Compile using -static-libgcc -static-libstdc++
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "calculator.h"
#include "operations.h"

using namespace std;

int main() {
  string user_input="";
  vector<string> operands;
  string operators="+-*/";
  int i;
  double result;
  bool isSplit, zeroDenom;

  cout << "Please type in the calculation that you would like to perform and then press Enter. Type 'exit' to terminate the program." << endl;
  while (user_input.compare("exit") != 0 && user_input.compare("EXIT") != 0) {
    isSplit = false;
    i=-1;
    zeroDenom=false;
    cout << "->";
    getline(cin, user_input);
    while (!isSplit && i<3) {
      i++;
      operands.clear();
      split(user_input, operands, operators[i]);
      if (operands.size()==2) {
        isSplit = true;
        if (is_digits(operands[0]) && is_digits(operands[1])) {
          switch (i) {
            case 0:
              result = add(operands);
              break;
            case 1:
              result = sub(operands);
              break;
            case 2:
              result = mul(operands);
              break;
            case 3:
              if (stod(operands[1]) == 0.0) zeroDenom=true;
              else result = div(operands);
              break;
            default:
              break;
          }
          if (zeroDenom) cout << "Denominator cannot be 0." << endl;
          else cout << "=" << result << endl;
        }
      }
    }
  }
  return(0);
}

bool is_digits(const string& str) {
  if (str.find_first_not_of("0123456789") == string::npos) return 1;
  else return 0;
}

void split(string& str, vector<string>& container, char delim) {
  stringstream ss(str);
  string token;
  while (getline(ss, token, delim)) {
    container.push_back(token);
  }
}
