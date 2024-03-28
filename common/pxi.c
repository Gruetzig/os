#include "types.h"
#include "pxi.h"

enum {
    PXI_BUFFERDATA = 1,
};

void PXI_Init() {
    *PXI_CNT = PXI_CNT_SEND_CLEAR | PXI_CNT_ENABLE_FIFO;
}

void PXI_Send(u32 word) {
    while (*PXI_CNT & PXI_CNT_SEND_FULL);
    *PXI_SEND = word;
}

u32 PXI_Recv() { //maybe timeout later?
    while (*PXI_CNT & PXI_CNT_RECV_EMPTY);
    return *PXI_RECV;
}

void PXI_WaitForEmptySend() {
    while (*PXI_CNT & PXI_CNT_SEND_EMPTY);
}

void PXI_SendBuffer(void* pointer, u32 size) {
    PXI_Send(PXI_BUFFERDATA);
    PXI_Send(size);
    PXI_Send((u32)pointer);
}

void* PXI_RecvBuffer(u32* size) {
    u32 recv = PXI_Recv();
    if (recv != PXI_BUFFERDATA) {
        *size = 69;
        return NULL;
    }
    *size = PXI_Recv();
    recv = PXI_Recv();
    return (void*)recv;
}