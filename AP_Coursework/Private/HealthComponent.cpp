#include "HealthComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

UHealthComponent::UHealthComponent(){
	FirstPlayedAnimation = true;

	DefaultHealth = 100;
	Health = DefaultHealth;
}

void UHealthComponent::BeginPlay(){
	Super::BeginPlay();
	AActor* MyOwner = GetOwner();
	if (MyOwner) {
		MyOwner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakedDamage);
	}
}

void UHealthComponent::TakedDamage(AActor* DamageActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser) {
	if (Damage <= 0)
		return;
	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);
}

bool UHealthComponent::IfDie() {
	if (Health <= 0 && FirstPlayedAnimation) {
		FirstPlayedAnimation = false;
		return true;
	}
	return false;
}
