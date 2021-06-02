#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIEnemy.generated.h"

UCLASS() class AP_COURSEWORK_API AAIEnemy : public ACharacter{
	GENERATED_BODY()


protected:
	virtual void BeginPlay() override;

public:	
	AAIEnemy();

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponente) override;

	UPROPERTY(EditAnywhere, Category = AI) class UBehaviorTree* BehaviorTree;
	UPROPERTY(VisibleAnywhere, Category = AI) class UPawnSensingComponent *PawnSensingComp;

private:
	UPROPERTY(EditAnywhere, Category = Gameplay) USoundBase* PunchSound;

	UPROPERTY(EditAnywhere, Category = Gameplay) int AttackCounter;

	UPROPERTY(EditAnywhere, Category = Gameplay) UAnimMontage* ComboPunch[2];

	UFUNCTION() void OnPlayerCaught(APawn* Pawn);
};
