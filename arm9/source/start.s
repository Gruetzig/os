.section .text.start
.align 4
.arm

.global _start
_start:
	@ Set stack pointer
    ldr sp, =20018000
/*
	@ Setup heap
    ldr r0, =fake_heap_start
    ldr r1, =__HEAP_ADDR
    str r1, [r0]

    ldr r0, =fake_heap_end
    ldr r1, =__HEAP_END
    str r1, [r0]
*/
    b main
