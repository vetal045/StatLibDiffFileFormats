#pragma once

#include "BaseStorageHelper.h"

//
// Declaration of the class StorageHelperNumberStringFormat.
//

class StorageHelperNumberStringFormat : public BaseStorageHelper
{
	//
	// Construction and destruction.
	//

	StorageHelperNumberStringFormat(const std::string& filePath);

	//
	// Public methods.
	//

public:

	//! Loads all data from the NumberString format file
	//! @Returns true if the file was successfully loaded and contained NumberString format data
	virtual bool load(const std::map<std::string, std::string>& fileStorage) override;

	//! Saves data to the NumberString format file
	virtual bool save(const std::map<std::string, std::string>& fileStorage) override;

	//! Sets path of the file
	void set(const std::string& filePath);

	//! @Returns string with path of the file
	const std::string& get() const;

	//
	// Private data members.
	//

private:
	std::string filePath_;
};

