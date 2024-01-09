#pragma once

// Tribes Vengeance (1) SDK

#ifdef _MSC_VER
#pragma pack(push, 0x1)
#endif

//#include <Windows.h>
//#include <stringapiset.h>
#include <list>

namespace SDK {
template <typename Fn>
inline Fn GetVFunction(const void* instance, std::size_t index) {
    auto vtable = *reinterpret_cast<const void***>(const_cast<void*>(instance));
    return reinterpret_cast<Fn>(vtable[index]);
}

template <class T>
struct TArray {
    friend struct FString;

   public:
    inline TArray() {
        Data = nullptr;
        Count = Max = 0;
    };

    inline size_t Num() const {
        return Count;
    };

    inline T& operator[](size_t i) {
        return Data[i];
    };

    inline const T& operator[](size_t i) const {
        return Data[i];
    };

    inline bool IsValidIndex(size_t i) const {
        return i < Num();
    }

    inline T& GetByIndex(size_t i) {
        return Data[i];
    }

    inline const T& GetByIndex(size_t i) const {
        return Data[i];
    }

   private:
    T* Data;
    int32_t Count;
    int32_t Max;
};

struct FString : private TArray<wchar_t> {
    inline FString() {
    }

    FString(const wchar_t* other) {
        Max = Count = *other ? std::wcslen(other) + 1 : 0;

        if (Count) {
            Data = const_cast<wchar_t*>(other);
        }
    };

    inline bool IsValid() const {
        return Data != nullptr;
    }

    inline const wchar_t* c_str() const {
        return Data;
    }

    std::string ToString() const;
};

template <class TEnum>
class TEnumAsByte {
   public:
    inline TEnumAsByte() {
    }

    inline TEnumAsByte(TEnum _value)
        : value(static_cast<uint8_t>(_value)) {
    }

    /*
    explicit inline TEnumAsByte(int32_t _value)
        : value(static_cast<uint8_t>(_value)) {
    }

    explicit inline TEnumAsByte(uint8_t _value)
        : value(_value) {
    }
    */
    
    inline operator TEnum() const {
        return (TEnum)value;
    }

    inline TEnum GetValue() const {
        return (TEnum)value;
    }

   private:
    uint8_t value;
};

struct FNameEntry {
    char UnknownData00[0xC];
    wchar_t Data[0x10];

    std::string GetName();
};

struct FName {
    int32_t Index;

    FName()
        : Index(0){};

    FName(int32_t i)
        : Index(i){};

    FName(const char* nameToFind)
        : Index(0) {
        static std::set<size_t> cache;

        for (auto i : cache) {
            if (GetGlobalNames()[i]->GetName() == nameToFind) {
                Index = i;

                return;
            }
        }

        for (auto i = 0u; i < GetGlobalNames().Num(); ++i) {
            if (GetGlobalNames()[i] != nullptr) {
                if (GetGlobalNames()[i]->GetName() == nameToFind) {
                    cache.insert(i);

                    Index = i;

                    return;
                }
            }
        }
    };

    static TArray<FNameEntry*>* GNames;
    static inline TArray<FNameEntry*>& GetGlobalNames() {
		GNames = (TArray<FNameEntry*>*)0x10405210;
        return *GNames;
    };

    inline std::string GetName() const {
        return GetGlobalNames()[Index]->GetName();
    };

    inline bool operator==(const FName& other) const {
        return Index == other.Index;
    };
};

struct FPointer {
    int Dummy;
};

struct FScriptDelegate {
    unsigned char UnknownData[0x0C];
};

struct FQWord {
    int A;
    int B;
};

//class UClass_Object_Field_Struct_State_Class;

class UClass_Object {
   public:
    void* VfTableObject;
    int InternalIndex;
    char UnknownData[20];
    int Flags;
    struct FName Name;
    class UClass_Object_Field_Struct_State_Class* Class;
    UClass_Object* Outer;

    static inline TArray<UClass_Object*>& GetGlobalObjects() {
        TArray<UClass_Object*>* GObjects = (TArray<UClass_Object*>*)0x1040b904;
        return *GObjects;
    }

    inline std::string GetName() const {
        return Name.GetName();
    }

    std::string GetFullName() const;

    template <typename T>
    static T* FindObject(const std::string& name) {
        for (auto i = 0u; i < GetGlobalObjects().Num(); ++i) {
            auto object = GetGlobalObjects().GetByIndex(i);

            if (i == 592) {
                bool breakpoint_here = true;
            }

            if (object == nullptr) {
                continue;
            }

            if (object->GetFullName() == name) {
                return static_cast<T*>(object);
            }
        }
        return nullptr;
    }

    
    template <typename T>
    static T* FindObjectByType(void) {
        for (auto i = 0u; i < GetGlobalObjects().Num(); ++i) {
            auto object = GetGlobalObjects().GetByIndex(i);
            if (object == nullptr) {
                continue;
            }

            if (object->IsA(T::StaticClass())) {
                return static_cast<T*>(object);
            }
        }
        return nullptr;
    }

    template <typename T>
    static std::list<T*> FindObjectsByType(void) {
        std::list<T*> list;
        try {
            for (auto i = 0u; i < GetGlobalObjects().Num(); ++i) {
                auto object = GetGlobalObjects().GetByIndex(i);
                if (object == nullptr) {
                    continue;
                }

                if (object->IsA(T::StaticClass())) {
                    //return static_cast<T*>(object);
                    list.push_back(static_cast<T*>(object));
                }
            }
        }
        catch (...) {
            return list;
        }
        return list;
        //return nullptr;
    }
    

    static class UClass_Object_Field_Struct_Function* FindFunctionFromObject(UClass_Object* object, std::string function_name);

    static UClass_Object_Field_Struct_State_Class* FindClass(const std::string& name) {
        return FindObject<UClass_Object_Field_Struct_State_Class>(name);
    }

    template <typename T>
    static T* GetObjectCasted(std::size_t index) {
        return static_cast<T*>(GetGlobalObjects().GetByIndex(index));
    }

    bool IsA(UClass_Object_Field_Struct_State_Class* cmp);

    void ProcessEvent(class UClass_Object_Field_Struct_Function* fn, void* params);

    inline bool IsValid() const {
        bool res = this != nullptr;
        if (!res)
            return false;
        try {
            int index = this->InternalIndex;
            if (index < 0 || index > GetGlobalObjects().Num())
                return false;
        } catch (...) {
            return false;
        }
        return res;
    }
};
}  // namespace SDK

#ifdef _MSC_VER
#pragma pack(pop)
#endif
