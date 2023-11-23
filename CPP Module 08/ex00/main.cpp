#include "easyfind.hpp"

int main(void){
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> deq;

	for (int i = 0; i < 10; i++){
		vec.push_back(i);
		lst.push_back(i);
		deq.push_back(i);
	}

	std::cout << "Vector: ";
	for (std::vector<int>::iterator cont = vec.begin(); cont != vec.end(); cont++)
		std::cout << *cont << " " << std::endl;

	std::cout << "List: ";
	for (std::list<int>::iterator cont = lst.begin(); cont != lst.end(); cont++)
		std::cout << *cont << " " << std::endl;

	std::cout << "Deque: ";
	for (std::deque<int>::iterator cont = deq.begin(); cont != deq.end(); cont++)
		std::cout << *cont << " " << std::endl;

	std::cout << "5 in vector: ";
	try{
		std::cout << *easyfind(vec, 5) << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "5 in list: ";
	try{
		std::cout << *easyfind(lst, 5) << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "5 in deque: ";
	try{
		std::cout << *easyfind(deq, 5) << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "10 in vector: ";
	try{
		std::cout << *easyfind(vec, 10) << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "10 in list: ";
	try{
		std::cout << *easyfind(lst, 10) << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "10 in deque: ";
	try{
		std::cout << *easyfind(deq, 10) << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}