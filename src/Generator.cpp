#include "Generator.h"

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
    string Makefile = makefileMain_1 + srcDir + "\n"
                    + makefileMain_2 + objDir + "\n"
                    + makefileMain_3 + linkFlags + "\n"
                    + makefileMain_4 + exeName + "\n"
                    + makefileMain_5;

    ofstream os( "Makefile" );

    os << Makefile;

    os.close();
}

void CommonGen( string compFlags ) {
    string Makefile = makefileCommon + compFlags;

    ofstream os( "Makefile_Common" );

    os << Makefile;

    os.close();
}

void SrcTreeGen( string strPath ) {
    DIR* curDir = opendir( strPath.c_str() );

    string makeCalls = "";
    string makeCallsTree = "";

    if( curDir == NULL ) {
        cout << "Could not open directory: " << strPath.c_str() << "\n";
        return;
    }

    struct dirent* subDir;
    while( ( subDir = readdir( curDir ) ) != NULL ) {
        if( subDir->d_type == DT_DIR && subDir->d_name[0] != '.' ) {
            makeCalls += MakeCallGen( subDir->d_name ) + "\n";
            makeCallsTree += MakeCallGen( subDir->d_name ) + " tree\n";

            string newPath = strPath + '/' + subDir->d_name;
            SrcTreeGen( newPath );
        }
    }

    string makefilePath = strPath + "/Makefile";
    ofstream os( makefilePath.c_str() );

    os << makefileTree_1 + makeCalls
        + makefileTree_2 + LabelGen( strPath )
        + makefileTree_3 + makeCallsTree
        + makefileTree_4;

    os.close();

    closedir( curDir );
}

string MakeCallGen( string dirName ) {
    return "	@$(MAKE) --no-print-directory -C " + dirName;
}

string StripPath( string path ) {
    for( int i = path.length() - 1; i >=0; i-- ) {
        if( path[i] == '/' ) {
            return path.substr( i + 1, path.length() - 1 - i );
        }
    }

    return path;
}

string LabelGen( string dirPath ) {
    string dirName = StripPath( dirPath );

    int labelSize = 27;

    int borderCount = labelSize - dirName.length() - 2;

    string border = "";
    for( int i = 0; i < borderCount / 2; i++ ) {
        border += "═";
    }

    if( borderCount % 2 == 0 ) {
        return border + "[" + dirName + "]" + border;
    }
    else {
        return border + "[" + dirName + "]" + border + "═";
    }
}