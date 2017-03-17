//
// Created by root on 1/24/17.
//

#ifndef BOOMAN_BOOMAN_H
#define BOOMAN_BOOMAN_H


#include <map>
#include <stack>
#include <queue>
#include "booTokenizer.h"


class booman {
private:
    //operator characters

    std::map<booLiteral, bool> _arguments;
    //std::stack

public:
    //argument stuff
    void clear_literal_definitions();
    int add_literal_defintition(booLiteral a, bool state);
    int get_literal_definition_count();

    bool eval_expression(booTokenList& exp);
    std::string get_string_expression(booTokenList& exp);

};




#endif //BOOMAN_BOOMAN_H
