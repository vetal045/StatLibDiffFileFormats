#include "Config.h"

#include <iostream>
#include <string>

Config::Config(const StorageHelperKeyValueFormat & keyValueFileDataStorage) 
	: formatFileStorage_(std::make_shared<StorageHelperKeyValueFormat>(keyValueFileDataStorage))
{
}

Config::Config(const StorageHelperStringStringFormat & stringStringfileDataStorage)
	: formatFileStorage_(std::make_shared<StorageHelperStringStringFormat>(stringStringfileDataStorage))
{
}

void Config::add(const std::string & key, const std::string & value)
{
	if (key.find(' ') == std::string::npos)
	{
		dataStorage_.insert(std::pair<std::string, std::string>(key, value));
	}
	else
	{
		std::cout << "Bad enter in the key '" + key + "'. Read rules to right adding for that format!" << std::endl;
	}
}

void Config::deleteByKey(const std::string & key)
{
	std::map<std::string, std::string>::iterator it = dataStorage_.find(key);

	dataStorage_.erase(it);
}

bool Config::load()
{
	return formatFileStorage_->load(dataStorage_);
}

bool Config::save()
{
	return formatFileStorage_->save(dataStorage_);
}

void Config::print(std::ostream & os)
{
	if (dataStorage_.empty() == true)
	{
		std::cout << "The container is an empty." << std::endl;
	}
	else
	{
		os << "===========================================" << std::endl;;
		os << "The container has: " << std::endl;

		int numb = 0;
		for (const auto& i : dataStorage_)
		{
			++numb;
			os << numb << ". Key: " << i.first << ", value: " << i.second << std::endl;
		}

		os << "===========================================" << std::endl;
	}
}

void Config::clear()
{
	if (dataStorage_.empty() == false)
	{
		dataStorage_.clear();
	}
}

void Config::set(const std::string & key, const std::string & value)
{
	std::map<std::string, std::string>::iterator it = dataStorage_.find(key);

	if (it != dataStorage_.end())
		it->second = value;
}

std::string Config::get(const std::string & key)
{
	std::string value;

	for (const auto& i : dataStorage_)
	{
		if (i.first == key)
		{
			value = i.second;
			break;
		}
	}

	return value;
}

bool Config::contains(const std::string & key)
{
	std::map<std::string, std::string>::iterator it = dataStorage_.find(key);

	if (it == dataStorage_.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}


