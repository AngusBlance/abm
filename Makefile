CC = gcc
CFLAGS = -Wall -Wextra -g3 -I$(CORE_DIR)
LDFLAGS = -lm
SRC_DIR = src
CORE_DIR = $(SRC_DIR)/core
MAIN_DIR = $(SRC_DIR)/main
TEST_DIR = $(SRC_DIR)/test
OUTPUT_DIR = output

# Main application
main: $(MAIN_DIR)/main.c $(CORE_DIR)/agent.c $(CORE_DIR)/agent.h
	$(CC) $(CFLAGS) $(MAIN_DIR)/main.c $(CORE_DIR)/agent.c $(LDFLAGS) -o $(OUTPUT_DIR)/main

# Test application
test: $(TEST_DIR)/arrest_test.c $(CORE_DIR)/agent.c $(CORE_DIR)/agent.h
	$(CC) $(CFLAGS) $(TEST_DIR)/arrest_test.c $(CORE_DIR)/agent.c $(LDFLAGS) -o $(OUTPUT_DIR)/arrest_test

# Build both
all: main test

# Clean build artifacts
clean:
	rm -f $(OUTPUT_DIR)/main $(OUTPUT_DIR)/arrest_test

# Run main application
run: main
	./$(OUTPUT_DIR)/main

# Run test
run-test: test
	./$(OUTPUT_DIR)/arrest_test

.PHONY: main test all clean run run-test 