#ifndef _ALUDLL_H
# define _ALUDLL_H

//#include "Python.h"
#include "axpaludlh.h"

/* #define PYDF(x) static PyObject* x(PyObject *self, PyObject *args)
#define PYDFRET return Py_BuildValue
#define pydf PYDF
#define pydfret PYDFRET */

//static PyObject *ErrorObject;

auto ret;
size_t cnt;

bool rettype(void);
auto axpalucore_arr(bool);
bool axpalucore_0(ptr, ptr, ptr, ptr);
bool axpalucore_1(char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char);

/*
pydf(axpalucore)
{
	//pass;
	pydfret();
}

static struct PyMethodDef methods[] =
{
		{"wlog", write_log, METH_VARARGS},
		{NULL, NULL}
};

void initaludll() */

#endif