#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using std::list; using std::string;

void print(const list<string>& lst)
{
	for (const auto& s : lst) std::cout << s << " ";
	std::cout << std::endl;
}

void elimDups(list<string>& lst)
{
	lst.sort();
	print(lst);

	lst.unique();
	print(lst);
}

int main()
{
	list<string> vs{ "It", "is", "a", "beautiful", "and", "a", "sunny", "day", "is", "it", "not?" };
	print(vs); 
	elimDups(vs);

	return 0;
}