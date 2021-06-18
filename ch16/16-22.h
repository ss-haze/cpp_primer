#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <iostream>
#include <memory>
#include "16-21.h"

using std::cin; using std::cout;
using std::ifstream; using std::istringstream;
using std::map; using std::set;
using std::shared_ptr;
using std::string; using std::vector;

class QueryResult;

class TextQuery
{
public:
  typedef vector<string>::size_type line_num_type;
  TextQuery(ifstream &ifs);
  QueryResult query(const string &s) const;

private:
  shared_ptr<vector<string>> text;
  map<string, shared_ptr<set<line_num_type>>> mp;
};

class QueryResult
{
  friend std::ostream &print(std::ostream &os, const QueryResult &q);

public:
  QueryResult(const string &str, shared_ptr<set<TextQuery::line_num_type>> lnt, shared_ptr<vector<string>> v)
      : s(str),
        line_ptr(v),
        set_ptr(lnt)
  {}

private:
  const string s;
  shared_ptr<set<TextQuery::line_num_type>> set_ptr;
  shared_ptr<vector<string>> line_ptr;
};

std::ostream &print(std::ostream &os, const QueryResult &q);

TextQuery::TextQuery(ifstream &ifs)
    : text(new vector<string>(), DebugDelete())
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

QueryResult TextQuery::query(const string &s) const
{
  auto it = mp.find(s);
  if (it == mp.end())
  {
    shared_ptr<set<line_num_type>> empty_set(new set<line_num_type>, DebugDelete());
    return QueryResult(s, empty_set, text);
  }
  return QueryResult(s, it->second, text);
}

std::ostream &print(std::ostream &os, const QueryResult &q)
{
  os << "The word " << q.s << " occurs " << q.set_ptr->size() << " times" << std::endl;
  for (const auto l : *q.set_ptr)
  {
    os << "(Line " << l << ") " << (*q.line_ptr)[l - 1] << std::endl;
  }
  return os;
}