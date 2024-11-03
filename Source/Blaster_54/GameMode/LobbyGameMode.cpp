// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	//현재 로비에 들어온 플레이어 수 추적
	int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();
	if (NumberOfPlayers == 2)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			//seamless 로 안정적인 맵 전환
			bUseSeamlessTravel = true;

			//리슨서버로
			World->ServerTravel(FString("/Game/Maps/BlasterMap?listen"));
		}
	}
}
