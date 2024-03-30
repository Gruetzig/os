#include "types.h"
#ifdef ARM9
#define PXI_REGS (0x10008000)
#else
#define PXI_REGS (0x10163000)
#endif
//
#define PXI_SYNC ((vu32*)(PXI_REGS + 0x0))
#define PXI_CNT  ((vu32*)(PXI_REGS + 0x4))
//send/recv
#define PXI_SEND ((vu32*)(PXI_REGS + 0x8))
#define PXI_RECV ((vu32*)(PXI_REGS + 0xC))
//sync irq stuff
#define PXI_SYNC_IRQ11 (1 << 29) //this is irq sutff. I have no clue
#define PXI_SYNC_IRQ9  (1 << 30) //this is irq stuff. I have no clue 
#define PXI_SYNC_IRQ_ENABLE (1 << 31) //disable that shit?
//cnt send
#define PXI_CNT_SEND_EMPTY (1 << 0) //is it empty?
#define PXI_CNT_SEND_FULL  (1 << 1) //is it full?
#define PXI_CNT_SEND_CLEAR (1 << 3) //write this to clear
//cnt recv
#define PXI_CNT_RECV_EMPTY (1 << 8) //is it empty?
#define PXI_CNT_RECV_FULL  (1 << 9) //is it full?
//cnt irqs
#define PXI_CNT_SEND_EMPTY_IRQ     (1 << 2) //yes
#define PXI_CNT_RECV_NOT_EMPTY_IRQ (1 << 10) //what is this again?
//cnt control
#define PXI_CNT_EMPTY_FULL_ERROR (1 << 14) //huh
#define PXI_CNT_ENABLE_FIFO (1 << 15) //yeah lol I think I wanna enable this
//sync send and recv bytes
#define PXI_SYNC_SEND (((vu8*)(PXI_SYNC)) + 0x0)
#define PXI_SYNC_RECV (((vu8*)(PXI_SYNC)) + 0x1)

void PXI_Init();

void PXI_Send(u32 word);
void PXI_Synchronize(u8 magic);
u32 PXI_Recv();
void PXI_WaitForEmptySend();
void PXI_SendBuffer(void* pointer, u32 size);
void* PXI_RecvBuffer(u32* size);
