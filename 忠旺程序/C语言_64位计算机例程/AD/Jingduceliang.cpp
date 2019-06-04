#include "stdafx.h"
#include "Jingduceliang.h"
#include "FileIo.h"

bool Jingducelinag::readFile(std::string file_name)
{
	FileIo fi;
	bool re = fi.read(file_name, data);
	if (re == false)
		return false;
	return true;
}