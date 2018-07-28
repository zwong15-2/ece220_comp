#Compiler
CC = g++
CFLAGS = -g -Wall

#Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TST_DIR = tests
OUT_DIR = output

#Files
SOURCES  := $(wildcard $(SRC_DIR)/*.cpp)
INCLUDES := $(wildcard $(SRC_DIR)/.*h)
OBJECTS  := $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
TESTS    := $(wildcard $(TST_DIR)/*_test.cpp)

#Binaries
EXEC = rectangle
TARGET := $(BIN_DIR)/$(EXEC)

.PHONY: all
all: $(TARGET)

$(TARGET): dirs $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

$(OBJECTS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: dirs
dirs:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)
	mkdir -p $(OUT_DIR)

.PHONY: test
test:
	bash ./$(TST_DIR)/runtests.sh

.PHONY: clean
clean:
	rm -rf $(BIN_DIR)
	rm -rf $(OBJ_DIR)
	rm -rf $(OUT_DIR)
