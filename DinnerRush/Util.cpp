#include "Util.h"

using std::ifstream;
using std::ofstream;

void pause(void)
{
	printf("Press any key to continue\n");
	getchar();
}

void die(const string& msg) 
{
	printf("Error: %s\n", msg.c_str());
	pause();
	exit(1);
}

string getFileExt(const string& filename)
{
	if (filename.find_last_of(".") != std::string::npos)
		return filename.substr(filename.find_last_of(".") + 1);
	return "";
}

byte readBinaryByte(ifstream& file)
{
	byte val;
	file.read((char*)&val, sizeof(val));
	return val;
}

int readBinaryInt(ifstream& file)
{
	int val;
	file.read((char*)&val, sizeof(val));
	return val;
}

float readBinaryFloat(ifstream& file)
{
	float val;
	file.read((char*)&val, sizeof(val));
	return val;
}

string readBinaryString(ifstream& file)
{
	unsigned int strLen;
	vector<char> str;

	file.read((char*)&strLen, sizeof(strLen));
	str.resize(strLen + 1);

	file.read(str.data(), strLen);
	str.push_back(0); // Null terminator

	return string(str.data());
}

void writeBinaryByte(ofstream& file, const byte& value)
{
	file.write((const char*)&value, sizeof(value));
}

void writeBinaryInt(ofstream& file, const int& value)
{
	file.write((const char*)&value, sizeof(value));
}

void writeBinaryFloat(ofstream& file, const float& value)
{
	file.write((const char*)&value, sizeof(value));
}

void writeBinaryString(ofstream& file, const string& value)
{
	writeBinaryInt(file, value.length());
	file.write(value.data(), value.length());
}
