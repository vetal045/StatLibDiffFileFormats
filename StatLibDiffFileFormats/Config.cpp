#include "Config.h"

#include <iostream>
#include <string>


Config::Config(const std::shared_ptr<BaseStorageHelper> keyValueFileDataStorage)
: formatFileStorage_(keyValueFileDataStorage)
{
}


/*Config::Config(const StorageHelperKeyValueFormat& keyValueFileDataStorage)
	: formatFileStorage_(std::make_shared<StorageHelperKeyValueFormat>(keyValueFileDataStorage))
{
}

Config::Config(const StorageHelperStringStringFormat& keyValueFileDataStorage)
	: formatFileStorage_(std::make_shared<StorageHelperStringStringFormat>(keyValueFileDataStorage))
{
}*/

void Config::add(const std::string & key, const std::string & value)
{
	if (key.find(' ') == std::string::npos)
	{
		const auto it = dataStorage_.find(key);

		if (it == dataStorage_.end())
		{
			dataStorage_.insert(std::pair<std::string, std::string>(key, value));
		}
		else
		{
			throw(std::runtime_error("Storage already contains note with the specified key - "+ key +"."));
		}
	}
	else
	{
		throw(std::runtime_error("Bad enter by specified key - " + key + "."));
	}
}

void Config::deleteByKey(const std::string & key)
{
	const auto it = dataStorage_.find(key);

	dataStorage_.erase(it);
}

void Config::load()
{
	formatFileStorage_->load(dataStorage_);
}

void Config::save()
{
	formatFileStorage_->save(dataStorage_);
}

void Config::print(std::ostream & os)
{
	if (dataStorage_.empty() == true)
	{
		os << "The container is an empty." << std::endl;
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
	dataStorage_.clear();
}

void Config::set(const std::string & key, const std::string & value)
{
	const auto it = dataStorage_.find(key);

	if (it != dataStorage_.end())
	{
		it->second = value;
	}
	else
	{
		add(key,value);
	}
}

std::string Config::get(const std::string & key)
{
	auto it = dataStorage_.find(key);

	std::string value;

	if (it != dataStorage_.end())
	{
		value = it->second;
	}
	else
	{
		throw(std::runtime_error("The pair don't exist by key - "+ key +"."));
	}
	
	return value;
}

bool Config::contains(const std::string & key)
{
	const auto it = dataStorage_.find(key);

	return (it != dataStorage_.end());
}


