#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <iostream>
#include <memory>

#include "StrBlobTotal.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::istringstream;
using std::map;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

class QueryResult
{
  friend std::ostream &print(std::ostream &os, const QueryResult &q);

public:
  QueryResult(const string &str, shared_ptr<set<StrBlob::size_type>> lnt, const StrBlob &v)
      : s(str),
        line_ptr(v),
        set_ptr(lnt)
  {
  }

private:
  const string s;
  shared_ptr<set<StrBlob::size_type>> set_ptr;
  StrBlob line_ptr;
};

class TextQuery
{
public:
  TextQuery(ifstream &ifs);

  QueryResult query(const string &s) const;

private:
  StrBlob text;
  map<string, shared_ptr<set<StrBlob::size_type>>> mp;
};
