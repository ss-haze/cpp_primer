#include <string>
#include <memory>
#include <iostream>

using std::ostream;
using std::shared_ptr;
using std::string;

class QueryResult;

class Query_base
{
  friend class Query;

protected:
  using line_no = TextQuery::line_no;
  virtual ~Query_base() = default;
  virtual QueryResult eval(const TextQuery &) const = 0;
  virtual string rep() const = 0;
};

class Query
{
  friend Query operator~(const Query &);
  friend Query operator|(const Query &, const Query &);
  friend Query operator&(const Query &, const Query &);

public:
  Query(const string &);

  QueryResult eval(const TextQuery &t const) { return q->eval(t); }
  string rep() const { return q->rep(); }

private:
  Query(shared_ptr<Query_base> query)
      : q(query) {}

  shared_ptr<Query_base> q;
};

ostream &operator<<(ostream os, const Query &query)
{
  return os << query.rep();
}

class WordQuery : public Query_base
{
  friend class Query;
  WordQuery(string &s)
      : query_word(s) {}

  QueryResult eval(const TextQuery &t const) { return t.query(query_word); }
  string rep() const { return query_word; }

  string query_word;
};