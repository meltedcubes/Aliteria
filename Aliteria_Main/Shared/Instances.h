#pragma once
#include <cstdint>
#include <Dependencies/Luau/VM/src/lstate.h>
#include <DataModel/DataModel.h>

namespace Shared
{
	inline uintptr_t ScriptContext;
	inline DataModel* DataModel_;
	inline lua_State* AliteriaState;
	inline lua_State* LuaState;
}