#include "12-27-QueryClasses.h"

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

QueryResult TextQuery::query(const string &s) const
{
  auto it = mp.find(s);
  if (it == mp.end())
  {
    shared_ptr<set<line_num_type>> empty_set = std::make_shared<set<line_num_type>>();
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