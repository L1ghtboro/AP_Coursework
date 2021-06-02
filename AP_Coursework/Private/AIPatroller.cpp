#include "AIPatroller.h"
#include "AIEnemy.h"
#include "AIPatrolPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Kismet/GameplayStatics.h"

AAIPatroller::AAIPatroller() {
	BehaviorTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTree"));				//Init through cast BehaviorTree in Cpp
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard"));			//Init Blackboard through cast

	PlayerKey = "Target";																		//Init Blackboards Key
	LocationKey = "WhereToGo";

	CurrentPatrolPoint = 0;
}

void AAIPatroller::OnPossess(APawn* Pawne) {
	Super::OnPossess(Pawne);
	AAIEnemy* AIChar = Cast<AAIEnemy>(Pawne);
	if (AIChar) {
		if (AIChar->BehaviorTree->BlackboardAsset) {
			BlackboardComp->InitializeBlackboard(*(AIChar->BehaviorTree->BlackboardAsset));
		}
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAIPatrolPoint::StaticClass(), PatrolPoints);
		BehaviorTreeComp->StartTree(*AIChar->BehaviorTree);
	}
}

void AAIPatroller::SetPlayerCaught(APawn* Pawne) {
	if (BlackboardComp) {
		BlackboardComp->SetValueAsObject(PlayerKey, Pawne);
		//return true;
	}
	//return false;
}