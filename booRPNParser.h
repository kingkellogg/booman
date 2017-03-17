//
// Created by root on 2/8/17.
//

#ifndef BOOMAN_BOOABSTRACTSYNTAXTREEPARSER_H
#define BOOMAN_BOOABSTRACTSYNTAXTREEPARSER_H


#include "booTokenizer.h"

class booRPNParser {
private:

public:
    booRPNParser();
    virtual ~booRPNParser();

    booTokenList generate_rpn(booTokenList &infix_token_list);

};


#endif //BOOMAN_BOOABSTRACTSYNTAXTREEPARSER_H
