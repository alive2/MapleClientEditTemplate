#pragma once

#include "Windows.h"

/*
 *  Addresses defined here were found using the following programs: Cheat Engine, Hex-Rays IDA, ReClassEx
 *  Default Image Base Address for a 32-bit exe in Windows, when loaded into Memory is 0x400000
 *  So all the addresses defined here already have 0x400000 added for convenience purposes
 *  These addresses are all virtual addresses defined in MapleStory.exe's virtual address space
 */

namespace Offsets {
#pragma region Hack Addresses
	//Main Tab
	extern ULONG logoSkipAddr;

	//Hacks Tabs
	extern ULONG fullGodmodeAddr;
	extern ULONG missGodmodeAddr;
	extern ULONG blinkGodmodeAddr;
	extern ULONG swimInAirAddr;
	extern ULONG unlimitedAttackAddr;
	extern ULONG fullAccuracyAddr; //Client sided only version?? This is incomplete acc hack.
	extern ULONG noBreathAddr; //Fake/imperfect no breath?
	extern ULONG noPlayerKnocbackAddr;
	extern ULONG noPlayerDeathAddr;
	extern ULONG jumpDownAnywhereAddr;
	extern ULONG noSkillEffectAddr;
	extern ULONG noAttackDelayAddr;
	extern ULONG noPlayerNameTagAddr;
	extern ULONG attackDelayAddr;
	extern ULONG instantDropItemsAddr;
	extern ULONG instantLootItemsAddr;
	extern ULONG tubiAddr;
	extern ULONG noMobReactionAddr;
	extern ULONG noMobDeathEffectAddr;
	extern ULONG noMobKnockbackAddr;
	extern ULONG mobDisarmAddr;
	extern ULONG noMapBackgroundAddr;
	extern ULONG noMapObjectsAddr;
	extern ULONG noMapTitlesAddr;
	extern ULONG noMapFadeEffect;
	extern ULONG mapSpeedUpAddr;
	extern ULONG removeSpamFilterAddr1;
	extern ULONG removeSpamFilterAddr2;
	extern ULONG infiniteChatboxAddr1;
	extern ULONG infiniteChatboxAddr2;
	extern ULONG noBlueBoxesAddr;
	extern ULONG walkingFrictionAddr; // je -> jne

	//Vac Tabs
	extern ULONG fullMapAttackAddr;
	extern ULONG zzVacAddr1;
	extern ULONG zzVacAddr2;
	extern ULONG vacForceRightAddr; // jae -> jna	
	extern ULONG vacRightNoForce; // jae -> jna
	extern ULONG vacJumpLeftAddr; // jae -> je
	extern ULONG vacJumpRightAddr; // jna -> je		
	extern ULONG vacJumpUpAddr; // jae -> je	
	extern ULONG vacLeftAddr;  // jae -> je	
	extern ULONG vacRightAddr; // jbe -> je	
	extern ULONG fangorVacAddr1; // fld(0) -> fld(1) //vac into left wall		
	extern ULONG fangorVacAddr2; // fld(0) -> fld(1) //vac into top left corner		
	extern ULONG pVacAddr; // codecave

	//Unimplemented Hacks
	extern ULONG multiClientAddr; // jne -> jmp
	extern ULONG lagHackAddr; // je -> jne
	extern ULONG accuracyHackAddr1; // codecave
	extern ULONG accuracyHackAddr2; // codecave
	extern ULONG accuracyHackAddr3; // codecave
	extern ULONG mpRegenTickTimeAddr; // cmp ebx,00002710 -> cmp ebx, [BYTE_VALUE]
	extern ULONG sitAnywhereAddr; // je -> 2x nop
	extern ULONG speedWalkAddr; // je -> 6x nop
	extern ULONG mouseCSEAXVacYAddr; // codecave
	extern ULONG mouseCSEAXVacXAddr; // codecave
	extern ULONG mesoDropCap; // 4 bytes
	extern ULONG magicAttCap; // 4 bytes
	extern ULONG gravity; // double
	extern ULONG bringYourOwnRopeAddr; // codecave
	extern ULONG MSCRCBypassAddr1; // codecave
	extern ULONG MSCRCBypassAddr2; // codecave
	extern ULONG slideRightAddr; // jna -> jne
	extern ULONG itsRainingMobsAddr; // F1 -> F2, bugged diassembly??
	extern ULONG attackUnrandommizerAddr; // codecave
	extern ULONG etcExplosionAddr; // 6x nop
	extern ULONG useRechargableItemsAfterDepletionAddr1; // 6x nop
	extern ULONG useRechargableItemsAfterDepletionAddr2; // je -> jns
	extern ULONG chargeSkillsNoChargingAddr1; //jne -> jmp		
	// extern ULONG chargeSkillsNoChargingAddr2		
	extern ULONG noJumpingMobAndPlayerAddr; //je -> jmp		
	extern ULONG vacLeftAddr2; //??		
	extern ULONG jmpRelatedstub; //??		
	extern ULONG gravityrelated; //jae -> jmp for monster fly up on jump
	extern ULONG mapGlideAddr; // jna 009B2C11 jna->jae monsters/players glide like in Elnath

