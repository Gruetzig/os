# Define the name of the target executable
EXECUTABLE = my_program
ARM9ELF = arm9/arm9.elf
# ARM11ELF = arm11.elf
# Define the default target to build when no target is specified
all: $(EXECUTABLE).firm

$(ARM9ELF):
	make -C arm9

#$(ARM11ELF):
#	make -C arm11

$(EXECUTABLE).firm: $(ARM9ELF)
	@echo $(ARM9ELF)
	firmtool build $@ -n 0x08006000 -e 0 -D $< -A 0x08006000 -C memcpy -i
#	firmtool build $@ -n 0x08006000 -e 0 -D $(ARM9ELF) $(ARM11ELF) -A 0x08006000 -C memcpy -i

clean:
	make -C arm9 clean
	#make -C arm11 clean
	rm -f $(EXECUTABLE).firm
