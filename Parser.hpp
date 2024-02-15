#ifndef PARSER_HPP
# define PARSER_HPP

#include "SymbolTable.hpp"
#include <fstream>
#include <iostream>

#define A_INSTRUCTION 1
#define C_INSTRUCTION 2
#define L_INSTRUCTION 3

class Parser
{
private:
    std::string     _commandLine;
    SymbolTable&    _table;
    std::ifstream   _infile;
    std::string     firstPathFname;
    std::ofstream   _firstPath;
    std::string     _secondPath;

public :
    Parser(std::string fname, SymbolTable &table);
    ~Parser();
    bool        hasMoreLines();
    void        advanced();
    int         instructionType();
    std::string symbol();
    std::string dest();
    std::string comp();
    std::string jump();
    void        firstPath();
    void        secondPath();
};



#endif