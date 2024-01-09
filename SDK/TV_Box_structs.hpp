#pragma once

// Tribes Vengeance (1) SDK

#ifdef _MSC_VER
	#pragma pack(push, 0x4)
#endif

namespace SDK
{
//---------------------------------------------------------------------------
//Script Structs
//---------------------------------------------------------------------------

// Struct Box.BoundingVolume
// 0x0010 (0x002C - 0x001C)
struct FStruct_Box_BoundingVolume : public FStruct_Box
{
	struct FStruct_Vector_Plane                        Sphere;                                                   // 0x001C(0x0010)
};

}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
