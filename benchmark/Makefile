NAME  = task
CXSRC = $(wildcard src/*.cpp)
CSRC  = $(wildcard src/*.c)

TARGET = benchmark_$(NAME)

LIBDIR  = ../lib
LIB     = lib$(NAME).so
BUILD   = build
LIBDEP  = $(LIBDIR)/$(BUILD)/$(LIB)


OBJ := $(patsubst %.cpp,$(BUILD)/%.o,$(CXSRC)) $(patsubst %.c,$(BUILD)/%.o,$(CSRC))

LIBRARIES = -lpthread -lbenchmark -lbenchmark_main -l$(NAME)
UNAME := $(shell uname -s)

ifeq ($(UNAME), Darwin)
CC       = cc
CXX      = c++
CFLAGS   = -std=c11 -Wall -g -fsanitize=address -I$(LIBDIR)/src -I..
CXXFLAGS = -std=c++17 -Wall -g -fsanitize=address -I$(LIBDIR)/src -I..
else
CC     = gcc
CXX    = g++
CFLAGS   = -std=c11 -Wall -fPIC -fsanitize=address -I$(LIBDIR)/src -I..
CXXFLAGS = -std=c++17 -Wall -fPIC -fsanitize=address -I$(LIBDIR)/src -I..
endif

all:  build $(TARGET) $(OBJ) $(LIBDEP)

$(TARGET) : build $(OBJ) $(LIBDEP)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(BUILD)/$(TARGET) -l$(NAME) $(LIBRARIES) -l$(NAME) -L$(LIBDIR)/$(BUILD) -I$(LIBDIR)

build:
	mkdir -p "$(BUILD)/src"

$(LIBDEP) :
	cd $(LIBDIR) && make

run: $(TARGET)
	./$(BUILD)/$(TARGET)

$(BUILD)/%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD)/%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD)
