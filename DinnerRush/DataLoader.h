#pragma once

#ifndef DATA_LOADER_H
#define DATA_LOADER_H

#include "Types.h"

typedef string DataKey;

class DataLoader
{
public:
	DataLoader();
	~DataLoader();

	void loadData(const string& filename);
	void saveData(const string& filename);

	void printAll(void);

	int	   getInt(const DataKey& key);
	float  getFloat(const DataKey& key);
	string getString(const DataKey& key);
	string getAsset(const DataKey& key);
	Point  getPoint(const DataKey& key1, const DataKey& key2);

private:

	void loadTextData(const string& filename);
	void loadBinaryData(const string& filename);

	void saveTextData(const string& filename);
	void saveBinaryData(const string& filename);

	map<DataKey, string>	m_StrMap; // Map for string data
	map<DataKey, int>		m_IntMap; // Map for int data 
	map<DataKey, float>		m_FltMap; // Map for float data
};

#endif // DATA_LOADER_H