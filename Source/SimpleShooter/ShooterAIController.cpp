// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"

#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"

void AShooterAIController::BeginPlay() {
    Super::BeginPlay();
    
    if (AIBehsvior != nullptr) {
        RunBehaviorTree(AIBehsvior);
        APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

        
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
    }
}

void AShooterAIController::Tick(float DeltaSecounds){
    Super::Tick(DeltaSecounds);
    
}

bool AShooterAIController::IsDead() const {
    AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
    if (ControlledCharacter != nullptr) {
        return ControlledCharacter->IsDead();
    }

    return true;
}

