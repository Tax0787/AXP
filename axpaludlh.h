#ifndef _AXPALUDLH_H
# define _AXPALUDLH_H

#include "axpaludlhh.h"

charr5 empty_charr5 = 0;
char[] empty_char[1] = (char*) empty_charr5;
axptype empty_axptype = 0;
gcstackv* GCStackBP = new gcstackv;
gcstackv* GCStackSP = &GCStackBP;

inline char* typecast_typecharr(int N)
{
	switch (N) {
		case 0:
			return "int";
		case 1:
			return "chr";
		case 2:
			return "chr2";
		case 3:
			return "chr3";
		case 4:
			return "chr4";
		case 5:
			return "chr5";
	}
}

inline char[] cmder_on_wrapper_core(int opcode)
{
	switch (opcode) {
		case 0:
			return "new";
		case 1:
			return "del";
		case 2:
			return "chr";
		case 3:
			return "chr2";
		case 4:
			return "chr3";
		case 5:
			return "chr4";
		case 6:
			return "chr5";
		case 7:
			return "int";
		case 8:
			return "codf";
		case 9:
			return "codl"
		case 0xA:
			return "add";
		case 0xB:
			return "sub";
		case 0xC:
			return "mot";
		case 0xD:
			return "div";
		case 0xE:
			return "mod";
		case 0xF:
			return "2int";
		case _:
			auto is_opcode_command_is_exist = false;
			assert(is_opcode_command_is_exist);
			break;
	};
}

//case : return "";

inline charr5 charr2charr5(char[] charr)
{
	return (charr5) charr; 
}

inline char[] charr5lengthcharr(char v1, char v2, char v3, char v4)
{
	char ret[4];
	ret[0] = v1;
	ret[1] = v2;
	ret[2] = v3;
	ret[3] = v4;
	return ret;
}

inline char[] charr5lengthcharr(char v1, char v2, char v3)
{
	char ret[3];
	ret[0] = v1;
	ret[1] = v2;
	ret[2] = v3;
	return ret;
}

inline char[] charr5lengthcharr(char v1, char v2)
{
	char ret[2];
	ret[0] = v1;
	ret[1] = v2;
	return ret;
}

inline char[] charr5lengthcharr(char x)
{
	char* ret = x;
	return &ret;
}

inline charr5 cmder_on_wrapper(int opcode)
{
	return charr2charr5(cmder_on_wrapper_core(opcode));
}

inline charr5 casevalue(char v1, char v2, char v3, char v4)
{
	return charr2charr5(charr5lengthcharr(v1, v2, v3, v4));
}

inline charr5 casevalue(char v1, char v2, char v3)
{
	return charr2charr5(charr5lengthcharr(v1, v2, v3));
}

inline charr5 casevalue(char v1, char v2)
{
	return charr2charr5(charr5lengthcharr(v1, v2));
}

inline charr5 casevalue(char x)
{
	return charr2charr5(charr5lengthcharr(x));
}

auto wrapper(wrappers_code argv)
{
	switch (cmder_on_wapper(argv.cmd.int)){
		case casevalue('n','e','w'):
			axptype* value = new axptype;
			value = argv.x
			return &value;
		case casevalue('d','e','l'):
			axptype *target = &argv.x.ptrvar;
			delete(target);
			return null;
		case casevalue('c', 'h', 'r'):
			axptype *target = &argv.x.tarvar; //x is pointer bacause list's value
			axptype *ret = new axptype;
			ret.charvar = &target.charvar; //typecase but use structure
			return ret;
		case casevalue('i', 'n', 't'):
			axptype *target = &argv.x.tarvar; //x is pointer bacause list's value
			axptype *ret;
			axptype *ret = new axptype;
			ret.intvar = target.intvar; //typecase but use structure
			return ret;
		case casevalue('c', 'h', 'r', nc(2)):
			axptype *target = &argv.x.tarvar; //x is pointer bacause list's value
			axptype *ret;
			axptype *ret = new axptype;
			ret.charr2var = target.charr2var; //typecase but use structure
			return ret;
		case casevalue('c', 'h', 'r', nc(3)):
			axptype *target = &argv.x.tarvar; //x is pointer bacause list's value
			axptype *ret;
			axptype *ret = new axptype;
			ret.charr3var = target.charr3var; //typecase but use structure
			return ret;
		case casevalue('c', 'h', 'r', nc(4)):
			axptype *target = &argv.x.tarvar; //x is pointer bacause list's value
			axptype *ret;
			axptype *ret = new axptype;
			ret.charr4var = target.charr4var; //typecase but use structure
			return ret;
		case casevalue('c', 'h', 'r', nc(5)):
			axptype *target = &argv.x.tarvar; //x is pointer bacause list's value
			axptype *ret;
			axptype *ret = new axptype;
			ret.charr5var = target.charr5var; //typecase but use structure
			return ret;
		case casevalue(nc(2),'i','n','t'):
			axptype *ret;
			axptype *ret = new axptype;
			ret.intvar = floor(argv.x.floatvar);
			return ret;
		case casevalue('a', 'd', 'd'):
			axptype *ret;
			axptype *ret = new axptype;
			ret.intvar = argv.x.intvar + argv.y.intvar;
			return ret;
		case casevalue('s', 'u', 'b'):
			axptype *ret;
			axptype *ret = new axptype;
			ret.intvar = argv.x.intvar - argv.y.intvar;
			return ret;
		case casevalue('m', 'o', 't'):
			axptype *ret;
			axptype *ret = new axptype;
			ret.intvar = argv.x.intvar * argv.y.intvar;
			return ret;
		case casevalue('d', 'i', 'v'):
			axptype *ret;
			axptype *ret = new axptype;
			ret.floatvar = argv.x.intvar / argv.y.intvar;
			return ret;
		case casevalue('m', 'o', 'd'):
			axptype *ret;
			axptype *ret = new axptype[1];
			ret.intvar = argv.x.intvar  % argv.y.intvar;
			return ret;
		case casevalue('c', 'o', 'd', 'f'): //code first
			code x;
			x.cmd = argv.x
			x.option = argv.y
			return x;
		case casevalue('c', 'o', 'd', 'l'): //code last
			code x;
			x.x = argv.x
			x.y = argv.y
			return x;
		case _:
			is_opcode_command_is_exist = false;
			assert(is_opcode_command_is_exist);
			break;
	};
}

