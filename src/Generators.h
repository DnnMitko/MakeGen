#ifndef __GENERATORS__
#define __GENERATORS__

#include <iostream>
#include <string>
#include <dirent.h>
#include <fstream>

#include "../templates/MakefileMain.h"
#include "../templates/MakefileCommon.h"
#include "../templates/MakefileTree.h"

using std::cin;
using std::cout;
using std::string;
using std::ofstream;

void Prepare();

void MainGen( string, string, string, string );

void CommonGen( string );

void SrcTreeGen( string );

#endif //__GENERATORS__