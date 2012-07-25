/* Copyright 2006-2009, BeatriX
 * File coded by BeatriX
 *
 * This file is part of BeaEngine.
 *
 *    BeaEngine is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    BeaEngine is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with BeaEngine.  If not, see <http://www.gnu.org/licenses/>. */

/* ====================================================================
 *      0x 0f 77
 * ==================================================================== */
void __bea_callspec__ emms_(PDISASM pMyDisasm)
{
	(*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+STATE_MANAGEMENT;
    (*pMyDisasm).Instruction.Mnemonic = I_EMMS;
	GV.EIP_++;
}

/* ====================================================================
 *      0x 0f 7e
 * ==================================================================== */
void __bea_callspec__ movd_EP(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+DATA_TRANSFER;
    /* ========= 0xf3 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVQ;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        if ((*pMyDisasm).Prefix.REX.W_ == 1) {
            (*pMyDisasm).Argument1.ArgSize = 64;
            (*pMyDisasm).Instruction.Mnemonic = I_MOVQ;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            (*pMyDisasm).Argument1.ArgSize = 32;
            (*pMyDisasm).Instruction.Mnemonic = I_MOVD;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    else {
        if ((*pMyDisasm).Prefix.REX.W_ == 1) {
            (*pMyDisasm).Argument1.ArgSize = 64;
            (*pMyDisasm).Instruction.Mnemonic = I_MOVQ;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.MMX_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.MMX_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            (*pMyDisasm).Argument1.ArgSize = 32;
            (*pMyDisasm).Instruction.Mnemonic = I_MOVD;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.MMX_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.MMX_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
}


/* ====================================================================
 *      0x 0f 6e
 * ==================================================================== */
void __bea_callspec__ movd_PE(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+DATA_TRANSFER;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        if ((*pMyDisasm).Prefix.REX.W_ == 1) {
            (*pMyDisasm).Argument2.ArgSize = 64;
            (*pMyDisasm).Instruction.Mnemonic = I_MOVQ;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            (*pMyDisasm).Argument2.ArgSize = 32;
            (*pMyDisasm).Instruction.Mnemonic = I_MOVD;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    else {
        if ((*pMyDisasm).Prefix.REX.W_ == 1) {
            (*pMyDisasm).Argument2.ArgSize = 64;
            (*pMyDisasm).Instruction.Mnemonic = I_MOVQ;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.MMX_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.MMX_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            (*pMyDisasm).Argument2.ArgSize = 32;
            (*pMyDisasm).Instruction.Mnemonic = I_MOVD;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.MMX_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.MMX_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
}



/* ====================================================================
 *      0x 0f 6f
 * ==================================================================== */
void __bea_callspec__ movq_PQ(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+DATA_TRANSFER;
    /* ========= 0xf3 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVDQU;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVDQA;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVQ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 7f
 * ==================================================================== */
void __bea_callspec__ movq_QP(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+DATA_TRANSFER;
    /* ========= 0xf3 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument1.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVDQU;
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument1.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVDQA;
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVQ;
        GV.MMX_ = 1;
        ExGx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d6
 * ==================================================================== */
void __bea_callspec__ movq_WV(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+DATA_TRANSFER;
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVDQ2Q;
        GV.MMX_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.MMX_ = 0;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;

    }
    /* ========= 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVQ2DQ;
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.MMX_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVQ;
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 1c
 * ==================================================================== */
void __bea_callspec__ pabsb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PABSB;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PABSB;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 38 1e
 * ==================================================================== */
void __bea_callspec__ pabsd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PABSD;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PABSD;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 38 1d
 * ==================================================================== */
void __bea_callspec__ pabsw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PABSW;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PABSW;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 63
 * ==================================================================== */
void __bea_callspec__ packsswb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PACKSSWB;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PACKSSWB;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 6b
 * ==================================================================== */
void __bea_callspec__ packssdw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PACKSSDW;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PACKSSDW;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 67
 * ==================================================================== */
void __bea_callspec__ packuswb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PACKUSWB;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PACKUSWB;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f fc
 * ==================================================================== */
void __bea_callspec__ paddb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PADDB;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PADDB;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f fd
 * ==================================================================== */
void __bea_callspec__ paddw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PADDW;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PADDW;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f fe
 * ==================================================================== */
void __bea_callspec__ paddd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PADDD;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PADDD;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f ec
 * ==================================================================== */
void __bea_callspec__ paddsb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PADDSB;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PADDSB;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f ed
 * ==================================================================== */
void __bea_callspec__ paddsw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PADDSW;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PADDSW;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f dc
 * ==================================================================== */
void __bea_callspec__ paddusb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PADDUSB;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PADDUSB;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f dd
 * ==================================================================== */
void __bea_callspec__ paddusw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PADDUSW;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PADDUSW;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f db
 * ==================================================================== */
void __bea_callspec__ pand_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+LOGICAL_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PAND;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PAND;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 0;
    }
}
/* ====================================================================
 *      0x 0f df
 * ==================================================================== */
void __bea_callspec__ pandn_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+LOGICAL_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PANDN;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PANDN;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 74
 * ==================================================================== */
void __bea_callspec__ pcmpeqb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+COMPARISON_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PCMPEQB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PCMPEQB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 75
 * ==================================================================== */
void __bea_callspec__ pcmpeqw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+COMPARISON_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PCMPEQW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PCMPEQW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 76
 * ==================================================================== */
void __bea_callspec__ pcmpeqd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+COMPARISON_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PCMPEQD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PCMPEQD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 64
 * ==================================================================== */
void __bea_callspec__ pcmpgtb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+COMPARISON_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PCMPGTB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PCMPGTB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 65
 * ==================================================================== */
void __bea_callspec__ pcmpgtw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+COMPARISON_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PCMPGTW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PCMPGTW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 66
 * ==================================================================== */
void __bea_callspec__ pcmpgtd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+COMPARISON_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PCMPGTD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PCMPGTD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f e5
 * ==================================================================== */
void __bea_callspec__ pmulhw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PMULHW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PMULHW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d5
 * ==================================================================== */
void __bea_callspec__ pmullw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PMULLW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PMULLW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f f5
 * ==================================================================== */
void __bea_callspec__ pmaddwd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PMADDWD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PMADDWD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f eb
 * ==================================================================== */
void __bea_callspec__ por_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+LOGICAL_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_POR;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_POR;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f f1
 * ==================================================================== */
void __bea_callspec__ psllw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PSLLW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PSLLW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f f2
 * ==================================================================== */
void __bea_callspec__ pslld_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PSLLD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PSLLD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f f3
 * ==================================================================== */
void __bea_callspec__ psllq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PSLLQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PSLLQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d1
 * ==================================================================== */
void __bea_callspec__ psrlw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PSRLW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PSRLW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d2
 * ==================================================================== */
void __bea_callspec__ psrld_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PSRLD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PSRLD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d3
 * ==================================================================== */
void __bea_callspec__ psrlq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PSRLQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PSRLQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f e1
 * ==================================================================== */
void __bea_callspec__ psraw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PSRAW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PSRAW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f e2
 * ==================================================================== */
void __bea_callspec__ psrad_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PSRAD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PSRAD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f f8
 * ==================================================================== */
void __bea_callspec__ psubb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PSUBB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PSUBB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f f9
 * ==================================================================== */
void __bea_callspec__ psubw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PSUBW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PSUBW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f fa
 * ==================================================================== */
void __bea_callspec__ psubd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PSUBD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PSUBD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f e8
 * ==================================================================== */
void __bea_callspec__ psubsb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PSUBSB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PSUBSB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f e9
 * ==================================================================== */
void __bea_callspec__ psubsw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PSUBSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PSUBSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d8
 * ==================================================================== */
void __bea_callspec__ psubusb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PSUBUSB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PSUBUSB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d9
 * ==================================================================== */
void __bea_callspec__ psubusw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PSUBUSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PSUBUSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 68
 * ==================================================================== */
void __bea_callspec__ punpckhbw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PUNPCKHBW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PUNPCKHBW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 69
 * ==================================================================== */
void __bea_callspec__ punpckhwd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PUNPCKHWD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PUNPCKHWD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 6a
 * ==================================================================== */
void __bea_callspec__ punpckhdq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PUNPCKHDQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PUNPCKHDQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 60
 * ==================================================================== */
void __bea_callspec__ punpcklbw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PUNPCKLBW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PUNPCKLBW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 61
 * ==================================================================== */
void __bea_callspec__ punpcklwd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PUNPCKLWD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PUNPCKLWD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 62
 * ==================================================================== */
void __bea_callspec__ punpckldq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PUNPCKLDQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PUNPCKLDQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f ef
 * ==================================================================== */
void __bea_callspec__ pxor_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+LOGICAL_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Mnemonic = I_PXOR;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Mnemonic = I_PXOR;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}
