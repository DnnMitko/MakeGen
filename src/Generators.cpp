#include "Generators.h"

void Prepare() {
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

void MainGen( string srcDir, string objDir, string exeName, string linkFlags ) {
    string Makefile = strMakefileMain_1 + srcDir + "\n"
                    + strMakefileMain_2 + objDir + "\n"
                    + strMakefileMain_3 + linkFlags + "\n"
                    + strMakefileMain_4 + exeName + "\n"
                    + strMakefileMain_5;

    ofstream os( "Makefile" );

    os << Makefile;

    os.close();
}

void CommonGen( string compFlags ) {
    string Makefile = strMakefileCommon + compFlags;

    ofstream os( "Makefile_Common" );

    os << Makefile;

    os.close();
}

void SrcTreeGen( string strPath ) {
    DIR* curDir = opendir( strPath.c_str() );

    if( curDir == NULL ) {
        cout << "Could not open directory: " << strPath.c_str() << "\n";
        return;
    }

    struct dirent* subDir;
    while( ( subDir = readdir( curDir ) ) != NULL ) {
        if( subDir->d_type == DT_DIR && subDir->d_name[0] != '.' ) {
            // printf( "%s\n", subDir->d_name ); TODO

            string newPath = strPath + '/' + subDir->d_name;
            SrcTreeGen( newPath );
        }
    }

    closedir( curDir );
}