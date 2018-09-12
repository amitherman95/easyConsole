using namespace std;
#
#include "oconbuff.h"

oconbuf::oconbuf() :fConsolebuff(NULL)
{
}
oconbuf::oconbuf(FILE*fp) : fConsolebuff(fp)
{
}



wstreambuf::int_type oconbuf::overflow(wstreambuf::int_type  c) {
	if (c != EOF)
	{
		return fputc(c, fConsolebuff);
	}

}


std::streamsize oconbuf::xsputn(const char*c, std::streamsize size) {
	return fwrite(c, sizeof(char), size, fConsolebuff);
}

void oconbuf::set_f(FILE*fp)
{
	fConsolebuff = fp;
}