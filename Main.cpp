#define _CRT_SECURE_NO_WARNINGS
#include <thread>
#include <Windows.h>
#include "Misc/Misc.h"
#include "Roblox/Definitions/Structs/DataModel/DataModel.h"
#include "Aliteria_Main/Shared/Instances.h"
#include "Aliteria_Main/Scheduler/Scheduler.h"
#include "Aliteria_Main/TpHandler/TpHandler.h"
#include "Aliteria_Main/Communication/Communication.h"
void Main( )
{
    /*
    
       If you inject in homepage this will likely crash
    
    */
    Misc::Print( "Loaded" );
    DataModel* DataModel_ = Misc::GetDataModel( );
    {
        DataModel_ = Misc::GetDataModel( );
        char Buffer [ 128 ];
        Shared::DataModel_ = DataModel_;
            uintptr_t ScriptContext = Misc::GetScriptContext( ( uintptr_t ) DataModel_ );
            if ( ScriptContext == 0 )
            {
                uintptr_t ScriptContext = Misc::GetScriptContext( ( uintptr_t ) DataModel_ );
            }
            sprintf_s( Buffer , "ScriptContext @ 0x%llX" , ScriptContext );
            Shared::ScriptContext = ScriptContext;
            Misc::Print( Buffer );
    }
    TaskScheduler::Initialize( );
    std::thread( TpHandler::Start ).detach( );
}

BOOL APIENTRY DllMain( HMODULE hModule , DWORD  ul_reason_for_call , LPVOID lpReserved )
{
	if ( ul_reason_for_call == DLL_PROCESS_ATTACH )
	{
        Misc::Print( "Starting main.." );
		std::thread( Main ).detach( );
        std::thread( Communication::Start ).detach( );
		return TRUE;
    }
	return TRUE;
}

