#include "DataLoader.h"
#include <fstream>
#include <iostream>

#include "Util.h"
#include "Benchmark.h"

DataLoader::DataLoader()
{

}

DataLoader::~DataLoader()
{
	mSMap.clear();
	mIMap.clear(); 
	mFMap.clear();
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

int DataLoader::getInt(const DataKey& key)
{
	map<DataKey, int>::iterator iter = mIMap.find(key);
	int toReturn = -1;

	if (iter != mIMap.end())
	{
		return iter->second;
	}

	return toReturn;
}

string DataLoader::getString(const DataKey& key)
{
	map<DataKey, string>::iterator iter = mSMap.find(key);
	string toReturn = "_";

	if (iter != mSMap.end())
	{
		return  iter->second;
	}

	return toReturn;
}

string DataLoader::getAsset(const DataKey& key)
{
	map<DataKey, string>::iterator iter = mSMap.find(key);
	string path = getString("AssetPath");
	string toReturn = "_";

	if (iter != mSMap.end())
	{
		return  path + iter->second;
	}

	return toReturn;
}

float DataLoader::getFloat(const DataKey& key)
{
	map<DataKey, float>::iterator iter = mFMap.find(key);
	float toReturn = -1;

	if (iter != mFMap.end())
	{
		return  iter->second;
	}

	return toReturn;
}

Point DataLoader::getPoint(const DataKey& key1, const DataKey& key2)
{
	map<DataKey, int>::iterator iter1 = mIMap.find(key1);
	map<DataKey, int>::iterator iter2 = mIMap.find(key2);
	Point toReturn{ 0, 0 };

	if (iter1 != mIMap.end() && iter2 != mIMap.end())
	{
		toReturn.x = static_cast<int>(iter1->second);
		toReturn.y = static_cast<int>(iter2->second);
	}

	return toReturn;
}

void DataLoader::loadTextData(const string& filename)
{
	BENCH_START();

	ifstream loadFile;
	loadFile.open(filename);

	if (loadFile.good())
	{
		while (!loadFile.eof())
		{
			string key;
			string toAdds, junk;
			int toAddi;
			float toAddf;
			char typeID;

			loadFile >> typeID;

			if (typeID == 's')
			{//load string
				loadFile >> key >> toAdds;

				map<DataKey, string>::iterator iter = mSMap.find(key);
				if (iter == mSMap.end())
				{
					mSMap[key] = toAdds;
				}


			}

			else if (typeID == 'i')
			{//load int
				loadFile >> key >> toAddi;

				map<DataKey, int>::iterator iter = mIMap.find(key);
				if (iter == mIMap.end())
				{
					mIMap[key] = toAddi;
				}
			}

			else if (typeID == 'f')
			{//load float
				loadFile >> key >> toAddf;

				map<DataKey, float>::iterator iter = mFMap.find(key);
				if (iter == mFMap.end())
				{
					mFMap[key] = toAddf;
				}
			}

			else
			{
				getline(loadFile, junk);
			}

		}//end while loop
	}

	else //File couldnt Open
	{
		cout << "Could not open data file";
	}

	loadFile.close();

	BENCH_PRINT("DataLoader::loadTextData");
}

void DataLoader::loadBinaryData(const string& filename)
{

}
