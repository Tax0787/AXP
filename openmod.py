from json import load as l
from json import dump as d_core_core
'''
o : open
w : write-open
r : read-open
a : append-open
x : create-open
~b : binary-open
~gen : opener funtion make (give opener-option, but another lambda gen need)
moder : opener(f, m)
writer : writer(x)(fp) = fp.write(x)
writelinesgen : writeline(x)(fp) = fp.writelines(x)
_core : writer, writelinesgen, d's core function, get vitual fp.x
d_core_core : json.dump
Get/SetJ : JSON get/set
wtr~ : wither~
do_~_core : gen do_~_core by wtropener
do_~ : (wtro mode) do right that time with-opened-func-do (write-func ver : wrtw)
'''

o, moder, fpfunc, _rwfuncs, _wfuncs = open, (
    lambda opener, f, m: opener(f, m)), (lambda fp, x: getattr(fp, x)), {
        'writer_core': 'write',
        'writelinesgen_core': 'writelines',
        'read': 'read',
        'readlines': 'readlines',
        'readline': 'readline'
    }, ['writer', 'writelinesgen', 'd']
_modes, _with_rfuncs, _with_wfuncs = list('wrax'), list(
    _rwfuncs.values())[2:], {
        i: j
        for i, j in zip(('write', 'writeline'), _wfuncs[:-1])
    }
_modes = _modes + list(map((lambda x: x + 'b'), _modes))
for i in _modes:
	globals()[i + 'gen'] = lambda opener, f: opener(
	    f, i)  #make var by globals() var space LOL
for i in _modes:
	globals()[i] = lambda f: globals()[i + 'gen'](open, f)
for i, j in _rwfuncs.items():
	globals()[i] = lambda fp: fpfunc(fp, j)


def d_core(fp):
	'''
	vitual fp.x
	d_core(fp) => lambda x : d_core_core(x, fp)
	'''
	return lambda x: d_core_core(x, fp)


def wfuncorer(func):
	'''
	write-open function core -er
	wfuncorer(func)(data)(fp)
	'''

	def wfuncorer_core(data):
		'''
		return wfuncorer_obj.
		wfuncoere_obj(fp) write data.
		'''

		def wfuncorer_obj(fp):
			return func(fp)(data)

		return wfuncorer_obj

	return wfuncorer_core


def wither(opener):
	'''
	1 | @wither(open-function)
	2 | function define
	opener-with-open and file-manage by fp(with as (fp))
	'''

	def with_deco(func):
		'''
		wither's decorator part
		'''

		def with_core(filename):
			'''
			wither-core-part
			with opener(filename) as fp:
				return func(fp)
			'''
			with opener(filename) as fp:
				return func(fp)

		return with_core

	return with_deco


def wrte_action(wtropener):
	'''
	@wrte_action(wtropener)
	function
	=> lambda f, x => write_do_func
	'''

	def wrte_action_deco(func):
		'''
		core part.
		'''
		return lambda f, x: wtropener(func(x))(f)


def wrtn_actioner(func):
	'''
	wrtn_actioner(func) => lambda wtropener : wtrn_action(wtropener, func)
	'''
	return lambda wtropener : wrte_action(wtropener)(func)

wtro = wither(o)

for i in _modes:
	globals()['wtr' + i] = wither(globals()[i])

for i in _with_rfuncs:
	globals()['do_' + i + '_core'] = lambda wtropener: wtropener(globals()[i])

for i in _with_rfuncs[2:]:
	globals()['do_' + i] = globals()['do_' + i + '_core'](wtro)

for i in _wfuncs:
	globals()[i] = wfuncorer(globals()[i + '_core'])

for i, j in _with_wfuncs.items():
	globals()['do_' + i + '_core'] = wrtn_actioner(globals()[j])

for i in _with_wfuncs.keys():
	globals()['do_' + i] = globals()['do_' + i + '_core'](wtrw)

GetJ = wtro(l)
SetJ = wrtn_actioner(d)(wrtw)
