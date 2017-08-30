/*=================================================
* 
* Created by: nosix1992
* Project name: MyFish
* Unreal Engine version: 4.13.0
* Created on: 2016/10/15
*
* Last Edited on: 2016/10/17
* Last Edited by: nosix1992
* 
* -------------------------------------------------
* For parts referencing UE4 code, the following copyright applies:
* Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
*
* Feel free to use this software in any commercial/free game.
* Selling this as a plugin/item, in whole or part, is not allowed.
* =================================================*/



// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFish.h"
#include "FishLeader.h"


// Sets default values
AFishLeader::AFishLeader()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EnableSplineTick = true;
	NextLeaderLocation = FVector(0, 0, 0);
	AddLeaderTimerInterval = 0;
	RemoveLeaderLocationInterval = 0;
	AddIndex = 0;
	RemoveIndex = 0;

}

void AFishLeader::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(UnusedHandle, this, &AFishLeader::AddNextLeaderLocation, AddLeaderTimerInterval, true);
	GetWorldTimerManager().SetTimer(UnusedHandle, this, &AFishLeader::RemoveLeaderLocation, RemoveLeaderLocationInterval, true);
}

void AFishLeader::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	LeaderLocation.Add(GetActorLocation());

	// GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::SanitizeFloat(LeaderLocation.Last().X));
	// GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::SanitizeFloat(LeaderLocation.Last().Y));
	// GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::SanitizeFloat(LeaderLocation.Last().Z));

}

void AFishLeader::AddNextLeaderLocation()
{	
	if (LeaderLocation.IsValidIndex(AddIndex))
	{
		NextLeaderLocation = LeaderLocation[AddIndex];
		// GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::SanitizeFloat(AddIndex));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString("Maybe u should increase Leader's TickInterval !!"));
		// GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::SanitizeFloat(AddIndex));

	}

	AddIndex++;
}

void AFishLeader::RemoveLeaderLocation()
{	
	if (LeaderLocation.IsValidIndex(RemoveIndex))
	{

		LeaderLocation.RemoveAt(RemoveIndex);
		// GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::SanitizeFloat(RemoveIndex));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString("Maybe u should increase Leader's TickInterval !!"));
		// GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::SanitizeFloat(RemoveIndex));

	}

	RemoveIndex++;
}