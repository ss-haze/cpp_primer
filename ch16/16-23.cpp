#include "16-22.h"

void runQueries(ifstream &infile)
{
  TextQuery tq(infile);
  while (true)
  {
    cout << "enter word to look for, or q to quit: ";
    string s;
    if (!(cin >> s) || s == "q")
      break;
    print(cout, tq.query(s)) << std::endl;
  }
}

int main()
{
  ifstream in("data.txt");
  runQueries(in);

  return 0;
}