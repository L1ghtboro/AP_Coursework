#include "Fisting.h"

AFisting::AFisting() {
	OnActorBeginOverlap.AddDynamic(this, &AFisting::Attack);
	Attacking = false;
}

void AFisting::BeginPlay() {
	Super::BeginPlay();
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("aaaaaaaaaaaaaaa Works!"));
}

void AFisting::Attack(class AActor* DealingDmg, class AActor* DmgReceiving) {
	if (DmgReceiving && DmgReceiving != this) {
		//ASimpleEnemy* EnemyGen = Cast<ASimpleEnemy>(DmgReceiving);
		/*if (EnemyGen && Attacking) {
			EnemyGen->TakedDamage();
		}*/
	}
}