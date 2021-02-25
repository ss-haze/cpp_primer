#include <memory>
#include <vector>
#include <string>

class StrBlob;

class StrBlobPtr
{
  typedef std::vector<std::string>::size_type size_type;

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
