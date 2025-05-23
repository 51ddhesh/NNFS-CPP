# Use 'make FILE=filename.cpp' to compile

# The source file to compile (passed as an argument)
FILE ?= main.cpp

# Get the base name without extension
OUT := $(basename $(notdir $(FILE)))

# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++23

# Default target
all:
	$(CXX) $(CXXFLAGS) -o out $(FILE)

# Clean the output binary
clean:
	rm -f out
