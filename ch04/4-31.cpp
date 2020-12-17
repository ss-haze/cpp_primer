#include <iostream>
#include <vector>

using std::vector; using std::cout;

int main() {
    vector<int> ivec(10);
    vector<int>::size_type cnt = ivec.size();
    for (std::vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
        ivec[ix] = cnt;
    for (const auto& i : ivec)
        cout << i << " ";
    cout << '\n';

    //We use the prefix operator because it increments the element and then returns the element as an lvalue
    //whereas the postfix operator increments the element and then returns a copy of the value of the unincremented element.
    //The prefix oerator does not need to store a copy, therefore doing less work than the postfix

    //rewritten program using postfix operators
    cnt = ivec.size();
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
        ivec[ix] = cnt;
    for (const auto& i : ivec)
        cout << i << " ";
    cout << '\n';

    return 0;
}