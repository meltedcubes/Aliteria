#pragma once
#include <string>
#include <Windows.h>
#include "../Roblox/Offsets.h"
#include "../Aliteria_Main/Shared/Instances.h"
namespace Misc
{
	inline uintptr_t MaxCaps = 0xFFFFFFFFFFFFFFFF;
	inline void MessageBox_( const char* Message )
	{
		MessageBoxA( nullptr , Message , "Aliteria", MB_OK );
	}
	inline void Print( const char* Message )
	{
		Functions::Print( 0 , Message );
	}
	inline void Error( const char* Message )
	{
		Functions::Print( 3 , Message );
	}
	inline uintptr_t GetScriptContext( uintptr_t DataModel )
	{
		uintptr_t Children = *reinterpret_cast< uintptr_t* >( DataModel + 0x78 );
		uintptr_t ScriptContext = *reinterpret_cast< uintptr_t* >( *reinterpret_cast< uintptr_t* >( Children ) + 0x440 );
		return ScriptContext;
	}
	inline DataModel* GetDataModel( )
	{
		uintptr_t FakeDataModel = *reinterpret_cast< uintptr_t* >( Offsets::FakeDataModelPointer );
		if ( !FakeDataModel ) return nullptr;

		DataModel* DataModel_ = *reinterpret_cast< DataModel** >( FakeDataModel + Offsets::FakeDataModelToDataModel );
		return DataModel_;
	}
}