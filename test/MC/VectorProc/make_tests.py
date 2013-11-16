import random, sys

def make_a_instruction(fmt, opcode, dest, src1, src2, mask):
	return ((6 << 29) | (fmt << 26) | (opcode << 20) | (src2 << 15) 
		| (mask << 10) | (dest << 5) | src1)

def make_b_instruction(fmt, opcode, dest, src1, imm, mask):
	return ((fmt << 28) | (opcode << 23) | (imm << 15) 
		| (mask << 10) | (dest << 5) | src1)

def make_bprime_instruction(fmt, opcode, dest, src1, imm):
	return ((fmt << 28) | (opcode << 23) | (imm << 10) 
		| (dest << 5) | src1)

def make_c_instruction(isLoad, op, srcDest, ptr, offs, mask):
	return ((1 << 31) | (isLoad << 29) | (op << 25) | (offs << 15) 
		| (mask << 10) | (srcDest << 5) | ptr)

def make_cprime_instruction(isLoad, op, srcDest, ptr, offs):
	return ((1 << 31) | (isLoad << 29) | (op << 25) | (offs << 10) 
		| (srcDest << 5) | ptr)

def make_text_encoding(x, sep):
	str = ''
	for y in range(4):
		if y != 0:
			str += sep
			
		str += '0x%02x' % (x & 0xff)
		x >>= 8

	return str

def make_test_case(string, encoding):
	global disasm_fp
	global asm_fp

	asm_fp.write(string + '  # CHECK: [' + make_text_encoding(encoding, ',') + ']\n')
	disasm_fp.write(make_text_encoding(encoding, ' ') + '  # CHECK: ' + string + '\n')

# Setup
disasm_fp = open('disassembler-tests.s', 'w')
asm_fp = open('assembler-tests.s', 'w')

asm_fp.write('# This file auto-generated by ' + sys.argv[0] + '. Do not edit.\n')
asm_fp.write('# RUN: llvm-mc -arch=vectorproc -show-encoding %s | FileCheck %s\n')

disasm_fp.write('# This file auto-generated by ' + sys.argv[0] + '. Do not edit.\n')
disasm_fp.write('# RUN: llvm-mc -arch=vectorproc -disassemble %s | FileCheck %s\n')

##############################################################
# Test cases
##############################################################

binaryOps = [
	(0, 'or'),
	(1, 'and'),
	(3, 'xor'),
	(5, 'add.i'),
	(6, 'sub.i'),
	(7, 'mul.i'),
	# Not implemented (8, 'div.i')
	(9, 'ashr'),
	(10, 'shr'),
	(11, 'shl'),
	(0x20, 'add.f'),
	(0x21, 'sub.f'),
	(0x22, 'mul.f'),
]

for opcode, mnemonic in binaryOps:
	rega = random.randint(0, 27)
	regb = random.randint(0, 27)
	regc = random.randint(0, 27)
	regm = random.randint(0, 27)
	
	# scalar/scalar/scalar
	make_test_case(mnemonic + ' s' + str(rega) + ', s' + str(regb) 
		+ ', s' + str(regc),
		make_a_instruction(0, opcode, rega, regb, regc, 0))

	# vector/vector/scalar
	make_test_case(mnemonic + ' v' + str(rega) + ', v' + str(regb) 
		+ ', s' + str(regc),
		make_a_instruction(1, opcode, rega, regb, regc, 0))

	# vector/vector/scalar masked
	make_test_case(mnemonic + '.mask v' + str(rega) + ', s' + str(regm) 
		+ ', v' + str(regb) + ', s' + str(regc),
		make_a_instruction(2, opcode, rega, regb, regc, regm))

	# vector/vector/scalar invert mask
	make_test_case(mnemonic + '.invmask v' + str(rega) + ', s' + str(regm) 
		+ ', v' + str(regb) + ', s' + str(regc),
		make_a_instruction(3, opcode, rega, regb, regc, regm))

	# vector/vector/vector		
	make_test_case(mnemonic + ' v' + str(rega) + ', v' + str(regb) 
		+ ', v' + str(regc),
		make_a_instruction(4, opcode, rega, regb, regc, 0))

	# vector/vector/vector masked
	make_test_case(mnemonic + '.mask v' + str(rega) + ', s' + str(regm) 
		+ ', v' + str(regb) + ', v' + str(regc),
		make_a_instruction(5, opcode, rega, regb, regc, regm))

	# vector/vector/vector invert mask
	make_test_case(mnemonic + '.invmask v' + str(rega) + ', s' + str(regm) 
		+ ', v' + str(regb) + ', v' + str(regc),
		make_a_instruction(6, opcode, rega, regb, regc, regm))

	if mnemonic[-2:] == '.f':
		continue	# Can't do immediate for FP instructions

	imm = random.randint(0, 255)

	# scalar/scalar
	make_test_case(mnemonic + ' s' + str(rega) + ', s' + str(regb) 
		+ ', ' + str(imm),
		make_bprime_instruction(0, opcode, rega, regb, imm))

	# vector/vector
	make_test_case(mnemonic + ' v' + str(rega) + ', v' + str(regb) + ', ' + str(imm),
		make_bprime_instruction(1, opcode, rega, regb, imm))

	# vector/vector masked
	make_test_case(mnemonic + '.mask v' + str(rega) + ', s' + str(regm) + ', v' + str(regb) + ', ' + str(imm),
		make_b_instruction(2, opcode, rega, regb, imm, regm))

	# vector/vector invert mask
	make_test_case(mnemonic + '.invmask v' + str(rega) + ', s' + str(regm) + ', v' + str(regb) + ', ' + str(imm),
		make_b_instruction(3, opcode, rega, regb, imm, regm))

	# vector/scalar
	make_test_case(mnemonic + ' v' + str(rega) + ', s' + str(regb) + ', ' + str(imm),
		make_bprime_instruction(4, opcode, rega, regb, imm))

	# vector/scalar masked
	make_test_case(mnemonic + '.mask v' + str(rega) + ', s' + str(regm) + ', s' + str(regb) + ', ' + str(imm),
		make_b_instruction(5, opcode, rega, regb, imm, regm))

	# vector/scalar invert mask
	make_test_case(mnemonic + '.invmask v' + str(rega) + ', s' + str(regm) + ', s' + str(regb) + ', ' + str(imm),
		make_b_instruction(6, opcode, rega, regb, imm, regm))

