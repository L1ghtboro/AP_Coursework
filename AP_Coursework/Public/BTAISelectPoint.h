#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTAISelectPoint.generated.h"

UCLASS()class AP_COURSEWORK_API UBTAISelectPoint : public UBTTaskNode {
	GENERATED_BODY()

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};