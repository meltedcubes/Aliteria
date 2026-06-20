#pragma once
#include <DataModel/DataModel.h>
#include "../Aliteria_Main/Shared/Instances.h"
#include <Aliteria_Main/Scheduler/Scheduler.h>

namespace TpHandler
{
    void Start( )
    {
        while ( true )
        {
            DataModel* CurrentDataModel = Shared::DataModel_;
            DataModel* NewDataModel = Misc::GetDataModel( );

            if ( NewDataModel != CurrentDataModel && NewDataModel )
            {
                while ( NewDataModel->GameLoaded != 31 )
                {
                    Sleep( 1000 );
                    NewDataModel = Misc::GetDataModel( );

                    if ( !NewDataModel ) {
                        Sleep( 1000 );
                        continue;
                    }
                }

                uintptr_t ScriptContext = Misc::GetScriptContext( ( uintptr_t )NewDataModel );
                if ( ScriptContext ) {
                    Shared::DataModel_ = NewDataModel;
                    Shared::ScriptContext = ScriptContext;
                    TaskScheduler::Initialize( );
                }
            }

            Sleep( 1000 );
        }
    }
}
