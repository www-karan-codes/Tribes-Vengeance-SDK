#pragma once

#ifdef _MSC_VER
#pragma pack(push, 0x1)
#endif

#include <math.h>

namespace SDK {

typedef uint8_t EMovementState;
typedef uint8_t EObjectiveStatus;
typedef uint8_t EMessageType;
typedef uint8_t ESheerAxis;
typedef uint8_t ERepDataType;
typedef uint8_t EObjectiveType;
typedef uint8_t ESortOrder;
typedef uint8_t ETexMapAxis;
typedef uint8_t EMaterialSequenceAction;
typedef uint8_t EAnimationType;
typedef uint8_t EDigitalAxisInput;
typedef uint8_t EVehiclePositionType;

// Struct Vector
// 0x000C
struct FStruct_Vector {
    float X;  // 0x0000(0x0004) (Edit, Config)
    float Y;  // 0x0004(0x0004) (Edit, Config)
    float Z;  // 0x0008(0x0004) (Edit, Config)

    inline FStruct_Vector() : X(0), Y(0), Z(0) {}

    inline FStruct_Vector(float x, float y, float z) : X(x), Y(y), Z(z) {}

    inline FStruct_Vector operator+(const FStruct_Vector& other) const { return FStruct_Vector(X + other.X, Y + other.Y, Z + other.Z); }

    inline FStruct_Vector operator-(const FStruct_Vector& other) const { return FStruct_Vector(X - other.X, Y - other.Y, Z - other.Z); }

    inline FStruct_Vector operator*(float scalar) const { return FStruct_Vector(X * scalar, Y * scalar, Z * scalar); }

    inline FStruct_Vector operator*(const FStruct_Vector& other) const { return FStruct_Vector(X * other.X, Y * other.Y, Z * other.Z); }

    inline FStruct_Vector operator/(float scalar) const { return FStruct_Vector(X / scalar, Y / scalar, Z / scalar); }

    inline FStruct_Vector operator/(const FStruct_Vector& other) const { return FStruct_Vector(X / other.X, Y / other.Y, Z / other.Z); }

    inline FStruct_Vector& operator=(const FStruct_Vector& other) {
        X = other.X;
        Y = other.Y;
        Z = other.Z;
        return *this;
    }

    inline FStruct_Vector& operator+=(const FStruct_Vector& other) {
        X += other.X;
        Y += other.Y;
        Z += other.Z;
        return *this;
    }

    inline FStruct_Vector& operator-=(const FStruct_Vector& other) {
        X -= other.X;
        Y -= other.Y;
        Z -= other.Z;
        return *this;
    }

    inline FStruct_Vector& operator*=(const float other) {
        X *= other;
        Y *= other;
        Z *= other;
        return *this;
    }

    inline float Dot(const FStruct_Vector& b) const { return (X * b.X) + (Y * b.Y) + (Z * b.Z); }

    inline float MagnitudeSqr() const { return Dot(*this); }

    inline float Magnitude() const { return sqrt(MagnitudeSqr()); }

    inline float MagnitudeXY() const { return sqrt(pow(X, 2) + pow(Y, 2)); }

    inline FStruct_Vector Unit() const {
        const float fMagnitude = Magnitude();
        return FStruct_Vector(X / fMagnitude, Y / fMagnitude, Z / fMagnitude);
    }

    friend bool operator==(const FStruct_Vector& first, const FStruct_Vector& second) { return first.X == second.X && first.Y == second.Y && first.Z == second.Z; }

