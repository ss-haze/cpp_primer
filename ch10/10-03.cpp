#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>

int main (){

std::vector<int> v {1,2,3,4,5,6,7,8,9};
std::cout <<std::accumulate (v.begin(), v.end(), 0);

  return 0;
}