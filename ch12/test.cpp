#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <iostream>
#include <utility>
#include <memory>

using std::cin;
using std::cout;
using std::ifstream;
using std::istringstream;
using std::map;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

class QueryResult;

class TextQuery
{
public:
  typedef vector<string>::size_type line_num_type;
  TextQuery(ifstream &ifs);
  QueryResult query(const string &s);

private:
  shared_ptr<vector<string>>
      text;
  map<string, shared_ptr<set<line_num_type>>> mp;
};

TextQuery::TextQuery(ifstream &ifs)
    : text(std::make_shared<vector<string>>())
{
  line_num_type line_num = 1;

  for (string line; std::getline(ifs, line); text->push_back(line), ++line_num)
  {
    istringstream iss(line);
    for (string word; iss >> word;)
    {
      if (mp.find(word) == mp.end())
      {
        mp.insert({word, std::make_shared<std::set<line_num_type>>()});
      }
      mp.at(word)->insert(line_num);
    }
  }
}

class QueryResult
{
  friend void print(std::ostream &os, QueryResult q);

public:
  QueryResult(const string &str, shared_ptr<set<TextQuery::line_num_type>> lnt, shared_ptr<vector<string>> v)
      : s(str),
        line_ptr(v),
        set_ptr(lnt)
  {
  }

private:
  string s;
  shared_ptr<set<TextQuery::line_num_type>> set_ptr;
  shared_ptr<vector<string>> line_ptr;
};

QueryResult TextQuery::query(const string &s)
{
  auto it = mp.find(s);
  if (it == mp.end())
  {
    shared_ptr<set<line_num_type>> empty_set = std::make_shared<set<line_num_type>>();
    return QueryResult(s, empty_set, text);
  }
  return QueryResult(s, it->second, text);
}

void runQueries(std::ifstream &infile)
{
  TextQuery tq(infile);
  while (true)
  {
    cout << "enter word to look for, or q to quit: ";
    string s;
    if (!(cin >> s) || s == "q")
      break;
    print(cout, tq.query(s));
  }
}

void print(std::ostream &os, QueryResult q)
{
  cout << "The word " << q.s << " occurs " << q.set_ptr->size() << " times" << std::endl;
  for (const auto l : *(q.set_ptr))
  {
    cout << "(Line " << l << ") " << (*q.line_ptr)[l - 1] << std::endl;
  }
}

int main()
{
  ifstream in("data.txt");
  runQueries(in);
}