#include "aludll.h"

size_t cnt = 0;

bool rettype(void) //see python parts
{
	return sizeof(ptr) > 40;
}

bool rettypes = rettype();

auto axpalucore_arr(bool p)
{
	if (p){
		return ret; 
	} else {
		return ret[cnt++]
	}
}

bool axpalucore_0(ptr a, ptr b, ptr c, ptr d)
{
	code x;
	x.cmd = a;
	x.option = b;
	x.x = c;
	x.y = d;
	auto ret = alus(x);
	if (a == 8 || a == 9) {
		return false;
	} else {
		return true
	}
}

bool axpalucore_1(char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8, char v9, char vA, char vB, char vC, char vD, char vE, char vF, char v10, char v11, char v12, char v13, char v14)
{
	code x;
	axptype y[4];
	char z[5];
	auto ret = alus(x);
	char v[20];
	v[0] = v1;
	v[1] = v2;
	v[2] = v3;
	v[3] = v4;
	v[4] = v5;
	v[5] = v6;
	v[6] = v7;
	v[7] = v8;
	v[8] = v9;
	v[9] = vA;
	v[0xA] = vB;
	v[0xB] = vC;
	v[0xC] = vD;
	v[0xD] = vE;
	v[0xE] = vF;
	v[0xF] = v10;
	v[16] = v11;
	v[17] = v12;
	v[18] = v13;
	v[19] = v14; //13 makes me scared.
	size_t j = 0
	for (char i :: v) {
		z[j%5] = i;
		j++;
		if (j%5 == 0) {
			y[j/5] = (axptypes) z;
		};
	};
	x.cmd = y[0];
	x.option = y[1];
	x.x = y[2];
	x.y = y[3];
	auto ret = alus(x);
	if (a == 8 || a == 9) {
		return false;
	} else {
		return true;
	};
}

void initaludll()
{
		PyObject* m;

		m = Py_InitModule("mylib", methods);

		ErrorObject = Py_BuildValue("s", "error");
}