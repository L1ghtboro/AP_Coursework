#include "AP_CourseworkCharacter.h"
//#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);


AAP_CourseworkCharacter::AAP_CourseworkCharacter() {
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
	AttackCounter = 0;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;											// Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);								// At this rotation rate
	GetCharacterMovement()->JumpZVelocity = 360.f;
	GetCharacterMovement()->AirControl = 0.2f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));						// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = -20.0f;																// The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true;															// Rotate the arm based on the controller

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);							// Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false;														// Camera does not rotate relative to arm

	CharactersMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));				// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	CharactersMesh->SetOnlyOwnerSee(false);
	CharactersMesh->SetupAttachment(FollowCamera);
	CharactersMesh->bCastDynamicShadow = true;
	CharactersMesh->CastShadow = true;
	CharactersMesh->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	CharactersMesh->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));
}

void AAP_CourseworkCharacter::BeginPlay() {
	Super::BeginPlay();																					// Call the base class  
	//if (GEngine) 
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Character Works!"));			// Printing in Debug I want to kill myself
	
	//if (Fist) {
	//	Fist->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("Right Arm Punch"));
	//}
		
}

void AAP_CourseworkCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AAP_CourseworkCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) {

	check(PlayerInputComponent);																		// Set up gameplay key bindings

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AAP_CourseworkCharacter::Attack);
	PlayerInputComponent->BindAction("Ultimate", IE_Pressed, this, &AAP_CourseworkCharacter::Ultimate);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AAP_CourseworkCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AAP_CourseworkCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AAP_CourseworkCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AAP_CourseworkCharacter::LookUpAtRate);
}

void AAP_CourseworkCharacter::Attack() {
	if (ComboPunch[0] && !AttackCounter) {
		UAnimInstance *BufferAnim = GetMesh()->GetAnimInstance();
		BufferAnim->Montage_Play(ComboPunch[0], 1.f);
		UGameplayStatics::SpawnSound2D(this, PunchSound, true);
		AttackCounter++;
	}
	else if (ComboPunch[1] && AttackCounter == 1) {
		UAnimInstance* BufferAnim = GetMesh()->GetAnimInstance();
		BufferAnim->Montage_Play(ComboPunch[1], 1.f);
		UGameplayStatics::SpawnSound2D(this, PunchSound, true);
		AttackCounter++;
	}
	else if (ComboPunch[2] && AttackCounter == 2) {
		UAnimInstance* BufferAnim = GetMesh()->GetAnimInstance();
		BufferAnim->Montage_Play(ComboPunch[2], 1.f);
		UGameplayStatics::SpawnSound2D(this, PunchSound, true);
		AttackCounter++;
	}
	else if (ComboPunch[3] && AttackCounter == 3) {
		UAnimInstance* BufferAnim = GetMesh()->GetAnimInstance();
		BufferAnim->Montage_Play(ComboPunch[3], 1.f);
		UGameplayStatics::SpawnSound2D(this, PunchSound, true);
		AttackCounter = 0;
	}
	//DamageComponent->DealtDamage(10.f);
}

void AAP_CourseworkCharacter::Ultimate() {

}


void AAP_CourseworkCharacter::TurnAtRate(float value){
	AddControllerYawInput(value * BaseTurnRate * GetWorld()->GetDeltaSeconds());                        //Calculate delta for this frame from the rate information
}

void AAP_CourseworkCharacter::LookUpAtRate(float value){
	AddControllerPitchInput(value * BaseLookUpRate * GetWorld()->GetDeltaSeconds());                    //Calculate delta for this frame from the rate information
}

void AAP_CourseworkCharacter::MoveForward(float value){
	if (Controller != nullptr && value != 0.0f){
		const FRotator rot = Controller->GetControlRotation();											//Find out which way is forward
		const FRotator yawRot(0, rot.Yaw, 0);
		const FVector direction = FRotationMatrix(yawRot).GetUnitAxis(EAxis::X);						//Get forward vector
		AddMovementInput(direction, value);
	}
}

void AAP_CourseworkCharacter::MoveRight(float value){
	if ((Controller != nullptr) && (value != 0.0f)){
		const FRotator rot = Controller->GetControlRotation();
		const FRotator yawRot(0, rot.Yaw, 0);
		const FVector direction = FRotationMatrix(yawRot).GetUnitAxis(EAxis::Y);						//Get right vector 
		AddMovementInput(direction, value);																//Add movement in that direction
	}
}
