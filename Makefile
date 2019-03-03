# Pekka Kana 2 by Janne Kivilahti from Piste Gamez (2003-2007)
# https://pistegamez.net/game_pk2.html
#
# This public release and rewritten is governed by a BSD-2-clause license.
#
# Makefile command:
# "make" - Creates Pekka Kana 2 binary
# "make clean" - Removes all objects, executables and dependencies

CPP = g++
CFLAGS += $(shell pkg-config --cflags sdl2) -g -O2 -std=gnu++17 -Wno-write-strings
LFLAGS += $(shell pkg-config --libs sdl2) -lSDL2_mixer

# Defines directories
SRC_DIR = src/
BIN_DIR = bin/
BUILD_DIR = build/

# Defines the engine and src used in main codes
ENGINE_SRC  = $(wildcard $(SRC_DIR)*.cpp)
ENGINE_OBJ := $(basename $(ENGINE_SRC))
ENGINE_OBJ := $(notdir $(ENGINE_OBJ))
ENGINE_OBJ := $(addsuffix .o, $(ENGINE_OBJ))
ENGINE_OBJ := $(addprefix $(BUILD_DIR), $(ENGINE_OBJ))

PK2_SPRITE_SRC = $(SRC_DIR)sprite.cpp
PK2_SPRITE_OBJ = $(BUILD_DIR)sprite.o

PK2_MAP_SRC = $(SRC_DIR)map.cpp
PK2_MAP_OBJ = $(BUILD_DIR)map.o

PK2_SRC = $(SRC_DIR)pk2.cpp
PK2_OBJ = $(BUILD_DIR)pk2.o

# Defines the destination of each binary file
PK2_BIN = $(BIN_DIR)/pekka-kana-2

DEPENDENCIES := $(PK2_OBJ) $(PK2_SPRITE_OBJ) $(PK2_MAP_OBJ) $(ENGINE_OBJ)
DEPENDENCIES := $(basename $(DEPENDENCIES))
DEPENDENCIES := $(addsuffix .d, $(DEPENDENCIES))

pk2: makedirs $(PK2_BIN)

# Rules for generate the binaries using the object files
$(PK2_BIN): $(PK2_OBJ) $(PK2_SPRITE_OBJ) $(PK2_MAP_OBJ) $(ENGINE_OBJ)
	@echo -Linking Pekka Kana 2
	@$(CPP) $^ $(LFLAGS) -o $@

# Rules for generate any *.o file
-include $(DEPENDENCIES)

build/%.o : src/%.cpp
	@echo -Some dependence of $@ was changed, updating
	@$(CPP) $(CFLAGS) -I$(SRC_DIR) -o $@ -c $<
	@$(CPP) -MM -MT $@ -I$(SRC_DIR) $< > build/$*.d

makedirs:
	@mkdir -p $(BIN_DIR) >/dev/null
	@mkdir -p $(BUILD_DIR) >/dev/null

clean:
	@rm -rf $(BIN_DIR)
	@rm -rf $(BUILD_DIR)

.PHONY: pk2 clean makedirs
