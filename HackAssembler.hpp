#ifndef HACKASSEMBLER_HPP
#define HACKASSEMBLER_HPP

#include <iostream>
#include "Parser.hpp"
#include "SymbolTable.hpp"

class HackAssembler
{
private:
    std::string _filename;
    std::string _curCommandLine;
    SymbolTable* _symbolTable;
public:
    HackAssembler(std::string fname);
    ~HackAssembler();
    void    run();
};



#endif