size_t typelengths(bool defdtypeN_is_code_not_ptr) //python only touch code or ptr.
{
	if (defdtypeN_is_code_not_types) {
		return sizeof(code);
	} else {
		return sizeof(ptr);
	};
}

void gcsf(ptr a, ptr b, ptr c)
{
	wrappers_code* v1 = a;
	axptype* v2 = b;
	axptype* v3 = c;
	delete(v1);
	delete(v2);
	delete(v3);
}

gcsftype gcspf = (gcsftype) gcsf;

gcstackv* GCSPush(ptr a, ptr b, ptr c)
{
	GCStackSP[3] = (ptr) new GCStackSP;
	GCStackSP[4][5] = (ptr) &GCStackSP;
	GCStackSP = (GCStackSP*) GCStackSP[4];
	GCStackSP[0] = a;
	GCStackSP[1] = b;
	GCStackSP[2] = c;
	return GCStackSP;
}
gcstackv* GCSPop(gcsftype f)
{
	f(GCStackSP[0], GCStackSP[1], GCStackSP[2]);
	GCStackSP = &GCStackSP[5];
	delete(GCStackSP[4]);
	return GCStackSP;
}

inline gcstackv* GCSPoper(void)
{
	return GCSPop(gcspf);
}

inline wrappers_code new_wrapper_code(int cmd, axptype* x, axptype* y)
{
	axptype cmds;
	cmds.intvar = cmd;
	wrappers_code* ret = new wrappers_code;
	ret.cmd = cmds;
	ret.x = &x;
	ret.y = &y;
	GCSPush((ptr) &ret, (ptr) &x, (ptr) &y);
	return ret;
}

inline auto use_wrapped_code(int cmd, axptype x, axptype y)
{
	axptype* x2 = new axptype;
	axptype* y2 = new axptype;
	axptype* x2 = x;
	axptype* y2 = y;
	return wrapper(new_wrapper_code(cmd, x2, y2));
}

inline auto use_wrapped_code_with_gc(int cmd, axptype x, axptype y)
{
	auto ret = use_wrapped_code(cmd, x, y);
	GCSPoper();
	return ret;
}

inline auto use_wrapped_code_with_gc(int cmd, axptype x)
{
	auto ret = use_wrapped_code(cmd, x, 0);
}

auto alus(code argv)
{
	switch (argv.x.cmd) {
		case 0:
			if argv.option.bool{
				switch (typecast_typecharr(argv.x.int))
				{
					case casevalue('i', 'n', 't'):
						return use_wrapped_code_with_gc(7, argv.x);
					case casevalue('c', 'h', 'r'):
						return use_wrapped_code_with_gc(7, argv.x);
					case casevalue('c', 'h', 'r', nc(2)):
						return use_wrapped_code_with_gc(8, argv.x);
					case casevalue('c', 'h', 'r', nc(3)):
						return use_wrapped_code_with_gc(9, argv.x);
					case casevalue('c', 'h', 'r', nc(4)):
						return use_wrapped_code_with_gc(0xA, argv.x);
					case casevalue('c', 'h', 'r', nc(5)):
						return use_wrapped_code_with_gc(0xB, argv.x);
					case _:
						TypeError = 0; //raise TypeErr
						assert(TypeError); //raise TypeErr
						break;
				};
			} elif (argv.x.bool) {
				return use_wrapped_code_with_gc(0, argv.x);
			} else {
				return use_wrapped_code_with_gc(1, argv.x);
			};
		case 1:
			if (argv.option.bool) {
				return use_wrapped_code_with_gc(8, argv.x);
			} else {
				return use_wrapped_code_with_gc(9, argv.x);
			};
		case 2:
			return use_wrapped_code_with_gc(0xA, argv.x, argv.y);
		case 3:
			return use_wrapped_code_with_gc(0xB, argv.x, argv.y);
		case 4:
			return use_wrapped_code_with_gc(0xC, argv.x, argv.y);
		case 5:
			return use_wrapped_code_with_gc(0xD, argv.x, argv.y);
		case 6:
			return use_wrapped_code_with_gc(0xE, argv.x, argv.y);
		case 7:
			return use_wrapped_code_with_gc(0xF, argv.x);
		case _:
			CommandNotFoundError = 0; //raise CommandNotFoundError
			assert(CommandNotFoundError); //raise CommandNotFoundError
			break;
	};
}

#endif