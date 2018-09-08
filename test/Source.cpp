#include "Config.h"
#include "StorageHelperKeyValueFormat.h"
#include "StorageHelperStringStringFormat.h"

#include<iostream>
#include<string>
#include<vector>


int main()
{

	try
	{
		//Test of work with files

		auto form1 = std::make_shared<StorageHelperKeyValueFormat>("C:/Users/Виталий/Documents/Visual Studio 2015/Projects/StatLibDiffFileFormats/123.txt");
		//StorageHelperKeyValueFormat form1("C:/123.txt"); //Creation object of new format for work with with files

		Config conf1(form1); //Creation config object to perform changes in 'form1'

		try
		{
			conf1.load(); //loading data from the file

			conf1.print(std::cout); //printing file context

			conf1.add("qwerty", "123456");

			conf1.print(std::cout); //Printing saved data of the file

			conf1.save();
		}
		catch (const std::runtime_error& e)
		{
			std::cerr << e.what() << std::endl;
		}


		//Test of work with vectors

		std::vector<std::pair<std::string, std::string>> myVec;

		myVec.push_back(std::make_pair("5", "five"));
		myVec.push_back(std::make_pair("3", "three"));


		auto form2 = std::make_shared<StorageHelperStringStringFormat>(myVec);

		Config conf2(form2);

		try
		{
			conf2.load();

			conf2.add("1", "one");

			conf2.print(std::cout);

			conf2.set("3", "123");

			std::cout << conf2.get("3") << std::endl;

			conf2.save();

			conf2.print(std::cout);
		}
		catch (const std::runtime_error& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (...)	{
		std::cerr << "Unknown error." << std::endl;
	}

	system("pause");
	return 0;
}