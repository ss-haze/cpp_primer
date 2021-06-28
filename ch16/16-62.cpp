#include <iostream>
#include "Sales_data.h"
#include <unordered_set>

namespace std {
template <> struct hash<Sales_data>
{
	using result = size_t;
	using argument_type = Sales_data;
	size_t operator()(const Sales_data&) const;
};
size_t
hash<Sales_data>::operator()(const Sales_data& s) const
{
	return hash<std::string>()(s.bookNo) ^
		   hash<unsigned>()(s.units_sold) ^
		   hash<double>()(s.revenue);
}
}

int main() 
{
	Sales_data item1("ITEM_1", 4, 10.99), item2("ITEM_2", 3, 9.99);
	std::unordered_multiset<Sales_data> set;
	set.insert(item1);
	set.insert(item2);
	auto pos = set.find(item2);

	if (pos != set.end())
		std::cout << *pos << std::endl;
	else
		std::cout << "item was not found"<<std::endl;

	return 0;
}