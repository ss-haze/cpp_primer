#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main()
{
    const size_t array_size = 3;

    //comparing arrays
    int a[array_size], b[array_size];

    for (int i = 0; i != array_size; ++i)
        cin >> a[i];
    for (int i = 0; i != array_size; ++i)
        cin >> b[i];

    int i = 0;
    for (; i != array_size; ++i)
    {
        if (a[i] != b[i])
        {
            cout << "The arrays are not the same\n";
            break;
        }
    }

    if (i == array_size)
        cout << "The arrays are the same\n";

    //comparing vectors
    vector<int> v1, v2;
    for (int i = 0; i != array_size; ++i)
    {
        int input;
        cin >> input;
        v1.push_back(input);
    }

    for (int it = 0; it != array_size; ++it)
    {
        int input;
        cin >> input;
        v2.push_back(input);
    }

    if (v1 == v2)
        cout << "The vectors are the same\n";
    else
        cout << "The vectors are not the same\n";

    return 0;
}