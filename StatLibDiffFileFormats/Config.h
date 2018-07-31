#pragma once

#include "BaseStorageHelper.h"
#include "StorageHelperKeyValueFormat.h"
#include "StorageHelperNumberStringFormat.h"

#include <map>
#include <memory>

//
// Declaration of the class Config.
//

class Config
{
public:
	Config(const StorageHelperKeyValueFormat& keyValueFileDataStorage);
	Config(const StorageHelperNumberStringFormat& numberStringfileDataStorage);


	//
	// Public methods.
	//

public:
	//! @Returns true if the file was successfully loaded and contained normal format of data
	bool load();

	//! Saves an file to a given file path
	//! @Returns true if the file was successfully saved
	bool save();

	//
	// Private data members.
	//

private:
	using mapSS = std::map<std::string, std::string>;

	mapSS fileDataStorage_;

	std::shared_ptr<BaseStorageHelper> formatFileStorage_;
};

