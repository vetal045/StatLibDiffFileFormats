#pragma once

#include "BaseStorageHelper.h"

#include <vector>

// Alias to vector format
using vectorFormat = std::vector<std::pair<std::string, std::string>>;

//
// Declaration of the class StorageHelperStringStringFormat.
//

class StorageHelperStringStringFormat : public BaseStorageHelper
{
	//
	// Construction and destruction.
	//

public:

	StorageHelperStringStringFormat(vectorFormat& vectorDataStorage);

	//
	// Public methods.
	//

public:

	//! Loads all data from the NumberString format file
	//! @Returns true if the file was successfully loaded and contained NumberString format data
	virtual void load(mapFormat& fileStorage) override;

	//! Saves data to the NumberString format file
	virtual void save(const mapFormat& fileStorage) override;
	
	//! Sets path of the file
	void set(const vectorFormat& vectorDataStorage);

	//! @Returns string with path of the file
	const vectorFormat& get() const;
	
	//
	// Private methods.
	//

private:

	//! Converts all data to KeyValue format
	void loadDataToStringStringFormat(const vectorFormat& vectData, mapFormat & vectorStorage);

	//! Saves data to KeyValue format file
	void saveToStringStringFile(const mapFormat& fileStringStringStorage);

	//
	// Private data members.
	//

private:
	vectorFormat& vectorDataStorage_;
};

