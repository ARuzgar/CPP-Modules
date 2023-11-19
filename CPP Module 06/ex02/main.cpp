#include "Base.hpp"

int main(int ac, char **av)
{
	(void)av;
    if (ac == 1)
    {
        Base *rand = generate();
        identify(rand);
        delete rand;
    }
    return (0);
}