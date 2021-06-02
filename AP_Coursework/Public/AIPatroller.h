#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AIPatroller.generated.h"

UCLASS() class AP_COURSEWORK_API AAIPatroller : public AAIController{
	GENERATED_BODY()

	UBehaviorTreeComponent* BehaviorTreeComp;
	//UBehaviorTree* BehaviorTreeComp;
	UBlackboardComponent* BlackboardComp;															//BlackBoard Component

	UPROPERTY(EditDefaultsOnly, Category = AI) FName LocationKey;
	UPROPERTY(EditDefaultsOnly, Category = AI) FName PlayerKey;

	TArray<AActor*> PatrolPoints;

	virtual void OnPossess(APawn* Pawne) override;

	public:
		AAIPatroller();

		int32 CurrentPatrolPoint;

		void SetPlayerCaught(APawn* Pawne);

		FORCEINLINE UBlackboardComponent* GetterToBlackboarComp() const { return BlackboardComp; } //Getter
		FORCEINLINE TArray<AActor*> GetterPatrolPoints() const { return PatrolPoints; }
};
