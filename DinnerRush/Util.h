#pragma once

#ifndef UTIL_H
#define UTIL_H

#include "Types.h"

void pause(void);

void die(const string& msg);

string getFileExt(const string& filename);

#endif // UTIL_H