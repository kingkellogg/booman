/*
 * ostAdapterBuffer.h
 *
 *  Created on: 11.09.2016
 *      Author: Swoosh
 */

#ifndef OSTBUFFER_H_
#define OSTBUFFER_H_

#include <stdio.h>
#include <stdlib.h>
#include <cstring>

class ocBuffer {
private:
	int _buf_size; //physical buffer size, normally not exposed to outside, maintained internally
	int _buf_pos; //current index in buffer. Gets reset through clear and reset_pos.
	int _buf_len; //current written bytes in buffer. Gets reset through clear
	int _max_buf_size; //maximum physical buffer size
	char* _buf; //buffer

public:
	ocBuffer();
	virtual ~ocBuffer();

	void clear();
	void reset_pos();

	int get_physical_size();
	int get_pos();
	void set_pos(int new_pos);
	void inc_pos(int add_pos);
	int get_len();

	void set_max_buffer_size(int s);



	void free_buffer();
	void set_size(int new_size);



	void* get_memory();


	template<typename T>
	void write(T value);

	void write(void *ptr, int len);


	template <typename T>
	T read();

	void* peek_current_pos();

};


//don't panic here - yes, we could remove completition_pos - but then we have two additions instead of one.
//uglier this way, but also faster.
template<typename T>
void ocBuffer::write(T value) {
	//we allocate 4 times as much memory as we actually need now.
	//since we only pass templated types here, we are just going to assume the type is small.
	//this aims to prevent rapid reallocation, because if we need to reallocate once,
	//we most likely have to reallocate more.
	int completion_pos = _buf_pos + sizeof(T);

	if ((completion_pos >= _buf_size) || (!_buf)){
		this->set_size(completion_pos + (sizeof(T) * 3));
	}

	*(T*) ((_buf) + (_buf_pos)) = (T) value;
	_buf_pos = completion_pos;
	if (_buf_len < _buf_pos)
		_buf_len = _buf_pos; //buf pos is maximum here
}

template<typename T>
T ocBuffer::read() {

	T res;
	res = *(T*) (_buf + (_buf_pos));
	_buf_pos += sizeof(T);
	return res;
}

#endif /* OSTADAPTERBUFFER_H_ */
