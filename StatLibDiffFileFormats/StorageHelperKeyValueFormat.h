#pragma once

#include "BaseStorageHelper.h"

#include <vector>

//
// Declaration of the class StorageHelperKeyValueFormat.
//

class StorageHelperKeyValueFormat : public BaseStorageHelper
{
	//
	// Construction and destruction.
	//

public:
	StorageHelperKeyValueFormat(const std::string& filePath);

	//
	// Public methods.
	//

public:

	//! Loads all data from the KeyValue format file
	//! @Returns true if the file was successfully loaded and contained KeyValue format data
	virtual bool load(std::map<std::string, std::string>& fileStorage) override;

	//! Saves data to the KeyValue format file
	virtual bool save(const std::map<std::string, std::string>& fileStorage) override;

	//! Sets path of the file
	void set(const std::string& filePath);

	//! @Returns string with path of the file
	const std::string& get() const;

	//! @Returns size of the file
	//const int getFileSize() const;

	//
	// Private methods.
	//

	//! Converts all data to KeyValue format
	void loadDataToKeyValueFormat(const std::vector <std::string>& fileData,  std::map <std::string,std::string> & fileStorage);

	//! Saves data to KeyValue format file
	bool saveToKeyValueFile(const std::map<std::string, std::string>& fileKeyValueStorage);

	//! Defines the size of current file
	//long long defineFileSize(std::ifstream& file);

	//
	// Private data members.
	//

private:
	std::string filePath_;
	//int fileSize_;
};

