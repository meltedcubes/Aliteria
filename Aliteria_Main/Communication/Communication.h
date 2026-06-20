#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <fstream>
#include <string>
#include <filesystem>
#include <Aliteria_Main/Execution/Execution.h>
#include <Aliteria_Main/Shared/Instances.h>

namespace Communication
{
    void Start( )
    {
        std::string FilePath = std::string( getenv( "LOCALAPPDATA" ) ) + "\\taskscheduler.txt";
        std::string LastContent;
        std::string CurrentContent;
        while ( true ) {
            Sleep( 1000 );
            if ( !std::filesystem::exists( FilePath ) ) {
                continue;
            }
            std::ifstream File( FilePath );
            if ( !File.is_open( ) ) {
                continue;
            }
            CurrentContent = std::string( ( std::istreambuf_iterator<char>( File ) ) , std::istreambuf_iterator<char>( ) );
            File.close( );
            if ( CurrentContent != LastContent && !CurrentContent.empty( ) ) {
                LastContent = CurrentContent;
                Execution::Execute( Shared::AliteriaState , CurrentContent );
            }
        }
    }
}