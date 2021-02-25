#include <memory>
#include <vector>
#include <string>

class ConstStrBlobPtr
{
  typedef std::vector<std::string>::size_type size_type;

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