#include "Parser.hpp"

inline std::string& ltrim(std::string& s, const char* t)
{
	s.erase(0, s.find_first_not_of(t));
	return s;
}
// trim from right 
inline std::string& rtrim(std::string& s, const char* t)
{
	s.erase(s.find_last_not_of(t) + 1);
	return s;
}
// trim from left & right 
inline std::string& trim(std::string s, const char* t)
{
	return ltrim(rtrim(s, t), t);
}

Parser::Parser(std::string fname)
{
    this->_infile.open(fname.c_str());
    this->_firstPathFname = fname + ".firstpath";
    this->_firstPath.open(_firstPathFname);
    this->_table = SymbolTable::getTable();
}

Parser::~Parser()
{
}

int Parser::instructionType()
{
    if (_commandLine[0] == '@')
        return 1;
    else if (_commandLine[0] == '(')
        return 3;
    else
        return 2;
}

std::string Parser::firstPath()
{
    std::string line;
    std::size_t pos = -1;
    int line_count = 0;
    while(std::getline(_infile, line))
    {
        if (line.length() == 0)
            continue;
        std::string trim_command = trim(line, " \t\v\n\f\r");
        pos = trim_command.find("//");
        if (pos != std::string::npos)
        {
            trim_command.erase(pos, std::string::npos);
            if (trim_command.length() == 0)
                continue;
        }
        _commandLine = trim_command;
        if (_commandLine.find("(") != std::string::npos)
            _table->addEntry(trim(_commandLine, " \t\v\n\f\r()"),  line_count);
        _firstPath << _commandLine;
        if (_commandLine.length())
            _firstPath << std::endl;
        if (instructionType() == 1 || instructionType() == 2)
            line_count++;
    }
    _firstPath.close();
    _infile.close();
    return _firstPathFname;
}

// void    Parser::secondPath()
// {
//     std::string line;
//     std::size_t pos = -1;
//     int         memoryNum = 16;

//     std::string a_instruction;
//     _infile.open(_firstPathFname);
//     while (std::getline(_infile, line))
//     {
//         if (instructionType() == A_INSTRUCTION)
//         {
//             if (_table->getAddress(trim(line, "@")) == -1)
//             {
//                 _table->addEntry(trim(line, "@"), memoryNum);
//                 memoryNum++;
//             }
//             a_instruction = '@' + std::to_string(_table->getAddress(trim(line, "@")));
//             std::cout << "A명령어 : " << a_instruction << std::endl;
//         }


//     }
// }

