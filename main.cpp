#include <iostream>
#include"Linkedlist.hpp"

int main() {
							
							Linkedlist<int>* list = new Linkedlist<int>(10);
							list->add(11);
							list->add(12);
							list->add(12);
							
							std::cout<<list->getSize()<<std::endl;
							
							list->display();
							
							return 0;
}