#ifndef _AXPALUDLHH_H
# define _AXPALUDLHH_H

#include <cstddef>
#include <cmath>
#include "stdbool.h"
#include "assert.h"

#define TEMPJOINN(a, b) ab
#define CHARRX(x) typedef char TEMPJOINN(charr, x)[x]
#define TYPEVAR(x) x TEMPJOINN(x, var)
#define NUMCHAR(x) 48 + x
#define NC NUMCHAR
#define ELIF else if
#define charrx CHARRX
#define typevar TYPEVAR
#define numchar NUMCHAR
#define nc NC
#define elif ELIF

charr5 empty_charr5;
char[] empty_charr[1];

charrx(2);
charrx(3);
charrx(4);
charrx(5);

typedef (void*) ptr;

typedef void *(gcsftype)(ptr, ptr, ptr);

typedef ptr gcstackv[5];

typedef union {
	typevar(bool);
	typevar(char);
	typevar(charr2);
	typevar(charr3);
	typevar(charr4);
	typevar(charr5);
	typevar(int);
	typevar(float);
	typevar(ptr);
} axptype;

typedef struct {
	axptype cmd;
	axptype option;
	axptype x;
	axptype y;
} code;

typedef struct {
	axptype cmd;
	axptype x;
	axptype y;
} wrappers_code;

inline char* typecast_typecharr(int);

/* opcode to text for readers */
inline char* cmder_on_wrapper_core(int);

inline charr5 charr2charr5(char*); //this typecast usally used

inline char* charr5lengthcharr(char, char, char, char);

inline char* charr5lengthcharr(char, char, char);

inline char* charr5lengthcharr(char, char);

inline char* charr5lengthcharr(char);

inline charr5 cmder_on_wrapper(int);

inline charr5 casevalue(char, char, char, char);

inline charr5 casevalue(char, char, char);

inline charr5 casevalue(char, char);

inline charr5 casevalue(char);

inline wrappers_code new_wrapper_code(int, axptype, axptype);

inline auto use_wrapped_code(int, axptype, axptype);

inline auto use_wrapped_code_with_gc(int, axptype, axptype);

inline auto use_wrapped_code_with_gc(int, axptype); //bad code but I got no times

/* opcode to text for readers */

auto wrapper(wrappers_code);

auto alus(code);

void gcsf(ptr, ptr, ptr);

axptype empty_axptype;
gcstackv* GCStackBP;
gcstackv* GCStackSP;
gcsftype gcspf;

gcstackv* GCSPush(ptr, ptr, ptr); //chaining
gcstackv* GCSPop(gcsftype); //chaining & func-use

inline gcstackv* GCSPoper(void);

#endif