//===-- VectorProcSubtarget.h - Define Subtarget for the VectorProc -----*-//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the VectorProc specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#ifndef VECTORPROC_SUBTARGET_H
#define VECTORPROC_SUBTARGET_H

#include "llvm/Target/TargetSubtargetInfo.h"
#include <string>

#define GET_SUBTARGETINFO_HEADER
#include "VectorProcGenSubtargetInfo.inc"

namespace llvm {
class StringRef;

class VectorProcSubtarget : public VectorProcGenSubtargetInfo {
  virtual void anchor();

public:
  VectorProcSubtarget(const std::string &TT, const std::string &CPU,
                      const std::string &FS);

  /// ParseSubtargetFeatures - Parses features string setting specified
  /// subtarget options.  Definition of function is auto generated by tblgen.
  void ParseSubtargetFeatures(StringRef CPU, StringRef FS);

  std::string getDataLayout() const {
    return std::string("e-m:e-p:32:32");
  }
};

} // end namespace llvm

#endif
