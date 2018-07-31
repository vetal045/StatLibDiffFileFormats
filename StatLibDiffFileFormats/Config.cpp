#include "Config.h"

Config::Config(const StorageHelperKeyValueFormat & keyValueFileDataStorage) 
	: formatFileStorage_(std::make_shared<StorageHelperKeyValueFormat>(keyValueFileDataStorage))
{
}

Config::Config(const StorageHelperNumberStringFormat & numberStringfileDataStorage)
	: formatFileStorage_(std::make_shared<StorageHelperNumberStringFormat>(numberStringfileDataStorage))
{
}

bool Config::load()
{
	return formatFileStorage_->load(fileDataStorage_);
}

bool Config::save()
{
	return formatFileStorage_->save(fileDataStorage_);
}


