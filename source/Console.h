//Name:Console.h
//Author:Amit Herman
//Email:amitherman@mail.tau.ac.il



#pragma once
#define _CONSOLE_H_
#include <Windows.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <memory>
#include <streambuf>
#include "oconbuff.h"

class Console {

public:

		Console();
		Console(const string& title);
		virtual ~Console();
		virtual void setConActive(int);
		virtual void start();
		virtual void kill();
	//	virtual void show();
		//virtual void hide();
		virtual HWND getConsoleHandle();
		virtual const std::string getTitle();
		virtual void setTitle(const string& title);
		std::wostream Cout;/// The intention is to write to the console by: Console.Cout <<  "...";
		
private:
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	bool conActive;//Console active?

	FILE* f_in; ///input stream
	FILE* f_out; ///output stream
	FILE* f_err; ///error stream
	oconbuf out_buff; //extended streambuf class. we use it to link i/o stream object to the conoslle.
	int TitleLen;

};

