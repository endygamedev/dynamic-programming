#include <Python.h>
#include "functions.h"


static PyObject *py_min_sum_partition(PyObject *self, PyObject *args) {
	PyListObject *list;

	if(!PyArg_ParseTuple(args, "O", &list))
		return NULL;

	long n = PyLong_AsLong(PyLong_FromSsize_t(PyList_Size(list)));
	
	int s[n];
	for(int i = 0; i < n; i++)
		s[i] = PyLong_AsLong(PyList_GetItem(list, i));
	
	return Py_BuildValue("i", min_sum_partition1(n, s, 0, 0));
}


static PyObject *py_coin_change(PyObject *self, PyObject *args) {
	PyObject *list;
	int amount;

	if(!PyArg_ParseTuple(args, "Oi", &list, &amount))
		return NULL;

	Py_ssize_t n = PyList_Size(list);
	
	int coins[n];
	for(int i = 0; i < n; i++)
		coins[i] = PyLong_AsLong(PyList_GetItem(list, i));

	return Py_BuildValue("i", coin_change(n, coins, amount));
}


static PyObject *py_const_cost_matrix_path(PyObject *self, PyObject *args) {
	PyListObject *list;
	int k;

	if(!PyArg_ParseTuple(args, "Oi", &list, &k))
		return NULL;

	Py_ssize_t m = PyList_Size(list);
	Py_ssize_t n = PyList_Size(PyList_GetItem(list, 0));

	int s[m][n];
	for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            s[i][j] = PyLong_AsLong(PyList_GetItem(PyList_GetItem(list, i), j));

	return Py_BuildValue("i", const_cost_matrix_path(m, n, s, k));
}


static PyObject *py_min_matrix_path(PyObject *self, PyObject *args) {
	PyListObject *list;

	if(!PyArg_ParseTuple(args, "O", &list))
		return NULL;

	Py_ssize_t m = PyList_Size(list);
	Py_ssize_t n = PyList_Size(PyList_GetItem(list, 0));

	int s[m][n];
	for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            s[i][j] = PyLong_AsLong(PyList_GetItem(PyList_GetItem(list, i), j));

	return Py_BuildValue("i", min_matrix_path(m, n, s));
}


static PyObject *py_levenshtein_distance(PyObject *self, PyObject *args) {
	char *x_string;
	char *y_string;

	if(!PyArg_ParseTuple(args, "ss", &x_string, &y_string))
		return NULL;

	return Py_BuildValue("i", levenshtein_distance(x_string, y_string));
}


static PyObject *py_matrix_chain_multiplication(PyObject *self, PyObject *args) {
	PyListObject *list;

	if(!PyArg_ParseTuple(args, "O", &list))
		return NULL;

	Py_ssize_t n = PyList_Size(list);

	int s[n];
	for(int i = 0; i < n; i++)
		s[i] = PyLong_AsLong(PyList_GetItem(list, i));

	return Py_BuildValue("i", matrix_chain_multiplication(n, s));
}


static PyObject *py_binary_strings_without_ones(PyObject *self, PyObject *args) {
    int n;

	if(!PyArg_ParseTuple(args, "i", &n))
		return NULL;

	return Py_BuildValue("i", binary_strings_without_ones(n));
}


static PyObject *py_rod_cut(PyObject *self, PyObject *args) {
	PyListObject *list;
	int k;

	if(!PyArg_ParseTuple(args, "Oi", &list, &k))
		return NULL;

	Py_ssize_t n = PyList_Size(list);

	int s[n];
	for(int i = 0; i < n; i++)
		s[i] = PyLong_AsLong(PyList_GetItem(list, i));

	return Py_BuildValue("i", rod_cut(s, k));
}


static PyMethodDef methods[] = {
	{
		"min_sum_partition",
		py_min_sum_partition,
		METH_VARARGS,
		"min_sum_partition"
	},
	{
		"coin_change",
		py_coin_change,
		METH_VARARGS,
		"coin_change"
	},
	{
		"const_cost_matrix_path",
		py_const_cost_matrix_path,
		METH_VARARGS,
		"const_cost_matrix_path"
	},
	{
		"min_matrix_path",
		py_min_matrix_path,
		METH_VARARGS,
		"min_matrix_path"
	},
	{
		"matrix_chain_multiplication",
		py_matrix_chain_multiplication,
		METH_VARARGS,
		"matrix_chain_multiplication"
	},
	{
		"binary_strings_without_ones",
		py_binary_strings_without_ones,
		METH_VARARGS,
		"binary_strings_without_ones"
	},
	{
		"rod_cut",
		py_rod_cut,
		METH_VARARGS,
		"rod_cut"
	},
	{
		"levenshtein_distance",
		py_levenshtein_distance,
		METH_VARARGS,
		"levenshtein_distance"
	}
};


static PyModuleDef module = {
	PyModuleDef_HEAD_INIT,
	"fdpp",
	"Favoirte dynamic programming module",
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
