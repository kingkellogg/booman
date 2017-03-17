//
// Created by Swoosh on 09.02.2017.
//

#include "booConst.h"
#include "booDllExport.h"


//dirty globals for dll usage
booman* boo;
 booTokenizer* boo_tokenizer;
 booRPNParser* boo_rpn_parser;
 booTokenSerializer* boo_serializer;

int boo_test() {
    return 0x88;
}

int boo_set_token_pairing(booTokenType tok, char character) {
    if (boo_tokenizer)
    {
        boo_tokenizer->set_token_pairing(tok,character);
        return BOO_RESULT_OKAY;
    }

    return BOO_RESULT_FAIL;
}


int boo_add_rpn(char *rpn_ptr, int rpn_len)
{

    return BOO_RESULT_OKAY;
}

int boo_tokenize_rpn(char *expression_ptr, int expression_len, char *out_tokenized_exp, int *out_tokenized_exp_len) {
    if (boo_tokenizer){
        int tokenized_count = boo_tokenizer->tokenize_expression(expression_ptr, expression_len);
        if (tokenized_count)
        {
            booTokenList tl = boo_tokenizer->get_tokens();
            tl = boo_rpn_parser->generate_rpn(tl);
            booTokenizedExpression tok_exp = boo_serializer->serialize_token_list(tl);
            *out_tokenized_exp_len = tok_exp.expression_len;
            memcpy(out_tokenized_exp, tok_exp.expression, tok_exp.expression_len);
            return BOO_RESULT_OKAY;
        }

        return BOO_RESULT_FAIL;

    }

    return BOO_RESULT_FAIL;
}

int boo_init() {

    //clear all old
    if (boo)
        delete boo;
    if (boo_tokenizer)
        delete boo_tokenizer;
    if (boo_rpn_parser)
        delete boo_rpn_parser;
    if (boo_serializer)
        delete boo_serializer;


    //create new from the ashes

    boo = new booman();
    boo_tokenizer = new booTokenizer();
    boo_rpn_parser = new booRPNParser();
    boo_serializer = new booTokenSerializer();

    boo->clear_literal_definitions();

    return BOO_RESULT_OKAY;

}

int boo_version() {
    return BOO_VERSION;
}

int boo_set_literal_length(int lit_len) {
    if (boo_tokenizer)
    {
        boo_tokenizer->set_token_literal_len(lit_len);
        return BOO_RESULT_OKAY;
    }

    return BOO_RESULT_FAIL;
}

int boo_add_literal_defintition(booLiteral a, bool state) {
    if (boo)
    {
        return boo->add_literal_defintition(a,state);
    }

    return BOO_RESULT_FAIL;
}

int boo_clear_literal_definitions() {
    if (boo)
    {
        boo->clear_literal_definitions();
        return BOO_RESULT_OKAY;
    }

    return BOO_RESULT_FAIL;
}

int boo_get_literal_definition_count() {
    if (boo)
    {
        return boo->get_literal_definition_count();
    }

    return BOO_RESULT_FAIL;
}

