#pragma once
#include <Dependencies/Luau/VM/include/lua.h>
#include <Misc.h>
#include <lualib.h>
#include <lua.h>
namespace IdentityManager
{
	void SetProtoCaps( Proto* Proto , uintptr_t* Caps );
	void SetThreadCaps( lua_State* L , int Identity , uintptr_t Caps );
}