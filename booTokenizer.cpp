//
// Created by root on 1/27/17.
//

#include <cassert>
#include <sstream>
#include "booTokenizer.h"


booTokenType booTokenizer::get_token_type(char input) {
    std::map<char, booTokenType>::iterator f_res = _token_associations.find(input);
    if (f_res != _token_associations.end()) {
        return f_res->second;
    }

    //value!

    return booTokenType_literal;

}

int booTokenizer::set_token_pairing(booTokenType tok, char character) {


    _token_associations[character] = tok;
    return BOO_RESULT_OKAY;


}


booTokenizer::booTokenizer() {

}

booTokenList booTokenizer::get_tokens() {
    return _tokens;
}

int booTokenizer::tokenize_expression(char *input_str, int input_len) {
    char input_char;
    int indx = 0;
    _tokens.clear();
    while (indx < (input_len)) {
        input_char = input_str[indx++];

        booToken* token = new booToken();
        booTokenType tok_type = get_token_type(input_char);

        if (tok_type == booTokenType_literal) {

            //read literal, up to 4 bytes
            char literal[BOO_LITERAL_MAX_LEN] = {0,0,0,0};
            int literal_rest = BOO_LITERAL_MAX_LEN-1;
            char input_literal = 0;

            //check if we are dealing with fixed length literals here.
            if (_literal_len == 0){
                do {
                    //while reading more literals, add them to literal string
                    input_literal = (unsigned char)input_str[indx];
                    if (get_token_type(input_literal) == booTokenType_literal) {
                        indx++;
                        literal[literal_rest--] = input_literal;
                    } else
                        break;

                } while (literal_rest >= 0);
            } else {
                //fixed length literals!
                literal_rest = _literal_len;
                do {
                    //while reading more literals, add them to literal string
                    input_literal = (unsigned char)input_str[indx++];
                    literal[literal_rest--] = input_literal;

                } while (literal_rest > 0);
            }


            token->literal = *(int*)literal;

        } else token->literal = 0;

        token->token_type = tok_type;

        _tokens.push_back(token);



    }

    return indx;
}

void booTokenizer::set_token_literal_len(int tok_len) {
    _literal_len = tok_len;
}

std::string booTokenizer::get_string_expression() {
    std::stringstream output;
    for (int i = 0; i < _tokens.size(); ++i) {
        booToken* bt = _tokens[i];
        output << bt->to_string();
    }

    return output.str();
}

