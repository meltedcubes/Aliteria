#pragma once
#include <cstdint>
#include <Windows.h>
#define r(address) (address + reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr)))

namespace Offsets
{
    namespace Luau
    {
        const uintptr_t Luau_Execute = r( 0x4683820 );
        const uintptr_t LuaO_NilObject = r( 0x68FCD10 );
        const uintptr_t LuaH_DummyNode = r( 0x68FCBB8 );
    }
	const uintptr_t Print = r( 0x1edba40 );
	const uintptr_t FakeDataModelToDataModel = 0x1D8;
	const uintptr_t FakeDataModelPointer = r( 0x7BCF6A8 );
    const uintptr_t GetLuaState = r( 0x1D5CB60 );
    const uintptr_t OpcodeLookupTable = r( 0x61a7d80 );
    const uintptr_t ScriptContext = 0x440;
    const uintptr_t RequireBypass = 0x851;
}
namespace Functions
{
    inline auto Print = ( uintptr_t( * )( int , const char* , ... ) )Offsets::Print;
}