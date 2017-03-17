//
// Created by root on 2/8/17.
//

#ifndef BOOMAN_BOOBOOLEXPRESSION_H
#define BOOMAN_BOOBOOLEXPRESSION_H


#include "booTokenizer.h"

class booBoolExpression {
private:
    booTokenType _bool_type;
    booBoolExpression* _left;
    booBoolExpression* _right;
    booLiteral _literal;

public:
    booTokenType get_bool_type() const;
    void set_bool_type(booTokenType _bool_type);

    booBoolExpression* get_left() const;
    void set_left(booBoolExpression* _left);

    booBoolExpression* get_right() const;
    void set_right(booBoolExpression* _right);

    booLiteral get_literal() const;
    void set_literal(booLiteral _literal);

    booBoolExpression(booLiteral literal);
    booBoolExpression(booBoolExpression* other);
    booBoolExpression(booTokenType op, booBoolExpression* left, booBoolExpression* right);


    static booBoolExpression* build_and(booBoolExpression* left, booBoolExpression* right);
    static booBoolExpression* build_or(booBoolExpression* left, booBoolExpression* right);
    static booBoolExpression* build_not(booBoolExpression* child);
    static booBoolExpression* build_literal(booLiteral lit);




};


#endif //BOOMAN_BOOBOOLEXPRESSION_H
