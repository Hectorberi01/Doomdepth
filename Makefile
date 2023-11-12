# A generic build template for C programs

# executable name
EXE = prod

# C compiler
CC = gcc
# linker
LD = gcc

# C flags
CFLAGS = -Wall 
# dependency-generation flags
DEPFLAGS = -MMD -MP -lncurses
# linker flags
LDFLAGS = 
# library flags
LDLIBS = -lncurses -ltinfo -lSDL2-2.0 -lSDL2_image

# build directories
BIN = bin
OBJ = obj
SRC = src

SOURCES := $(wildcard $(SRC)/*.c)

OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(wildcard $(SRC)/*.c)) 

# include compiler-generated dependency rules
DEPENDS := $(OBJECTS:.o=.d)

# compile C source
COMPILE.c = $(CC) -c -o $@
# compile C++ source
COMPILE.cxx = $(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) -c -o $@
# link objects
LINK.o = $(LD) -o $@ $(OBJECTS) $(LDFLAGS) $(LDLIBS) 

.DEFAULT_GOAL = all

.PHONY: all
all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(SRC) $(OBJ) $(BIN) $(OBJECTS)
	$(LINK.o)

$(SRC):
	mkdir -p $(SRC)

$(OBJ):
	mkdir -p $(OBJ)

$(BIN):
	mkdir -p $(BIN)

$(OBJ)/%.o:	$(SRC)/%.c
	$(COMPILE.c) $< $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) 

# force rebuild
.PHONY: remake
remake:	clean $(BIN)/$(EXE)

# execute the program
.PHONY: run
run: $(BIN)/$(EXE)
	./$(BIN)/$(EXE)

# remove previous build and objects
.PHONY: clean
clean:
	$(RM) $(OBJECTS)
	$(RM) $(DEPENDS)
	$(RM) $(BIN)/$(EXE)

# remove everything except source
.PHONY: reset
reset:
	$(RM) -r $(OBJ)
	$(RM) -r $(BIN)

-include $(DEPENDS)