//
// Created by Swoosh on 09.02.2017.
//

#ifndef BOOMAN_BOODLLEXPORT_H
#define BOOMAN_BOODLLEXPORT_H

#define DllExport   extern "C" __declspec( dllexport )
#include "booman.h"
#include "booRPNParser.h"
#include "booTokenSerializer.h"
#include "booConst.h"





DllExport int boo_test();
DllExport int boo_version();

DllExport int boo_init(); //reset and init.


/* for bmw :
 *     //setup token properties
    set_token_pairing(booTokenType_and, '+');
    set_token_pairing(booTokenType_or, ',');
    set_token_pairing(booTokenType_not, '!');
    set_token_pairing(booTokenType_paranthesis_close, ')');
    set_token_pairing(booTokenType_paranthesis_open, '(');
    set_token_pairing(booTokenType_literal, 'S');

    */

DllExport int boo_set_token_pairing(booTokenType tok, char character); //set token type pairing
DllExport int boo_tokenize_rpn(char* expression_ptr, int expression_len, char* out_tokenized_exp, int* out_tokenized_exp_len); //tokenize to RPN.
DllExport int boo_set_literal_length(int lit_len);
DllExport int boo_add_rpn(char* rpn_ptr, int rpn_len); //used by tool to add a rpm fragment
DllExport int boo_add_literal_defintition(booLiteral a, bool state);
DllExport int boo_clear_literal_definitions();
DllExport int boo_get_literal_definition_count();


#endif //BOOMAN_BOODLLEXPORT_H
