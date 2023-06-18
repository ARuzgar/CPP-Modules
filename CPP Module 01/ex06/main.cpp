#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string hurl = av[1];
		Harl harl;
		harl.complain(hurl);
	}
	else
		std::cout << "Insufficent/Wrong Arguments. Please follow the template : ./harl DEBUG or INFO or WARNING or ERROR" << std::endl;
	return (0);
}