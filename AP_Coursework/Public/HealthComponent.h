#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) ) class AP_COURSEWORK_API UHealthComponent : public UActorComponent{
	GENERATED_BODY()

public:	
	UHealthComponent();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health") float DefaultHealth;

	UPROPERTY(BlueprintReadOnly) float Health;

	UFUNCTION() void TakedDamage(AActor* DamageActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	
	UFUNCTION(BlueprintCallable) bool IfDie();

private:
	bool FirstPlayedAnimation;
};
