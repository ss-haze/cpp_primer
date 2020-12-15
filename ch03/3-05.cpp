#include <iostream>
#include <string>

using std::cin; using std::cout; using std::string;

void concatenate() {
  string output;
  for (string input; cin >> input; output += input);
  cout << output;
}

void concatenate_spaces() {
  string output;
  for (string input; cin >> input; output += input + " ");
  cout << output;
}

int main() {

  //concatenate();
  //concatenate_spaces();

  return 0;
}