.section .text.start
.align 4
.arm

.global _start
_start:
	@ Set stack pointer
    ldr sp, =0x20018000
    b main
