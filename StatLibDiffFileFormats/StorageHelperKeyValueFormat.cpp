#include "StorageHelperKeyValueFormat.h"

StorageHelperKeyValueFormat::StorageHelperKeyValueFormat(const std::string& filePath) : filePath_(filePath)
{
}

bool StorageHelperKeyValueFormat::load(const std::map<std::string, std::string>& fileStorage)
{
	return false;
}

bool StorageHelperKeyValueFormat::save(const std::map<std::string, std::string>& fileStorage)
{
	return false;
}

void StorageHelperKeyValueFormat::set(const std::string & filePath)
{
	filePath_ = filePath;
}

const std::string & StorageHelperKeyValueFormat::get() const
{
	return filePath_;
}
