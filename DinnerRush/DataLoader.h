#pragma once

#ifndef DATA_LOADER_H
#define DATA_LOADER_H

#include "Types.h"
#include <map>
//Include Vector2D/Point in future

using namespace std;

typedef string DataKey;

class DataLoader
{
public:
	DataLoader();
	~DataLoader();

	void loadData(const string& filename);

	int	   getInt(const DataKey& key);
	float  getFloat(const DataKey& key);
	string getString(const DataKey& key);
	string getAsset(const DataKey& key);
	Point  getPoint(const DataKey& key1, const DataKey& key2);

private:

	void loadTextData(const string& filename);
	void loadBinaryData(const string& filename);

	map<DataKey, string> mSMap; //Map for string data
	map<DataKey, int> mIMap; //Map for int data 
	map<DataKey, float> mFMap;
};

#endif // DATA_LOADER_H