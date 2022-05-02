# Save Data Plugin
A system used to easily save/load game data

## Installation
1. Download the latest release from GitHub
2. Navigate to `C:\Program Files\Epic Games\UE_{VERSION}\Engine\Plugins\`
3. Create a `Marketplace` folder if needed
4. Extract the release and copy to the `Marketplace` folder
5. Open Unreal Engine
6. Click on `Edit > Plugins`
7. Enable the plugin under the `Installed > Unreal Toolbox` category
8. Restart Unreal Engine

## Save Data
You need to create a `Save Game` object before you can save/load data. This object contains all the variables/data that you want to save

## Save Manager
The `Save Manager` is used to save and load the data specified in the `Save Game` object. This actor needs to be placed in every map where you use the save system. You need to set the following properties before you can use the `Save Manager`:
1. `Save Game Class` - A reference to the `Save Game` class that contains the data you want to save

The following functions can be used to interact with the `Save Manager`
1. `Set Current Save Slot` - Set the current save slot
2. `Get Save Data` - Return the save data at the current save slot
3. `Save Data` - Save the data to the current save slot
4. `Is Save Slot Used` - Return a boolean value indicating if the specified save slot is in use

You are required to set the save slot before using any of the other functions. If not, you will get `nullptr` and might cause the game to crash