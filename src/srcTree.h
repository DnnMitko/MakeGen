#include <stdio.h>
#include <dirent.h>
#include <string>

using std::string;

int SrcTreeGen( string strPath ) {
    DIR* curDir = opendir( strPath.c_str() );

    if( curDir == NULL ) {
        printf( "Could not open directory: %s\n", strPath.c_str() );
        return 1;
    }

    struct dirent* subDir;
    while( ( subDir = readdir( curDir ) ) != NULL ) {
        if( subDir->d_type == DT_DIR && subDir->d_name[0] != '.' ) {
            printf( "%s\n", subDir->d_name );

            string newPath = strPath + '/' + subDir->d_name;
            SrcTreeGen( newPath );
        }
    }

    closedir( curDir );
}