#pragma once

#include "GameFramework/SaveGame.h"
#include "GameFramework/Actor.h"
#include "SaveManager.generated.h"

/**
 * @brief Responsible for saving/loading game data
 */
UCLASS()
class UTSAVEDATA_API ASaveManager final : public AActor
{
	GENERATED_BODY()
	
public:
	/**
	 * @brief The class that holds the data that should be saved/loaded
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Save Data")
	TSubclassOf<USaveGame> SaveGameClass;

	/**
	 * @brief Get the save data that is currently loaded
	 * @return A reference to the current save data
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Save Manager")
	USaveGame* GetSaveData() const;

	/**
	 * @brief Save the modified data currently in memory
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Save Manager")
	void SaveData();

	/**
	 * @brief Set the current save slot
	 * @param Index The index of the save slot
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Save Manager")
	void SetCurrentSaveSlot(int Index);

	/**
	 * @brief Check if a save slot is used
	 * @param Index The index of the save slot to check
	 * @return A boolean value indicating if the save slot is used
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Save Manager")
	bool IsSaveSlotUsed(int Index);

private:
	/**
	 * @brief A reference to the loaded save data
	 */
	UPROPERTY()
    USaveGame* CurrentSaveGame;
	
	/**
	 * @brief The index of the save slot currently loaded
	 */
	int CurrentSaveSlot;

	/**
	 * @brief Load data at the specified index
	 * @param Index The save slot index to load data from
	 */
	void LoadData(int Index);
	
	/**
	 * @brief Get the save file name for the save slot
	 * @param Index The index of the save slot
	 * @return The file name of the save slot at the specified index
	 */
	FString GetSaveSlotName(int Index);
};