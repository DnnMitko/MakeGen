#include "Generators.h"

using std::string;

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