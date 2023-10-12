.section .text.start
.align 4
.arm

.global _start
_start:
	@ Set stack pointer
    ldr sp, =20018000
    b main
