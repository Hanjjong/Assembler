#ifndef SYMBOLTABLE_HPP
#define SYMBOLTABLE_HPP

#include <iostream>
#include <map>

class SymbolTable
{
private:
    std::map<std::string, int> _table;
public:
    SymbolTable(/* args */);
    ~SymbolTable();
    void addEntry(std::string symbol, int address);
    bool contains(std::string symbol);
    int getAddress(std::string symbol);
};



#endif