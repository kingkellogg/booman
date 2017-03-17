/*
 * ostAdapterBuffer.cpp
 *
 *  Created on: 11.09.2016
 *      Author: Swoosh
 */

#include <climits>
#include "ocBuffer.h"

ocBuffer::ocBuffer() {
    _buf_pos = 0;
    _buf_size = 0;
    _buf_len = 0;
    _max_buf_size = INT_MAX;
    _buf = NULL;
}

ocBuffer::~ocBuffer() {
    this->free_buffer();
}

void ocBuffer::clear() {
    //reset index, and buffer length
    //does not reset physical size
    this->reset_pos();
    _buf_len = 0;

//	if ((_buf_size > 0) && (_buf))
//			memset(_buf, 0x00, _buf_size);
}

void ocBuffer::set_max_buffer_size(int s){
    _max_buf_size = s;
}

void ocBuffer::set_size(int new_size) {
    if (new_size <= _buf_size || new_size > _max_buf_size)
        return;

    _buf = (char*) realloc(_buf, new_size);
    _buf_size = new_size;
}

int ocBuffer::get_physical_size() {
    return _buf_size;
}

void ocBuffer::free_buffer() {
    //clears length, size and index. Complete reset.
    clear();
    _buf_size = 0;
    if (_buf)
        free(_buf);
}

int ocBuffer::get_pos() {
    return _buf_pos;
}

void* ocBuffer::get_memory() {
    return _buf;
}

void ocBuffer::write(void* ptr, int len) {
    this->set_size(len + _buf_pos);
    memcpy(((_buf) + _buf_pos), ptr, len);
    _buf_pos += len;
    if (_buf_len < _buf_pos)
        _buf_len = _buf_pos; //buf pos is maximum here
}

void ocBuffer::reset_pos() {
    _buf_pos = 0;
}

int ocBuffer::get_len() {
    return _buf_len;
}

void* ocBuffer::peek_current_pos() {
    return (_buf + (_buf_pos));
}

void ocBuffer::inc_pos(int add_pos) {
    _buf_pos += add_pos;

}

void ocBuffer::set_pos(int new_pos) {
    _buf_pos = new_pos;
}
