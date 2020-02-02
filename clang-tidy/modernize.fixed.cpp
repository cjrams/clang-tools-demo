#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
auto main() -> int
{
    std::vector<int> v{1,2,3};
    std::reverse(std::begin(v), std::end(v));
    for(int i : v) {
    	std::cout << i;	
    } 
    std::cout << '\n';
}
