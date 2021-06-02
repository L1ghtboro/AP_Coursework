#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Damage.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) ) class AP_COURSEWORK_API UDamage : public UActorComponent/*, public UUltimatePower */{
	GENERATED_BODY()
public:	
	UDamage();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage") float DamageValue;

	//UFUNCTION() void DealtDamage(float Damage);
};
