#include "StorageHelperNumberStringFormat.h"

StorageHelperNumberStringFormat::StorageHelperNumberStringFormat(const std::string& filePath) : filePath_(filePath)
{
}

bool StorageHelperNumberStringFormat::load(const std::map<std::string, std::string>& fileStorage)
{
	return false;
}

bool StorageHelperNumberStringFormat::save(const std::map<std::string, std::string>& fileStorage)
{
	return false;
}

void StorageHelperNumberStringFormat::set(const std::string & filePath)
{
	filePath_ = filePath;
}

const std::string & StorageHelperNumberStringFormat::get() const
{
	return filePath_;
}
