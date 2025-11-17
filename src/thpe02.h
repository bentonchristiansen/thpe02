#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include "stringtracker.h"

#ifndef __THPE02__H
#define __THPE02__H

void checkArgc(int argc);

void openInFile(std::ifstream &fin, char fileName[]);

void openOutFile(std::ofstream &fout, char fileName[]);


#endif