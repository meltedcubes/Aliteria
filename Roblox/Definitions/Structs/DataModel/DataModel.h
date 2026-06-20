#pragma once
#include <cstdint>

struct DataModel {
    char dih0 [ 8 ];
    uintptr_t ToRenderView2;
    char dih1 [ 24 ];
    uintptr_t ToRenderView3;
    char dih2 [ 328 ];
    uintptr_t Workspace;
    char dih3 [ 24 ];
    uintptr_t CreatorId;
    uintptr_t GameId;
    uintptr_t PlaceId;
    char dih4 [ 20 ];
    int PlaceVersion;
    char dih5 [ 24 ];
    uintptr_t ToRenderView1;
    char dih6 [ 600 ];
    uintptr_t ScriptContext;
    char dih7 [ 96 ];
    int PrimitiveCount;
    char dih8 [ 460 ];
    uintptr_t GameLoaded;
};