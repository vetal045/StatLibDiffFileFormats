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
	virtual bool load(const std::map<std::string, std::string>& fileStorage) = 0;

	//! Saves data to the file
	virtual bool save(const std::map<std::string, std::string>& fileStorage) = 0;

	//! Sets path of the file
	virtual void set(const std::string& filePath) = 0;

	//! @Returns string with path of the file
	virtual const std::string& get() const = 0;
};

