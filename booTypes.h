//
// Created by root on 2/8/17.
//

#ifndef BOOMAN_BOOTYPES_H_H
#define BOOMAN_BOOTYPES_H_H


#include <vector>
#include <sstream>

typedef int booLiteral;

enum booTokenType{
    booTokenType_literal, booTokenType_not, booTokenType_paranthesis_open, booTokenType_paranthesis_close, booTokenType_and, booTokenType_or
};


struct booToken{
    bool operator==(const booToken &rhs) const {
        return token_type == rhs.token_type &&
               literal == rhs.literal;
    }

    bool operator!=(const booToken &rhs) const {
        return !(rhs == *this);
    }

    booTokenType token_type;
    booLiteral literal;

    std::string to_string() {
        std::string ss;
        switch(token_type){

            case booTokenType_literal:{
                ss = literal;
                break;
            }

            case booTokenType_not:{
                ss = "!";
                break;
            }

            case booTokenType_and:{
                ss = "&";
                break;
            }

            case booTokenType_or:{
                ss = "|";
                break;
            }

            case booTokenType_paranthesis_open:{
                ss = "(";
                break;
            }

            case booTokenType_paranthesis_close:{
                ss = ")";
                break;
            }

            default:
                return NULL;


        }

        return ss;
    }
};

typedef std::vector<booToken*> booTokenList;

struct booTokenizedExpression {
    char* expression;
    int expression_len;
};

#endif //BOOMAN_BOOTYPES_H_H
