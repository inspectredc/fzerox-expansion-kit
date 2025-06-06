#include "global.h"
#include "fzx_assets.h"

OSContStatus gControllerStatus[MAXCONTROLLERS];
OSContPad gControllerPads[MAXCONTROLLERS];
Controller gControllers[MAXCONTROLLERS + 1];
Controller gSharedController;
s32 gPlayerControlPorts[MAXCONTROLLERS];
s32 gControllersConnected;

extern s16 D_8076C938;

void func_806F5A50(void) {
    s32 i;

    if (D_8076C938 != 0) {
        Controller_UpdateInputs();
        D_8076C938 = 0;
    }

    for (i = 0; i < MAXCONTROLLERS; i++) {
        if (osMotorStop(&gControllers[i].pfs) == 0) {
            gControllers[i].unk_74 = 1;
        } else {
            gControllers[i].unk_74 = 0;
        }
        gControllers[i].unk_72 = gControllers[i].unk_76 = 0;
    }
}

void Controller_ClearInputs(void) {
    Controller* var_v0;

    // clang-format off
    var_v0 = &gControllers[4];\
    do {
        if (var_v0->errno == 0) {
            var_v0->unk_82 = var_v0->buttonCurrent = var_v0->buttonPressed = var_v0->buttonReleased = var_v0->buttonPrev = 0;
            var_v0->stickX = var_v0->stickY = var_v0->stickCurrent = var_v0->stickPressed = var_v0->stickReleased = var_v0->stickPrev = 0;
            var_v0->unk_84 = 0;
        }
        var_v0--;
    } while (var_v0 >= gControllers);
    // clang-format on

    gSharedController.unk_82 = gSharedController.buttonCurrent = gSharedController.buttonPressed =
        gSharedController.buttonReleased = 0;
    gSharedController.stickX = gSharedController.stickY = gSharedController.stickCurrent =
        gSharedController.stickPressed = gSharedController.stickReleased = 0;
}

extern OSContPad gControllerPads[];
extern s32 gControllersConnected;
extern OSMesgQueue gSerialEventQueue;
extern OSMesg D_8079E920;
extern s32 D_8076C930;
extern s32 D_8076C934;
extern s32 D_8076C770;
extern bool gResetStarted;

