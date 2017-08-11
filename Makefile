# Binary
BIN := ep1rand

# Flags
CFLAGS   := # e.g. -Wall -Wextra -Wpedantic -Werror -O2
LDFLAGS  := # e.g. -lm
CPPFLAGS := -D MATRIX # or -D LIST
CLIBS    := -I include

# Directories
INCDIR := include
SRCDIR := src
OBJDIR := build
BINDIR := bin

# Programs
RM    := rm -f
RMDIR := rm -rf
MKDIR := mkdir -p

# Subdirectories
SRCSUB := $(filter-out $(SRCDIR),$(shell find $(SRCDIR) -type d))
OBJSUB := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SRCSUB))

# Files
SRC := $(foreach d,$(SRCDIR) $(SRCSUB), $(wildcard $d/*.c))
OBJ := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

# Phony targets
.PHONY: all
all: $(BINDIR)/$(BIN)

.PHONY: nothing
nothing:

# Recipes
$(BINDIR)/$(BIN): $(OBJ) | $(BINDIR)
	$(CC) $(CPPFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR) $(OBJSUB)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(CLIBS) -c $< -o $@

$(OBJDIR) $(OBJSUB) $(BINDIR):
	$(MKDIR) $@

# Clean
.PHONY: clean
clean:
	$(RMDIR) $(OBJDIR)
	$(RMDIR) $(BINDIR)

# Debug
.PHONY: debug
debug:
	@echo $(SRC)
	@echo $(OBJ)
	@echo $(SRCSUB)
	@echo $(OBJSUB)
