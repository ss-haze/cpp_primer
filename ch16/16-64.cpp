#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace::std;

template <typename T>
size_t total_count(const vector<T>& vec, const T &n)
{
	// forwarding is not necessary since v_count doesn't change the value of n.
	return std::count(vec.cbegin(), vec.cend(), n);
}

template<>
size_t total_count(const vector<const char *> & vec, const char* const &n)
{
  return std::count(vec.cbegin(), vec.cend(), n);
}

int main() {
	vector<int> vec{1,1,2,3,4,5,1};
	cout << total_count(vec, 1) << endl;

	vector<float> dvec{1.1f, 2.1f, 2.1f, 2.1f, 2.1f, 3.f};
	cout << total_count(dvec, 2.1f) << endl;

	vector<string>
		svec{"here", "there", "be", "monsters", "be"};
	cout << total_count(svec, string("be")) << endl;

//specialized template use
const char *p ="two";
vector<const char*> ccPvec {"one", "two", "three", "four", "five", "two"};
cout <<total_count(ccPvec, p)<<endl;

return 0;
}