#pragma once

#include "AliasFormats.h"

#include "BaseStorageHelper.h"
#include "StorageHelperKeyValueFormat.h"
#include "StorageHelperStringStringFormat.h"

#include <memory>

//
// Declaration of the class Config.
//

class Config
{
	//
	// Construction and destruction.
	//

public:
	Config(const std::shared_ptr<BaseStorageHelper> keyValueFileDataStorage);

	//Config(const StorageHelperKeyValueFormat& keyValueFileDataStorage);
	//Config(const StorageHelperStringStringFormat& keyValueFileDataStorage);

	//
	// Public methods.
	//

public:
	//! Adds string with parameters such as key and value to data of the file
	void add(const std::string& key, const std::string& value);

	//! Deletes the string from file by specified key
	void deleteByKey(const std::string& key);

	//! @Returns true if the file was successfully loaded and contained normal format of data
	void load();

	//! Saves an file to a given file path
	//! @Returns true if the file was successfully saved
	void save();

	//! Prints the content 
	void print(std::ostream& os);

	//! Clears current data of the container
	void clear();

	//! Changes value by key
	void set(const std::string& key, const std::string& value);

	//! Returns certain note by key
	std::string get(const std::string& key);

	//! Returns the true if file contains the note by specified key
	bool contains(const std::string& key);

	//
	// Private data members.
	//

private:
	mapFormat dataStorage_;

	std::shared_ptr<BaseStorageHelper> formatFileStorage_;

	//std::shared_ptr<BaseStorageHelper> formatFileStorage_;
};

