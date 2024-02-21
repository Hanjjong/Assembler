
#include "HackAssembler.hpp"

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

HackAssembler::HackAssembler(std::string fname)
{
    this->_filename = fname;
    _symbolTable = SymbolTable::getTable();
}

HackAssembler::~HackAssembler()
{
}

std::string intTo16BitBinaryString(int num) {
    return std::bitset<16>(num).to_string();
}

void    HackAssembler::run()
{
    std::string line;
    std::size_t pos = -1;
    int         memoryNum = 16;
    std::string a_instruction;
    std::ifstream _infile;

    Parser parser(_filename);
    std::string fname = parser.firstPath();

    _infile.open(fname);
    _result.open("result.asm");
    while (std::getline(_infile, line))
    {
        if (instructionType() == A_INSTRUCTION)
        {
            if (_symbolTable->getAddress(trim(line, "@")) == -1)
            {
                _symbolTable->addEntry(trim(line, "@"), memoryNum);
                memoryNum++;
            }
            a_instruction = '@' + std::to_string(_symbolTable->getAddress(trim(line, "@")));
            std::cout << "A명령어 : " << a_instruction << std::endl;
            _result << intTo16BitBinaryString(_symbolTable->getAddress(trim(line, "@")));
        }
    }
    _symbolTable->print();
}