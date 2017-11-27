#ifndef __GENERATORS__
#define __GENERATORS__

#include <iostream>
#include <string>
#include <dirent.h>

using std::cin;
using std::cout;
using std::string;

void Prepare();

void MainGen( string, string, string, string );

void CommonGen( string );

void SrcTreeGen( string );

#endif //__GENERATORS__