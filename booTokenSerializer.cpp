//
// Created by Swoosh on 09.02.2017.
//

#include "booTokenSerializer.h"

booTokenizedExpression booTokenSerializer::serialize_token_list(booTokenList &tl) {
    _tokenized_expression.clear();
    for (int i = 0; i < tl.size(); ++i) {

        booToken* bt = tl[i];

        unsigned char token_data = ((((unsigned char)bt->token_type) << 4) & 0xF0) | (sizeof(bt->literal) & 0x0F) ;
        _tokenized_expression.write<unsigned char>(token_data);
        if (bt->token_type == booTokenType_literal)
            _tokenized_expression.write<booLiteral>(bt->literal);


    }

    booTokenizedExpression res;
    res.expression = (char*)_tokenized_expression.get_memory();
    res.expression_len = _tokenized_expression.get_len();

    return res;
}
