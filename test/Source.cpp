#include "Config.h"
#include "StorageHelperKeyValueFormat.h"
#include "StorageHelperStringStringFormat.h"

#include<iostream>
#include<string>
#include<vector>


void main()
{

	//Test of work with files

	StorageHelperKeyValueFormat form1("C:/123.txt"); //Creation object of new format for work with with files

	Config conf1(form1); //Creation config object to perform changes in 'form1'

	conf1.load(); //loading data from the  file

	conf1.print(std::cout); //printing file context

	conf1.add("qwerty", "123456");

	conf1.save();

	conf1.print(std::cout); //Printing saved data of the file




	//Test of work with vectors

	std::vector<std::pair<std::string, std::string>> myVec;

	myVec.push_back(std::make_pair("5", "five"));
	myVec.push_back(std::make_pair("3", "three"));


	StorageHelperStringStringFormat form2(myVec);

	Config conf2(form2);

	conf2.load();

	conf2.add("1", "one");

	conf2.print(std::cout);

	conf2.set("3", "123");

	std::cout << conf2.get("4") << std::endl;

	conf2.save();

	conf2.print(std::cout);
}