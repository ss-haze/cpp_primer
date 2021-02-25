#include "12-33-declare.h"

TextQuery::TextQuery(ifstream &ifs)
{
  StrBlob::size_type line_num = 1;

  for (string line; std::getline(ifs, line); text.push_back(line), ++line_num)
  {
    istringstream iss(line);
    for (string word; iss >> word;)
    {
      if (mp.find(word) == mp.end())
      {
        mp.insert({word, std::make_shared<std::set<StrBlob::size_type>>()});
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
    shared_ptr<set<StrBlob::size_type>> empty_set = std::make_shared<set<StrBlob::size_type>>();
    return QueryResult(s, empty_set, text);
  }
  return QueryResult(s, it->second, text);
}

std::ostream &print(std::ostream &os, const QueryResult &q)
{
  os << "The word " << q.s << " occurs " << q.set_ptr->size() << " times" << std::endl;
  for (auto l : *q.set_ptr)
  {
    ConstStrBlobPtr str_blb_ptr(q.line_ptr, l - 1);
    os << "(Line " << l << ") " << str_blb_ptr.deref() << std::endl;
  }
  return os;
}
