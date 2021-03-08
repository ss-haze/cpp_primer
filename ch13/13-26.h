#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

using std::string;
using std::vector;

class ConstStrBlobPtr;

class StrBlob
{
public:
  using size_type = vector<string>::size_type;
  friend class ConstStrBlobPtr;

  ConstStrBlobPtr begin() const;
  ConstStrBlobPtr end() const;

  StrBlob() : data(std::make_shared<vector<string>>()) {}
  StrBlob(std::initializer_list<string> il) : data(std::make_shared<vector<string>>(il)) {}

   //copy constructor
   StrBlob (const StrBlob& rhs)
   :
   data (std::make_shared<vector<string>> (*rhs.data))
   {}

   //assignment operator
   StrBlob& operator = (const StrBlob& rhs)
   {
     data = std::make_shared<vector<int>> (*rhs.data);
     return *this;
   }
   
    size_type size() const {
    return data->size(); }
    bool empty() const {
    return data->empty(); }

    void push_back(const string &t) {
    data->push_back(t); }
    void pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
    }

    string& front() {
    check(0, "front on empty StrBlob");
    return data->front();
    }

    string& back() {
    check(0, "back on empty StrBlob");
    return data->back();
    }

    const string& front() const {
    check(0, "front on empty StrBlob");
    return data->front();
    }
    const string& back() const {
    check(0, "back on empty StrBlob");
    return data->back();
    }

private:
    void check(size_type i, const string &msg) const {
    if (i >= data->size())
      throw std::out_of_range(msg);
    }
    std::shared_ptr<vector<string>> data;
};


ConstStrBlobPtr StrBlob::begin() const 
{
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const 
{
    return ConstStrBlobPtr(*this, data->size());
}

class ConstStrBlobPtr
{
public:
  ConstStrBlobPtr() : curr(0) {}
  ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {} 

  const string &deref() const
  { 
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
  }
  ConstStrBlobPtr &incr()
  {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
  }

private:
  std::shared_ptr<vector<string>> check(size_t i, const string &msg) const
  {
    auto ret = wptr.lock();
    if (!ret)
      throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
      throw std::out_of_range(msg);
    return ret;
  }
  std::weak_ptr<vector<string>> wptr;
  size_t curr;
};