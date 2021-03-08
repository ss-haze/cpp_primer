#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <iostream>
#include <memory>

#include "StrVec.h"

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
  TextQuery(ifstream &ifs);
  QueryResult query(const string &s) const;

private:
  shared_ptr<StrVec>
      text;
  map<string, shared_ptr<set<size_t>>> mp;
};

class QueryResult
{
  friend std::ostream &print(std::ostream &os, const QueryResult &q);

public:
  QueryResult(const string &str, shared_ptr<set<size_t>> lnt, shared_ptr<StrVec> v)
      : s(str),
        line_ptr(v),
        set_ptr(lnt)
  {
  }

private:
  const string s;
  shared_ptr<set<size_t>> set_ptr;
  shared_ptr<StrVec> line_ptr;
};

std::ostream &print(std::ostream &os, const QueryResult &q);