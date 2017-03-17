//
// Created by root on 1/27/17.
//

#ifndef BOOMAN_BOOTOKENIZERBASE_H
#define BOOMAN_BOOTOKENIZERBASE_H

#include <map>
#include <queue>
#include "booConst.h"
#include "ocBuffer.h"
#include "booTypes.h"


class booTokenizer {
protected:
    booTokenList _tokens;
    std::map<char, booTokenType> _token_associations;
    int _literal_len = 0; //0 - literaly can be max BOO_LITERAL_MAX_LEN. If > 0, literals HAVE to be set length.

public:
    booTokenizer();

//token stuff
    //set a token type to a character. This makes it possible to parse different inputs
    int set_token_pairing(booTokenType tok, char character);

    void set_token_literal_len(int tok_len);

    //exports
    int tokenize_expression(char* input_str, int input_len);

    //token stuff
    booTokenType get_token_type(char input);
    booTokenList get_tokens();

    std::string get_string_expression();



};


#endif //BOOMAN_BOOTOKENIZERBASE_H
