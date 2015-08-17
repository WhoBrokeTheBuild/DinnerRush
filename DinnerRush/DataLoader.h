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
	void saveData(const string& filename) const;

	void printAll(void) const;

	int	   getInt   (const DataKey& key) const;
	float  getFloat (const DataKey& key) const;
	string getString(const DataKey& key) const;
	string getAsset (const DataKey& key) const;
	Point  getPoint (const DataKey& key1, const DataKey& key2) const;

private:

	void loadTextData  (const string& filename);
	void loadBinaryData(const string& filename);

	void saveTextData  (const string& filename) const;
	void saveBinaryData(const string& filename) const;

	map<DataKey, string>	m_StrMap; // Map for string data
	map<DataKey, int>		m_IntMap; // Map for int data 
	map<DataKey, float>		m_FltMap; // Map for float data

}; // class DataLoader

#endif // DATA_LOADER_H