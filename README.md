# booman
BOOlean MANager

# What does this do?
It parses boolean expressions. This one for example:

((!S0009+S000A+!S0006,S0009)+(S0002,S0003,S0060),S0061,S0062,S012D+(!S000A+S0009,S000A,S0029))+!(S0018,S0006)+!S01E9+S01E0+!S0244

You can tell booman what literals (the Sxxxx) are true and false, and you can define what other operators look like in your input data. For example, in the above string, "!" is a NOT expression.

# Okay and how can I use it?

booman was written to be used as a dll on windows. Check the booExportDll stuff. Here is a usage example:

    //init booman
    boo_init();
    
    //define token types
    boo_set_token_pairing(booTokenType_and, '+');
    boo_set_token_pairing(booTokenType_or, ',');
    boo_set_token_pairing(booTokenType_not, '!');
    boo_set_token_pairing(booTokenType_paranthesis_close, ')');
    boo_set_token_pairing(booTokenType_paranthesis_open, '(');
    boo_set_token_pairing(booTokenType_literal, 'S');
    
    //set token length to 0, thatw ay the tokenizer attempts to determine length automatically
    boo_set_literal_length(0);
    
    
    
To be continued...
    
