#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <iostream>
#include <memory>

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