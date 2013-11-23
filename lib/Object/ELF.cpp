//===- ELF.cpp - ELF object file implementation -----------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "llvm/Object/ELF.h"

namespace llvm {
namespace object {

#define LLVM_ELF_SWITCH_RELOC_TYPE_NAME(enum)                                  \
  case ELF::enum:                                                              \
    return #enum;                                                              \

StringRef getELFRelocationTypeName(uint32_t Machine, uint32_t Type) {
  switch (Machine) {
  case ELF::EM_X86_64:
    switch (Type) {
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_NONE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_PC32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_GOT32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_PLT32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_COPY);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_GLOB_DAT);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_JUMP_SLOT);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_RELATIVE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_GOTPCREL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_32S);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_PC16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_8);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_PC8);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_DTPMOD64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_DTPOFF64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_TPOFF64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_TLSGD);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_TLSLD);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_DTPOFF32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_GOTTPOFF);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_TPOFF32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_PC64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_GOTOFF64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_GOTPC32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_GOT64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_GOTPCREL64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_GOTPC64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_GOTPLT64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_PLTOFF64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_SIZE32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_SIZE64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_GOTPC32_TLSDESC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_TLSDESC_CALL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_TLSDESC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_X86_64_IRELATIVE);
    default:
      break;
    }
    break;
  case ELF::EM_386:
    switch (Type) {
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_NONE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_PC32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_GOT32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_PLT32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_COPY);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_GLOB_DAT);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_JUMP_SLOT);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_RELATIVE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_GOTOFF);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_GOTPC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_32PLT);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_TPOFF);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_IE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_GOTIE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_LE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_GD);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_LDM);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_PC16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_8);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_PC8);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_GD_32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_GD_PUSH);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_GD_CALL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_GD_POP);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_LDM_32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_LDM_PUSH);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_LDM_CALL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_LDM_POP);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_LDO_32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_IE_32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_LE_32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_DTPMOD32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_DTPOFF32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_TPOFF32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_GOTDESC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_DESC_CALL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_TLS_DESC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_386_IRELATIVE);
    default:
      break;
    }
    break;
  case ELF::EM_MIPS:
    switch (Type) {
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_NONE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_REL32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_26);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_HI16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_LO16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_GPREL16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_LITERAL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_GOT16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_PC16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_CALL16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_GPREL32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_SHIFT5);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_SHIFT6);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_GOT_DISP);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_GOT_PAGE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_GOT_OFST);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_GOT_HI16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_GOT_LO16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_SUB);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_INSERT_A);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_INSERT_B);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_DELETE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_HIGHER);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_HIGHEST);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_CALL_HI16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_CALL_LO16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_SCN_DISP);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_REL16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_ADD_IMMEDIATE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_PJUMP);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_RELGOT);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_JALR);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_TLS_DTPMOD32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_TLS_DTPREL32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_TLS_DTPMOD64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_TLS_DTPREL64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_TLS_GD);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_TLS_LDM);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_TLS_DTPREL_HI16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_TLS_DTPREL_LO16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_TLS_GOTTPREL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_TLS_TPREL32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_TLS_TPREL64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_TLS_TPREL_HI16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_TLS_TPREL_LO16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_GLOB_DAT);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_COPY);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_JUMP_SLOT);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MICROMIPS_26_S1);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MICROMIPS_HI16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MICROMIPS_LO16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MICROMIPS_GOT16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MICROMIPS_PC16_S1);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MICROMIPS_CALL16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MICROMIPS_GOT_DISP);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MICROMIPS_GOT_PAGE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MICROMIPS_GOT_OFST);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MICROMIPS_TLS_DTPREL_HI16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MICROMIPS_TLS_DTPREL_LO16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MICROMIPS_TLS_TPREL_HI16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MICROMIPS_TLS_TPREL_LO16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_MIPS_NUM);
    default:
      break;
    }
    break;
  case ELF::EM_AARCH64:
    switch (Type) {
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_NONE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_ABS64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_ABS32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_ABS16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_PREL64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_PREL32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_PREL16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_MOVW_UABS_G0);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_MOVW_UABS_G0_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_MOVW_UABS_G1);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_MOVW_UABS_G1_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_MOVW_UABS_G2);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_MOVW_UABS_G2_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_MOVW_UABS_G3);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_MOVW_SABS_G0);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_MOVW_SABS_G1);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_MOVW_SABS_G2);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_LD_PREL_LO19);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_ADR_PREL_LO21);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_ADR_PREL_PG_HI21);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_ADD_ABS_LO12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_LDST8_ABS_LO12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TSTBR14);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_CONDBR19);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_JUMP26);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_CALL26);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_LDST16_ABS_LO12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_LDST32_ABS_LO12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_LDST64_ABS_LO12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_LDST128_ABS_LO12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_ADR_GOT_PAGE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_LD64_GOT_LO12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLD_MOVW_DTPREL_G2);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLD_MOVW_DTPREL_G1);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLD_MOVW_DTPREL_G1_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLD_MOVW_DTPREL_G0);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLD_MOVW_DTPREL_G0_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLD_ADD_DTPREL_HI12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLD_ADD_DTPREL_LO12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLD_ADD_DTPREL_LO12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLD_LDST8_DTPREL_LO12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLD_LDST8_DTPREL_LO12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLD_LDST16_DTPREL_LO12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLD_LDST16_DTPREL_LO12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLD_LDST32_DTPREL_LO12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLD_LDST32_DTPREL_LO12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLD_LDST64_DTPREL_LO12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLD_LDST64_DTPREL_LO12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSIE_MOVW_GOTTPREL_G1);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSIE_MOVW_GOTTPREL_G0_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSIE_ADR_GOTTPREL_PAGE21);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSIE_LD64_GOTTPREL_LO12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSIE_LD_GOTTPREL_PREL19);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLE_MOVW_TPREL_G2);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLE_MOVW_TPREL_G1);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLE_MOVW_TPREL_G1_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLE_MOVW_TPREL_G0);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLE_MOVW_TPREL_G0_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLE_ADD_TPREL_HI12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLE_ADD_TPREL_LO12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLE_ADD_TPREL_LO12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLE_LDST8_TPREL_LO12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLE_LDST8_TPREL_LO12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLE_LDST16_TPREL_LO12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLE_LDST16_TPREL_LO12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLE_LDST32_TPREL_LO12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLE_LDST32_TPREL_LO12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLE_LDST64_TPREL_LO12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSLE_LDST64_TPREL_LO12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSDESC_ADR_PAGE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSDESC_LD64_LO12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSDESC_ADD_LO12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_AARCH64_TLSDESC_CALL);
    default:
      break;
    }
    break;
  case ELF::EM_ARM:
    switch (Type) {
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_NONE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_PC24);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ABS32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_REL32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_LDR_PC_G0);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ABS16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ABS12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_ABS5);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ABS8);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_SBREL32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_CALL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_PC8);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_BREL_ADJ);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_TLS_DESC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_SWI8);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_XPC25);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_XPC22);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_TLS_DTPMOD32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_TLS_DTPOFF32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_TLS_TPOFF32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_COPY);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_GLOB_DAT);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_JUMP_SLOT);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_RELATIVE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_GOTOFF32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_BASE_PREL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_GOT_BREL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_PLT32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_CALL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_JUMP24);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_JUMP24);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_BASE_ABS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ALU_PCREL_7_0);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ALU_PCREL_15_8);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ALU_PCREL_23_15);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_LDR_SBREL_11_0_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ALU_SBREL_19_12_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ALU_SBREL_27_20_CK);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_TARGET1);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_SBREL31);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_V4BX);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_TARGET2);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_PREL31);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_MOVW_ABS_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_MOVT_ABS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_MOVW_PREL_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_MOVT_PREL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_MOVW_ABS_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_MOVT_ABS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_MOVW_PREL_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_MOVT_PREL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_JUMP19);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_JUMP6);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_ALU_PREL_11_0);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_PC12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ABS32_NOI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_REL32_NOI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ALU_PC_G0_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ALU_PC_G0);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ALU_PC_G1_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ALU_PC_G1);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ALU_PC_G2);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_LDR_PC_G1);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_LDR_PC_G2);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_LDRS_PC_G0);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_LDRS_PC_G1);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_LDRS_PC_G2);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_LDC_PC_G0);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_LDC_PC_G1);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_LDC_PC_G2);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ALU_SB_G0_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ALU_SB_G0);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ALU_SB_G1_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ALU_SB_G1);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ALU_SB_G2);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_LDR_SB_G0);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_LDR_SB_G1);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_LDR_SB_G2);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_LDRS_SB_G0);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_LDRS_SB_G1);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_LDRS_SB_G2);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_LDC_SB_G0);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_LDC_SB_G1);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_LDC_SB_G2);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_MOVW_BREL_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_MOVT_BREL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_MOVW_BREL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_MOVW_BREL_NC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_MOVT_BREL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_MOVW_BREL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_TLS_GOTDESC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_TLS_CALL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_TLS_DESCSEQ);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_TLS_CALL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_PLT32_ABS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_GOT_ABS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_GOT_PREL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_GOT_BREL12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_GOTOFF12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_GOTRELAX);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_GNU_VTENTRY);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_GNU_VTINHERIT);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_JUMP11);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_JUMP8);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_TLS_GD32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_TLS_LDM32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_TLS_LDO32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_TLS_IE32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_TLS_LE32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_TLS_LDO12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_TLS_LE12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_TLS_IE12GP);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_PRIVATE_0);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_PRIVATE_1);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_PRIVATE_2);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_PRIVATE_3);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_PRIVATE_4);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_PRIVATE_5);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_PRIVATE_6);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_PRIVATE_7);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_PRIVATE_8);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_PRIVATE_9);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_PRIVATE_10);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_PRIVATE_11);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_PRIVATE_12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_PRIVATE_13);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_PRIVATE_14);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_PRIVATE_15);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_ME_TOO);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_TLS_DESCSEQ16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_ARM_THM_TLS_DESCSEQ32);
    default:
      break;
    }
    break;
  case ELF::EM_HEXAGON:
    switch (Type) {
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_NONE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_B22_PCREL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_B15_PCREL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_B7_PCREL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_LO16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_HI16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_8);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GPREL16_0);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GPREL16_1);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GPREL16_2);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GPREL16_3);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_HL16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_B13_PCREL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_B9_PCREL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_B32_PCREL_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_32_6_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_B22_PCREL_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_B15_PCREL_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_B13_PCREL_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_B9_PCREL_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_B7_PCREL_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_16_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_12_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_11_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_10_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_9_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_8_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_7_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_6_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_32_PCREL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_COPY);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GLOB_DAT);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_JMP_SLOT);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_RELATIVE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_PLT_B22_PCREL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GOTREL_LO16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GOTREL_HI16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GOTREL_32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GOT_LO16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GOT_HI16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GOT_32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GOT_16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_DTPMOD_32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_DTPREL_LO16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_DTPREL_HI16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_DTPREL_32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_DTPREL_16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GD_PLT_B22_PCREL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GD_GOT_LO16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GD_GOT_HI16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GD_GOT_32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GD_GOT_16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_IE_LO16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_IE_HI16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_IE_32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_IE_GOT_LO16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_IE_GOT_HI16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_IE_GOT_32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_IE_GOT_16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_TPREL_LO16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_TPREL_HI16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_TPREL_32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_TPREL_16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_6_PCREL_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GOTREL_32_6_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GOTREL_16_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GOTREL_11_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GOT_32_6_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GOT_16_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GOT_11_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_DTPREL_32_6_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_DTPREL_16_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_DTPREL_11_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GD_GOT_32_6_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GD_GOT_16_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_GD_GOT_11_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_IE_32_6_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_IE_16_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_IE_GOT_32_6_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_IE_GOT_16_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_IE_GOT_11_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_TPREL_32_6_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_TPREL_16_X);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_HEX_TPREL_11_X);
    default:
      break;
    }
    break;
  case ELF::EM_PPC:
    switch (Type) {
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_NONE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_ADDR32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_ADDR24);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_ADDR16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_ADDR16_LO);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_ADDR16_HI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_ADDR16_HA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_ADDR14);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_ADDR14_BRTAKEN);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_ADDR14_BRNTAKEN);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_REL24);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_REL14);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_REL14_BRTAKEN);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_REL14_BRNTAKEN);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_GOT16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_GOT16_LO);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_GOT16_HI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_GOT16_HA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_REL32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_TLS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_DTPMOD32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_TPREL16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_TPREL16_LO);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_TPREL16_HI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_TPREL16_HA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_TPREL32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_DTPREL16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_DTPREL16_LO);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_DTPREL16_HI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_DTPREL16_HA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_DTPREL32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_GOT_TLSGD16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_GOT_TLSGD16_LO);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_GOT_TLSGD16_HI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_GOT_TLSGD16_HA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_GOT_TLSLD16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_GOT_TLSLD16_LO);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_GOT_TLSLD16_HI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_GOT_TLSLD16_HA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_GOT_TPREL16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_GOT_TPREL16_LO);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_GOT_TPREL16_HI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_GOT_TPREL16_HA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_GOT_DTPREL16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_GOT_DTPREL16_LO);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_GOT_DTPREL16_HI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_GOT_DTPREL16_HA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_TLSGD);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_TLSLD);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_REL16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_REL16_LO);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_REL16_HI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC_REL16_HA);
    default:
      break;
    }
    break;
  case ELF::EM_PPC64:
    switch (Type) {
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_NONE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_ADDR32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_ADDR24);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_ADDR16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_ADDR16_LO);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_ADDR16_HI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_ADDR16_HA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_ADDR14);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_ADDR14_BRTAKEN);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_ADDR14_BRNTAKEN);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_REL24);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_REL14);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_REL14_BRTAKEN);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_REL14_BRNTAKEN);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT16_LO);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT16_HI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT16_HA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_REL32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_ADDR64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_ADDR16_HIGHER);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_ADDR16_HIGHERA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_ADDR16_HIGHEST);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_ADDR16_HIGHESTA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_REL64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TOC16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TOC16_LO);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TOC16_HI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TOC16_HA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TOC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_ADDR16_DS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_ADDR16_LO_DS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT16_DS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT16_LO_DS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TOC16_DS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TOC16_LO_DS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TLS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_DTPMOD64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TPREL16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TPREL16_LO);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TPREL16_HI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TPREL16_HA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TPREL64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_DTPREL16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_DTPREL16_LO);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_DTPREL16_HI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_DTPREL16_HA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_DTPREL64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT_TLSGD16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT_TLSGD16_LO);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT_TLSGD16_HI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT_TLSGD16_HA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT_TLSLD16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT_TLSLD16_LO);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT_TLSLD16_HI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT_TLSLD16_HA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT_TPREL16_DS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT_TPREL16_LO_DS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT_TPREL16_HI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT_TPREL16_HA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT_DTPREL16_DS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT_DTPREL16_LO_DS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT_DTPREL16_HI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_GOT_DTPREL16_HA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TPREL16_DS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TPREL16_LO_DS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TPREL16_HIGHER);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TPREL16_HIGHERA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TPREL16_HIGHEST);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TPREL16_HIGHESTA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_DTPREL16_DS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_DTPREL16_LO_DS);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_DTPREL16_HIGHER);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_DTPREL16_HIGHERA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_DTPREL16_HIGHEST);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_DTPREL16_HIGHESTA);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TLSGD);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_TLSLD);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_REL16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_REL16_LO);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_REL16_HI);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_PPC64_REL16_HA);
    default:
      break;
    }
    break;
  case ELF::EM_S390:
    switch (Type) {
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_NONE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_8);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_PC32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_GOT12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_GOT32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_PLT32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_COPY);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_GLOB_DAT);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_JMP_SLOT);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_RELATIVE);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_GOTOFF);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_GOTPC);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_GOT16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_PC16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_PC16DBL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_PLT16DBL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_PC32DBL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_PLT32DBL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_GOTPCDBL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_PC64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_GOT64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_PLT64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_GOTENT);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_GOTOFF16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_GOTOFF64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_GOTPLT12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_GOTPLT16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_GOTPLT32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_GOTPLT64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_GOTPLTENT);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_PLTOFF16);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_PLTOFF32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_PLTOFF64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_LOAD);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_GDCALL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_LDCALL);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_GD32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_GD64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_GOTIE12);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_GOTIE32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_GOTIE64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_LDM32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_LDM64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_IE32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_IE64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_IEENT);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_LE32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_LE64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_LDO32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_LDO64);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_DTPMOD);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_DTPOFF);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_TPOFF);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_20);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_GOT20);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_GOTPLT20);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_TLS_GOTIE20);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_390_IRELATIVE);
    default:
      break;
    }
    break;
  case ELF::EM_VECTORPROC:
    switch (Type) {
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_VECTORPROC_ABS32);
      LLVM_ELF_SWITCH_RELOC_TYPE_NAME(R_VECTORPROC_BRANCH);
    default: break;
    }
    break;
  default:
    break;
  }
  return "Unknown";
}

#undef LLVM_ELF_SWITCH_RELOC_TYPE_NAME

} // end namespace object
} // end namespace llvm
