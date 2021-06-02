#include "AP_CourseworkHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"

AAP_CourseworkHUD::AAP_CourseworkHUD() {
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/FPSwordAndShield/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshairTexObj.Object;
}


void AAP_CourseworkHUD::DrawHUD() {
	//Super::DrawHUD();
	//const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
	//const FVector2D CrosshairDrawPosition((Center.X), (Center.Y + 20.0f));
	//FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	//TileItem.BlendMode = SE_BLEND_Translucent;
	//Canvas->DrawItem(TileItem);
}
