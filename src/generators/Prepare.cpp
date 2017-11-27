#include "Generators.h"

void Prepare()
{
    string srcDir;
    string objDir;
    string exeName;
    string compFlags;
    string linkFlags;

    cout << "Enter source directory: ";
    std::getline ( cin, srcDir );

    cout << "Enter objects directory: ";
    std::getline ( cin, objDir );

    cout << "Enter executable name: ";
    std::getline ( cin, exeName );

    cout << "Enter compiler flags: ";
    std::getline ( cin, compFlags );

    cout << "Enter linker flags: ";
    std::getline ( cin, linkFlags );

    MainGen( srcDir, objDir, exeName, linkFlags );

    CommonGen( compFlags );

    SrcTreeGen( srcDir );
}