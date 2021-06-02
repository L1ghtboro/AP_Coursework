#include "AP_CourseworkGameModeBase.h"
#include "AP_CourseworkHUD.h"
#include "UObject/ConstructorHelpers.h"

AAP_CourseworkGameModeBase::AAP_CourseworkGameModeBase() : Super() {
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FPSwordAndShield/Blueprints/FirstPersonCharacter"));
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/AP_CourseworkCharacter"));
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/ParagonGideon/Characters/Heroes/Gideon/GideonPlayerCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
	HUDClass = AAP_CourseworkHUD::StaticClass();
}
