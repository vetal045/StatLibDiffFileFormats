#include "StorageHelperKeyValueFormat.h"

#include <exception>
#include <fstream>
#include <string>

StorageHelperKeyValueFormat::StorageHelperKeyValueFormat(const std::string& filePath) : filePath_(filePath)
{
}

bool StorageHelperKeyValueFormat::load(std::map<std::string, std::string>& fileStorage)
{
	std::ifstream file(filePath_, std::ios::in);
	std::vector<std::string> fileData;
	std::string strFile;

	if (!file.is_open() || !file.good())
	{
		throw(std::runtime_error("Doesn't exist or can't open file " + filePath_ + "."));

		return false;
	}

	//fileSize_ = defineFileSize(file);

	while (std::getline(file, strFile))
	{
		fileData.push_back(strFile);
	}

	loadDataToKeyValueFormat(fileData, fileStorage);

	return true;
}

bool StorageHelperKeyValueFormat::save(const std::map<std::string, std::string>& fileStorage)
{
	return saveToKeyValueFile(fileStorage);
}

void StorageHelperKeyValueFormat::set(const std::string & filePath)
{
	filePath_ = filePath;
}

const std::string & StorageHelperKeyValueFormat::get() const
{
	return filePath_;
}

void StorageHelperKeyValueFormat::loadDataToKeyValueFormat(const std::vector<std::string>& fileData, std::map<std::string, std::string>& fileStorage)
{
	int foundAssign, foundSpace;
	std::string key, value;

	if (fileStorage.empty() == false)
	{
		fileStorage.clear();
	}

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
		}
	}
}

bool StorageHelperKeyValueFormat::saveToKeyValueFile(const std::map<std::string, std::string>& fileKeyValueStorage)
{
	std::ofstream file;

	file.open(filePath_, std::ofstream::out);

	if (!file.is_open())
	{
		throw(std::runtime_error("Can't open the file '" + filePath_ + "' to save changes.\n"));

		return false;
	}

	for (const auto& i : fileKeyValueStorage)
	{
		file << i.first + "=" + i.second << std::endl;
	}

	file.close();

	return true;
}
