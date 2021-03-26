#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
public:
  typedef std::vector<std::string>::size_type size_type;

  friend class StrBlobPtr;
  friend class ConstStrBlobPtr;
  friend bool operator==(const StrBlob &, const StrBlob &);
  friend bool operator!=(const StrBlob &, const StrBlob &);
  friend bool operator<(const StrBlob &, const StrBlob &);
  friend bool operator<=(const StrBlob &, const StrBlob &);
  friend bool operator>(const StrBlob &, const StrBlob &);
  friend bool operator>=(const StrBlob &, const StrBlob &);

  StrBlobPtr begin();
  StrBlobPtr end();
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

bool operator==(const StrBlob &, const StrBlob &);
bool operator!=(const StrBlob &, const StrBlob &);
bool operator<(const StrBlob &, const StrBlob &);
bool operator<=(const StrBlob &, const StrBlob &);
bool operator>(const StrBlob &, const StrBlob &);
bool operator>=(const StrBlob &, const StrBlob &);

class StrBlobPtr
{
  typedef std::vector<std::string>::size_type size_type;
  friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

public:
  StrBlobPtr();
  StrBlobPtr(StrBlob &a, size_t sz = 0);

  std::string &deref() const;
  StrBlobPtr &incr();

private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  size_t curr;
};

bool operator==(const StrBlobPtr &, const StrBlobPtr &);
bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
bool operator<(const StrBlobPtr &, const StrBlobPtr &);
bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
bool operator>(const StrBlobPtr &, const StrBlobPtr &);
bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

class ConstStrBlobPtr
{
  typedef std::vector<std::string>::size_type size_type;
  friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

public:
  ConstStrBlobPtr();
  ConstStrBlobPtr(const StrBlob &a, size_t sz = 0);

  std::string &deref() const;
  ConstStrBlobPtr &incr();

private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  size_t curr;
};

bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
