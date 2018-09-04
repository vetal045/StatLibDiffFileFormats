#pragma once

#include "AliasFormats.h"

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
	virtual void load(mapFormat& fileStorage) = 0;

	//! Saves data
	virtual void save(const mapFormat& fileStorage) = 0;
};

