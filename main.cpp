#include <iostream>
#include"Linkedlist.hpp"
#include"Array.hpp"

int main() {
	
	Array<int,5> numbers = {5,8,9,7,4};
	
	for(auto itr = numbers.begin(); itr != numbers.end(); itr++)
	{
		std::cout<<*itr<<std::endl;
	}
    
	return 0;
}