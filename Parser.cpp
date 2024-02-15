#include "Parser.hpp"

Parser::Parser(std::string fname, SymbolTable &table)
{
    this->_infile.open(fname.c_str());
    this->_table = table;
    this->firstPathFname = fname + ".firstpath";
    this->_firstPath.open(firstPathFname);
}

Parser::~Parser()
{
}

void Parser::firstPath()
{
    std::string line;
    std::size_t pos = -1;
    while(std::getline(_infile, line))
    {
        
        pos = line.find("//");
        if (line.length() == 0)
            continue;
        else if (pos != std::string::npos)
        {
            line.erase(pos, std::string::npos);
        }
        _firstPath << line;
        if (line.length())
            _firstPath << std::endl;
    }
    _firstPath.close();
    _infile.close();
}

void    Parser::secondPath()
{
    std::string line;
    std::size_t pos = -1;
    int         lineNum = -1;
    int         memoryNum = 16;

    std::string a_instruction;
    _infile.open(firstPathFname);
    while (std::getline(_infile, line))
    {
        ++lineNum;
        if (line[0] == '(')
            _table.addEntry(line, lineNum);
        if (line[0] == '@')
        {
            if (_table.getAddress(line) == -1)
            {
                _table.addEntry(line, memoryNum);
                memoryNum++;
            }
            a_instruction = '@' + std::to_string(_table.getAddress(line));
        }
    }
}
