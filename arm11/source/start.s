.section .text.start
.align 4
.arm

.global _start
_start:
	@ Set stack pointer
    ldr sp, =0x20020000
    bl main
