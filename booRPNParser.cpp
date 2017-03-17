//
// Created by root on 2/8/17.
//

#include <stack>
#include <algorithm>
#include "booRPNParser.h"

booRPNParser::booRPNParser() {

}

booRPNParser::~booRPNParser() {

}

booTokenList booRPNParser::generate_rpn(booTokenList &infix_token_list) {
    booTokenList polish_notation_output;
    polish_notation_output.clear();

    std::stack<booToken*> stack;

    int indx = 0;
    while( indx < infix_token_list.size()){
        booToken* tok = infix_token_list[indx++];
        switch(tok->token_type){
            case booTokenType_and:
            case booTokenType_or:
            case booTokenType_not:
            case booTokenType_paranthesis_open:
            {
                stack.push(tok);
                break;
            }

            case booTokenType_paranthesis_close:
            {
                //if (stack.size() > 0) {
                    while (stack.top()->token_type != booTokenType_paranthesis_open){
                        polish_notation_output.push_back(stack.top());
                        stack.pop();
                    }


                    stack.pop(); //open paranthesis we don't need anymore

                    //check if we have a NOT still
                    if (stack.size() > 0 && stack.top()->token_type == booTokenType_not){
                        polish_notation_output.push_back(stack.top());
                        stack.pop();
                    }

               // }


                break;
            }

            case booTokenType_literal:
            {
                polish_notation_output.push_back(tok);
                break;
            }
        }
    }

    //add stack to result
    while (stack.size()){
        polish_notation_output.push_back(stack.top());
        stack.pop();
    }



    //std::reverse(polish_notation_output.begin(),polish_notation_output.end());

    return polish_notation_output;

}
