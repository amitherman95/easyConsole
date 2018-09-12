///easyConsole
///name:Console.cpp
///Created by:Amit Herman
///mail:amitherman@mail.tau.ac.il

#include "Console.h"
using namespace std;

Console::Console(const string& title) :Cout(&out_buff), TitleLen(title.length()) {
	
	Console::start();
	Console::setTitle(title.c_str());
	}
	/// The expression Cout(&out_buff) sets out_buff as the buffer of the wostream object.


	Console::Console() :Cout(&out_buff) {
		setConActive(FALSE);
	}

	

	Console::~Console() {
		if (this->conActive == TRUE)
			FreeConsole();

	}

	void Console::setConActive(int mode)
	{
		///mode={TRUE,FLASE}
		this->conActive = mode;
	}


	void Console::start()
	{
	
		//Exceptions: a console is already allocated/attached. to be added
		long hCin;///INPUT HANDLE
		long hCout; ///OUTPUT HANDLE
		long hCerr;//ERROR HANDLE
		int fdCin;
		int fdCout;
		int fdCerr;


		try {
			if (!AllocConsole()) throw (0);
		}
		catch (...){
			goto Error;
		}

		setConActive(TRUE);


		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),
			&consoleInfo); ///Gets the info about the console

		   
		hCin = (long)GetStdHandle(STD_INPUT_HANDLE);
		hCout = (long)GetStdHandle(STD_OUTPUT_HANDLE);
		hCerr = (long)GetStdHandle(STD_ERROR_HANDLE);
		///Get the standard i/o handles
		

		
		fdCin = _open_osfhandle(hCin, _O_TEXT);
		fdCout = _open_osfhandle(hCout, _O_TEXT);
		fdCerr = _open_osfhandle(hCerr, _O_TEXT);
		///Link file descriptors to each system handle.
		
		f_in = _fdopen(fdCin, "r");
		f_out = _fdopen(fdCout, "w");
		f_err = _fdopen(fdCout, "w");
		///Open file descriptors. now we can use normal i/o functions to write/read into/from the console.

		setvbuf(f_in, NULL, _IONBF, 0);
		setvbuf(f_out, NULL, _IONBF, 0);
		setvbuf(f_err, NULL, _IONBF, 0);

		out_buff.set_f(f_out);
		///links file pointer to oconbuf objects.

		return;

	Error:
		setConActive(FALSE);
		return;
	}

	void Console::kill()
	{
		if (this->conActive == TRUE) {
			FreeConsole();
			setConActive(FALSE);
		}
	}

	HWND Console::getConsoleHandle() {
	
		return GetConsoleWindow();
	}
	const string Console::getTitle()
	{
		int i;
		string title;
		auto pTitle = new char[TitleLen];
			
		GetConsoleTitle(pTitle, TitleLen);

		title = pTitle;
		
		delete(pTitle);
		return title;
	}


	void Console::setTitle(const string& title){

		TitleLen = title.length();
		SetConsoleTitle( title.c_str );

	}