	// OLDSKOOL STUFF
	// pin typer v0.62 004A0A6B: //83 FA 6F 0F 86 ?? ?? ?? ?? 83 FA 7B 
	// jbe -> je
	// take one dmg v0.62 00670090: // DF E0 9E 72 04 DD D8 D9 E8 DC 15
	// jb -> ja
	// ZPVac v0.62 007F2A18: // C3 DD D8 5D C3 55 8B EC
	// fstp st(0) -> fstp st(6)
	// Unlimited summon v0.62 004D6D95: //74 2D 8B 7C 24 0C 8B 07 6A 05 50 E8 ?? ?? ?? ??
	// je -> jne
#pragma endregion

#pragma region CodeCave Addresses
	extern ULONG statHookAddr; //Inside CUIStatusBar::SetNumberValue
	extern ULONG statHookAddrRet;
	extern ULONG mapNameHookAddr; //Inside CItemInfo::GetMapString()
	extern ULONG mapNameHookAddrRet;
	extern ULONG itemVacAddr; //Inside CDropPool::TryPickUpDrop()
	extern ULONG itemVacAddrRet;
	extern ULONG mouseFlyXAddr; //Inside CVecCtrl::raw__GetSnapshot()
	extern ULONG mouseFlyXAddrRet;
	extern ULONG mouseFlyYAddr; //Inside CVecCtrl::raw__GetSnapshot()
	extern ULONG mouseFlyYAddrRet;
	extern ULONG mobFreezeAddr; //Inside CVecCtrlMob::WorkUpdateActive()
	extern ULONG mobFreezeAddrRet;
	extern ULONG mobAutoAggroAddr; //Inside CVecCtrlMob::WorkUpdateActive() (call to CVecCtrl::WorkUpdateActive())
	extern ULONG cVecCtrlWorkUpdateActiveCall; //Start of CVecCtrl::WorkUpdateActive()
	extern ULONG mobAutoAggroAddrRet;
	extern ULONG spawnPointAddr; //Start of CVecCtrl::SetActive()
	extern ULONG spawnPointAddrRet;
	extern ULONG itemFilterAddr; //Inside CDropPool::OnDropEnterField()
	extern ULONG itemFilterAddrRet;
	extern ULONG mobFilter1Addr; //Inside CMobPool::SetLocalMob()
	extern ULONG mobFilter1AddrRet;
	extern ULONG mobFilter1JmpAddr; //mov ecx,[ebp-0C] above the ret 0004 at the end of function
	extern ULONG mobFilter2Addr; //Inside CMobPool::OnMobEnterField()
	extern ULONG mobFilter2AddrRet;
	extern ULONG mobFilter2JmpAddr; //mov ecx,[ebp-0C] above the ret 0004 at the end of function
	extern ULONG cInPacketDecode4Addr; //Start of CInPacket::Decode4()
	extern ULONG cOutPacketAddr;
	extern ULONG cOutPacketAddrRet;
	extern ULONG dupeXAddr;
	extern ULONG dupeXAddrRet;
#pragma endregion

#pragma region MapleStory Function Hook Addresses
	//Hook Addresses
	extern ULONG enterCSAddr;
	extern ULONG exitCSAddr;
	extern ULONG ccAddr;
	extern ULONG jobNameAddr;
	extern ULONG charDataAddr;
	extern ULONG userlocalUpdateAddr;
	extern ULONG cloginOnRecommendWorldAddr;
	extern ULONG cloginSendLoginPacketAddr;

	//Hooks
	// typedef void(__stdcall *pfnCWvsContext__SendMigrateToShopRequest)(PVOID, PVOID, int); // Enters Cash Shop
	// auto CWvsContext__SendMigrateToShopRequest = reinterpret_cast<pfnCWvsContext__SendMigrateToShopRequest>(enterCSAddr);

	// typedef void(__stdcall *pfnCCashShop__SendTransferFieldPacket)(); // Exits Cash Shop
	// auto CCashShop__SendTransferFieldPacket = reinterpret_cast<pfnCCashShop__SendTransferFieldPacket>(exitCSAddr);

