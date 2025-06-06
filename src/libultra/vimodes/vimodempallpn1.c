#include "PR/os.h"
#include "PR/rcp.h"
#include "PR/viint.h"

OSViMode osViModeMpalLpn1 = {
    OS_VI_MPAL_LPN1, // type
    {
        // comRegs
        VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_GAMMA_ON | VI_CTRL_ANTIALIAS_MODE_2 |
            VI_CTRL_PIXEL_ADV_3, // ctrl
        WIDTH(320),              // width
        BURST(57, 30, 5, 70),    // burst
        VSYNC(525),              // vSync
        HSYNC(3089, 4),          // hSync
        LEAP(3097, 3098),        // leap
        HSTART(108, 748),        // hStart
        SCALE(2, 0),             // xScale
        VCURRENT(0),             // vCurrent
    },
    { // fldRegs
      {
          // [0]
          ORIGIN(640),        // origin
          SCALE(1, 0),        // yScale
          HSTART(37, 511),    // vStart
          BURST(4, 2, 14, 0), // vBurst
          VINTR(2),           // vIntr
      },
      {
          // [1]
          ORIGIN(640),        // origin
          SCALE(1, 0),        // yScale
          HSTART(37, 511),    // vStart
          BURST(4, 2, 14, 0), // vBurst
          VINTR(2),           // vIntr
      } },
};
