#include "DataLoader.h"
#include<fstream>
#include<iostream>

DataLoader* gpDataLoader = NULL;

DataLoader::DataLoader()
{

}

DataLoader::~DataLoader()
{
	mSMap.clear();
	mIMap.clear(); 
}

void DataLoader::loadInfo()
{
	ifstream loadFile;
	loadFile.open(INFO_SHEET_LOC);

	if (loadFile.good())
	{
		while (!loadFile.eof())
		{
			string key;
			string toAdd, junk;
			char typeID;

			loadFile >> typeID;

			if (typeID == 's')
			{//load string
				loadFile >> key >> toAdd;
				
				map<DataKey, string>::iterator iter = mSMap.find(key);
				if (iter == mSMap.end())
				{
					mSMap[key] = toAdd;
				}

				else
				{
					getline(loadFile, junk);
				}
			}
		}


	}

	else //File couldnt Open
	{
		cout << "Could not open data file";
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

//For later when point/vector added
/*

Vector2D DataLoader::getAsVector(const DataKey& key1, const DataKey& key2)
{
map<DataKey, int>::iterator iter1 = mIMap.find(key1);
map<DataKey, int>::iterator iter2 = mIMap.find(key2);
Vector2D toReturn(0, 0);

if (iter1 != mIMap.end() && iter2 != mIMap.end())
{
toReturn.setX(static_cast<float>(iter1->second));
toReturn.setY(static_cast<float>(iter2->second));
}

return toReturn;
}
*/