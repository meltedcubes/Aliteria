#include "../Scheduler/Scheduler.h"
#include "../Aliteria_Main/Shared/Instances.h"
#include <Dependencies/Luau/VM/include/lua.h>
#include <Misc.h>
#include <lualib.h>
#include <lua.h>
#include <Dependencies/Luau/VM/src/lapi.h>
#include <Aliteria_Main/Compiler.h>
#include "../IdentityManager/IdentityManager.h"
namespace Execution
{

	void Execute( lua_State* L , std::string Script )
	{
        int Top = lua_gettop( L );
        lua_State* Thread = lua_newthread( L );
        lua_pop( L , 1 );
        luaL_sandboxthread( Thread );
        IdentityManager::SetThreadCaps( Thread , 8 , Misc::MaxCaps );
        std::string bytecode = Anetia_Compiler::BytecodeCompile( Script );
        if ( luau_load( Thread , "" , bytecode.c_str( ) , bytecode.length( ) , 0 ) != LUA_OK )
        {
            std::string err = lua_tostring( Thread , -1 );
            Misc::Error( err.c_str( ) );
            lua_pop( Thread , 1 );
        }
        Closure* cl = clvalue( luaA_toobject( Thread , -1 ) );
        IdentityManager::SetProtoCaps( cl->l.p , &Misc::MaxCaps );
        lua_getglobal( Thread , "task" );
        lua_getfield( Thread , -1 , "defer" );
        lua_remove( Thread , -2 );
        lua_insert( Thread , -2 );
        if ( lua_pcall( Thread , 1 , 0 , 0 ) != LUA_OK )
        {
            std::string err = lua_tostring( Thread , -1 );
            Misc::Error( err.c_str( ) );
            lua_pop( Thread , 1 );
        }
        lua_settop( L , Top );
	}
}