#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main ()
{

  //line at a time
  string output;
  for (string input; getline(cin, input); output+=input + '\n'); 
  cout << output<<'\n';

  //word at a time
  string word_output;
  for (string input; cin >> input; word_output+=input + " ");
  cout << word_output<<'\n';

  return 0;
}