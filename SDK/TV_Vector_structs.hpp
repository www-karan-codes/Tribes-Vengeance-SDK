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

// Struct Vector.Plane
// 0x0004 (0x0010 - 0x000C)
struct FStruct_Vector_Plane : public FStruct_Vector
{
	float                                              W;                                                        // 0x000C(0x0004) (Edit, Config)
};

}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
