; RUN: llc -mtriple vectorproc-elf %s -o - | FileCheck %s

target triple = "vectorproc"

define <16 x float>* @bug() {
	%array = alloca [16 x <16 x float>], align 64
	%ep = getelementptr inbounds [16 x <16 x float>]* %array, i32 0, i32 2

	; CHECK: add_i sp, sp, -

	ret <16 x float>* %ep
}
