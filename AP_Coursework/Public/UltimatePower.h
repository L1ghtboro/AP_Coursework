#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UltimatePower.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )class AP_COURSEWORK_API UUltimatePower : public UActorComponent{
	GENERATED_BODY()

public:	
	UUltimatePower();

protected:
	virtual void BeginPlay() override;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health") float NeedPoints;

	UPROPERTY(BlueprintReadOnly) float UltimateCurrent;

	UPROPERTY(BluePrintReadOnly) bool UltimateIsReady = false;

	void Attack();
	void Ultimate();

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);
};
