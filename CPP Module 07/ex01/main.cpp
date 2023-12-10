
#include "iter.hpp"

template <typename TA >
void print(TA &a) {
	std::cout << reset << a << magenta << std::endl;
}

template <typename TA >
void cast(TA &a) {
	srand(time(0));
	a = rand() % 9;
	std::cout << schwarz << "rand loading..." << std::endl;
	usleep(696969);
}

template <typename TA >
void addOne(TA &a) {
	a += 1;
}

int main( void ) {
	std::cout << scrclean << std::endl;
	int array[5] = {512, 213, 134, 1287, 123};
	 std::cout << magenta << "Array print with iter:" << std::endl << std::endl;
    iter(array, 5, print<int>);
	std::cout << std::endl;
    iter(array, 5, cast<int>);
    std::cout << std::endl << magenta << "Array print with iter after rand cast with iter :" << std::endl << std::endl ;
    iter(array, 5, print<int>);
	std::cout << std::endl;
    iter(array, 5, addOne<int>);
    std::cout << "Array print with iter after addOne with iter :" << std::endl << std::endl;
    iter(array, 5, print<int>);
	std::cout << std::endl;
    char array2[5] = {'a', 'b', 'c', 'd', 'e'};
    std::cout << "Char array print with iter:" << std::endl << std::endl;
    iter(array2, 5, print<char>);

	return 0;
}