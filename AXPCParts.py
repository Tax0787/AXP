from ctypes import c_char, c_void_p, c_bool
from aludll import rettype, axpalucore_arr, axpalucore_0, axpalucore_1

cbooltrue = c_bool(True)
cboolfalse = c_bool(False)

def cbool2num(x):
	if x == cbooltrue:
		return 1;
	elif x == cboolfalse:
		return 0;
	else:
		raise SystemError('cbool!!!!! need but it\'s not.')

p = cbool2num(rettype())
f = axpalucore_1 if p else axpalucore_0
n = 4 if p else 20

def axpalucore_arr(*argv):
	yield n
	if f(*argv):
		for i in range(n):
			yield axpalucore_arr()
	else:
		yield axpalucore_arr()