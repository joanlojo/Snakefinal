#pragma once
#include "ID.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include "Logger.h"
#include "Assert.h"
#include "Resource.h"
//#include <XML/rapidxml_utils.hpp>
using namespace Logger;

namespace IOManager {

	// Base test function for XML purposes (TODO)
	/*void TestXML(std::string &&filename) {
	rapidxml::file<> xmlFile(RESOURCE_FILE(filename));
	rapidxml::xml_document<> doc;
	doc.parse<0>(xmlFile.data());
	rapidxml::xml_node<> *root_node = doc.first_node("document");
	for (rapidxml::xml_node<> * node = root_node->first_node("node"); node; node = node->next_sibling()) {
	Println("Node: ",
	node->first_attribute("att1")->value(),
	" - ",
	node->first_attribute("att2")->value());
	}
	}*/

	// Loader function that takes level info for a grid
	std::vector<std::vector<ObjectID>> LoadLevel(std::string &&filename, int &rows, int &cols) {
		std::ifstream fileData(RESOURCE_FILE(filename));
		ASSERT(fileData.good());
		std::vector<std::vector<ObjectID>> lvlData;
		std::string line;
		while (std::getline(fileData, line)) {
			std::istringstream strData(std::move(line));
			lvlData.emplace_back(std::istream_iterator<ObjectID>(std::move(strData)), std::istream_iterator<ObjectID>());
		}
		rows = int(lvlData.size()); cols = int(lvlData[0].size());
		fileData.close();
#pragma region DEBUG_DATA
		Println("Level: ", filename);
		for (auto &r : lvlData) {
			for (auto &c : r) Print(c, ' ');
			Endln();
		}
#pragma endregion
		return std::move(lvlData);
	}

}