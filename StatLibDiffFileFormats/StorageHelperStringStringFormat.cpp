#include "StorageHelperStringStringFormat.h"

#include <string>
#include <algorithm>

StorageHelperStringStringFormat::StorageHelperStringStringFormat(std::vector<std::pair<std::string, std::string>>& vectorDataStorage)
	: vectorDataStorage_(vectorDataStorage)
{
}

bool StorageHelperStringStringFormat::load(std::map<std::string, std::string>& fileStorage)
{
	loadDataToStringStringFormat(vectorDataStorage_, fileStorage);

	return true;
}

bool StorageHelperStringStringFormat::save(const std::map<std::string, std::string>& fileStorage)
{
	return saveToStringStringFile(fileStorage);
}

void StorageHelperStringStringFormat::set(const std::vector<std::pair<std::string, std::string>>& vectorDataStorage)
{
	vectorDataStorage_ = vectorDataStorage;
}

const std::vector<std::pair<std::string, std::string>>& StorageHelperStringStringFormat::get() const
{
	return vectorDataStorage_;
}

void StorageHelperStringStringFormat::loadDataToStringStringFormat(const std::vector<std::pair<std::string, std::string>>& vectData, std::map<std::string, std::string>& fileStorage)
{
	int foundAssign, foundSpace;
	std::string key, value;

	if (fileStorage.empty() == false)
	{
		fileStorage.clear();
	}

	for (const auto& i : vectData)
	{
		foundSpace = i.first.find(' ');

		if (foundSpace == std::string::npos)
		{
			key = i.first;
			value = i.second;

			fileStorage.insert(std::pair<std::string, std::string>(key, value));
		}
	}
}

bool StorageHelperStringStringFormat::saveToStringStringFile(const std::map<std::string, std::string>& fileStringStringStorage)
{
	if (!vectorDataStorage_.empty())
	{
		vectorDataStorage_.clear();
	}

	for (const auto& i : fileStringStringStorage)
	{
		vectorDataStorage_.push_back(std::make_pair(i.first, i.second));
	}

	return true;
}
