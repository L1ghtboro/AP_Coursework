//#include "AP_Coursework.h"
#include "BTAISelectPoint.h"
#include "AIPatrolPoint.h"
#include "AIPatroller.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTAISelectPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	AAIPatroller* AICon = Cast<AAIPatroller>(OwnerComp.GetAIOwner());
	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Red, TEXT("Works2"));
	if (AICon) {
		UBlackboardComponent* BlackboardComp = AICon->GetterToBlackboarComp();

		AAIPatrolPoint* CurrentPoint = Cast<AAIPatrolPoint>(BlackboardComp->GetValueAsObject("WhereToGo"));

		TArray<AActor*> AvailablePatrolPoints = AICon->GetterPatrolPoints();

		AAIPatrolPoint* NextPatrolPoint = nullptr;
		if (AICon->CurrentPatrolPoint != AvailablePatrolPoints.Num() - 1) {
			NextPatrolPoint = Cast<AAIPatrolPoint>(AvailablePatrolPoints[++AICon->CurrentPatrolPoint]);
		}
		else {
			NextPatrolPoint = Cast<AAIPatrolPoint>(AvailablePatrolPoints[0]);
			AICon->CurrentPatrolPoint = 0;
		}
		BlackboardComp->SetValueAsObject("WhereToGo", NextPatrolPoint);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
