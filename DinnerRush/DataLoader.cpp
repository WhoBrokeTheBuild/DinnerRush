#include "DataLoader.h"
#include <fstream>
#include <iostream>

#include "Util.h"
#include "Benchmark.h"

using std::ifstream;
using std::ofstream;

DataLoader::DataLoader()
{

}

DataLoader::~DataLoader()
{
	m_StrMap.clear();
	m_IntMap.clear(); 
	m_FltMap.clear();
}

void DataLoader::loadData(const string& filename)
{
	const string& ext = getFileExt(filename);

	if (ext == "txt") {
		loadTextData(filename);
	}
	else if (ext == "bin") {
		loadBinaryData(filename);
	}

}

void DataLoader::saveData(const string& filename) const
{
	const string& ext = getFileExt(filename);

	if (ext == "txt") {
		saveTextData(filename);
	}
	else if (ext == "bin") {
		saveBinaryData(filename);
	}
}

int DataLoader::getInt(const DataKey& key) const
{
	auto iter = m_IntMap.find(key);
	int toReturn = -1;

	if (iter != m_IntMap.end())
	{
		return iter->second;
	}

	return toReturn;
}

string DataLoader::getString(const DataKey& key) const
{
	auto iter = m_StrMap.find(key);
	string toReturn = "_";

	if (iter != m_StrMap.end())
	{
		return  iter->second;
	}

	return toReturn;
}

string DataLoader::getAsset(const DataKey& key) const
{
	auto iter = m_StrMap.find(key);
	string path = getString("AssetPath");
	string toReturn = "_";

	if (iter != m_StrMap.end())
	{
		return  path + iter->second;
	}

	return toReturn;
}

float DataLoader::getFloat(const DataKey& key) const
{
	auto iter = m_FltMap.find(key);
	float toReturn = -1;

	if (iter != m_FltMap.end())
	{
		return  iter->second;
	}

	return toReturn;
}

Point DataLoader::getPoint(const DataKey& key1, const DataKey& key2) const
{
	auto iter1 = m_IntMap.find(key1);
	auto iter2 = m_IntMap.find(key2);
	Point toReturn{ 0, 0 };

	if (iter1 != m_IntMap.end() && iter2 != m_IntMap.end())
	{
		toReturn.x = iter1->second;
		toReturn.y = iter2->second;
	}

	return toReturn;
}

void DataLoader::loadTextData(const string& filename)
{
	BENCH_START();

	ifstream file;
	file.open(filename);

	if (file.good())
	{
		while (!file.eof())
		{
			char typeID;
			string key, junk;

			file >> typeID;

			// load string
			if (typeID == 's')
			{
				string value;
				file >> key >> value;

				auto iter = m_StrMap.find(key);
				if (iter == m_StrMap.end())
				{
					m_StrMap[key] = value;
				}


			}
			// load int
			else if (typeID == 'i')
			{
				int value;
				file >> key >> value;

				auto iter = m_IntMap.find(key);
				if (iter == m_IntMap.end())
				{
					m_IntMap[key] = value;
				}
			}
			// load float
			else if (typeID == 'f')
			{
				float value;
				file >> key >> value;

				auto iter = m_FltMap.find(key);
				if (iter == m_FltMap.end())
				{
					m_FltMap[key] = value;
				}
			}
			//  Skip line
			else
			{
				getline(file, junk);
			}

		}
	}
	// File couldn't Open
	else 
	{
		die("Could not open data file");
	}

	file.close();

	BENCH_PRINT("DataLoader::loadTextData");
}

void DataLoader::loadBinaryData(const string& filename)
{
	BENCH_START();

	ifstream file;
	file.open(filename, ifstream::binary);

	if (file.good())
	{
		while (!file.eof())
		{
			const byte& typeID = readBinaryByte(file);

			// load string
			if (typeID == 's') 
			{ 
				const string& key = readBinaryString(file);
				const string& value = readBinaryString(file);

				auto iter = m_StrMap.find(key);
				if (iter == m_StrMap.end())
				{
					m_StrMap[key] = value;
				}
			}
			// load int
			else if (typeID == 'i')
			{
				const string& key = readBinaryString(file);
				const int& value = readBinaryInt(file);

				auto iter = m_IntMap.find(key);
				if (iter == m_IntMap.end())
				{
					m_IntMap[key] = value;
				}
			}
			// load float
			else if (typeID == 'f')
			{
				const string& key = readBinaryString(file);
				const float& value = readBinaryFloat(file);

				auto iter = m_FltMap.find(key);
				if (iter == m_FltMap.end())
				{
					m_FltMap[key] = value;
				}
			}
		}
	}
	// File couldn't Open
	else 
	{
		die("Could not open data file");
	}

	file.close();

	BENCH_PRINT("DataLoader::loadBinaryData");
}

void DataLoader::saveTextData(const string& filename) const
{
	BENCH_START();

	ofstream file;
	file.open(filename);

	if (file.good())
	{
		for (auto iter = m_StrMap.cbegin(); iter != m_StrMap.cend(); ++iter) {
			file << "s " << iter->first << " " << iter->second << "\n";
		}

		for (auto iter = m_IntMap.cbegin(); iter != m_IntMap.cend(); ++iter) {
			file << "i " << iter->first << " " << iter->second << "\n";
		}

		for (auto iter = m_FltMap.cbegin(); iter != m_FltMap.cend(); ++iter) {
			file << "f " << iter->first << " " << iter->second << "\n";
		}
	}
	// File couldn't Open
	else 
	{
		die("Could not open data file");
	}

	file.close();

	BENCH_PRINT("DataLoader::saveTextData");
}

void DataLoader::saveBinaryData(const string& filename) const
{
	BENCH_START();

	ofstream file;
	file.open(filename, ofstream::binary);

	if (file.good())
	{
		for (auto iter = m_StrMap.cbegin(); iter != m_StrMap.cend(); ++iter) {
			writeBinaryByte(file, 's');
			writeBinaryString(file, iter->first);
			writeBinaryString(file, iter->second);
		}

		for (auto iter = m_IntMap.cbegin(); iter != m_IntMap.cend(); ++iter) {
			writeBinaryByte(file, 'i');
			writeBinaryString(file, iter->first);
			writeBinaryInt(file, iter->second);
		}

		for (auto iter = m_FltMap.cbegin(); iter != m_FltMap.cend(); ++iter) {
			writeBinaryByte(file, 'f');
			writeBinaryString(file, iter->first);
			writeBinaryFloat(file, iter->second);
		}
	}
	// File couldn't Open
	else
	{
		die("Could not open data file");
	}

	file.close();

	BENCH_PRINT("DataLoader::saveBinaryData");
}

void DataLoader::printAll(void) const
{
	for (auto iter = m_StrMap.cbegin(); iter != m_StrMap.cend(); ++iter) {
		std::cout << "s " << iter->first << " " << iter->second << "\n";
	}

	for (auto iter = m_IntMap.cbegin(); iter != m_IntMap.cend(); ++iter) {
		std::cout << "i " << iter->first << " " << iter->second << "\n";
	}

	for (auto iter = m_FltMap.cbegin(); iter != m_FltMap.cend(); ++iter) {
		std::cout << "f " << iter->first << " " << iter->second << "\n";
	}
}
