# Define the target architecture and compiler
ARCH = armv5te
CC = arm-none-eabi-gcc
# CC = $(HOME)/opt/cross/bin/arm-none-eabi-gcc


# Define the source files
SOURCES = source source/drivers source/drivers/fatfs source/drawing ../common ../common/console
INCLUDE = $(foreach dir,$(SOURCES),-I "$(shell pwd)/$(dir)")
SFILES	= $(foreach dir, $(SOURCES), $(wildcard $(dir)/*.s))
CFILES	= $(foreach dir, $(SOURCES), $(wildcard $(dir)/*.c))

# Define the object files that will be generated from the source files
C_OBJECTS = $(CFILES:.c=.arm9.o)
ASM_OBJECTS = $(SFILES:.s=.arm9.o)
OBJECTS = $(C_OBJECTS) $(ASM_OBJECTS)

# Define the name of the target executable
ELF = arm9.elf

# Define the flags to be passed to the compiler
CFLAGS = -DARM9 $(INCLUDE) -march=$(ARCH) -O2 -Wall -mthumb -ffreestanding
LDFLAGS = -T link.ld -Wl,--no-warn-rwx-segments -lgcc -nostartfiles -nostdlib
# Define the default target to build when no target is specified
all: $(ELF)

# Define a rule to build the target executable
$(ELF): $(OBJECTS)
	@echo [ARM9] Linking together to $@
	@$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

# Define a rule to build the C object files
%.arm9.o: %.c
	@echo [ARM9] Compiling $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Define a rule to build the ASM object files
%.arm9.o: %.s
	@echo [ARM9] Compiling $<
	@$(CC) $(CFLAGS) -c $< -o $@


# Define a rule to clean up the project directory
clean:
	@echo [ARM9] Cleaning up...
	@rm -f $(ELF)
	@rm -f $(OBJECTS)
