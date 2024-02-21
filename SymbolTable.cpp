
#include "SymbolTable.hpp"

SymbolTable* SymbolTable::_instance = NULL;

SymbolTable* SymbolTable::SymbolTable::getTable()
{
    if (_instance == NULL)
		_instance = new SymbolTable();
	return _instance;
}

SymbolTable::SymbolTable(/* args */)
{
    
}

SymbolTable::~SymbolTable()
{
}

void SymbolTable::addEntry(std::string symbol, int address)
{
    _table.insert(std::make_pair(symbol, address));
}

int SymbolTable::getAddress(std::string symbol)
{
    auto it = _table.find(symbol); 
    if (it != _table.end()) { 
        return it->second;
    } else { 
        return -1;
    }
}

void SymbolTable::print()
{
    for (auto it = _table.begin(); it != _table.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}