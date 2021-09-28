#include"Error.h"
#include<string>
using namespace std;

Error::Error(ErrorCode code)
{
	this->code = code;
}

string Error::ToString()
{
	switch (code)
	{
	case NegativeYear:
		return "Year is negative";
	case IdxOutsideLimit:
		return "Index is outside the limit";
	case MaxSizeReached:
		return "Max size reached";
	default:
		return "";
	}
}