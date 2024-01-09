// Tribes Vengeance (1) SDK

#ifdef _MSC_VER
	#pragma pack(push, 0x4)
#endif

#include "../SDK.hpp"

#define WINDOWS_IGNORE_PACKING_MISMATCH
#include <Windows.h>

namespace SDK
{
TArray<FNameEntry*>* FName::GNames = (TArray<FNameEntry*>*)0x10405210;
//TArray<UClass_Object*>* UClass_Object::GObjects = (TArray<UClass_Object*>*)0x1040b904;

//typedef void(__thiscall* tProcessEvent)(UObject*, UFunction*, void*);
//tProcessEvent _ProcessEvent = (tProcessEvent)PROCESS_EVENT_ADDRESS;

std::string FString::ToString() const {
    int size = WideCharToMultiByte(CP_UTF8, 0, Data, Count - 1, nullptr, 0, nullptr, nullptr);
    std::string str(size, 0);
    WideCharToMultiByte(CP_UTF8, 0, Data, Count - 1, &str[0], size, nullptr, nullptr);
    return str;
}

std::string FNameEntry::GetName() {
    auto length = std::wcslen(Data);
    auto neededLength = WideCharToMultiByte(CP_UTF8, 0, Data, length, nullptr, 0, nullptr, nullptr);
    std::string str(neededLength, 0);
    WideCharToMultiByte(CP_UTF8, 0, Data, length, &str[0], neededLength, nullptr, nullptr);
    return str;
}


std::string UClass_Object::GetFullName() const {
    std::string name;
    UClass_Object* previous_outer = nullptr;

    if (Class != nullptr) {
        std::string temp;
        for (auto p = Outer; p; p = p->Outer) {
            try {
                if (previous_outer == p) {
                    break;
                }

                if (this == p) {
                    break;
                }

                if (p->InternalIndex <= 0 || p->InternalIndex > GetGlobalObjects().Num()) {
                    break;
                }

                temp = p->GetName() + "." + temp;
                previous_outer = p;
            } catch (...) {
                break;
            }
        }

        name = Class->GetName();
        name += " ";
        name += temp;
        name += GetName();
    }

    return name;
}

bool UClass_Object::IsA(UClass_Object_Field_Struct_State_Class* cmp) {
    if (this == nullptr || cmp == nullptr) {
        return false;
    }
    for (UClass_Object_Field_Struct_State_Class* super = this->Class; super; super = (UClass_Object_Field_Struct_State_Class*)(super->Outer)) {
        if (super == nullptr)
        {
            return false;
        }

        if (super == cmp) {
            return true;
        }

        if (super->Outer == nullptr)
        {
            return false;
        }
    }

    return false;
}


UClass_Object_Field_Struct_Function* UClass_Object::FindFunctionFromObject(UClass_Object* object, std::string function_name){ 
    if (!object)
        return nullptr;

    if (!object->IsA(UClass_Object_Field_Struct_State_Class::StaticClass()))
        return nullptr;

    UClass_Object_Field_Struct_State_Class* object_as_class = (UClass_Object_Field_Struct_State_Class*)object;

    for (auto prop = (UClass_Object_Field_Property*)object_as_class->Children; prop && prop->IsValid(); prop = (UClass_Object_Field_Property*)prop->Next) {
        if (prop->IsA(UClass_Object_Field_Struct_Function::StaticClass())) {
            std::string full_function_name = prop->GetFullName();
            if (function_name == full_function_name) {
                return (UClass_Object_Field_Struct_Function*)prop;
            }
        }
    }

    return nullptr;
}


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
