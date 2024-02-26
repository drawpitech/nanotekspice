##
## EPITECH PROJECT, 2024
## tekspice
## File description:
## Makefile
##

# ↓ Basic variables
CXX := g++ -std=c++20
CXXFLAGS := -W -Wall -Wextra -Wunused -Wpedantic
CXXFLAGS += -Wundef -Wshadow -Wcast-align
# CXXFLAGS += -Waggregate-return
CXXFLAGS += -Wcast-qual
CXXFLAGS += -Wunreachable-code
CXXFLAGS += -U_FORTIFY_SOURCE
CXXFLAGS += -iquote ./src
CXXFLAGS += -iquote ./include

# ↓ Binaries
NAME := nanotekspice
TEST_NAME := unit_tests
DEBUG_NAME := debug
PROF_NAME := prof

# Source files
SRC := $(shell find ./src -name "*.cpp")

# Tests files
TEST_SRC := $(subst ./src/main.cpp,,$(SRC))

# ↓ Objects
BUILD_DIR := .build
OBJ := $(SRC:%.cpp=$(BUILD_DIR)/source/%.o)
TEST_OBJ := $(TEST_SRC:%.cpp=$(BUILD_DIR)/tests/%.o)
DEBUG_OBJ := $(SRC:%.cpp=$(BUILD_DIR)/debug/%.o)
PROF_OBJ := $(SRC:%.cpp=$(BUILD_DIR)/prof/%.o)

# ↓ Dependencies for headers
DEPS_FLAGS := -MMD -MP
DEPS := $(OBJ:.o=.d)
TEST_DEPS := $(TEST_OBJ:.o=.d)
DEBUG_DEPS := $(DEBUG_OBJ:.o=.d)
PROF_DEPS := $(PROF_OBJ:.o=.d)

ECHO := echo -e
DIE := exit 1
# ↓ Colors
ECHO := echo -e
C_RESET := \033[00m
C_BOLD := \e[1m
C_RED := \e[31m
C_GREEN := \e[32m
C_YELLOW := \e[33m
C_BLUE := \e[34m
C_PURPLE := \e[35m
C_CYAN := \e[36m

.DEFAULT_GOAL := all

all: $(NAME)

# ↓ Compiling
$(BUILD_DIR)/source/%.o: %.cpp
	@ mkdir -p $(dir $@)
	@ $(ECHO) "[${C_BOLD}${C_RED}CXX${C_RESET}] $^"
	@ $(CXX) -o $@ -c $< $(CXXFLAGS) $(DEPS_FLAGS) || $(DIE)

$(NAME): $(OBJ)
	@ $(ECHO) "[${C_BOLD}${C_YELLOW}CXX${C_RESET}] ${C_GREEN}$@${C_RESET}"
	@ $(CXX) -o $@ $^ $(CXXFLAGS) || $(DIE)

# ↓ Unit tests
$(BUILD_DIR)/tests/%.o: %.cpp
	@ mkdir -p $(dir $@)
	@ $(ECHO) "[${C_BOLD}${C_RED}CXX${C_RESET}] $^"
	@ $(CXX) -o $@ -c $< $(CXXFLAGS) $(DEPS_FLAGS) || $(DIE)

ifneq ($(NO_COV), 1)
$(TEST_NAME): CXXFLAGS += -g3 --coverage
endif
$(TEST_NAME): CXXFLAGS += -lcriterion
$(TEST_NAME): $(TEST_OBJ)
	@ $(ECHO) "[${C_BOLD}${C_YELLOW}CXX${C_RESET}] ${C_GREEN}$@${C_RESET}"
	@ $(CXX) -o $@ $^ $(CXXFLAGS) || $(DIE)

tests_run: $(TEST_NAME)
	@ ./$^

.PHONY: tests_run

# ↓ Asan
$(BUILD_DIR)/debug/%.o: %.cpp
	@ mkdir -p $(dir $@)
	@ $(ECHO) "[${C_BOLD}${C_RED}CXX${C_RESET}] $^"
	@ $(CXX) -o $@ -c $< $(CXXFLAGS) $(DEPS_FLAGS) || $(DIE)

$(DEBUG_NAME): CXXFLAGS += -fanalyzer
$(DEBUG_NAME): CXXFLAGS +=  -g3 -D DEBUG_MODE
$(DEBUG_NAME): $(DEBUG_OBJ)
	@ $(ECHO) "[${C_BOLD}${C_YELLOW}CXX${C_RESET}] ${C_GREEN}$@${C_RESET}"
	@ $(CXX) -o $@ $^ $(CXXFLAGS) || $(DIE)

# ↓ Profiler
$(BUILD_DIR)/prof/%.o: %.cpp
	@ mkdir -p $(dir $@)
	@ $(ECHO) "[${C_BOLD}${C_RED}CXX${C_RESET}] $^"
	@ $(CXX) -o $@ -c $< $(CXXFLAGS) $(DEPS_FLAGS) || $(DIE)

$(PROF_NAME): CXXFLAGS += -pg
$(PROF_NAME): $(PROF_OBJ)
	@ $(ECHO) "[${C_BOLD}${C_YELLOW}CXX${C_RESET}] ${C_GREEN}$@${C_RESET}"
	@ $(CXX) -o $@ $^ $(CXXFLAGS) || $(DIE)

# ↓ Coverage
cov: GCOVR_FLAGS := --exclude bonus/
cov: GCOVR_FLAGS += --exclude tests/
cov:
	@ gcovr $(GCOVR_FLAGS)
	@ gcovr $(GCOVR_FLAGS) --branches

.PHONY: cov

# ↓ Cleaning
clean:
	@ $(RM) $(OBJ) $(TEST_OBJ) $(DEBUG_OBJ)

fclean: clean
	@ $(RM) $(NAME) $(TEST_NAME) $(DEBUG_NAME) $(PROF_NAME)
	@ $(RM) -r $(BUILD_DIR)

.PHONY: clean fclean

re: fclean all

.NOTPARALLEL: re
.PHONY: re

-include $(DEPS)
-include $(TEST_DEPS)
-include $(DEBUG_DEPS)
-include $(PROF_DEPS)
