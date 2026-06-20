#include "IdentityManager.h"

namespace IdentityManager
{
    void SetProtoCaps( Proto* Proto , uintptr_t* Caps )
    {
        Proto->userdata = Caps;
        for ( int i = 0; i < Proto->sizep; ++i )
            SetProtoCaps( Proto->p [ i ] , Caps );
    }

    void SetThreadCaps( lua_State* L , int Identity , uintptr_t Caps )
    {
        L->userdata->Identity = Identity;
        L->userdata->Capabilities = Caps;
    }
}