unaryOps = [
	(12, 'clz'),
	(14, 'ctz'),
	(0xf, 'move'),
]

# These unary ops do not support all form
#	(0x1b, 'ftoi'),
#	(0x1c, 'reciprocal'),
#	(0x1d, 'sext.8'),
#	(0x1e, 'sext.16'),
#	(0x2a, 'itof')

for opcode, mnemonic in unaryOps:
	rega = random.randint(0, 27)
	regb = random.randint(0, 27)
	regm = random.randint(0, 27)

	# Scalar/Scalar
	make_test_case(mnemonic + ' s' + str(rega) + ', s' + str(regb),
		make_a_instruction(0, opcode, rega, 0, regb, 0))

	# Vector/Scalar
	make_test_case(mnemonic + ' v' + str(rega) + ', s' + str(regb),
		make_a_instruction(1, opcode, rega, 0, regb, 0))

	# Vector/Scalar Masked
	make_test_case(mnemonic + '.mask v' + str(rega) + ', s' + str(regm) + ', s' + str(regb),
		make_a_instruction(2, opcode, rega, 0, regb, regm))

	# Vector/Scalar Invert Mask
	make_test_case(mnemonic + '.invmask v' + str(rega) + ', s' + str(regm) + ', s' + str(regb),
		make_a_instruction(3, opcode, rega, 0, regb, regm))

	# Vector/Vector
	make_test_case(mnemonic + ' v' + str(rega) + ', v' + str(regb),
		make_a_instruction(4, opcode, rega, 0, regb, 0))

	# Vector/Vector masked	
	make_test_case(mnemonic + '.mask v' + str(rega) + ', s' + str(regm) + ', v'
		+ str(regb), make_a_instruction(5, opcode, rega, 0, regb, regm))

	# Vector/Vector invert mask	
	make_test_case(mnemonic + '.invmask v' + str(rega) + ', s' + str(regm) + ', v'
		+ str(regb), make_a_instruction(6, opcode, rega, 0, regb, regm))

# XXX HACK: These instructions should support all forms, but this is here in the interim

make_test_case('reciprocal s7, s9', make_a_instruction(0, 0x1c, 7, 0, 9, 0))

make_test_case('shuffle v1, v2, v3', make_a_instruction(4, 0xd, 1, 2, 3, 0))

# XXX shuffle.mask should be supported, but isn't by compiler

make_test_case('getfield s4, v5, s6', make_a_instruction(1, 0x1a, 4, 5, 6, 0))

# getfield with an immediate param should be supported, but isn't by compiler

cmpOps = [
	(0x12, 'gt.i'),
	(0x13, 'ge.i'),
	(0x14, 'lt.i'),
	(0x15, 'le.i'),
	(0x16, 'gt.u'),
	(0x17, 'ge.u'),
	(0x18, 'lt.u'),
	(0x19, 'le.u'),
	(0x2c, 'gt.f'),
	(0x2d, 'ge.f'),
	(0x2e, 'lt.f'),
	(0x2f, 'le.f')
]

