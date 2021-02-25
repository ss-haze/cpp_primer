#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>

class ConstStrBlobPtr;

class StrBlob
{
public:
  typedef std::vector<std::string>::size_type size_type;

  friend ConstStrBlobPtr;

  ConstStrBlobPtr begin() const;
  ConstStrBlobPtr end() const;

  StrBlob();
  StrBlob(std::initializer_list<std::string> il);

  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  void push_back(const std::string &s) { data->push_back(s); }
  void pop_back();
  std::string &front();
  std::string &back();
  const std::string &front() const;
  const std::string &back() const;

private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type i, const std::string &msg) const;
};