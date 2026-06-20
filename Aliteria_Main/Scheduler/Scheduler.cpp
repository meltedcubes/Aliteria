#include "../Aliteria_Main/Shared/Instances.h"
#include <Dependencies/Luau/VM/include/lua.h>
#include "../Execution/Execution.h"
#include <Misc.h>
using namespace Shared;
namespace TaskScheduler
{
    inline lua_State* Anetia_GetLuaState( uintptr_t Sc = Shared::ScriptContext )
    {
        char Buffer [ 128 ];
        sprintf_s( Buffer , "ScriptContext @ 0x%llX" , Sc );
        Functions::Print( 0 , Buffer );
        Sleep( 500 );
        *reinterpret_cast< BOOLEAN* >( Sc + Offsets::RequireBypass ) = TRUE;
        auto Call = [ ] ( uintptr_t sc ) -> lua_State* {
            uint64_t Zero = 0;
            using Fn = lua_State * ( __fastcall* )( uintptr_t , uint64_t* , uint64_t* );
            return reinterpret_cast< Fn >( Offsets::GetLuaState )( sc , &Zero , &Zero );
            };
        return Call( Sc );
    }

    void Initialize( )
    {
        LuaState = Anetia_GetLuaState( );
        if ( LuaState ) {
            AliteriaState = lua_newthread( LuaState );
            Execution::Execute( AliteriaState , "print'hi'" );
        }
        else {
            Functions::Print( 0 , "Failed to get Lua State" );
        }
    }
}