	// typedef char*(__cdecl *pfnGet_Job_Name)(int); // Retrieves Job name
	// auto GetJobName = reinterpret_cast<pfnGet_Job_Name>(jobNameAddr);

	// typedef void*(__thiscall *pfnCWvsContext__GetCharacterData)(extern ULONG, PVOID);
	// auto CWvsContext__GetCharacterData = reinterpret_cast<pfnCWvsContext__GetCharacterData>(charDataAddr);

	//typedef ZXString<char>*(__fastcall* StringPool__GetString_t)(void *StringPool, void *edx, ZXString<char> *result, unsigned int nIdx);
	//auto StringPool__GetString = (StringPool__GetString_t)0x0049B330; //
	//void **ms_pInstance_StringPool = (void **)0x01C1C200; pointer that gets all Strings in StringPool
#pragma endregion

#pragma region Pointer Addresses & Offsets
	extern ULONG PtInRectAddr;

	extern ULONG LoginBase; //CLogin
	extern ULONG OFS_LoginStep; //0 = login screen or logged in, 1 = Select World/Channel, 2 = Select Char
	extern ULONG OFS_LoginScreen; //255 == login screen, 1 == loggin in, 0 = logged in

	extern ULONG UIInfoBase;
	extern ULONG OFS_HP;
	extern ULONG OFS_MP;
	extern ULONG OFS_EXP;

	extern ULONG UIStatusBarBase; // CUIStatusBar
	extern ULONG OFS_HPAlert;
	extern ULONG OFS_MPAlert;

	extern ULONG UIMiniMapBase; // CUIMiniMap
	extern ULONG OFS_MapID;

	extern ULONG CharacterStatBase; //GW_CharacterStat //CWvsContext::GetCharacterData() returns ZRef<CharacterData>; &CharacterData[0] = GW_CharacterStat
	extern ULONG OFS_Ign;
	extern ULONG OFS_Level;
	extern ULONG OFS_JobID;
	extern ULONG OFS_Mesos;

	extern ULONG NPCPoolBase; //CNPCPool
	extern ULONG OFS_NPCCount;

	extern ULONG PortalListBase; // CPortalList 
	extern ULONG OFS_PortalCount;

	extern ULONG ServerBase; // CWvsContext 
	extern ULONG OFS_World;
	extern ULONG OFS_Channel;
	extern ULONG OFS_Tubi;
	extern ULONG OFS_CharacterCount;
	extern ULONG OFS_ZRef_CharacterData; //CharacterStatBase*

	extern ULONG UserLocalBase; // CUserLocal 
	extern ULONG OFS_pID;
	extern ULONG OFS_Foothold;
	extern ULONG OFS_KB;
	extern ULONG OFS_KBX;
	extern ULONG OFS_KBY;
	extern ULONG OFS_Aggro;
	extern ULONG OFS_CharX;
	extern ULONG OFS_CharY;
	extern ULONG OFS_AttackCount;
	extern ULONG OFS_Breath;
	extern ULONG OFS_Morph; //Change pointer to 9 and freeze
	extern ULONG OFS_CharAnimation;
	extern ULONG OFS_Tele;
	extern ULONG OFS_TeleX;
	extern ULONG OFS_TeleY;
	extern ULONG OFS_BuffCount; // Couldn't find it within CUserLocal, so static address
	extern ULONG OFS_ComboCount;

	extern ULONG DropPoolBase; // CDropPool 
	extern ULONG OFS_ItemCount;

	extern ULONG CWvsPhysicalSpace2DBase; // CWvsPhysicalSpace2D 
	extern ULONG OFS_LeftWall;
	extern ULONG OFS_RightWall;
	extern ULONG OFS_TopWall;
	extern ULONG OFS_BottomWall;

	extern ULONG UserPoolBase; // CUserPool
	extern ULONG OFS_PeopleCount;

	extern ULONG InputBase; // CInputSystem
	extern ULONG OFS_MouseAnimation;
	extern ULONG OFS_MouseLocation;
	extern ULONG OFS_MouseX;
	extern ULONG OFS_MouseY;

	//TODO: Get valid names according to struct
	extern ULONG MobPoolBase; // CMobPool
	extern ULONG OFS_Mob1;
	extern ULONG OFS_Mob2;
	extern ULONG OFS_Mob3;
	extern ULONG OFS_Mob4;
	extern ULONG OFS_MobX;
	extern ULONG OFS_MobY;
	extern ULONG OFS_DeadMob; //Wrong
	extern ULONG OFS_MobCount;

	extern ULONG CItemInfo;
	extern ULONG StringPool;

	extern ULONG CInPacketDecryptDataRet;
#pragma endregion
}