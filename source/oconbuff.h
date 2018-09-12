///Name:Ouput console buffer
///filename:oconbugff.h
///Description:extended wstreambuf class.



#pragma once


#include <streambuf>
#include <iostream>
#define _O_CON_BUFF_

class oconbuf : public std::wstreambuf {
	///Inherits std::streambuf,search for documentation for more information.
public:
	oconbuf();
	oconbuf(FILE*); /// we use this ctor to link a stream buffer to a file pointer.

	virtual int_type overflow(int_type) override;
	///inherited from basic_streambuf, this method is called each time we reach eof.

	virtual std::streamsize xsputn(const char*, std::streamsize);
	virtual void set_f(FILE*);

private:
	FILE* fConsolebuff; ///the file pointer, linked to the console i/o buffer.

};