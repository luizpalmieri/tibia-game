#ifndef TIBIA_CONFIG_HH_
#define TIBIA_CONFIG_HH_ 1

#include "common.hh"
#include "enums.hh"

struct TDatabaseSettings {
    char Product[30];
    char Database[30];
    char Login[30];
    char Password[30];
    char Host[30];
    char Port[6];
};

struct TQueryManagerSettings {
    char Host[50];
    int Port;
    char Password[30];
};

struct TRateStage {
    int MinLevel;
    int MaxLevel;  // 0 = unlimited
    int Rate;
};

extern char BINPATH[4096];
extern char DATAPATH[4096];
extern char LOGPATH[4096];
extern char MAPPATH[4096];
extern char MONSTERPATH[4096];
extern char NPCPATH[4096];
extern char ORIGMAPPATH[4096];
extern char SAVEPATH[4096];
extern char USERPATH[4096];
extern int SHMKey;
extern int AdminPort;
extern int GamePort;
extern int QueryManagerPort;
extern char AdminAddress[16];
extern char GameAddress[16];
extern char QueryManagerAddress[16];
extern char QueryManagerAdminPW[9];
extern char QueryManagerGamePW[9];
extern char QueryManagerWebPW[9];
extern int DebugLevel;
extern bool PrivateWorld;
extern TWorldType WorldType;
extern char WorldName[30];
extern int MaxPlayers;
extern int MaxNewbies;
extern int PremiumPlayerBuffer;
extern int PremiumNewbieBuffer;
extern int Beat;
extern int RebootTime;
extern int ExperienceStageCount;
extern TRateStage ExperienceStages[10];
extern int LootRate;
extern int MagicRate;
extern int MeleeRate;
extern int DistanceRate;
extern int ShieldingRate;
extern TDatabaseSettings ADMIN_DATABASE;
extern TDatabaseSettings VOLATILE_DATABASE;
extern TDatabaseSettings WEB_DATABASE;
extern TDatabaseSettings FORUM_DATABASE;
extern TDatabaseSettings MANAGER_DATABASE;
extern int NumberOfQueryManagers;
extern TQueryManagerSettings QUERY_MANAGER[10];

// Death penalty settings
extern int DeathPenaltyPercent;         // Base exp/skill loss for non-promoted (default: 10)
extern int DeathPenaltyPromotedPercent; // Base exp/skill loss for promoted (default: 7)
extern int ItemDropChance;              // Chance to drop non-container items: 1 in N (default: 10)
extern bool DropContainersOnDeath;      // Whether containers always drop on death (default: true)

void ReadConfig(void);

#endif //TIBIA_CONFIG_HH_
