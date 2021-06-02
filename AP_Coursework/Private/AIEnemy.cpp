#include "AIEnemy.h"
#include "AIPatroller.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"
#include "Kismet/GameplayStatics.h"

AAIEnemy::AAIEnemy(){
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->SetPeripheralVisionAngle(90.f);
	AttackCounter = 0;
}

void AAIEnemy::SetupPlayerInputComponent(class UInputComponent* InputComponente) {
	Super::SetupPlayerInputComponent(InputComponente);
}

void AAIEnemy::BeginPlay(){
	Super::BeginPlay();
	if (PawnSensingComp)
		PawnSensingComp->OnSeePawn.AddDynamic(this, &AAIEnemy::OnPlayerCaught);
}


void AAIEnemy::OnPlayerCaught(APawn* Pawn) {
	AAIPatroller* AIPatrol = Cast<AAIPatroller>(GetController());
	if (AIPatrol) {
		if (ComboPunch[0] && !AttackCounter) {
			UAnimInstance* BufferAnim = GetMesh()->GetAnimInstance();
			BufferAnim->Montage_Play(ComboPunch[0], 1.f);
			UGameplayStatics::SpawnSound2D(this, PunchSound, true);
			AttackCounter++;
		}
		else if (ComboPunch[1] && AttackCounter == 1) {
			UAnimInstance* BufferAnim = GetMesh()->GetAnimInstance();
			BufferAnim->Montage_Play(ComboPunch[1], 1.f);
			UGameplayStatics::SpawnSound2D(this, PunchSound, true);
			AttackCounter=0;
		}
		AIPatrol->SetPlayerCaught(Pawn);
	}
}