    friend bool operator!=(const FStruct_Vector& first, const FStruct_Vector& second) { return !(first == second); }

};

// Struct Vector.Plane
// 0x0004 (0x0010 - 0x000C)
struct FStruct_Vector_Plane : public FStruct_Vector {
    float W;  // 0x000C(0x0004) (Edit, Config)
};

// Struct Rotator
// 0x000C
struct FStruct_Rotator {
    int Pitch;  // 0x0000(0x0004) (Edit, Config)
    int Yaw;    // 0x0004(0x0004) (Edit, Config)
    int Roll;   // 0x0008(0x0004) (Edit, Config)
};

// Struct Color
// 0x0004
struct FStruct_Color {
    unsigned char B;  // 0x0000(0x0001) (Edit, Config)
    unsigned char G;  // 0x0001(0x0001) (Edit, Config)
    unsigned char R;  // 0x0002(0x0001) (Edit, Config)
    unsigned char A;  // 0x0003(0x0001) (Edit, Config)
};

// Struct Matrix
// 0x0040
struct FStruct_Matrix {
    struct FStruct_Vector_Plane XPlane;  // 0x0000(0x0010) (Edit)
    struct FStruct_Vector_Plane YPlane;  // 0x0010(0x0010) (Edit)
    struct FStruct_Vector_Plane ZPlane;  // 0x0020(0x0010) (Edit)
    struct FStruct_Vector_Plane WPlane;  // 0x0030(0x0010) (Edit)
};

// Struct Range
// 0x0008
struct FStruct_Range {
    float Min;  // 0x0000(0x0004) (Edit, Config)
    float Max;  // 0x0004(0x0004) (Edit, Config)
};

// Struct InventoryStationCombatRole
// 0x0008
struct FStruct_InventoryStationCombatRole {
    class UClass_Object_Field_Struct_State_Class* combatRoleClass;  // 0x0000(0x0004) (Edit)
    unsigned long bEnabled : 1;                                     // 0x0004(0x0004) (Edit)
};

// Struct InventoryStationWeapon
// 0x0008
struct FStruct_InventoryStationWeapon {
    class UClass_Object_Field_Struct_State_Class* weaponClass;  // 0x0000(0x0004) (Edit)
    unsigned long bEnabled : 1;                                 // 0x0004(0x0004) (Edit)
};

struct FStruct_TerminalConditions {
    char UnknownData[0x10];
};

// Struct InventoryStationPack
// 0x0008
struct FStruct_InventoryStationPack {
    class UClass_Object_Field_Struct_State_Class* packClass;  // 0x0000(0x0004) (Edit)
    unsigned long bEnabled : 1;                               // 0x0004(0x0004) (Edit)
};

// Struct InventoryStationGrenades
// 0x0008
struct FStruct_InventoryStationGrenades {
    class UClass_Object_Field_Struct_State_Class* grenadeClass;  // 0x0000(0x0004) (Edit)
    unsigned long bEnabled : 1;                                  // 0x0004(0x0004) (Edit)
};

// Struct ButtonParams
// 0x0018
struct FStruct_ButtonParams {
    float gutter;              // 0x0000(0x0004) (Edit, Config, NoClear)
    int rows;                  // 0x0004(0x0004) (Edit, Config, NoClear)
    int columns;               // 0x0008(0x0004) (Edit, Config, NoClear)
    struct FString StyleName;  // 0x000C(0x000C) (Edit, Config, NeedCtorLink, NoClear)
};

// Struct MojoActorRef
// 0x0008
struct FStruct_MojoActorRef {
    struct FName Name;                 // 0x0000(0x0004) (Edit)
    class AClass_Object_Actor* Actor;  // 0x0004(0x0004) (Transient)
};

// Struct EventMessage
// 0x0024
struct FStruct_EventMessage {
    struct FString StringOne;                    // 0x0000(0x000C) (NeedCtorLink)
    TEnumAsByte<EMessageType> StringOneType;     // 0x000C(0x0001)
    unsigned char UnknownData00[0x3];            // 0x000D(0x0003) MISSED OFFSET
    struct FString StringTwo;                    // 0x0010(0x000C) (NeedCtorLink)
    TEnumAsByte<EMessageType> StringTwoType;     // 0x001C(0x0001)
    unsigned char UnknownData01[0x3];            // 0x001D(0x0003) MISSED OFFSET
    class UClass_Object_Material* IconMaterial;  // 0x0020(0x0004)
};

// Struct MojoKeyframe
// 0x0018
struct FStruct_MojoKeyframe {
    struct FStruct_Vector Position;   // 0x0000(0x000C) (Edit)
    struct FStruct_Rotator Rotation;  // 0x000C(0x000C) (Edit)
};

// Struct ClientObjectiveInfo
// 0x0024
struct FStruct_ClientObjectiveInfo {
    class UClass_Object_Field_Struct_State_Class* radarInfoClass;  // 0x0000(0x0004)
    struct FString Description;                                    // 0x0004(0x000C) (NeedCtorLink)
    TEnumAsByte<EObjectiveStatus> status;                          // 0x0010(0x0001)
    TEnumAsByte<EObjectiveType> Type;                              // 0x0011(0x0001)
    unsigned char UnknownData00[0x2];                              // 0x0012(0x0002) MISSED OFFSET
    unsigned long bFlashing : 1;                                   // 0x0014(0x0004)
    unsigned char State;                                           // 0x0018(0x0001)
    unsigned char UnknownData01[0x3];                              // 0x0019(0x0003) MISSED OFFSET
    unsigned long IsFriendly : 1;                                  // 0x001C(0x0004)
    class UClass_Object_Field_Struct_State_Class* TeamInfoClass;   // 0x0020(0x0004)
};

// Struct GameData
// 0x0018
struct FStruct_GameData {
    struct FString Name;       // 0x0000(0x000C) (NeedCtorLink)
    struct FString ClassName;  // 0x000C(0x000C) (NeedCtorLink)
};

// Struct GameSpyServerData
// 0x0108
struct FStruct_GameSpyServerData {
    int gsServerId;                         // 0x0000(0x0004)
    struct FString gsIpAddress;             // 0x0004(0x000C) (NeedCtorLink)
    int gsPing;                             // 0x0010(0x0004)
    unsigned long gsLAN : 1;                // 0x0014(0x0004)
    struct FString gsMapName;               // 0x0018(0x000C) (NeedCtorLink)
    struct FString gsNumPlayers;            // 0x0024(0x000C) (NeedCtorLink)
    struct FString gsMaxPlayers;            // 0x0030(0x000C) (NeedCtorLink)
    struct FString gsHostName;              // 0x003C(0x000C) (NeedCtorLink)
    struct FString gsHostPort;              // 0x0048(0x000C) (NeedCtorLink)
    struct FString gsGameType;              // 0x0054(0x000C) (NeedCtorLink)
    struct FString gsGameVer;               // 0x0060(0x000C) (NeedCtorLink)
    struct FString gsRequiresPassword;      // 0x006C(0x000C) (NeedCtorLink)
    struct FString gsTeamOneName;           // 0x0078(0x000C) (NeedCtorLink)
    struct FString gsTeamTwoName;           // 0x0084(0x000C) (NeedCtorLink)
    struct FString gsTeamOneScore;          // 0x0090(0x000C) (NeedCtorLink)
    struct FString gsTeamTwoScore;          // 0x009C(0x000C) (NeedCtorLink)
    struct FString gsAdminName;             // 0x00A8(0x000C) (NeedCtorLink)
    struct FString gsAdminEmail;            // 0x00B4(0x000C) (NeedCtorLink)
    struct FString gsTrackingStats;         // 0x00C0(0x000C) (NeedCtorLink)
    struct FString gsMinVersion;            // 0x00CC(0x000C) (NeedCtorLink)
    TArray<struct FString> gsPlayerNames;   // 0x00D8(0x000C) (NeedCtorLink)
    TArray<struct FString> gsPlayerScores;  // 0x00E4(0x000C) (NeedCtorLink)
    TArray<struct FString> gsPlayerPings;   // 0x00F0(0x000C) (NeedCtorLink)
    TArray<struct FString> gsPlayerTeams;   // 0x00FC(0x000C) (NeedCtorLink)
};

// Struct ClientObjectiveActorInfo
// 0x0028
struct FStruct_ClientObjectiveActorInfo {
    unsigned char objectiveDataIndex;                             // 0x0000(0x0001)
    unsigned char UnknownData00[0x3];                             // 0x0001(0x0003) MISSED OFFSET
    unsigned long IsFriendly : 1;                                 // 0x0004(0x0004)
    class UClass_Object_Field_Struct_State_Class* TeamInfoClass;  // 0x0008(0x0004)
    float XPosition;                                              // 0x000C(0x0004)
    float YPosition;                                              // 0x0010(0x0004)
    float Distance;                                               // 0x0014(0x0004)
    int height;                                                   // 0x0018(0x0004)
    int ScreenX;                                                  // 0x001C(0x0004)
    int ScreenY;                                                  // 0x0020(0x0004)
    unsigned long bFlashing : 1;                                  // 0x0024(0x0004)
};

// Struct POIInfo
// 0x001C
struct FStruct_POIInfo {
    class UClass_Object_Field_Struct_State_Class* radarInfoClass;  // 0x0000(0x0004)
    struct FStruct_Vector Location;                                // 0x0004(0x000C)
    struct FString LabelText;                                      // 0x0010(0x000C) (NeedCtorLink)
};

// Struct AircraftState
// 0x0024
struct FStruct_AircraftState {
    struct FStruct_Vector Position;                 // 0x0000(0x000C)
    struct FStruct_Vector Velocity;                 // 0x000C(0x000C)
    int flightAngles;                               // 0x0018(0x0004)
    unsigned long serverThrusting : 1;              // 0x001C(0x0004)
    unsigned long serverDiving : 1;                 // 0x001C(0x0004)
    TEnumAsByte<EDigitalAxisInput> serverStrafe;    // 0x0020(0x0001)
    TEnumAsByte<EDigitalAxisInput> serverThrottle;  // 0x0021(0x0001)
    unsigned char UnknownData00[0x2];               // 0x0022(0x0002) MISSED OFFSET
};

// Struct MutatorRecord
// 0x0038
struct FStruct_MutatorRecord {
    struct FString ClassName;                                // 0x0000(0x000C) (Edit, NeedCtorLink)
    class UClass_Object_Field_Struct_State_Class* mutClass;  // 0x000C(0x0004) (Edit)
    struct FString GroupName;                                // 0x0010(0x000C) (Edit, NeedCtorLink)
    struct FString FriendlyName;                             // 0x001C(0x000C) (Edit, Localized, NeedCtorLink)
    struct FString Description;                              // 0x0028(0x000C) (Edit, Localized, NeedCtorLink)
    unsigned char bActivated;                                // 0x0034(0x0001) (Edit)
    unsigned char UnknownData00[0x3];                        // 0x0035(0x0003) MISSED OFFSET
};

// Struct SkinPreferenceMapping
// 0x0010
struct FStruct_SkinPreferenceMapping {
    class UClass_Object_Primitive_Mesh* Mesh;  // 0x0000(0x0004) (Config)
    struct FString Skin;                       // 0x0004(0x000C) (Config, NeedCtorLink)
};

// Struct HUDLocalizedMessage
// 0x0044
struct FStruct_HUDLocalizedMessage {
    class UClass_Object_Field_Struct_State_Class* Message;  // 0x0000(0x0004)
    int Switch;                                             // 0x0004(0x0004)
    class UClass_Object* Related1;                          // 0x0008(0x0004)
    class UClass_Object* Related2;                          // 0x000C(0x0004)
    class UClass_Object* OptionalObject;                    // 0x0010(0x0004)
    float EndOfLife;                                        // 0x0014(0x0004)
    float lifetime;                                         // 0x0018(0x0004)
    unsigned long bDrawing : 1;                             // 0x001C(0x0004)
    int numLines;                                           // 0x0020(0x0004)
    struct FString StringMessage;                           // 0x0024(0x000C) (NeedCtorLink)
    struct FStruct_Color DrawColor;                         // 0x0030(0x0004)
    class UClass_Object_Font* StringFont;                   // 0x0034(0x0004)
    float XL;                                               // 0x0038(0x0004)
    float YL;                                               // 0x003C(0x0004)
    float YPos;                                             // 0x0040(0x0004)
};

// Struct Particle
// 0x00C8
struct FStruct_Particle {
    struct FStruct_Vector Location;               // 0x0000(0x000C)
    struct FStruct_Vector OldLocation;            // 0x000C(0x000C)
    struct FStruct_Vector Velocity;               // 0x0018(0x000C)
    struct FStruct_Vector StartSize;              // 0x0024(0x000C)
    struct FStruct_Vector SpinsPerSecond;         // 0x0030(0x000C)
    struct FStruct_Vector StartSpin;              // 0x003C(0x000C)
    struct FStruct_Vector RevolutionCenter;       // 0x0048(0x000C)
    struct FStruct_Vector RevolutionsPerSecond;   // 0x0054(0x000C)
    struct FStruct_Vector RevolutionsMultiplier;  // 0x0060(0x000C)
    struct FStruct_Vector Size;                   // 0x006C(0x000C)
    struct FStruct_Vector StartLocation;          // 0x0078(0x000C)
    struct FStruct_Vector ColorMultiplier;        // 0x0084(0x000C)
    struct FStruct_Vector VelocityMultiplier;     // 0x0090(0x000C)
    struct FStruct_Vector OldMeshLocation;        // 0x009C(0x000C)
    struct FStruct_Color Color;                   // 0x00A8(0x0004)
    float Time;                                   // 0x00AC(0x0004)
    float MaxLifetime;                            // 0x00B0(0x0004)
    float Mass;                                   // 0x00B4(0x0004)
    int HitCount;                                 // 0x00B8(0x0004)
    int flags;                                    // 0x00BC(0x0004)
    int Subdivision;                              // 0x00C0(0x0004)
    int BoneIndex;                                // 0x00C4(0x0004)
};

// Struct StaticMeshProjectorRenderInfoPtr
// 0x0004
struct FStruct_StaticMeshProjectorRenderInfoPtr {
    int Ptr;  // 0x0000(0x0004)
};

// Struct HUDPositionData
// 0x0018
struct FStruct_HUDPositionData {
    int posX;                             // 0x0000(0x0004)
    int posY;                             // 0x0004(0x0004)
    unsigned long bOccupiedByPlayer : 1;  // 0x0008(0x0004)
    unsigned long bOccupied : 1;          // 0x0008(0x0004)
    unsigned long bNotLabelled : 1;       // 0x0008(0x0004)
    struct FString SwitchHotKey;          // 0x000C(0x000C) (NeedCtorLink)
};

// Struct AnimRep
// 0x000C
struct FStruct_AnimRep {
    struct FName AnimSequence;         // 0x0000(0x0004)
    unsigned long bAnimLoop : 1;       // 0x0004(0x0004)
    unsigned char AnimRate;            // 0x0008(0x0001)
    unsigned char AnimFrame;           // 0x0009(0x0001)
    unsigned char TweenRate;           // 0x000A(0x0001)
    unsigned char UnknownData00[0x1];  // 0x000B(0x0001) MISSED OFFSET
};

// Struct QuantityWeapon
// 0x0008
struct FStruct_QuantityWeapon {
    class UClass_Object_Field_Struct_State_Class* typeClass;  // 0x0000(0x0004) (Edit)
    int quantity;                                             // 0x0004(0x0004) (Edit)
};

// Struct QuantityGrenades
// 0x0008
struct FStruct_QuantityGrenades {
    class UClass_Object_Field_Struct_State_Class* typeClass;  // 0x0000(0x0004) (Edit)
    int quantity;                                             // 0x0004(0x0004) (Edit)
};

// Struct TraversalLineCheck
// 0x001C
struct FStruct_TraversalLineCheck {
    struct FStruct_Vector Start;  // 0x0000(0x000C)
    struct FStruct_Vector End;    // 0x000C(0x000C)
    struct FStruct_Color colour;  // 0x0018(0x0004)
};

// Struct Quat
// 0x0010
struct FStruct_Quat {
    float X;  // 0x0000(0x0004) (Edit, Config)
    float Y;  // 0x0004(0x0004) (Edit, Config)
    float Z;  // 0x0008(0x0004) (Edit, Config)
    float W;  // 0x000C(0x0004) (Edit, Config)
};

// Struct QuantityDeployable
// 0x0008
struct FStruct_QuantityDeployable {
    class UClass_Object_Field_Struct_State_Class* typeClass;  // 0x0000(0x0004) (Edit)
    int quantity;                                             // 0x0004(0x0004) (Edit)
};

// Struct QuantityConsumable
// 0x0008
struct FStruct_QuantityConsumable {
    class UClass_Object_Field_Struct_State_Class* typeClass;  // 0x0000(0x0004) (Edit)
    int quantity;                                             // 0x0004(0x0004) (Edit)
};

// Struct HUDMessage
// 0x0010
struct FStruct_HUDMessage {
    struct FString Text;               // 0x0000(0x000C) (NeedCtorLink)
    TEnumAsByte<EMessageType> Type;    // 0x000C(0x0001)
    unsigned char UnknownData00[0x3];  // 0x000D(0x0003) MISSED OFFSET
};

// Struct TerrainMaterialLayer
// 0x0048
struct FStruct_TerrainMaterialLayer {
    class UClass_Object_Material* Texture;                                      // 0x0000(0x0004)
    class UClass_Object_Material_RenderedMaterial_BitmapMaterial* AlphaWeight;  // 0x0004(0x0004)
    struct FStruct_Matrix TextureMatrix;                                        // 0x0008(0x0040)
};

// Struct SpawnPointData
// 0x001C
struct FStruct_SpawnPointData {
    unsigned long bValid : 1;                  // 0x0000(0x0004)
    struct FString SpawnPointName;             // 0x0004(0x000C) (NeedCtorLink)
    struct FStruct_Vector SpawnPointLocation;  // 0x0010(0x000C)
};

// Struct HUDWeaponInfo
// 0x0024
struct FStruct_HUDWeaponInfo {
    class UClass_Object_Field_Struct_State_Class* Type;  // 0x0000(0x0004)
    int Ammo;                                            // 0x0004(0x0004)
    struct FString HotKey;                               // 0x0008(0x000C) (NeedCtorLink)
    unsigned long bCanFire : 1;                          // 0x0014(0x0004)
    float refireTime;                                    // 0x0018(0x0004)
    float timeSinceLastFire;                             // 0x001C(0x0004)
    float Spread;                                        // 0x0020(0x0004)
};

// Struct MarkerData
// 0x0018
struct FStruct_MarkerData {
    class UClass_Object_Field_Struct_State_Class* Type;  // 0x0000(0x0004)
    int ScreenX;                                         // 0x0004(0x0004)
    int ScreenY;                                         // 0x0008(0x0004)
    unsigned char State;                                 // 0x000C(0x0001)
    unsigned char UnknownData00[0x3];                    // 0x000D(0x0003) MISSED OFFSET
    unsigned long Friendly : 1;                          // 0x0010(0x0004)
    class UClass_Object_Field_Struct_State_Class* Team;  // 0x0014(0x0004)
};

// Struct HavokRigidBodyState
// 0x0034
struct FStruct_HavokRigidBodyState {
    struct FStruct_Vector Position;  // 0x0000(0x000C)
    struct FStruct_Quat Quaternion;  // 0x000C(0x0010)
    struct FStruct_Vector LinVel;    // 0x001C(0x000C)
    struct FStruct_Vector AngVel;    // 0x0028(0x000C)
};

// Struct Coords
// 0x0030
struct FStruct_Coords {
    struct FStruct_Vector Origin;  // 0x0000(0x000C) (Edit, Config)
    struct FStruct_Vector XAxis;   // 0x000C(0x000C) (Edit, Config)
    struct FStruct_Vector YAxis;   // 0x0018(0x000C) (Edit, Config)
    struct FStruct_Vector ZAxis;   // 0x0024(0x000C) (Edit, Config)
};

// Struct ActorRenderDataPtr
// 0x0004
struct FStruct_ActorRenderDataPtr {
    int Ptr;  // 0x0000(0x0004)
};

// Struct LightRenderDataPtr
// 0x0004
struct FStruct_LightRenderDataPtr {
    int Ptr;  // 0x0000(0x0004)
};

// Struct BatchReference
// 0x0008
struct FStruct_BatchReference {
    int BatchIndex;    // 0x0000(0x0004)
    int ElementIndex;  // 0x0004(0x0004)
};

// Struct PointRegion
// 0x000C
struct FStruct_PointRegion {
    class AClass_Object_Actor_Info_ZoneInfo* Zone;  // 0x0000(0x0004)
    int iLeaf;                                      // 0x0004(0x0004)
    unsigned char ZoneNumber;                       // 0x0008(0x0001)
    unsigned char UnknownData00[0x3];               // 0x0009(0x0003) MISSED OFFSET
};

// Struct Box
// 0x001C
struct FStruct_Box {
    struct FStruct_Vector Min;         // 0x0000(0x000C)
    struct FStruct_Vector Max;         // 0x000C(0x000C)
    unsigned char IsValid;             // 0x0018(0x0001)
    unsigned char UnknownData00[0x3];  // 0x0019(0x0003) MISSED OFFSET
};

// Struct ProjectorRenderInfoPtr
// 0x0004
struct FStruct_ProjectorRenderInfoPtr {
    int Ptr;  // 0x0000(0x0004)
};

// Struct ConsoleMessage
// 0x0018
struct FStruct_ConsoleMessage {
    struct FString Text;                                                        // 0x0000(0x000C) (NeedCtorLink)
    struct FStruct_Color TextColor;                                             // 0x000C(0x0004)
    float MessageLife;                                                          // 0x0010(0x0004)
    class AClass_Object_Actor_Info_ReplicationInfo_PlayerReplicationInfo* PRI;  // 0x0014(0x0004)
};

// Struct TagBindingMap
// 0x0024
struct FStruct_TagBindingMap {
    struct FString Tag;          // 0x0000(0x000C) (NeedCtorLink)
    struct FString BindingText;  // 0x000C(0x000C) (NeedCtorLink)
    struct FString BoundKey;     // 0x0018(0x000C) (NeedCtorLink)
};

// Struct NormalPair
// 0x0018
struct FStruct_NormalPair {
    struct FStruct_Vector Normal1;  // 0x0000(0x000C)
    struct FStruct_Vector Normal2;  // 0x000C(0x000C)
};

// Struct ControlSpec
// 0x0018
struct FStruct_ControlSpec {
    struct FString ClassName;  // 0x0000(0x000C) (Edit, Config, NeedCtorLink, NoClear)
    struct FString ObjName;    // 0x000C(0x000C) (Edit, Config, NeedCtorLink, NoClear)
};

// Struct SpeakerRef
// 0x000C
struct FStruct_SpeakerRef {
    class AClass_Object_Actor_Pawn_Rook_Ragdoll_Character* Character;           // 0x0000(0x0004)
    class AClass_Object_Actor_Info_ReplicationInfo_PlayerReplicationInfo* PRI;  // 0x0004(0x0004)
    unsigned long bAnnouncer : 1;                                               // 0x0008(0x0004)
};

// Struct baseDeviceStat
// 0x0008
struct FStruct_baseDeviceStat {
    class UClass_Object_Field_Struct_State_Class* statClass;        // 0x0000(0x0004) (Edit)
    class UClass_Object_Field_Struct_State_Class* baseDeviceClass;  // 0x0004(0x0004) (Edit)
};

// Struct SpeechPoolMap
// 0x0010
struct FStruct_SpeechPoolMap {
    struct FName Tag;     // 0x0000(0x0004)
    struct FString File;  // 0x0004(0x000C) (NeedCtorLink)
};

// Struct ParticleSound
// 0x0028
struct FStruct_ParticleSound {
    class UClass_Object_Sound* Sound;  // 0x0000(0x0004) (Edit)
    struct FStruct_Range Radius;       // 0x0004(0x0008) (Edit)
    struct FStruct_Range Pitch;        // 0x000C(0x0008) (Edit)
    int Weight;                        // 0x0014(0x0004) (Edit)
    struct FStruct_Range Volume;       // 0x0018(0x0008) (Edit)
    struct FStruct_Range Probability;  // 0x0020(0x0008) (Edit)
};

// Struct sMoveGroup
// 0x000C
struct FStruct_sMoveGroup {
    TArray<class UClass_Object_GUI_GUIComponent*> CtrlGroup;  // 0x0000(0x000C) (Edit, EditConst, NeedCtorLink, NoClear, EditInline)
};

// Struct MissionInfo
// 0x0040
struct FStruct_MissionInfo {
    struct FString startCutsceneMap;   // 0x0000(0x000C) (Edit, NeedCtorLink)
    struct FString startCutsceneName;  // 0x000C(0x000C) (Edit, NeedCtorLink)
    struct FString endCutsceneMap;     // 0x0018(0x000C) (Edit, NeedCtorLink)
    struct FString endCutsceneName;    // 0x0024(0x000C) (Edit, NeedCtorLink)
    struct FString MapName;            // 0x0030(0x000C) (Edit, NeedCtorLink)
    unsigned long bPersist : 1;        // 0x003C(0x0004) (Edit)
};

// Struct DecorationLayerData
// 0x000C
struct FStruct_DecorationLayerData {
    TArray<struct FStruct_DecoSectorInfo> Sectors;  // 0x0000(0x000C) (NeedCtorLink)
};

// Struct HavokCharacterObjectInteractionEvent
// 0x0030
struct FStruct_HavokCharacterObjectInteractionEvent {
    struct FStruct_Vector Position;   // 0x0000(0x000C)
    struct FStruct_Vector Normal;     // 0x000C(0x000C)
    float ObjectImpulse;              // 0x0018(0x0004)
    float Timestep;                   // 0x001C(0x0004)
    float ProjectedVelocity;          // 0x0020(0x0004)
    float ObjectMassInv;              // 0x0024(0x0004)
    float CharacterMassInv;           // 0x0028(0x0004)
    class AClass_Object_Actor* Body;  // 0x002C(0x0004)
};

// Struct HavokCharacterObjectInteractionResult
// 0x0024
struct FStruct_HavokCharacterObjectInteractionResult {
    struct FStruct_Vector ObjectImpulse;     // 0x0000(0x000C)
    struct FStruct_Vector ImpulsePosition;   // 0x000C(0x000C)
    struct FStruct_Vector CharacterImpulse;  // 0x0018(0x000C)
};

// Struct CompressedPosition
// 0x0024
struct FStruct_CompressedPosition {
    struct FStruct_Vector Location;   // 0x0000(0x000C)
    struct FStruct_Rotator Rotation;  // 0x000C(0x000C)
    struct FStruct_Vector Velocity;   // 0x0018(0x000C)
};

// Struct DamageComponent
// 0x000C
struct FStruct_DamageComponent {
    class UClass_Object_Field_Struct_State_Class* objectType;            // 0x0000(0x0004) (Edit, NoClear)
    struct FName attachmentPoint;                                        // 0x0004(0x0004) (Edit, NoClear)
    class AClass_Object_Actor_HavokActor_DynamicObject* objectInstance;  // 0x0008(0x0004)
};

// Struct MatCoords
// 0x0010
struct FStruct_MatCoords {
    float U;   // 0x0000(0x0004) (Edit, Config)
    float V;   // 0x0004(0x0004) (Edit, Config)
    float UL;  // 0x0008(0x0004) (Edit, Config)
    float VL;  // 0x000C(0x0004) (Edit, Config)
};

// Struct HavokCarryableReplicationState
// 0x0038
struct FStruct_HavokCarryableReplicationState {
    struct FStruct_Vector Position;  // 0x0000(0x000C)
    struct FStruct_Quat Rotation;    // 0x000C(0x0010)
    struct FStruct_Vector LinVel;    // 0x001C(0x000C)
    struct FStruct_Vector AngVel;    // 0x0028(0x000C)
    unsigned long bNewState : 1;     // 0x0034(0x0004)
};

// Struct DesiredHavokState
// 0x0038
struct FStruct_DesiredHavokState {
    struct FStruct_Vector Velocity;         // 0x0000(0x000C)
    struct FStruct_Vector angularVelocity;  // 0x000C(0x000C)
    struct FStruct_Vector Position;         // 0x0018(0x000C)
    struct FStruct_Quat Rotation;           // 0x0024(0x0010)
    unsigned long ignoreRotation : 1;       // 0x0034(0x0004)
    unsigned long NewState : 1;             // 0x0034(0x0004)
};

// Struct DynamicTurretRotationProcessingOutput
// 0x0018
struct FStruct_DynamicTurretRotationProcessingOutput {
    struct FStruct_Rotator worldSpaceNoRollRotation;  // 0x0000(0x000C)
    struct FStruct_Rotator vehicleSpaceRotation;      // 0x000C(0x000C)
};

// Struct HavokCarState
// 0x004C
struct FStruct_HavokCarState {
    struct FStruct_HavokRigidBodyState ChassisState;  // 0x0000(0x0034)
    float ServerHandbrake;                            // 0x0034(0x0004)
    float ServerBrake;                                // 0x0038(0x0004)
    float ServerGas;                                  // 0x003C(0x0004)
    int ServerGear;                                   // 0x0040(0x0004)
    float ServerSteering;                             // 0x0044(0x0004)
    int bNewState;                                    // 0x0048(0x0004)
};

// Struct MaterialDef
// 0x0024
struct FStruct_MaterialDef {
    class UClass_Object_Material* Material;  // 0x0000(0x0004) (Edit, Config)
    struct FStruct_MatCoords Coords;         // 0x0004(0x0010) (Edit, Config)
    struct FStruct_Color DrawColor;          // 0x0014(0x0004) (Edit, Config)
    float Alpha;                             // 0x0018(0x0004) (Edit, Config)
    unsigned long bFlashing : 1;             // 0x001C(0x0004) (Edit, Config, NoClear)
    float flashFrequency;                    // 0x0020(0x0004) (Edit, Config, NoClear)
};

// Struct SCreateTeamData
// 0x0034
struct FStruct_SCreateTeamData {
    struct FString ProfilePassword;  // 0x0000(0x000C) (NeedCtorLink)
    struct FString teamTag;          // 0x000C(0x000C) (NeedCtorLink)
    struct FString teamName;         // 0x0018(0x000C) (NeedCtorLink)
    struct FString TeamPassword;     // 0x0024(0x000C) (NeedCtorLink)
    int TeamID;                      // 0x0030(0x0004)
};

// Struct DeployableInfo
// 0x0008
struct FStruct_DeployableInfo {
    class UClass_Object_Field_Struct_State_Class* deployableClass;  // 0x0000(0x0004) (Edit, NoClear)
    int Amount;                                                     // 0x0004(0x0004) (Edit, NoClear)
};

// Struct WeaponInfo
// 0x0008
struct FStruct_WeaponInfo {
    class UClass_Object_Field_Struct_State_Class* weaponClass;  // 0x0000(0x0004) (Edit)
    int Ammo;                                                   // 0x0004(0x0004) (Edit, NoClear)
};

// Struct GrenadeInfo
// 0x0008
struct FStruct_GrenadeInfo {
    class UClass_Object_Field_Struct_State_Class* grenadeClass;  // 0x0000(0x0004) (Edit)
    int Ammo;                                                    // 0x0004(0x0004) (Edit, NoClear)
};

// Struct ConsumableInfo
// 0x0008
struct FStruct_ConsumableInfo {
    class UClass_Object_Field_Struct_State_Class* consumableClass;  // 0x0000(0x0004) (Edit)
    int Amount;                                                     // 0x0004(0x0004) (Edit)
};

// Struct DifficultyData
// 0x000C
struct FStruct_DifficultyData {
    float aiLeadAbilityMultiplier;  // 0x0000(0x0004) (Edit, Config)
    float aiHealthMultiplier;       // 0x0004(0x0004) (Edit, Config)
    float playerHealthMultiplier;   // 0x0008(0x0004) (Edit, Config)
};

// Struct serverFilter
// 0x0018
struct FStruct_serverFilter {
    struct FString filterName;   // 0x0000(0x000C) (Config, NeedCtorLink)
    struct FString queryString;  // 0x000C(0x000C) (Config, NeedCtorLink)
};

// Struct TurretEntryData
// 0x000C
struct FStruct_TurretEntryData {
    float Radius;                                                    // 0x0000(0x0004) (Edit)
    float height;                                                    // 0x0004(0x0004) (Edit)
    class UClass_Object_Field_Struct_State_Class* turretEntryClass;  // 0x0008(0x0004) (Edit)
};

// Struct RoleData
// 0x001C
struct FStruct_RoleData {
    class UClass_Object_Field_Struct_State_Class* Role;           // 0x0000(0x0004) (Edit, NoClear)
    class UClass_Object_Primitive_Mesh* Mesh;                     // 0x0004(0x0004) (Edit, NoClear)
    class UClass_Object_Primitive_Mesh* femaleMesh;               // 0x0008(0x0004) (Edit, NoClear)
    class UClass_Object_Field_Struct_State_Class* jetpack;        // 0x000C(0x0004) (Edit, NoClear)
    class UClass_Object_Field_Struct_State_Class* femaleJetpack;  // 0x0010(0x0004) (Edit, NoClear)
    class UClass_Object_Primitive_Mesh* armsMesh;                 // 0x0014(0x0004) (Edit, NoClear)
    class UClass_Object_Material* armorIcon;                      // 0x0018(0x0004) (Edit, NoClear)
};

// Struct GUIListElem
// 0x0024
struct FStruct_GUIListElem {
    struct FString Item;              // 0x0000(0x000C) (NeedCtorLink)
    class UClass_Object* ExtraData;   // 0x000C(0x0004)
    struct FString ExtraStrData;      // 0x0010(0x000C) (NeedCtorLink)
    int ExtraIntData;                 // 0x001C(0x0004)
    unsigned long ExtraBoolData : 1;  // 0x0020(0x0004)
};

// Struct FindPathAIProperties
// 0x0010
struct FStruct_FindPathAIProperties {
    unsigned long jetpack : 1;    // 0x0000(0x0004)
    unsigned long Airborne : 1;   // 0x0000(0x0004)
    unsigned long roadBased : 1;  // 0x0000(0x0004)
    struct FName teamName;        // 0x0004(0x0004)
    float upCostFactor;           // 0x0008(0x0004)
    float downCostFactor;         // 0x000C(0x0004)
};

// Struct RouteCacheElement
// 0x0020
struct FStruct_RouteCacheElement {
    struct FStruct_Vector Location;       // 0x0000(0x000C)
    unsigned long jetpack : 1;            // 0x000C(0x0004)
    float energy;                         // 0x0010(0x0004)
    class AClass_Object_Actor* obstacle;  // 0x0014(0x0004)
    float height;                         // 0x0018(0x0004)
    float Angle;                          // 0x001C(0x0004)
};

// Struct InventoryStationLoadout
// 0x007C
struct FStruct_InventoryStationLoadout {
    struct FStruct_InventoryStationCombatRole Role;      // 0x0000(0x0008)
    struct FStruct_InventoryStationWeapon weapons[0xA];  // 0x0008(0x0008)
    int activeWeaponSlot;                                // 0x0058(0x0004)
    struct FStruct_InventoryStationPack Pack;            // 0x005C(0x0008)
    struct FStruct_InventoryStationGrenades grenades;    // 0x0064(0x0008)
    unsigned long NoLoadout : 1;                         // 0x006C(0x0004)
    struct FString userSkin;                             // 0x0070(0x000C) (NeedCtorLink)
};

// Struct ClientAdjustment
// 0x0038
struct FStruct_ClientAdjustment {
    float TimeStamp;                       // 0x0000(0x0004)
    float Accumulator;                     // 0x0004(0x0004)
    float energy;                          // 0x0008(0x0004)
    struct FName NewState;                 // 0x000C(0x0004)
    TEnumAsByte<EMovementState> Movement;  // 0x0010(0x0001)
    unsigned char UnknownData00[0x3];      // 0x0011(0x0003) MISSED OFFSET
    struct FStruct_Vector startLoc;        // 0x0014(0x000C)
    struct FStruct_Vector EndLoc;          // 0x0020(0x000C)
    struct FStruct_Vector newVel;          // 0x002C(0x000C)
};

// Struct RangeVector
// 0x0018
struct FStruct_RangeVector {
    struct FStruct_Range X;  // 0x0000(0x0008) (Edit, Config)
    struct FStruct_Range Y;  // 0x0008(0x0008) (Edit, Config)
    struct FStruct_Range Z;  // 0x0010(0x0008) (Edit, Config)
};

// Struct QuickChatInfo
// 0x0010
struct FStruct_QuickChatInfo {
    unsigned long bSwitch : 1;  // 0x0000(0x0004)
    struct FString TagID;       // 0x0004(0x000C) (NeedCtorLink)
};

// Struct ParticleBeamScale
// 0x0010
struct FStruct_ParticleBeamScale {
    struct FStruct_Vector FrequencyScale;  // 0x0000(0x000C) (Edit)
    float RelativeLength;                  // 0x000C(0x0004) (Edit)
};

// Struct DynamicMusicOptions
// 0x000C
struct FStruct_DynamicMusicOptions {
    float FadeInTime;   // 0x0000(0x0004) (Edit)
    float FadeOutTime;  // 0x0004(0x0004) (Edit)
    float MinLifetime;  // 0x0008(0x0004) (Edit)
};

// Struct extendedProjectileDamageStat
// 0x0008
struct FStruct_extendedProjectileDamageStat {
    class UClass_Object_Field_Struct_State_Class* damageTypeClass;    // 0x0000(0x0004) (Edit)
    class UClass_Object_Field_Struct_State_Class* extendedStatClass;  // 0x0004(0x0004) (Edit)
};

// Struct QueueElement
// 0x0014
struct FStruct_QueueElement {
    class AClass_Object_Actor_Pawn_Rook_Ragdoll_Character* Character;                         // 0x0000(0x0004)
    class AClass_Object_Actor_UseableObject_BaseDeviceAccess_InventoryStationAccess* access;  // 0x0004(0x0004)
    int accessIndex;                                                                          // 0x0008(0x0004)
    int extensionIndex;                                                                       // 0x000C(0x0004)
    unsigned long accessible : 1;                                                             // 0x0010(0x0004)
};

// Struct ParticleTrailInfo
// 0x0014
struct FStruct_ParticleTrailInfo {
    int TrailIndex;                      // 0x0000(0x0004)
    int NumPoints;                       // 0x0004(0x0004)
    struct FStruct_Vector LastLocation;  // 0x0008(0x000C)
};

// Struct TreadVehicleReplicationState
// 0x003C
struct FStruct_TreadVehicleReplicationState {
    struct FStruct_Vector Position;                       // 0x0000(0x000C)
    struct FStruct_Quat Rotation;                         // 0x000C(0x0010)
    struct FStruct_Vector LinVel;                         // 0x001C(0x000C)
    struct FStruct_Vector AngVel;                         // 0x0028(0x000C)
    TEnumAsByte<EDigitalAxisInput> digitalThrottleInput;  // 0x0034(0x0001)
    TEnumAsByte<EDigitalAxisInput> digitalStrafeInput;    // 0x0035(0x0001)
    unsigned char ServerSteering[0x2];                    // 0x0036(0x0001)
    unsigned long ServerGripping : 1;                     // 0x0038(0x0004)
    unsigned long softThrottleSteering : 1;               // 0x0038(0x0004)
};

// Struct ClientOccupantEnterData
// 0x0010
struct FStruct_ClientOccupantEnterData {
    class AClass_Object_Actor_Controller* Controller;                 // 0x0000(0x0004)
    class AClass_Object_Actor_Pawn_Rook_Ragdoll_Character* occupant;  // 0x0004(0x0004)
    unsigned char positionIndex;                                      // 0x0008(0x0001)
    unsigned char UnknownData00[0x3];                                 // 0x0009(0x0003) MISSED OFFSET
    unsigned long newData : 1;                                        // 0x000C(0x0004)
    unsigned long flipFlop : 1;                                       // 0x000C(0x0004)
};

// Struct VehiclePosition
// 0x006C
struct FStruct_VehiclePosition {
    TEnumAsByte<EVehiclePositionType> Type;                                    // 0x0000(0x0001)
    unsigned char UnknownData00[0x3];                                          // 0x0001(0x0003) MISSED OFFSET
    class AClass_Object_Actor_Pawn_Rook_Ragdoll_Character* occupant;           // 0x0004(0x0004)
    unsigned long wantsToGetOut : 1;                                           // 0x0008(0x0004)
    unsigned long hideOccupant : 1;                                            // 0x0008(0x0004)
    unsigned long thirdPersonCamera : 1;                                       // 0x0008(0x0004)
    unsigned long lookAtInheritPitch : 1;                                      // 0x0008(0x0004)
    class AClass_Object_Actor_Pawn_Rook* toBePossessed;                        // 0x000C(0x0004)
    struct FName occupantControllerState;                                      // 0x0010(0x0004)
    struct FStruct_Vector firstPersonCameraLocation;                           // 0x0014(0x000C)
    struct FStruct_Vector firstPersonWeaponLocation;                           // 0x0020(0x000C)
    struct FName enterAnimation;                                               // 0x002C(0x0004)
    struct FName exitAnimation;                                                // 0x0030(0x0004)
    struct FName occupiedAnimation;                                            // 0x0034(0x0004)
    struct FName unoccupiedAnimation;                                          // 0x0038(0x0004)
    class AClass_Object_Actor_Equipment_Equippable_Weapon* oldOccupantWeapon;  // 0x003C(0x0004)
    struct FStruct_Vector occupantRelativeLocation;                            // 0x0040(0x000C)
    struct FStruct_Rotator occupantRelativeRotation;                           // 0x004C(0x000C)
    int ManifestXPosition;                                                     // 0x0058(0x0004) (Edit, NoClear)
    int ManifestYPosition;                                                     // 0x005C(0x0004) (Edit, NoClear)
    unsigned long bNotLabelledInManifest : 1;                                  // 0x0060(0x0004) (Edit, NoClear)
    struct FName occupantConnection;                                           // 0x0064(0x0004)
    struct FName occupantAnimation;                                            // 0x0068(0x0004) (Edit)
};

// Struct VehicleEntryData
// 0x0028
struct FStruct_VehicleEntryData {
    float Radius;                                                  // 0x0000(0x0004) (Edit)
    float height;                                                  // 0x0004(0x0004) (Edit)
    struct FStruct_Vector Offset;                                  // 0x0008(0x000C) (Edit)
    TEnumAsByte<EVehiclePositionType> primaryPosition;             // 0x0014(0x0001) (Edit)
    unsigned char UnknownData00[0x3];                              // 0x0015(0x0003) MISSED OFFSET
    TArray<TEnumAsByte<EVehiclePositionType>> secondaryPositions;  // 0x0018(0x000C) (Edit, NeedCtorLink)
    class UClass_Object_Field_Struct_State_Class* entryClass;      // 0x0024(0x0004) (Edit)
};

// Struct VehicleFlipTriggerData
// 0x0014
struct FStruct_VehicleFlipTriggerData {
    float Radius;                  // 0x0000(0x0004) (Edit)
    float height;                  // 0x0004(0x0004) (Edit)
    struct FStruct_Vector Offset;  // 0x0008(0x000C) (Edit)
};

// Struct ExitData
// 0x0010
struct FStruct_ExitData {
    struct FStruct_Vector Offset;                // 0x0000(0x000C) (Edit)
    TEnumAsByte<EVehiclePositionType> Position;  // 0x000C(0x0001) (Edit)
    unsigned char UnknownData00[0x3];            // 0x000D(0x0003) MISSED OFFSET
};

// Struct ClientPositionData
// 0x0004
struct FStruct_ClientPositionData {
    class AClass_Object_Actor_Pawn_Rook_Ragdoll_Character* occupant;  // 0x0000(0x0004)
};

// Struct VehicleEffect
// 0x000C
struct FStruct_VehicleEffect {
    struct FName EffectName;                                               // 0x0000(0x0004)
    unsigned long Flag : 1;                                                // 0x0004(0x0004)
    class UClass_Object_DeleteableObject_VehicleEffectObserver* Observer;  // 0x0008(0x0004)
};

// Struct LoadoutSlot
// 0x004C
struct FStruct_LoadoutSlot {
    struct FString loadoutName;                                    // 0x0000(0x000C) (Edit, Config, NeedCtorLink)
    struct FString combatRoleClassName;                            // 0x000C(0x000C) (Edit, Config, NeedCtorLink)
    struct FString packClassName;                                  // 0x0018(0x000C) (Edit, Config, NeedCtorLink)
    struct FString grenadeClassName;                               // 0x0024(0x000C) (Edit, Config, NeedCtorLink)
    TArray<struct FString> weaponClassNameList;                    // 0x0030(0x000C) (Edit, Config, NeedCtorLink)
    unsigned long occupied : 1;                                    // 0x003C(0x0004) (Edit, Config)
    TArray<struct FStruct_SkinPreferenceMapping> skinPreferences;  // 0x0040(0x000C) (Edit, Config, NeedCtorLink)
};

// Struct WheelOutput
// 0x000C
struct FStruct_WheelOutput {
    float skidEnergyDensity;          // 0x0000(0x0004)
    float suspensionLength;           // 0x0004(0x0004)
    unsigned long groundContact : 1;  // 0x0008(0x0004)
};

// Struct HavokCarReplicationState
// 0x003C
struct FStruct_HavokCarReplicationState {
    struct FStruct_Vector Position;                       // 0x0000(0x000C)
    struct FStruct_Quat Rotation;                         // 0x000C(0x0010)
    struct FStruct_Vector LinVel;                         // 0x001C(0x000C)
    struct FStruct_Vector AngVel;                         // 0x0028(0x000C)
    TEnumAsByte<EDigitalAxisInput> digitalThrottleInput;  // 0x0034(0x0001)
    TEnumAsByte<EDigitalAxisInput> digitalStrafeInput;    // 0x0035(0x0001)
    unsigned char ServerSteering[0x2];                    // 0x0036(0x0001)
    unsigned long ServerBoost : 1;                        // 0x0038(0x0004)
    unsigned long ServerHandbrake : 1;                    // 0x0038(0x0004)
};

// Struct RibbonPoint
// 0x0034
struct FStruct_RibbonPoint {
    struct FStruct_Vector Location;              // 0x0000(0x000C) (Edit)
    struct FStruct_Vector AxisNormal;            // 0x000C(0x000C) (Edit)
    float Width;                                 // 0x0018(0x0004) (Edit)
    struct FStruct_Vector Velocity;              // 0x001C(0x000C) (Edit)
    struct FStruct_Vector InterpolatedLocation;  // 0x0028(0x000C) (Edit)
};

// Struct sDynamicPositionSpec
// 0x0018
struct FStruct_sDynamicPositionSpec {
    float WinLeft;         // 0x0000(0x0004) (Edit, Config, NoClear)
    float WinTop;          // 0x0004(0x0004) (Edit, Config, NoClear)
    float WinWidth;        // 0x0008(0x0004) (Edit, Config, NoClear)
    float WinHeight;       // 0x000C(0x0004) (Edit, Config, NoClear)
    float TransitionTime;  // 0x0010(0x0004) (Edit, Config, NoClear)
    struct FName KeyName;  // 0x0014(0x0004) (Edit, Config, NoClear)
};

// Struct sTransitionSpec
// 0x0028
struct FStruct_sTransitionSpec {
    struct FStruct_sDynamicPositionSpec NewPos;  // 0x0000(0x0018) (Edit, EditConst, NoClear)
    float OldWinLeft;                            // 0x0018(0x0004) (Edit, EditConst, NoClear)
    float OldWinTop;                             // 0x001C(0x0004) (Edit, EditConst, NoClear)
    float OldWinWidth;                           // 0x0020(0x0004) (Edit, EditConst, NoClear)
    float OldWinHeight;                          // 0x0024(0x0004) (Edit, EditConst, NoClear)
};

// Struct DecorationType
// 0x0024
struct FStruct_DecorationType {
    class UClass_Object_Primitive_StaticMesh* StaticMesh;  // 0x0000(0x0004) (Edit)
    struct FStruct_Range Count;                            // 0x0004(0x0008) (Edit)
    struct FStruct_Range DrawScale;                        // 0x000C(0x0008) (Edit)
    int bAlign;                                            // 0x0014(0x0004) (Edit)
    int bRandomPitch;                                      // 0x0018(0x0004) (Edit)
    int bRandomYaw;                                        // 0x001C(0x0004) (Edit)
    int bRandomRoll;                                       // 0x0020(0x0004) (Edit)
};

// Struct WeatherPcl
// 0x0030
struct FStruct_WeatherPcl {
    struct FStruct_Vector pos;  // 0x0000(0x000C)
    struct FStruct_Vector Vel;  // 0x000C(0x000C)
    float Life;                 // 0x0018(0x0004)
    float Size;                 // 0x001C(0x0004)
    float HitTime;              // 0x0020(0x0004)
    float InvLifeSpan;          // 0x0024(0x0004)
    float DistAtten;            // 0x0028(0x0004)
    unsigned char frame;        // 0x002C(0x0001)
    unsigned char Dummy1;       // 0x002D(0x0001)
    unsigned char Visible;      // 0x002E(0x0001)
    unsigned char Dummy2;       // 0x002F(0x0001)
};

// Struct sBorderOffset
// 0x0010
struct FStruct_sBorderOffset {
    float LeftOffset;    // 0x0000(0x0004) (Edit, Config, NoClear)
    float RightOffset;   // 0x0004(0x0004) (Edit, Config, NoClear)
    float TopOffset;     // 0x0008(0x0004) (Edit, Config, NoClear)
    float BottomOffset;  // 0x000C(0x0004) (Edit, Config, NoClear)
};

// Struct URL
// 0x0044
struct FStruct_URL {
    struct FString Protocol;    // 0x0000(0x000C) (NeedCtorLink)
    struct FString Host;        // 0x000C(0x000C) (NeedCtorLink)
    int Port;                   // 0x0018(0x0004)
    struct FString Map;         // 0x001C(0x000C) (NeedCtorLink)
    TArray<struct FString> Op;  // 0x0028(0x000C) (NeedCtorLink)
    struct FString Portal;      // 0x0034(0x000C) (NeedCtorLink)
    int Valid;                  // 0x0040(0x0004)
};

// Struct ConnectToElement
// 0x000C
struct FStruct_ConnectToElement {
    struct FName Node;           // 0x0000(0x0004) (Edit)
    unsigned long jetpack : 1;   // 0x0004(0x0004) (Edit)
    struct FName obstacleLabel;  // 0x0008(0x0004) (Edit)
};

// Struct ParameterResolveInfo
// 0x000C
struct FStruct_ParameterResolveInfo {
    class UClass_Object_Action* Action;  // 0x0000(0x0004) (ExportObject)
    struct FName Variable;               // 0x0004(0x0004)
    struct FName PropertyName;           // 0x0008(0x0004)
};

// Struct Scale
// 0x0014
struct FStruct_Scale {
    struct FStruct_Vector Scale;        // 0x0000(0x000C) (Edit, Config)
    float SheerRate;                    // 0x000C(0x0004) (Edit, Config)
    TEnumAsByte<ESheerAxis> SheerAxis;  // 0x0010(0x0001) (Edit, Config)
    unsigned char UnknownData00[0x3];   // 0x0011(0x0003) MISSED OFFSET
};

// Struct PlayInfoData
// 0x0064
struct FStruct_PlayInfoData {
    class UClass_Object_Field_Property* ThisProp;             // 0x0000(0x0004) (Const)
    class UClass_Object_Field_Struct_State_Class* ClassFrom;  // 0x0004(0x0004) (Const)
    struct FString SettingName;                               // 0x0008(0x000C) (Const, NeedCtorLink)
    struct FString DisplayName;                               // 0x0014(0x000C) (Const, NeedCtorLink)
    struct FString RenderType;                                // 0x0020(0x000C) (Const, NeedCtorLink)
    struct FString Grouping;                                  // 0x002C(0x000C) (Const, NeedCtorLink)
    struct FString data;                                      // 0x0038(0x000C) (Const, NeedCtorLink)
    struct FString ExtraPriv;                                 // 0x0044(0x000C) (Const, NeedCtorLink)
    unsigned char SecLevel;                                   // 0x0050(0x0001) (Const)
    unsigned char Weight;                                     // 0x0051(0x0001) (Const)
    unsigned char UnknownData00[0x2];                         // 0x0052(0x0002) MISSED OFFSET
    unsigned long bGlobal : 1;                                // 0x0054(0x0004) (Const)
    struct FString Value;                                     // 0x0058(0x000C) (Const, NeedCtorLink)
};

// Struct FlaggedSound
// 0x0008
struct FStruct_FlaggedSound {
    class UClass_Object_Sound* SoundToPlay;  // 0x0000(0x0004) (Config)
    int Flag;                                // 0x0004(0x0004) (Config)
};

// Struct ParticleSparkData
// 0x0020
struct FStruct_ParticleSparkData {
    float TimeBeforeVisible;              // 0x0000(0x0004)
    float TimeBetweenSegments;            // 0x0004(0x0004)
    struct FStruct_Vector StartLocation;  // 0x0008(0x000C)
    struct FStruct_Vector StartVelocity;  // 0x0014(0x000C)
};

// Struct ParticleColorScale
// 0x0008
struct FStruct_ParticleColorScale {
    float RelativeTime;          // 0x0000(0x0004) (Edit)
    struct FStruct_Color Color;  // 0x0004(0x0004) (Edit)
};

// Struct StaticMeshMaterial
// 0x000C
struct FStruct_StaticMeshMaterial {
    class UClass_Object_Material* Material;  // 0x0000(0x0004) (Edit)
    unsigned long EnableCollision : 1;       // 0x0004(0x0004) (Edit)
    unsigned char UnknownData00[0x4];        // 0x0008(0x0004) MISSED OFFSET
};

// Struct ParticleRevolutionScale
// 0x0010
struct FStruct_ParticleRevolutionScale {
    float RelativeTime;                        // 0x0000(0x0004) (Edit)
    struct FStruct_Vector RelativeRevolution;  // 0x0004(0x000C) (Edit)
};

// Struct ParticleTimeScale
// 0x0008
struct FStruct_ParticleTimeScale {
    float RelativeTime;  // 0x0000(0x0004) (Edit)
    float RelativeSize;  // 0x0004(0x0004) (Edit)
};

// Struct ParticleVelocityScale
// 0x0010
struct FStruct_ParticleVelocityScale {
    float RelativeTime;                      // 0x0000(0x0004) (Edit)
    struct FStruct_Vector RelativeVelocity;  // 0x0004(0x000C) (Edit)
};

// Struct ParticleTrailData
// 0x001C
struct FStruct_ParticleTrailData {
    struct FStruct_Vector Location;  // 0x0000(0x000C)
    struct FStruct_Color Color;      // 0x000C(0x0004)
    float Size;                      // 0x0010(0x0004)
    int DoubleDummy1;                // 0x0014(0x0004)
    int DoubleDummy2;                // 0x0018(0x0004)
};

// Struct TerrainLayer
// 0x0078
struct FStruct_TerrainLayer {
    class UClass_Object_Material* Texture;                                                 // 0x0000(0x0004) (Edit)
    class UClass_Object_Material_RenderedMaterial_BitmapMaterial_Texture* AlphaMap;        // 0x0004(0x0004) (Edit)
    float UScale;                                                                          // 0x0008(0x0004) (Edit)
    float VScale;                                                                          // 0x000C(0x0004) (Edit)
    float UPan;                                                                            // 0x0010(0x0004) (Edit)
    float VPan;                                                                            // 0x0014(0x0004) (Edit)
    TEnumAsByte<ETexMapAxis> TextureMapAxis;                                               // 0x0018(0x0001) (Edit)
    unsigned char UnknownData00[0x3];                                                      // 0x0019(0x0003) MISSED OFFSET
    float TextureRotation;                                                                 // 0x001C(0x0004) (Edit)
    struct FStruct_Rotator LayerRotation;                                                  // 0x0020(0x000C) (Edit)
    struct FStruct_Matrix TerrainMatrix;                                                   // 0x002C(0x0040)
    float KFriction;                                                                       // 0x006C(0x0004) (Edit)
    float KRestitution;                                                                    // 0x0070(0x0004) (Edit)
    class UClass_Object_Material_RenderedMaterial_BitmapMaterial_Texture* LayerWeightMap;  // 0x0074(0x0004) (Transient)
};

// Struct DecorationLayer
// 0x0078
struct FStruct_DecorationLayer {
    int ShowOnTerrain;                                                                 // 0x0000(0x0004) (Edit)
    class UClass_Object_Material_RenderedMaterial_BitmapMaterial_Texture* ScaleMap;    // 0x0004(0x0004) (Edit)
    class UClass_Object_Material_RenderedMaterial_BitmapMaterial_Texture* DensityMap;  // 0x0008(0x0004) (Edit)
    class UClass_Object_Material_RenderedMaterial_BitmapMaterial_Texture* ColorMap;    // 0x000C(0x0004) (Edit)
    class UClass_Object_Primitive_StaticMesh* StaticMesh;                              // 0x0010(0x0004) (Edit)
    struct FStruct_RangeVector ScaleMultiplier;                                        // 0x0014(0x0018) (Edit)
    struct FStruct_Range FadeoutRadius;                                                // 0x002C(0x0008) (Edit)
    struct FStruct_Range DensityMultiplier;                                            // 0x0034(0x0008) (Edit)
    int MaxPerQuad;                                                                    // 0x003C(0x0004) (Edit)
    int Seed;                                                                          // 0x0040(0x0004) (Edit)
    int AlignToTerrain;                                                                // 0x0044(0x0004) (Edit)
    TEnumAsByte<ESortOrder> DrawOrder;                                                 // 0x0048(0x0001) (Edit)
    unsigned char UnknownData00[0x3];                                                  // 0x0049(0x0003) MISSED OFFSET
    int ShowOnInvisibleTerrain;                                                        // 0x004C(0x0004) (Edit)
    int LitDirectional;                                                                // 0x0050(0x0004) (Edit)
    int DisregardTerrainLighting;                                                      // 0x0054(0x0004) (Edit)
    int RandomYaw;                                                                     // 0x0058(0x0004) (Edit)
    TEnumAsByte<EAnimationType> AnimationType;                                         // 0x005C(0x0001) (Edit)
    unsigned char UnknownData01[0x3];                                                  // 0x005D(0x0003) MISSED OFFSET
    float AnimationSpeed;                                                              // 0x0060(0x0004) (Edit)
    float AnimationAmplitude;                                                          // 0x0064(0x0004) (Edit)
    float AnimationWorldPeriod;                                                        // 0x0068(0x0004) (Edit)
    struct FStruct_Range ScaleMultiplier3D;                                            // 0x006C(0x0008) (Edit)
    int GetLightingFromFinalisedMacro;                                                 // 0x0074(0x0004) (Edit)
};

// Struct TexRegion
// 0x0014
struct FStruct_TexRegion {
    int X;                                                                    // 0x0000(0x0004) (Edit)
    int Y;                                                                    // 0x0004(0x0004) (Edit)
    int W;                                                                    // 0x0008(0x0004) (Edit)
    int H;                                                                    // 0x000C(0x0004) (Edit)
    class UClass_Object_Material_RenderedMaterial_BitmapMaterial_Texture* t;  // 0x0010(0x0004) (Edit)
};

// Struct InterpCurve
// 0x000C
struct FStruct_InterpCurve {
    TArray<struct FStruct_InterpCurvePoint> Points;  // 0x0000(0x000C) (Edit, NeedCtorLink)
};

// Struct ServerResponseLine
// 0x0060
struct FStruct_ServerResponseLine {
    int ServerID;                                          // 0x0000(0x0004) (Edit)
    struct FString IP;                                     // 0x0004(0x000C) (Edit, NeedCtorLink)
    int Port;                                              // 0x0010(0x0004) (Edit)
    int QueryPort;                                         // 0x0014(0x0004) (Edit)
    struct FString ServerName;                             // 0x0018(0x000C) (Edit, NeedCtorLink)
    struct FString MapName;                                // 0x0024(0x000C) (Edit, NeedCtorLink)
    struct FString GameType;                               // 0x0030(0x000C) (Edit, NeedCtorLink)
    int CurrentPlayers;                                    // 0x003C(0x0004) (Edit)
    int MaxPlayers;                                        // 0x0040(0x0004) (Edit)
    int Ping;                                              // 0x0044(0x0004) (Edit)
    TArray<struct FStruct_KeyValuePair> ServerInfo;        // 0x0048(0x000C) (Edit, NeedCtorLink)
    TArray<struct FStruct_PlayerResponseLine> PlayerInfo;  // 0x0054(0x000C) (Edit, NeedCtorLink)
};

// Struct projectileDamageStat
// 0x0014
struct FStruct_projectileDamageStat {
    class UClass_Object_Field_Struct_State_Class* damageTypeClass;        // 0x0000(0x0004) (Edit)
    class UClass_Object_Field_Struct_State_Class* playerDamageStatClass;  // 0x0004(0x0004) (Edit)
    class UClass_Object_Field_Struct_State_Class* objectDamageStatClass;  // 0x0008(0x0004) (Edit)
    class UClass_Object_Field_Struct_State_Class* headShotStatClass;      // 0x000C(0x0004) (Edit)
    class UClass_Object_Field_Struct_State_Class* backstabStatClass;      // 0x0010(0x0004) (Edit)
};

// Struct ParticleProjectorInfo
// 0x004C
struct FStruct_ParticleProjectorInfo {
    class UClass_Object_Material_RenderedMaterial_BitmapMaterial* BitmapMaterial;  // 0x0000(0x0004)
    struct FStruct_Matrix Matrix;                                                  // 0x0004(0x0040)
    int Projected;                                                                 // 0x0044(0x0004)
    int BlendMode;                                                                 // 0x0048(0x0004)
};

// Struct characterPresence
// 0x0008
struct FStruct_characterPresence {
    class AClass_Object_Actor_Pawn_Rook_Ragdoll_Character* Character;  // 0x0000(0x0004)
    float markerTime;                                                  // 0x0004(0x0004)
};

// Struct InitVec
// 0x000C
struct FStruct_InitVec {
    float X;  // 0x0000(0x0004)
    float Y;  // 0x0004(0x0004)
    float Z;  // 0x0008(0x0004)
};

// Struct MaterialSequenceItem
// 0x000C
struct FStruct_MaterialSequenceItem {
    class UClass_Object_Material* Material;       // 0x0000(0x0004) (Edit, EditInline, EditInlineUse)
    float Time;                                   // 0x0004(0x0004) (Edit)
    TEnumAsByte<EMaterialSequenceAction> Action;  // 0x0008(0x0001) (Edit)
    unsigned char UnknownData00[0x3];             // 0x0009(0x0003) MISSED OFFSET
};

// Struct ParticleBeamEndPoint
// 0x0020
struct FStruct_ParticleBeamEndPoint {
    struct FName ActorTag;              // 0x0000(0x0004) (Edit)
    struct FStruct_RangeVector Offset;  // 0x0004(0x0018) (Edit)
    float Weight;                       // 0x001C(0x0004) (Edit)
};

// Struct Alias
// 0x0010
struct FStruct_Alias {
    struct FName Alias;      // 0x0000(0x0004) (Config)
    struct FString Command;  // 0x0004(0x000C) (Config, NeedCtorLink)
};

// Struct ParticleBeamData
// 0x0010
struct FStruct_ParticleBeamData {
    struct FStruct_Vector Location;  // 0x0000(0x000C)
    float t;                         // 0x000C(0x0004)
};

// Struct VoiceChatterInfo
// 0x000C
struct FStruct_VoiceChatterInfo {
    class AClass_Object_Actor_Controller* Controller;  // 0x0000(0x0004)
    int IpAddr;                                        // 0x0004(0x0004)
    int Handle;                                        // 0x0008(0x0004)
};

// Struct LevelData
// 0x0028
struct FStruct_LevelData {
    struct FString Name;               // 0x0000(0x000C) (NeedCtorLink)
    struct FString Title;              // 0x000C(0x000C) (NeedCtorLink)
    int checksum;                      // 0x0018(0x0004)
    TArray<struct FString> gameTypes;  // 0x001C(0x000C) (NeedCtorLink)
};

// Struct baseDeviceAreaStat
// 0x000C
struct FStruct_baseDeviceAreaStat {
    class UClass_Object_Field_Struct_State_Class* statClass;        // 0x0000(0x0004) (Edit)
    class UClass_Object_Field_Struct_State_Class* baseDeviceClass;  // 0x0004(0x0004) (Edit)
    int Radius;                                                     // 0x0008(0x0004) (Edit)
};

// Struct TransitionData
// 0x0008
struct FStruct_TransitionData {
    struct FName State;  // 0x0000(0x0004)
    float Time;          // 0x0004(0x0004)
};

// Struct BuilderPoly
// 0x0018
struct FStruct_BuilderPoly {
    TArray<int> VertexIndices;  // 0x0000(0x000C) (NeedCtorLink)
    int direction;              // 0x000C(0x0004)
    struct FName Item;          // 0x0010(0x0004)
    int PolyFlags;              // 0x0014(0x0004)
};

// Struct AdminPlayer
// 0x0008
struct FStruct_AdminPlayer {
    class UClass_Object_TribesAdminBase_TribesAdminUser* User;                  // 0x0000(0x0004)
    class AClass_Object_Actor_Info_ReplicationInfo_PlayerReplicationInfo* PRI;  // 0x0004(0x0004)
};

// Struct SpecificationStruct
// 0x0008
struct FStruct_SpecificationStruct {
    struct FName SpecificationType;                                    // 0x0000(0x0004)
    class UClass_Object_Field_Struct_State_Class* SpecificationClass;  // 0x0004(0x0004)
};

// Struct TeamDamageVoteScore
// 0x0008
struct FStruct_TeamDamageVoteScore {
    int YesVotes;  // 0x0000(0x0004)
    int NoVotes;   // 0x0004(0x0004)
};

// Struct PolyLoopStruct
// 0x000C
struct FStruct_PolyLoopStruct {
    struct FStruct_Range PolyLoopRange;  // 0x0000(0x0008) (Config)
    int LoopSoundLimit;                  // 0x0008(0x0004) (Config)
};

// Struct TerrainSample
// 0x0028
struct FStruct_TerrainSample {
    struct FStruct_Vector Location;          // 0x0000(0x000C)
    struct FStruct_Vector Normal;            // 0x000C(0x000C)
    struct FStruct_Vector Velocity;          // 0x0018(0x000C)
    unsigned long bTerrain : 1;              // 0x0024(0x0004)
    unsigned long bDownSlope : 1;            // 0x0024(0x0004)
    unsigned long bBeforeSkiRouteStart : 1;  // 0x0024(0x0004)
};

// Struct Region
// 0x0010
struct FStruct_Region {
    int X;  // 0x0000(0x0004) (Edit)
    int Y;  // 0x0004(0x0004) (Edit)
    int W;  // 0x0008(0x0004) (Edit)
    int H;  // 0x000C(0x0004) (Edit)
};

// Struct MouseCursor
// 0x0010
struct FStruct_MouseCursor {
    class UClass_Object_Material_RenderedMaterial_BitmapMaterial_Texture* Tex;  // 0x0000(0x0004)
    int HotX;                                                                   // 0x0004(0x0004)
    int HotY;                                                                   // 0x0008(0x0004)
    unsigned char WindowsCursor;                                                // 0x000C(0x0001)
    unsigned char UnknownData00[0x3];                                           // 0x000D(0x0003) MISSED OFFSET
};

// Struct announcement
// 0x0014
struct FStruct_announcement {
    struct FName EffectEvent;    // 0x0000(0x0004) (Edit)
    struct FName SpeechTag;      // 0x0004(0x0004) (Edit)
    struct FString DebugString;  // 0x0008(0x000C) (Edit, Localized, NeedCtorLink)
};

// Struct msg
// 0x001C
struct FStruct_msg {
    struct FString StringOne;            // 0x0000(0x000C) (Edit, Localized, NeedCtorLink, NoClear)
    struct FString StringTwo;            // 0x000C(0x000C) (Edit, Localized, NeedCtorLink, NoClear)
    class UClass_Object_Material* Icon;  // 0x0018(0x0004) (Edit, NoClear)
};

// Struct MPActorLink
// 0x0014
struct FStruct_MPActorLink {
    class AClass_Object_Actor_Pawn_Rook_MPActor* A;  // 0x0000(0x0004) (Edit)
    class AClass_Object_Actor_Pawn_Rook_MPActor* B;  // 0x0004(0x0004) (Edit)
    TArray<struct FStruct_TeamLink> accessList;      // 0x0008(0x000C) (Edit, NeedCtorLink, NoClear)
};

// Struct TeamLink
// 0x0004
struct FStruct_TeamLink {
    class AClass_Object_Actor_Info_TeamInfo* Team;  // 0x0000(0x0004) (Edit)
};

// Struct HUDExtension
// 0x0024
struct FStruct_HUDExtension {
    struct FString elementName;  // 0x0000(0x000C) (Edit, Config, NeedCtorLink, NoClear)
    struct FString ClassName;    // 0x000C(0x000C) (Edit, Config, NeedCtorLink, NoClear)
    struct FString IniFile;      // 0x0018(0x000C) (Edit, Config, NeedCtorLink, NoClear)
};

// Struct AdminUser
// 0x003C
struct FStruct_AdminUser {
    struct FString AdminName;              // 0x0000(0x000C) (Config, NeedCtorLink)
    struct FString Password;               // 0x000C(0x000C) (Config, NeedCtorLink)
    struct FString Privileges;             // 0x0018(0x000C) (Config, NeedCtorLink)
    TArray<struct FString> Groups;         // 0x0024(0x000C) (Config, NeedCtorLink)
    TArray<struct FString> ManagedGroups;  // 0x0030(0x000C) (Config, NeedCtorLink)
};

// Struct AdminGroup
// 0x001C
struct FStruct_AdminGroup {
    struct FString GroupName;          // 0x0000(0x000C) (Config, NeedCtorLink)
    struct FString Privileges;         // 0x000C(0x000C) (Config, NeedCtorLink)
    unsigned char GameSecLevel;        // 0x0018(0x0001) (Config)
    unsigned char UnknownData00[0x3];  // 0x0019(0x0003) MISSED OFFSET
};

// Struct LevelsForGameType
// 0x0018
struct FStruct_LevelsForGameType {
    struct FString GameType;                  // 0x0000(0x000C) (NeedCtorLink)
    TArray<struct FStruct_LevelData> levels;  // 0x000C(0x000C) (NeedCtorLink)
};

// Struct MapVoteGameConfigLite
// 0x0024
struct FStruct_MapVoteGameConfigLite {
    struct FString GameClass;  // 0x0000(0x000C) (NeedCtorLink)
    struct FString Prefix;     // 0x000C(0x000C) (NeedCtorLink)
    struct FString GameName;   // 0x0018(0x000C) (NeedCtorLink)
};

// Struct MapVoteMapList
// 0x0018
struct FStruct_MapVoteMapList {
    struct FString MapName;      // 0x0000(0x000C) (NeedCtorLink)
    int PlayCount;               // 0x000C(0x0004)
    int Sequence;                // 0x0010(0x0004)
    unsigned long bEnabled : 1;  // 0x0014(0x0004)
};

// Struct MapVoteScore
// 0x000C
struct FStruct_MapVoteScore {
    int MapIndex;         // 0x0000(0x0004)
    int GameConfigIndex;  // 0x0004(0x0004)
    int VoteCount;        // 0x0008(0x0004)
};

// Struct KickVoteScore
// 0x000C
struct FStruct_KickVoteScore {
    int PlayerID;       // 0x0000(0x0004)
    int Team;           // 0x0004(0x0004)
    int KickVoteCount;  // 0x0008(0x0004)
};

// Struct AdminVoteScore
// 0x000C
struct FStruct_AdminVoteScore {
    int PlayerID;        // 0x0000(0x0004)
    int Team;            // 0x0004(0x0004)
    int AdminVoteCount;  // 0x0008(0x0004)
};

// Struct TournamentVoteScore
// 0x0008
struct FStruct_TournamentVoteScore {
    int YesVotes;  // 0x0000(0x0004)
    int NoVotes;   // 0x0004(0x0004)
};

// Struct MapVoteGameConfig
// 0x0048
struct FStruct_MapVoteGameConfig {
    struct FString GameClass;  // 0x0000(0x000C) (NeedCtorLink)
    struct FString Prefix;     // 0x000C(0x000C) (NeedCtorLink)
    struct FString Acronym;    // 0x0018(0x000C) (NeedCtorLink)
    struct FString GameName;   // 0x0024(0x000C) (NeedCtorLink)
    struct FString Mutators;   // 0x0030(0x000C) (NeedCtorLink)
    struct FString Options;    // 0x003C(0x000C) (NeedCtorLink)
};

// Struct AccumulationData
// 0x0010
struct FStruct_AccumulationData {
    struct FString Name;  // 0x0000(0x000C) (NeedCtorLink)
    int VoteCount;        // 0x000C(0x0004)
};

// Struct TickedReplicationQueueItem
// 0x000C
struct FStruct_TickedReplicationQueueItem {
    TEnumAsByte<ERepDataType> dataType;  // 0x0000(0x0001)
    unsigned char UnknownData00[0x3];    // 0x0001(0x0003) MISSED OFFSET
    int Index;                           // 0x0004(0x0004)
    int Last;                            // 0x0008(0x0004)
};

// Struct AutoLoginInfo
// 0x0034
struct FStruct_AutoLoginInfo {
    struct FString IP;             // 0x0000(0x000C) (Edit, Config, NeedCtorLink)
    struct FString Port;           // 0x000C(0x000C) (Edit, Config, NeedCtorLink)
    struct FString Username;       // 0x0018(0x000C) (Edit, Config, NeedCtorLink)
    struct FString Password;       // 0x0024(0x000C) (Edit, Config, NeedCtorLink)
    unsigned long bAutologin : 1;  // 0x0030(0x0004) (Edit, Config)
};

// Struct ServerFavorite
// 0x0018
struct FStruct_ServerFavorite {
    struct FString IP;    // 0x0000(0x000C) (Edit, Config, NeedCtorLink)
    struct FString Port;  // 0x000C(0x000C) (Edit, Config, NeedCtorLink)
};

// Struct HUDMaterial
// 0x0040
struct FStruct_HUDMaterial {
    class UClass_Object_Material* Material;  // 0x0000(0x0004) (Edit, NoClear)
    struct FStruct_Color DrawColor;          // 0x0004(0x0004) (Edit, NoClear)
    struct FStruct_MatCoords Coords;         // 0x0008(0x0010) (Edit, NoClear)
    unsigned char Style;                     // 0x0018(0x0001) (Edit, NoClear)
    unsigned char UnknownData00[0x3];        // 0x0019(0x0003) MISSED OFFSET
    unsigned long bStretched : 1;            // 0x001C(0x0004) (Edit, NoClear)
    unsigned long bNoRender : 1;             // 0x001C(0x0004)
    unsigned long bProgressControlled : 1;   // 0x001C(0x0004)
    unsigned long bFlashing : 1;             // 0x001C(0x0004) (Edit, NoClear)
    float flashFrequency;                    // 0x0020(0x0004) (Edit, NoClear)
    float lastFlashTime;                     // 0x0024(0x0004)
    unsigned long bFading : 1;               // 0x0028(0x0004) (Edit, NoClear)
    unsigned long bFadePulse : 1;            // 0x0028(0x0004) (Edit, NoClear)
    struct FStruct_Color fadeSourceColor;    // 0x002C(0x0004) (Edit, NoClear)
    struct FStruct_Color fadeTargetColor;    // 0x0030(0x0004) (Edit, NoClear)
    float fadeDuration;                      // 0x0034(0x0004) (Edit, NoClear)
    float fadeStartTime;                     // 0x0038(0x0004)
    float fadeProgress;                      // 0x003C(0x0004)
};

// Struct IpAddr
// 0x0008
struct FStruct_IpAddr {
    int Addr;  // 0x0000(0x0004)
    int Port;  // 0x0004(0x0004)
};

// Struct sTabButtonPair
// 0x0008
struct FStruct_sTabButtonPair {
    class UClass_Object_GUI_GUIComponent_GUITextComponent_GUIButton* TabHeader;  // 0x0000(0x0004) (Edit, ExportObject, Config, NeedCtorLink, NoClear, EditInline)
    class UClass_Object_GUI_GUIComponent_GUITextComponent_GUIButton* TabPanel;   // 0x0004(0x0004) (Edit, ExportObject, Config, NeedCtorLink, NoClear, EditInline)
};

}  // namespace SDK

#ifdef _MSC_VER
#pragma pack(pop)
#endif
