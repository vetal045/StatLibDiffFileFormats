#pragma once

#include <map>

//
// Declaration of the class BaseStorageHelper.
//

class BaseStorageHelper
{
	//
	// Public methods.
	//

public:

	//! Loads all data from the file
	//! @Returns true if the file was successfully loaded and contained normal format of data
	virtual bool load(std::map<std::string, std::string>& fileStorage) = 0;

	//! Saves data
	virtual bool save(const std::map<std::string, std::string>& fileStorage) = 0;
};

