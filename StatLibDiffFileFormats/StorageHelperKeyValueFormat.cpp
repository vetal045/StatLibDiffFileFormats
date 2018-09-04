#include "StorageHelperKeyValueFormat.h"

#include <exception>
#include <fstream>
#include <string>

StorageHelperKeyValueFormat::StorageHelperKeyValueFormat(const std::string& filePath) : filePath_(filePath)
{
}

void StorageHelperKeyValueFormat::load(mapFormat& fileStorage)
{
	std::ifstream file(filePath_, std::ios::in);

	if (!file.is_open() || !file.good())
	{
		throw(std::runtime_error("Doesn't exist or can't open file " + filePath_ + "."));
	}

	//fileSize_ = defineFileSize(file);

	std::vector<std::string> fileData;
	std::string strFile;

	while (std::getline(file, strFile))
	{
		fileData.push_back(strFile);
	}

	loadDataToKeyValueFormat(fileData, fileStorage);
}

void StorageHelperKeyValueFormat::save(const mapFormat& fileStorage)
{
	saveToKeyValueFile(fileStorage);
}

void StorageHelperKeyValueFormat::set(const std::string & filePath)
{
	filePath_ = filePath;
}

const std::string & StorageHelperKeyValueFormat::get() const
{
	return filePath_;
}

void StorageHelperKeyValueFormat::loadDataToKeyValueFormat(const std::vector<std::string>& fileData, mapFormat& fileStorage)
{
	if (fileStorage.empty() == false)
	{
		fileStorage.clear();
	}

	int foundAssign, foundSpace;
	std::string key, value;

	for (const auto& i : fileData)
	{
		foundAssign = i.find('=');

		if (foundAssign != std::string::npos)
		{
			key = i.substr(0, foundAssign);

			if ((foundSpace = key.find(' ') == std::string::npos) ? true : false)
			{
				value = i.substr(foundAssign + 1);

				fileStorage.insert(std::pair<std::string, std::string>(key, value));
			}
			else
			{
				throw(std::runtime_error("The file "+ filePath_ +"contains not correct data format."));
			}
		}
		else
		{
			throw(std::runtime_error("File contains one of notes without required symbol '='."));
		}
	}
}

void StorageHelperKeyValueFormat::saveToKeyValueFile(const mapFormat& fileKeyValueStorage)
{
	std::ofstream file;

	file.open(filePath_, std::ofstream::out);

	if (!file.is_open())
	{
		throw(std::runtime_error("Can't open the file '" + filePath_ + "' to save changes."));
	}

	for (const auto& i : fileKeyValueStorage)
	{
		file << i.first << "=" << i.second << std::endl;
	}

	file.close();
}
