//
// Created by root on 2/8/17.
//

#include "booBoolExpression.h"

booTokenType booBoolExpression::get_bool_type() const {
    return _bool_type;
}

void booBoolExpression::set_bool_type(booTokenType _bool_type) {
    booBoolExpression::_bool_type = _bool_type;
}

booBoolExpression* booBoolExpression::get_left() const {
    return _left;
}

void booBoolExpression::set_left(booBoolExpression* _left) {
    booBoolExpression::_left = _left;
}

booBoolExpression* booBoolExpression::get_right() const {
    return _right;
}

void booBoolExpression::set_right(booBoolExpression* _right) {
    booBoolExpression::_right = _right;
}

booLiteral booBoolExpression::get_literal() const {
    return _literal;
}

void booBoolExpression::set_literal(booLiteral _literal) {
    booBoolExpression::_literal = _literal;
}

booBoolExpression::booBoolExpression(booLiteral literal) {
    _bool_type = booTokenType_literal;
    _left = NULL;
    _right = NULL;
    _literal = literal;
}

booBoolExpression::booBoolExpression(booBoolExpression* other) {
    _literal = other->get_literal();
    _left = other->get_left();
    _right = other->get_right();
    _bool_type = other->get_bool_type();
}

booBoolExpression::booBoolExpression(booTokenType op, booBoolExpression* left, booBoolExpression* right) {
    _bool_type = op;
    _left = left;
    _right = right;
    _literal = 0;
}

booBoolExpression* booBoolExpression::build_and(booBoolExpression* left, booBoolExpression* right) {
   return new booBoolExpression(booTokenType_and, left, right);
}

booBoolExpression* booBoolExpression::build_or(booBoolExpression* left, booBoolExpression* right) {
    return new booBoolExpression(booTokenType_or, left, right);
}

booBoolExpression* booBoolExpression::build_not(booBoolExpression* child) {
    return new booBoolExpression(booTokenType_not, child, NULL);
}

booBoolExpression* booBoolExpression::build_literal(booLiteral lit) {
    return new booBoolExpression(lit);
}
