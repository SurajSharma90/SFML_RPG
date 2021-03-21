CXX = g++

STD_ARGS = -std=c++2a
WARN_ARGS = -Wall -Wextra -Wpedantic
OPT_ARGS = -O2

CFLAGS = -c $(STD_ARGS) $(WARN_ARGS) $(OPT_ARGS)

SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = .

OBJ_FILES = obj/stdafx.o obj/main.o obj/Game.o obj/MainMenuState.o obj/GameState.o obj/EditorMode.o obj/EnemyEditorMode.o obj/DefaultEditorMode.o obj/EditorState.o obj/SettingsState.o obj/Gui.o obj/State.o obj/GraphicsSettings.o obj/PauseMenu.o obj/TileMap.o obj/PlayerGUI.o obj/Sword.o obj/Bow.o obj/TextTagSystem.o obj/Player.o obj/AIFollow.o obj/AIOption.o obj/AnimationComponent.o obj/AttributeComponent.o obj/Bird1.o obj/CharacterTab.o obj/VectorMath.o obj/Enemy.o obj/EnemySpawnerTile.o obj/EnemySystem.o obj/Entity.o obj/HitboxComponent.o obj/Inventory.o obj/Item.o obj/MeleeWeapon.o obj/MovementComponent.o obj/PlayerGUITabs.o obj/RangedWeapon.o obj/Rat.o obj/RegularTile.o obj/SkillComponent.o obj/Tab.o obj/Tile.o obj/Weapon.o

LINK_LIBS = -lGL -lGLEW -lsfml-graphics -lsfml-window -lsfml-system

LFLAGS = $(LINK_LIBS) -o $(BIN_DIR)/a.out

.PHONY:
	all clean

all: bin obj/VectorMath.o obj/main.o
	$(CXX) $(STD_ARGS) $(WARN_ARGS) $(OBJ_FILES) $(LFLAGS)

clean:
	rm -rf a.out obj

obj:
	mkdir -p obj

bin:
	mkdir -p bin

obj/stdafx.o: obj 
	$(CXX) $(CFLAGS) $(SRC_DIR)/stdafx.cpp -o $(OBJ_DIR)/stdafx.o

obj/main.o: obj/stdafx.o obj/Game.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o

obj/Game.o: obj obj/stdafx.o obj/MainMenuState.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/Game.cpp -o $(OBJ_DIR)/Game.o

obj/MainMenuState.o: obj obj/stdafx.o obj/GameState.o obj/EditorState.o obj/SettingsState.o obj/Gui.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/MainMenuState.cpp -o $(OBJ_DIR)/MainMenuState.o

obj/GameState.o: obj obj/stdafx.o obj/State.o obj/PauseMenu.o obj/TileMap.o obj/PlayerGUI.o obj/Sword.o obj/Bow.o obj/TextTagSystem.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/GameState.cpp -o $(OBJ_DIR)/GameState.o

obj/EditorState.o: obj obj/stdafx.o obj/State.o obj/Gui.o obj/PauseMenu.o obj/TileMap.o obj/EditorMode.o obj/EnemyEditorMode.o obj/DefaultEditorMode.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/EditorState.cpp -o $(OBJ_DIR)/EditorState.o

obj/SettingsState.o: obj obj/stdafx.o obj/Player.o obj/Gui.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/SettingsState.cpp -o $(OBJ_DIR)/SettingsState.o

obj/Gui.o: obj obj/stdafx.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/Gui.cpp -o $(OBJ_DIR)/Gui.o

obj/State.o: obj obj/stdafx.o obj/Player.o obj/GraphicsSettings.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/State.cpp -o $(OBJ_DIR)/State.o

obj/GraphicsSettings.o: obj obj/stdafx.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/GraphicsSettings.cpp -o $(OBJ_DIR)/GraphicsSettings.o

obj/PauseMenu.o: obj obj/stdafx.o obj/Gui.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/PauseMenu.cpp -o $(OBJ_DIR)/PauseMenu.o

obj/TileMap.o: obj obj/stdafx.o obj/EnemySpawnerTile.o obj/RegularTile.o obj/EnemySystem.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/TileMap.cpp -o $(OBJ_DIR)/TileMap.o

obj/PlayerGUI.o: obj obj/stdafx.o obj/PlayerGUITabs.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/PlayerGUI.cpp -o $(OBJ_DIR)/PlayerGUI.o

obj/Sword.o: obj obj/stdafx.o obj/MeleeWeapon.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/Sword.cpp -o $(OBJ_DIR)/Sword.o

obj/Bow.o: obj obj/stdafx.o obj/RangedWeapon.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/Bow.cpp -o $(OBJ_DIR)/Bow.o

obj/TextTagSystem.o: obj obj/stdafx.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/TextTagSystem.cpp -o $(OBJ_DIR)/TextTagSystem.o

