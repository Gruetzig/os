# Define the name of the target executable
EXECUTABLE = my_program
ARM9ELF = arm9/arm9.elf
ARM11ELF = arm11/arm11.elf

# Define the default target to build when no target is specified
all: $(EXECUTABLE).firm

.PHONY: $(ARM9ELF) $(ARM11ELF)

# Define a rule to build the arm9 elf file
$(ARM9ELF):
	@echo Building arm9 $@
	@make --no-print-directory -C arm9

# Define a rule to build the arm11 elf file
$(ARM11ELF):
	@echo Building arm11 $@
	@make --no-print-directory -C arm11

#Define a rule to build the firm file
$(EXECUTABLE).firm: $(ARM9ELF) $(ARM11ELF)
	@echo building $@
#	@firmtool build $@ -n 0x08006000 -e 0 -D $< -A 0x08006000 -C memcpy -i
	@firmtool build $@ -n 0x08006000 -e 0x1FF80000 -D $(ARM9ELF) $(ARM11ELF) -A 0x08006000 0x1FF80000 -C NDMA XDMA -i

clean:
	@make --no-print-directory -C arm9 clean
	@make --no-print-directory -C arm11 clean
	@rm -f $(EXECUTABLE).firm
