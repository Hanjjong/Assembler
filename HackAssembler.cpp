
#include "HackAssembler.hpp"


HackAssembler::HackAssembler(std::string fname)
{
    this->_filename = fname;
    _symbolTable = SymbolTable::getTable();
}

HackAssembler::~HackAssembler()
{
}

void    HackAssembler::run()
{
    Parser parser(_filename);

    parser.firstPath();
    parser.secondPath();
    _symbolTable->print();
    // 1. 공백, 주석 다지우기
    // 2. 심볼 테이블을 만들기

    //오픈 다시
    // while (parser.hasMoreLine())
    // {
    //     if(paser.instructionType() == A)
    //         code.asdasd(paser.getCommandA);
    //     else if (...)
    //         code.func(parser.getCommandC);

    //     code.writefile();
    // }
}