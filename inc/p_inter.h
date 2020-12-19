#if !defined(__P_INTER_H__)
#define __P_INTER_H__

dboolean P_GiveBody(int num, int max, dboolean stat);
dboolean P_GiveMegaHealth(dboolean stat);
dboolean P_GiveArmor(armortype_t armortype, dboolean stat);
dboolean P_GiveAllCards(void);
dboolean P_GiveAllKeyCards(void);
dboolean P_GiveAllSkullKeys(void);
dboolean P_GiveAllCardsInMap(void);
dboolean P_GivePower(int power);
dboolean P_GiveAllWeapons(void);
dboolean P_GiveBackpack(dboolean giveammo, dboolean stat);
dboolean P_GiveFullAmmo(void);
void P_AddBonus(void);
void P_UpdateAmmoStat(ammotype_t ammotype, int num);
void P_UpdateArmorStat(int num);
void P_UpdateHealthStat(int num);
void P_UpdateKillStat(mobjtype_t type, int value);
void P_KillMobj(mobj_t *target, mobj_t *inflicter, mobj_t *source);

#endif
