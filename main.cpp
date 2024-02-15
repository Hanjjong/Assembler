#include "HackAssembler.hpp"

int main(int ac, char **av)
{
    std::string fname(av[1]);
    HackAssembler hackAssembler(fname);
    hackAssembler.run();
}