obj/Player.o: obj obj/stdafx.o obj/Entity.o obj/Inventory.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/Player.cpp -o $(OBJ_DIR)/Player.o

obj/EditorMode.o: obj obj/stdafx.o obj/State.o obj/TileMap.o obj/Gui.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/EditorMode.cpp -o $(OBJ_DIR)/EditorMode.o

obj/AIComponent.o: obj obj/stdafx.o obj/Entity.o obj/AIFollow.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/AIComponent.cpp -o $(OBJ_DIR)/AIComponent.o

obj/AIFollow.o: obj obj/stdafx.o obj/AIOption.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/AIFollow.cpp -o $(OBJ_DIR)/AIFollow.o

obj/AIOption.o: obj obj/stdafx.o obj/Entity.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/AIOption.cpp -o $(OBJ_DIR)/AIOption.o

obj/AnimationComponent.o: obj obj/stdafx.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/AnimationComponent.cpp -o $(OBJ_DIR)/AnimationComponent.o

obj/AttributeComponent.o: obj obj/stdafx.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/AttributeComponent.cpp -o $(OBJ_DIR)/AttributeComponent.o

obj/Bird1.o: obj obj/stdafx.o obj/Enemy.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/Bird1.cpp -o $(OBJ_DIR)/Bird1.o

obj/CharacterTab.o: obj obj/stdafx.o obj/Tab.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/CharacterTab.cpp -o $(OBJ_DIR)/CharacterTab.o

obj/DefaultEditorMode.o: obj obj/stdafx.o obj/EditorMode.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/DefaultEditorMode.cpp -o $(OBJ_DIR)/DefaultEditorMode.o

obj/EnemyEditorMode.o: obj obj/stdafx.o obj/EditorMode.o obj/EnemySpawnerTile.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/EnemyEditorMode.cpp -o $(OBJ_DIR)/EnemyEditorMode.o

obj/Enemy.o: obj obj/stdafx.o obj/Entity.o obj/EnemySpawnerTile.o obj/AIFollow.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/Enemy.cpp -o $(OBJ_DIR)/Enemy.o

obj/EnemySpawnerTile.o: obj obj/stdafx.o obj/Tile.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/EnemySpawnerTile.cpp -o $(OBJ_DIR)/EnemySpawnerTile.o

obj/EnemySystem.o: obj obj/stdafx.o obj/EnemySpawnerTile.o obj/Rat.o obj/Bird1.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/EnemySystem.cpp -o $(OBJ_DIR)/EnemySystem.o

obj/Entity.o: obj obj/stdafx.o obj/HitboxComponent.o obj/MovementComponent.o obj/AnimationComponent.o obj/AttributeComponent.o obj/SkillComponent.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/Entity.cpp -o $(OBJ_DIR)/Entity.o

obj/HitboxComponent.o: obj obj/stdafx.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/HitboxComponent.cpp -o $(OBJ_DIR)/HitboxComponent.o

obj/Inventory.o: obj obj/stdafx.o obj/Item.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/Inventory.cpp -o $(OBJ_DIR)/Inventory.o

obj/Item.o: obj obj/stdafx.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/Item.cpp -o $(OBJ_DIR)/Item.o

obj/MeleeWeapon.o: obj obj/stdafx.o obj/Weapon.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/MeleeWeapon.cpp -o $(OBJ_DIR)/MeleeWeapon.o

obj/MovementComponent.o: obj obj/stdafx.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/MovementComponent.cpp -o $(OBJ_DIR)/MovementComponent.o

obj/PlayerGUITabs.o: obj obj/stdafx.o obj/CharacterTab.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/PlayerGUITabs.cpp -o $(OBJ_DIR)/PlayerGUITabs.o

obj/RangedWeapon.o: obj obj/stdafx.o obj/Weapon.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/RangedWeapon.cpp -o $(OBJ_DIR)/RangedWeapon.o

obj/Rat.o: obj obj/stdafx.o obj/Enemy.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/Rat.cpp -o $(OBJ_DIR)/Rat.o

obj/RegularTile.o: obj obj/stdafx.o obj/Tile.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/RegularTile.cpp -o $(OBJ_DIR)/RegularTile.o

obj/SkillComponent.o: obj obj/stdafx.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/SkillComponent.cpp -o $(OBJ_DIR)/SkillComponent.o

obj/Tab.o: obj obj/stdafx.o obj/Player.o obj/Gui.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/Tab.cpp -o $(OBJ_DIR)/Tab.o

obj/Tile.o: obj obj/stdafx.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/Tile.cpp -o $(OBJ_DIR)/Tile.o

obj/VectorMath.o: obj obj/stdafx.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/VectorMath.cpp -o $(OBJ_DIR)/VectorMath.o

obj/Weapon.o: obj obj/stdafx.o obj/Item.o
	$(CXX) $(CFLAGS) $(SRC_DIR)/Weapon.cpp -o $(OBJ_DIR)/Weapon.o


