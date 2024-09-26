# build:
# 	g++ hw3_prog.cpp -o checkmatrix

# all:build
# Makefile for hw3_prog

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g -std=c++11

# Target executable
TARGET = checkmatrix

# Source files
SRCS = hw3_prog.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove compiled files
clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean

