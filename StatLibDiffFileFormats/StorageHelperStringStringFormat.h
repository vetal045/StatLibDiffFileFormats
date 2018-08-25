#pragma once

#include "BaseStorageHelper.h"

#include <vector>

//
// Declaration of the class StorageHelperStringStringFormat.
//

class StorageHelperStringStringFormat : public BaseStorageHelper
{
	//
	// Construction and destruction.
	//

public:

	StorageHelperStringStringFormat(std::vector<std::pair<std::string, std::string>>& vectorDataStorage);

	//
	// Public methods.
	//

public:

	//! Loads all data from the NumberString format file
	//! @Returns true if the file was successfully loaded and contained NumberString format data
	virtual bool load(std::map<std::string, std::string>& fileStorage) override;

	//! Saves data to the NumberString format file
	virtual bool save(const std::map<std::string, std::string>& fileStorage) override;
	
	//! Sets path of the file
	void set(const std::vector<std::pair<std::string, std::string>>& vectorDataStorage);

	//! @Returns string with path of the file
	const std::vector<std::pair<std::string, std::string>>& get() const;
	
	//
	// Private methods.
	//

private:

	//! Converts all data to KeyValue format
	void loadDataToStringStringFormat(const std::vector<std::pair<std::string, std::string>>& vectData, std::map <std::string, std::string> & fileStorage);

	//! Saves data to KeyValue format file
	bool saveToStringStringFile(const std::map<std::string, std::string>& fileStringStringStorage);

	//
	// Private data members.
	//

private:
	std::vector<std::pair<std::string, std::string>>& vectorDataStorage_;
};

