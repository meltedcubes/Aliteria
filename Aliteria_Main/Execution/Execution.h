#pragma once
#include <lualib.h>
#include <lua.h>
#include <string>
namespace Execution
{
    void Execute( lua_State* L , const std::string Script );
}