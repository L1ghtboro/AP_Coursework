#pragma once

#include "CoreMinimal.h"
#include "Public/Damage.h"
#include "Public/UltimatePower.h"
#include "GameFramework/Character.h"
#include "AP_CourseworkCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;
class UMotionControllerComponent;
class UAnimMontage;
class USoundBase;

UCLASS() class AP_COURSEWORK_API AAP_CourseworkCharacter : public ACharacter{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh) USkeletalMeshComponent* CharactersMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true")) class USpringArmComponent* CameraBoom;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true")) class UCameraComponent* FollowCamera;
	
	AAP_CourseworkCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera) float BaseTurnRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera) float BaseLookUpRate;

private:

	UPROPERTY(EditAnywhere, Category = Gameplay) AActor* Fist;
	
	UPROPERTY(EditAnywhere, Category = Gameplay) UAnimMontage* ComboPunch[4];

	UPROPERTY(EditAnywhere, Category = Gameplay) USoundBase * PunchSound;

	UPROPERTY(EditAnywhere, Category = Gameplay) USoundBase* Footstep;

	//UPROPERTY(EditAnywhere, Category = Gameplay) UDamage* DamageComponent;

	UPROPERTY(EditAnywhere, Category = Gameplay) int AttackCounter;

protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void MoveForward(float value);
	void MoveRight(float value);
	void TurnAtRate(float value);
	void LookUpAtRate(float value);

	void Attack();
	void Ultimate();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
