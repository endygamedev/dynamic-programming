#include <Python.h>
#include "fibonacci.h"
#include "functions.h"


static PyObject *fib(PyObject *self, PyObject *args) {
	double n;

	if(!PyArg_ParseTuple(args, "d", &n))
		return NULL;
	
	return Py_BuildValue("i", fibonacci(n));

}


static PyObject *py_min_sum_partition(PyObject *self, PyObject *args) {
	PyListObject *list;
	int s1, s2;

	if(!PyArg_ParseTuple(args, "Oii", &list, &s1, &s2))
		return NULL;

	Py_ssize_t n = PyList_Size(list);
	
	int s[n];
	for(int i = 0; i < n; i++)
		s[i] = PyLong_AsLong(PyList_GetItem(list, i));

	return Py_BuildValue("i", min_sum_partition(n, s, s1, s2));
}


static PyMethodDef methods[] = {
	{
		"min_sum_partition",
		py_min_sum_partition,
		METH_VARARGS,
		"Doc"
	},
	{
		"fib",
		fib,
		METH_VARARGS,
		"doc"
	}
};


static PyModuleDef module = {
	PyModuleDef_HEAD_INIT,
	"fdpp",
	"doc",
	-1,
	methods,
	NULL,
	NULL,
	NULL,
	NULL
};


PyMODINIT_FUNC PyInit_fdpp(void) {
	PyObject *m;
	m = PyModule_Create(&module);
	if(m == NULL)
		return NULL;

	return m;
}
