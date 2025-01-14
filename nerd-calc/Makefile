CC = gcc
CFLAGS = -Wall -g

SRC_DIR = src
BUILD_DIR = src_build
BIN_DIR = bin
TEST_DIR = tests

SRC = $(SRC_DIR)/main.c $(SRC_DIR)/util.c $(SRC_DIR)/calc.c

SRC_OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

EXEC = $(BIN_DIR)/nerd_calc.out

all: $(EXEC) $(TEST_EXEC)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(SRC_OBJ)
	$(CC) $(CFLAGS) $(SRC_OBJ) -o $(EXEC)

clean:
	rm -f $(BUILD_DIR)/*.o $(BIN_DIR)/*

run: $(EXEC)
	./$(EXEC)

.PHONY: all run_tests clean run
