#include "Damage.h"

UDamage::UDamage(){
	PrimaryComponentTick.bCanEverTick = false;
	DamageValue = 15.f;
}

void UDamage::BeginPlay(){
	Super::BeginPlay();
}

//void UDamage::DealtDamage(float Damage){
//	FMath::Clamp(DamageValue + Damage, 0.0f, DamageValue);
//}