void Controller_UpdateInputs(void) {
    s32 i;
    s32 j;
    u16 buttonDiff;
    s32 var_fp;
    s32 var_s2;
    s32 var_s6;
    s32 var_s7;
    Controller* controller;
    OSContPad* var_s5;
    s32* var_v0;

    gSharedController.unk_82 = gSharedController.buttonCurrent = gSharedController.buttonPressed =
        gSharedController.buttonReleased = 0;
    var_s6 = 0;
    var_s7 = 0;
    var_fp = 0;
    gSharedController.stickCurrent = gSharedController.stickPressed = gSharedController.stickReleased = 0;

    controller = &gControllers[4];
    i = 4;
    //! @bug OOB array access, no reads are done before going back in bounds
    var_s5 = &gControllerPads[4];

    osRecvMesg(&gSerialEventQueue, &D_8079E920, OS_MESG_BLOCK);
    osContGetReadData(gControllerPads);
    do {
        controller--;
        var_s5--;
        i--;

        if (controller->errno == 0) {
            if ((controller->errno = var_s5->errno) != 0) {
                gControllersConnected--;

                for (j = 3; j >= 0; j--) {
                    if (i == gPlayerControlPorts[j]) {
                        gPlayerControlPorts[j] = PORT_DISCONNECTED;
                        break;
                    }
                }
            } else {
                var_s6++;
                controller->buttonPrev = controller->buttonCurrent;
                gSharedController.buttonCurrent |= controller->buttonCurrent = var_s5->button & CONT_MASK;

                buttonDiff = (controller->buttonPrev ^ controller->buttonCurrent);

                gSharedController.buttonPressed |= controller->buttonPressed = buttonDiff & controller->buttonCurrent;
                gSharedController.buttonReleased |= controller->buttonReleased = buttonDiff & controller->buttonPrev;

                var_fp += controller->stickX = var_s5->stick_x;
                var_s7 += controller->stickY = var_s5->stick_y;

                controller->stickPrev = controller->stickCurrent;

                if (controller->stickX < -50) {
                    controller->stickCurrent = STICK_LEFT;
                } else if (controller->stickX > 50) {
                    controller->stickCurrent = STICK_RIGHT;
                } else {
                    controller->stickCurrent = 0;
                }

                if (controller->stickY < -50) {
                    controller->stickCurrent |= STICK_DOWN;
                } else if (controller->stickY > 50) {
                    controller->stickCurrent |= STICK_UP;
                }

                gSharedController.stickCurrent |= controller->stickCurrent;

                buttonDiff = (controller->stickPrev ^ controller->stickCurrent);

                gSharedController.stickPressed |= controller->stickPressed = buttonDiff & controller->stickCurrent;
                gSharedController.stickReleased |= controller->stickReleased = buttonDiff & controller->stickPrev;

                controller->unk_82 = 0;
                if (((controller->buttonCurrent != 0) || (controller->stickCurrent != 0)) &&
                    (controller->buttonPrev == controller->buttonCurrent) &&
                    (controller->stickPrev == controller->stickCurrent)) {
                    controller->unk_84++;
                    if ((controller->unk_84 >= D_8076C930) && (((controller->unk_84 - D_8076C930) % D_8076C934) == 0)) {
                        controller->unk_82 = 1;
                    }
                } else {
                    controller->unk_84 = 0;
                }
                gSharedController.unk_82 |= controller->unk_82;
                if (controller->unk_78 != 0) {
                    if (osMotorInit(&gSerialEventQueue, &controller->pfs, i) == 0) {
                        osMotorStop(&controller->pfs);
                        controller->unk_74 = 1;
                    } else {
                        controller->unk_74 = 0;
                    }
                    controller->unk_76 = 0;
                    controller->unk_90 = 0;
                    controller->unk_8C = 0;
                    controller->unk_88 = 0;
                    controller->unk_78 = controller->unk_76;
                } else if ((controller->unk_72 == 0) || gResetStarted) {
                    if ((controller->unk_74 == 1) && ((controller->unk_76 == 1) || !(((i << 5) + D_8076C770) & 0x7F))) {
                        if (osMotorStop(&controller->pfs) == 0) {
                            controller->unk_76 = 0;
                        } else {
                            controller->unk_74 = 0;
                        }
                    }
                } else if (controller->unk_74 == 1) {
                    controller->unk_88 += controller->unk_8C;
                    controller->unk_8C -= controller->unk_90;
                    if (controller->unk_8C < 0) {
                        controller->unk_8C = 0;
                    }

                    if (controller->unk_88 >= 1000) {
                        controller->unk_88 -= 1000;
                        if (controller->unk_76 == 0) {
                            if (osMotorStart(&controller->pfs) == 0) {
                                controller->unk_76 = 1;
                            } else {
                                controller->unk_74 = 0;
                            }
                        }
                    } else if (controller->unk_76 == 1) {
                        if (osMotorStop(&controller->pfs) == 0) {
                            controller->unk_76 = 0;
                        } else {
                            controller->unk_74 = 0;
                        }
                    }
                }
            }
        }
    } while (controller != gControllers);

    if (var_s6 != 0) {
        gSharedController.stickX = var_fp / var_s6;

        gSharedController.stickY = var_s7 / var_s6;
    }
}

extern OSContStatus gControllerStatus[];

void Controller_Init(void) {
    s32 i;
    u8 sp53;

    osContInit(&gSerialEventQueue, &sp53, gControllerStatus);
    gControllersConnected = 0;

    for (i = 0; i < MAXCONTROLLERS; i++) {

        gControllers[i].errno = gControllerStatus[i].errno;
        gControllers[i].unk_72 = gControllers[i].unk_74 = gControllers[i].unk_76 = gControllers[i].unk_78 = 0;
        gControllers[i].unk_88 = gControllers[i].unk_8C = gControllers[i].unk_90 = 0;
        if (gControllerStatus[i].errno == 0) {
            gPlayerControlPorts[gControllersConnected] = i;
            gControllersConnected++;
            if (osMotorInit(&gSerialEventQueue, &gControllers[i].pfs, i) == 0) {
                osMotorStop(&gControllers[i].pfs);
                gControllers[i].unk_74 = 1;
            }
        }
    }

    for (i = gControllersConnected; i < 4; i++) {
        gPlayerControlPorts[i] = PORT_DISCONNECTED;
    }

    Controller_ClearInputs();
}
