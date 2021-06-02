#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Fisting.generated.h"


UCLASS() class AP_COURSEWORK_API AFisting : public ATriggerBox{
	GENERATED_BODY()
public:
	AFisting();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION() void Attack(class AActor* DealingDmg, class AActor* DmgReceiving);
	UPROPERTY() bool Attacking;
};
