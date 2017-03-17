//
// Created by root on 1/24/17.
//

#include <cassert>
#include <sstream>
#include "booman.h"

int booman::add_literal_defintition(booLiteral a, bool state) {
    if(_arguments.find(a) == _arguments.end()){
        _arguments[a] = state;
        return BOO_RESULT_OKAY;
    } else {
        if (state == _arguments[a])
            return BOO_RESULT_OKAY;
    }

    return BOO_RESULT_FAIL;

}

void booman::clear_literal_definitions() {
    _arguments.clear();
}

bool booman::eval_expression(booTokenList& exp) {

    int indx = 0;

    std::stack<bool> stack;

    while (indx < exp.size()){
        booToken* tok = exp[indx++];

        switch(tok->token_type){

            case booTokenType_literal:{

                bool arg = _arguments[tok->literal]; //TODO : Add false case

                stack.push(arg);
                break;
            }

            case booTokenType_not:{
                bool op = stack.top();
                stack.pop();

                stack.push(!op);
                break;
            }

            case booTokenType_and:{
                bool op = stack.top();
                stack.pop();
                bool op2 = stack.top();
                stack.pop();

                bool res = op && op2;

                stack.push(res);
                break;
            }

            case booTokenType_or:{
                bool op = stack.top();
                stack.pop();
                bool op2 = stack.top();
                stack.pop();

                bool res = op || op2;

                stack.push(res);
                break;
            }

            default:
                return NULL;


        }

    }

    return stack.top();
}

std::string booman::get_string_expression(booTokenList& exp) {
    std::stringstream output;
    for (int i = 0; i < exp.size(); ++i) {

        booToken* bt = exp[i];


        switch(bt->token_type){

            case booTokenType_literal:{
                output <<   _arguments[bt->literal];
                break;
            }

            default:
               output << bt->to_string();


        }


    }

    return output.str();
}

int booman::get_literal_definition_count() {
    return _arguments.size();
}