for opcode, mnemonic in cmpOps:
	make_test_case('set' + mnemonic +  ' s' + str(rega) + ', s' + str(regb) + ', s' + str(regc),
		make_a_instruction(0, opcode, rega, regb, regc, 0))

	make_test_case('set' + mnemonic + ' s' + str(rega) + ', v' + str(regb) + ', s' + str(regc),
		make_a_instruction(1, opcode, rega, regb, regc, 0))

	make_test_case('set' + mnemonic + ' s' + str(rega) + ', v' + str(regb) + ', v' + str(regc),
		make_a_instruction(4, opcode, rega, regb, regc, 0))

	if mnemonic[-2:] == '.f':
		continue	# Can't do immediate for FP instructions
			
	imm = random.randint(0, 255)
	make_test_case('set' + mnemonic +  ' s' + str(rega) + ', s' + str(regb) + ', ' + str(imm),
		make_bprime_instruction(0, opcode, rega, regb, imm))

	make_test_case('set' + mnemonic + ' s' + str(rega) + ', v' + str(regb) + ', ' + str(imm),
		make_bprime_instruction(1, opcode, rega, regb, imm))
	
make_test_case('getfield s1, v2, s3 ', make_a_instruction(1, 0x1a, 1, 2, 3, 0))

# Scalar load/stores
make_test_case('load.u8 s10, 20(s5)', make_cprime_instruction(1, 0, 10, 5, 20))
make_test_case('load.u8 s11, (s6)', make_cprime_instruction(1, 0, 11, 6, 0))
make_test_case('load.s8 s10, 20(s5)', make_cprime_instruction(1, 1, 10, 5, 20))
make_test_case('load.s8 s11, (s6)', make_cprime_instruction(1, 1, 11, 6, 0))
make_test_case('load.u16 s12, 30(s7)', make_cprime_instruction(1, 2, 12, 7, 30))
make_test_case('load.u16 s13, (s8)', make_cprime_instruction(1, 2, 13, 8, 0))
make_test_case('load.s16 s12, 30(s7)', make_cprime_instruction(1, 3, 12, 7, 30))
make_test_case('load.s16 s13, (s8)', make_cprime_instruction(1, 3, 13, 8, 0))
make_test_case('load.32 s14, 40(s9)', make_cprime_instruction(1, 4, 14, 9, 40))
make_test_case('load.32 s15, (s10)', make_cprime_instruction(1, 4, 15, 10, 0))
make_test_case('store.8 s1, 50(s2)', make_cprime_instruction(0, 1, 1, 2, 50))
make_test_case('store.16 s3, 60(s4)', make_cprime_instruction(0, 3, 3, 4, 60))
make_test_case('store.32 s5, 70(s6)', make_cprime_instruction(0, 4, 5, 6, 70))

# Block Vector load/stores
make_test_case('load.v v2, 20(s5)', make_cprime_instruction(1, 7, 2, 5, 20))
make_test_case('load.v v3, (s6)', make_cprime_instruction(1, 7, 3, 6, 0))
make_test_case('store.v v2, 20(s5)', make_cprime_instruction(0, 7, 2, 5, 20))
make_test_case('store.v v3, (s6)', make_cprime_instruction(0, 7, 3, 6, 0))

make_test_case('load.v.mask v2, s7, 20(s5)', make_c_instruction(1, 8, 2, 5, 20, 7))
make_test_case('load.v.mask v3, s7, (s6)', make_c_instruction(1, 8, 3, 6, 0, 7))
make_test_case('store.v.mask v2, s7, 20(s5)', make_c_instruction(0, 8, 2, 5, 20, 7))
make_test_case('store.v.mask v3, s7, (s6)', make_c_instruction(0, 8, 3, 6, 0, 7))

# Scatter vector stores (partial)
make_test_case('store.scat v2, (v5)', make_c_instruction(0, 0xd, 2, 5, 0, 0))
make_test_case('store.scat.mask v3, s7, (v6)', make_c_instruction(0, 0xe, 3, 6, 0, 7))

# Synchronized load/stores
make_test_case('load.sync s2, 20(s5)', make_cprime_instruction(1, 5, 2, 5, 20))
make_test_case('load.sync s3, (s6)', make_cprime_instruction(1, 5, 3, 6, 0))
make_test_case('store.sync s2, 20(s5)', make_cprime_instruction(0, 5, 2, 5, 20))
make_test_case('store.sync s3, (s6)', make_cprime_instruction(0, 5, 3, 6, 0))

# XXX scatter/gather vector loads

# Control register
make_test_case('getcr s7, 9', make_cprime_instruction(1, 6, 7, 9, 0))
make_test_case('setcr s11, 13', make_cprime_instruction(0, 6, 11, 13, 0))

# Cleanup
disasm_fp.close()
asm_fp.close()