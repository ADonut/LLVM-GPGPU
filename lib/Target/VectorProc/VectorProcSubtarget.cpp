//===-- VectorProcSubtarget.cpp - VectorProc Subtarget Information  ------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the vectorproc specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#include "VectorProcSubtarget.h"
#include "VectorProc.h"
#include "llvm/Support/TargetRegistry.h"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#define DEBUG_TYPE "vectorproc-subtarget"
#include "VectorProcGenSubtargetInfo.inc"

using namespace llvm;

void VectorProcSubtarget::anchor() {}

VectorProcSubtarget::VectorProcSubtarget(const std::string &TT,
                                         const std::string &CPU,
                                         const std::string &FS)
    : VectorProcGenSubtargetInfo(TT, CPU, FS) {

  // Determine default and user specified characteristics
  std::string CPUName = CPU;
  if (CPUName.empty()) {
    CPUName = "vectorproc";
  }

  // Parse features string.
  ParseSubtargetFeatures(CPUName, FS);
}
