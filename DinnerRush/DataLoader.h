#pragma once

#include <string>
#include <map>
//Include Vector2D/Point in future

using namespace std;

typedef string DataKey;

class DataLoader
{
public:
	DataLoader();
	~DataLoader();

	void loadInfo();
	int getInt(const DataKey& key);
	float getFloat(const DataKey& key);
	string getString(const DataKey& key);
	string getAsset(const DataKey& key);
	//Vector2D/Point getAsVector(const DataKey& key1, const DataKey& key2);

private:
	const string INFO_SHEET_LOC = "GameData.txt";

	map<DataKey, string> mSMap; //Map for string data
	map<DataKey, int> mIMap; //Map for int data 
	map<DataKey, float> mFMap;
};

extern DataLoader* gpDataLoader;