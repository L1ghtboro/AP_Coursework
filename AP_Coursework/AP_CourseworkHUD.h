#pragma once 
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AP_CourseworkHUD.generated.h"

UCLASS() class AP_COURSEWORK_API AAP_CourseworkHUD : public AHUD {
	GENERATED_BODY()

public:
	AAP_CourseworkHUD();
	virtual void DrawHUD() override;
private:
	class UTexture2D* CrosshairTex;
};

