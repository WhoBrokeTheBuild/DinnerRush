#pragma once

#ifndef UTIL_H
#define UTIL_H

#include "Types.h"
#include <fstream>

void pause(void);

void die(const string& msg);

string getFileExt(const string& filename);

byte readBinaryByte(std::ifstream& file);
int readBinaryInt(std::ifstream& file);
float readBinaryFloat(std::ifstream& file);
string readBinaryString(std::ifstream& file);

void writeBinaryByte(std::ofstream& file, const byte& value);
void writeBinaryInt(std::ofstream& file, const int& value);
void writeBinaryFloat(std::ofstream& file, const float& value);
void writeBinaryString(std::ofstream& file, const string& value);

#endif // UTIL_H