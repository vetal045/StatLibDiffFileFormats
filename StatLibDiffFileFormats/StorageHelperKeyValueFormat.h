#pragma once

#include "BaseStorageHelper.h"

//
// Declaration of the class StorageHelperKeyValueFormat.
//

class StorageHelperKeyValueFormat : public BaseStorageHelper
{
	//
	// Construction and destruction.
	//

	StorageHelperKeyValueFormat(const std::string& filePath);

	//
	// Public methods.
	//

public:

	//! Loads all data from the KeyValue format file
	//! @Returns true if the file was successfully loaded and contained KeyValue format data
	virtual bool load(const std::map<std::string, std::string>& fileStorage) override;

	//! Saves data to the KeyValue format file
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

