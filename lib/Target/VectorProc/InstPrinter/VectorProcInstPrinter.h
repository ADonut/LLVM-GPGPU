//=== VectorProcInstPrinter.h - Convert VectorProc MCInst to assembly syntax -*-
//C++ -*-==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This class prints a VectorProc MCInst to a .s file.
//
//===----------------------------------------------------------------------===//

#ifndef VPINSTPRINTER_H
#define VPINSTPRINTER_H
#include "llvm/MC/MCInstPrinter.h"
#include "llvm/Support/Compiler.h"

namespace llvm {

class TargetMachine;

class VectorProcInstPrinter : public MCInstPrinter {
public:
  VectorProcInstPrinter(const MCAsmInfo &MAI, const MCInstrInfo &MII,
                        const MCRegisterInfo &MRI)
      : MCInstPrinter(MAI, MII, MRI) {}

  // Autogenerated by tblgen.
  void printInstruction(const MCInst *MI, raw_ostream &O);
  static const char *getRegisterName(unsigned RegNo);

  virtual void printRegName(raw_ostream &OS, unsigned RegNo) const override;
  virtual void printInst(const MCInst *MI, raw_ostream &O, StringRef Annot) override;

private:
  void printCPURegs(const MCInst *MI, unsigned OpNo, raw_ostream &O);
  bool printAliasInstr(const MCInst *MI, raw_ostream &OS);
  void printOperand(const MCInst *MI, unsigned OpNo, raw_ostream &O);
  void printUnsignedImm(const MCInst *MI, int opNum, raw_ostream &O);
  void printMemOperand(const MCInst *MI, int opNum, raw_ostream &O);
  void printJumpTableOperand(const MCInst *MI, int opNum, raw_ostream &O);
};
} // end namespace llvm

#endif
