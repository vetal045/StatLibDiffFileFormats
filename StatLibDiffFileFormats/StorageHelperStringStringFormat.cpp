#include "StorageHelperStringStringFormat.h"

#include <string>
#include <algorithm>

StorageHelperStringStringFormat::StorageHelperStringStringFormat(vectorFormat& vectorDataStorage)
	: vectorDataStorage_(vectorDataStorage)
{
}

void StorageHelperStringStringFormat::load(mapFormat& fileStorage)
{
	loadDataToStringStringFormat(vectorDataStorage_, fileStorage);
}

void StorageHelperStringStringFormat::save(const mapFormat& fileStorage)
{
	saveToStringStringFile(fileStorage);
}

void StorageHelperStringStringFormat::set(const vectorFormat& vectorDataStorage)
{
	vectorDataStorage_ = vectorDataStorage;
}

const std::vector<std::pair<std::string, std::string>>& StorageHelperStringStringFormat::get() const
{
	return vectorDataStorage_;
}

void StorageHelperStringStringFormat::loadDataToStringStringFormat(const vectorFormat& vectData, mapFormat& vectorStorage)
{
	if (vectorStorage.empty() == false)
	{
		vectorStorage.clear();
	}

	int foundSpace;

	for (const auto& i : vectData)
	{
		foundSpace = i.first.find(' ');

		if (foundSpace == std::string::npos)
		{
			vectorStorage.insert(i);
		}
		else
		{
			throw(std::runtime_error("Vector contains not correct data format."));
		}
	}
}

void StorageHelperStringStringFormat::saveToStringStringFile(const mapFormat& fileStringStringStorage)
{
	if (!vectorDataStorage_.empty())
	{
		vectorDataStorage_.clear();
	}

	for (const auto& i : fileStringStringStorage)
	{
		vectorDataStorage_.push_back(std::make_pair(i.first, i.second));
	}
}
