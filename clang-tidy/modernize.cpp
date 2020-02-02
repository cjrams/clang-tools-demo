#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
int main()
{
    std::vector<int> v{1,2,3};
    std::reverse(std::begin(v), std::end(v));
    for(int i = 0; i < v.size(); ++i) {
    	std::cout << v.at(i);	
    } 
    std::cout << '\n';
}
