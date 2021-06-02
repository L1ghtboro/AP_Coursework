#include "UltimatePower.h"

UUltimatePower::UUltimatePower(){
	PrimaryComponentTick.bCanEverTick = false;
	NeedPoints = 100.f;
	UltimateCurrent = 0.f;
	UltimateIsReady = false;
}

void UUltimatePower::BeginPlay(){
	Super::BeginPlay();
}

void UUltimatePower::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) {
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &UUltimatePower::Attack);
	PlayerInputComponent->BindAction("Ultimate", IE_Pressed, this, &UUltimatePower::Ultimate);
}

void UUltimatePower::Attack() {
	UltimateCurrent += 10.f;
	if (NeedPoints == UltimateCurrent)
		UltimateIsReady = true;
}

void UUltimatePower::Ultimate() {
	if (UltimateIsReady) {
		UltimateIsReady = false;
	}
}