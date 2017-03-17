//
// Created by Swoosh on 09.02.2017.
//

#ifndef BOOMAN_BOOTOKENSERIALIZER_H
#define BOOMAN_BOOTOKENSERIALIZER_H


#include "booTypes.h"
#include "ocBuffer.h"

class booTokenSerializer {
private:
    ocBuffer _tokenized_expression;
public:

    booTokenizedExpression serialize_token_list(booTokenList& tl);

};


#endif //BOOMAN_BOOTOKENSERIALIZER_H
