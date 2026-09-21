// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "EXTDSCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputAction;
class UArrowComponent;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(abstract)
class AEXTDSCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	/** Arrow component that acts as a pivot for camera*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UArrowComponent* CameraPivotArrow;

protected:

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MoveAction;

	/** Mouse Look Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MouseLookAction;

	/** Turn Left Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* TurnLeftAction;

	/** Turn Right Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* TurnRightAction;

	/** Rotaiton pitch */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera", meta = (ClampMin = "0.0", ClampMax = "360.0"))
	float CameraYaw;
	
	/** Rotation speed in degrees per second when turning */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera", meta = (ClampMin = "0.0", ClampMax = "360.0"))
	float TurnSpeed = 90.0f;

public:

	/** Constructor */
	AEXTDSCharacter();

protected:

	/** Initialize input action bindings */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called every frame while TurnLeft action is held */
	void TurnLeft(const FInputActionValue& Value);

	/** Called every frame while TurnRight action is held */
	void TurnRight(const FInputActionValue& Value);

public:

	/** Handles move inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoMove(float Right, float Forward);

	/** Handles jump pressed inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpStart();

	/** Handles jump pressed inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpEnd();

public:

	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	/** Returns CameraPivotArrow subobject **/
	FORCEINLINE UArrowComponent* GetCameraPivotArrow() const { return CameraPivotArrow; }
	
	virtual void Tick(float DeltaSeconds) override;
};