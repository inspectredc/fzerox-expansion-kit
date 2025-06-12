#include "global.h"
#include "fzx_game.h"
#include "fzx_machine.h"

s32 func_i7_GetEndScreenIndex(s32 difficulty, s16 character, s8 customType) {
    s32 endScreenCharacterIndex;

    switch (character) {
        case CAPTAIN_FALCON:
            if (IS_SUPER_MACHINE(customType)) {
                endScreenCharacterIndex = 30;
            } else {
                switch (difficulty) {
                    case STANDARD:
                    case EXPERT:
                        endScreenCharacterIndex = 31;
                        break;
                    case MASTER:
                        endScreenCharacterIndex = character;
                        break;
                }
            }
            break;
        case SAMURAI_GOROH:
            if (IS_SUPER_MACHINE(customType)) {
                endScreenCharacterIndex = 32;
            } else {
                endScreenCharacterIndex = character;
            }
            break;
        case JODY_SUMMER:
            if (IS_SUPER_MACHINE(customType)) {
                endScreenCharacterIndex = 33;
            } else {
                endScreenCharacterIndex = character;
            }
            break;
        default:
            endScreenCharacterIndex = character;
            break;
    }
    return endScreenCharacterIndex;
}

bool func_i7_80092880(void) {
    s8* sp1C;
    s32 i;
    bool var_a1;

    sp1C = func_807084E4(0, 4 * 30 * 7);
    Save_UpdateCupSave(sp1C);

    var_a1 = false;
    sp1C += 3 * 30 * 7;
    for (i = 0; i < 30 * 7; i++, sp1C++) {
        if (*sp1C == 0) {
            break;
        }
    }
    if (i == 30 * 7) {
        var_a1 = true;
    }

    return var_a1;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/EndingCutscene_Init.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/EndingCutscene_Update.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/func_i7_8009318C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/EndingCutscene_Draw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/func_i7_80093A18.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/func_i7_80093DE0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/func_i7_80094130.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/D_i7_8009A240.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/D_i7_8009A24C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/D_i7_8009A258.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/D_i7_8009A264.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/D_i7_8009A270.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/D_i7_8009A27C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/D_i7_8009A284.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/D_i7_8009A290.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/func_i7_800943A0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/func_i7_80094C14.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/func_i7_80094EE8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/func_i7_80094F0C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/func_i7_80095018.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/func_i7_8009513C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/func_i7_80095230.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/func_i7_800956E8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/func_i7_8009580C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/F5080/func_i7_80095D14.s")
