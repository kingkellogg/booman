#include <iostream>
#include <cassert>
#include <cstring>
#include "booDllExport.h"


#define AST_TEST_CRASH "((!S0009+S000A+!S0006,S0009)+(S0002,S0003,S0060),S0061,S0062,S012D+(!S000A+S0009,S000A,S0029))+!(S0018,S0006)+!S01E9+S01E0+!S0244"


unsigned char rawData[91] =
        {
                0x28, 0x28, 0x21, 0x53, 0x09, 0x00, 0x2B, 0x53, 0x0A, 0x00, 0x2B, 0x21, 0x53, 0x06, 0x00, 0x2C,
                0x53, 0x09, 0x00, 0x29, 0x2B, 0x28, 0x53, 0x02, 0x00, 0x2C, 0x53, 0x03, 0x00, 0x2C, 0x53, 0x60,
                0x00, 0x29, 0x2C, 0x53, 0x61, 0x00, 0x2C, 0x53, 0x62, 0x00, 0x2C, 0x53, 0x2D, 0x01, 0x2B, 0x28,
                0x21, 0x53, 0x0A, 0x00, 0x2B, 0x53, 0x09, 0x00, 0x2C, 0x53, 0x0A, 0x00, 0x2C, 0x53, 0x29, 0x00,
                0x29, 0x29, 0x2B, 0x21, 0x28, 0x53, 0x18, 0x00, 0x2C, 0x53, 0x06, 0x00, 0x29, 0x2B, 0x21, 0x53,
                0xE9, 0x01, 0x2B, 0x53, 0xE0, 0x01, 0x2B, 0x21, 0x53, 0x44, 0x02,
        } ;


int main() {

    boo_init();


    int s = sizeof(bool);

    boo_set_token_pairing(booTokenType_and, '+');
    boo_set_token_pairing(booTokenType_or, ',');
    boo_set_token_pairing(booTokenType_not, '!');
    boo_set_token_pairing(booTokenType_paranthesis_close, ')');
    boo_set_token_pairing(booTokenType_paranthesis_open, '(');
    boo_set_token_pairing(booTokenType_literal, 'S');


    booTokenizer bt;
    bt.set_token_pairing(booTokenType_and, '+');
    bt.set_token_pairing(booTokenType_or, ',');
    bt.set_token_pairing(booTokenType_not, '!');
    bt.set_token_pairing(booTokenType_paranthesis_close, ')');
    bt.set_token_pairing(booTokenType_paranthesis_open, '(');
    bt.set_token_pairing(booTokenType_literal, 'S');

    bt.set_token_literal_len(0);

    bt.tokenize_expression((char *) AST_TEST_CRASH, strlen(AST_TEST_CRASH));

    std::cout << "string expr " << std::endl;
    std::cout << bt.get_string_expression();

    booTokenList tl_str = bt.get_tokens();

    bt.set_token_literal_len(2);

    bt.tokenize_expression((char *) rawData, 91);

    std::cout << "string expr bin" << std::endl;
    std::cout << bt.get_string_expression();

    booTokenList tl_bin = bt.get_tokens();

    std::cout << "start cmp" << std::endl;

    for (unsigned int i = 0; i < std::min(tl_bin.size(), tl_str.size()); ++i) {
        std::cout << (int)tl_bin[i]->token_type << " | " <<  (int)tl_str[i]->token_type << std::endl;
    }

    char boo_buf[1000];
    int boo_buf_count;
    memset(&boo_buf, 0, 1000);

    boo_tokenize_rpn((char *) AST_TEST_CRASH, strlen(AST_TEST_CRASH),boo_buf,&boo_buf_count);


    boo_tokenize_rpn((char *) rawData, 91,boo_buf,&boo_buf_count);

    std::cout << "Success! retn=0x" << std::hex << boo_test() << std::endl;

    getchar();

    return 0;
}