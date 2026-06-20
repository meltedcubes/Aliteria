#pragma once
#include <string>
#include <Windows.h>
#include "../Dependencies/Luau/Bytecode/include/Luau/BytecodeBuilder.h"
#include "../Dependencies/Luau/Common/include/Luau/Bytecode.h"
#include "../Dependencies/Luau/Common/include/Luau/BytecodeUtils.h"
#include "../Dependencies/Luau/Compiler/include/Luau/Compiler.h"
#include <Roblox/Offsets.h>

class Anetia_BytecodeEncoder : public Luau::BytecodeEncoder
{
public:
    void encode( uint32_t* data , size_t count ) override;
};
void Anetia_BytecodeEncoder::encode( uint32_t* data , size_t count )
{
    for ( auto i = 0; i < count;)
    {
        uint8_t Opcode = LUAU_INSN_OP( data [ i ] );
        const auto LookupTable = reinterpret_cast< BYTE* >( Offsets::OpcodeLookupTable );
        uint8_t FinalOpcode = Opcode * 227;
        FinalOpcode = LookupTable [ FinalOpcode ];

        data [ i ] = ( FinalOpcode ) | ( data [ i ] & ~0xFF );
        i += Luau::getOpLength( static_cast< LuauOpcode >( Opcode ) );
    }
}
namespace Anetia_Compiler
{
    std::string BytecodeCompile( std::string Script )
    {
        Anetia_BytecodeEncoder BytecodeEncoder;
        static const char* Shared [ ] = { "Game", "Workspace", "game", "plugin", "script", "shared", "workspace", "_G", "_ENV", nullptr };
        Luau::CompileOptions Options;
        Options.debugLevel = 2;
        Options.optimizationLevel = 1;
        Options.mutableGlobals = Shared;
        Options.vectorLib = "Vector3";
        Options.vectorCtor = "new";
        Options.vectorType = "Vector3";
        return Luau::compile( Script , Options , {} , &BytecodeEncoder );
    }
}