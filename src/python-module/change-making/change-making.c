#include <Python.h>
#include "structmember.h"
#include "functions.h"


typedef struct {
    PyObject_HEAD
	int n;
	PyObject *coins;
	int amount;
	int val;
	PyObject *change;
} ChangeMaking;


static void ChangeMaking_dealloc(ChangeMaking* self) {
    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject *ChangeMaking_new(PyTypeObject *type, PyObject *args) {
    ChangeMaking *self;

    self = (ChangeMaking *)type->tp_alloc(type, 0);
    if (self != NULL) {
		self->n = 0;
		self->coins = NULL;
		self->amount = 0;
		self->val = 0;
		self->change = NULL;
    }

    return (PyObject *)self;
}


static int ChangeMaking_init(ChangeMaking *self, PyObject *args, PyObject *kwds) {

	PyObject *py_coins = NULL, *tmp;

	static char *kwlist[] = {"amount", "coins", NULL};

	if (!PyArg_ParseTupleAndKeywords(args, kwds, "|iO", kwlist, &self->amount, &py_coins))
		return -1;

	if (py_coins) {
		tmp = self->coins;
		Py_INCREF(py_coins);
		self->coins = py_coins;
		Py_XDECREF(tmp);
	}
	
	Py_ssize_t n = PyList_Size(py_coins);
	self->n = n;

	int coins[n];
	for(int i = 0; i < n; i++)
		coins[i] = PyLong_AsLong(PyList_GetItem(py_coins, i));

	if (!self->val) {
		int table[n+1][self->amount+1];
		change_making_table(n, coins, self->amount, table);
		self->val = table[n][self->amount];
	}

	if (!self->change) {
		int change[n];
		PyObject *py_change = PyList_New(n);
		change_making_coins(n, coins, self->amount, change);
		for (int i = 0; i < n; i++)
			PyList_SetItem(py_change, i, Py_BuildValue("i", change[i]));
		tmp = self->change;
		Py_INCREF(py_change);
		self->change = py_change;
		Py_XDECREF(tmp);
	}
	
	return 0;
}


static PyMemberDef ChangeMaking_members[] = {
    {"amount", T_INT, offsetof(ChangeMaking, amount), 0, "doc"},
    {"n", T_INT, offsetof(ChangeMaking, n), 0, "doc"},
    {"coins", T_OBJECT_EX, offsetof(ChangeMaking, coins), 0, "doc"},
    {"val", T_INT, offsetof(ChangeMaking, val), 0, "doc"},
    {"change", T_OBJECT_EX, offsetof(ChangeMaking, change), 0, "doc"},
    {NULL}
};


static PyObject *ChangeMaking_amount(ChangeMaking* self) {
	return Py_BuildValue("i", self->amount);
}


static PyObject *ChangeMaking_n(ChangeMaking* self) {
	return Py_BuildValue("i", self->n);
}


static PyObject *ChangeMaking_coins(ChangeMaking* self) {
	return self->coins;
}


static PyObject *ChangeMaking_change(ChangeMaking* self) {
	return self->change;
}


static PyObject *ChangeMaking_val(ChangeMaking* self) {
	return Py_BuildValue("i", self->val);
}


static PyMethodDef ChangeMaking_methods[] = {
	    {
			"amount", (PyCFunction)ChangeMaking_amount, METH_NOARGS,
			"DOC"
		},
	    {
			"n", (PyCFunction)ChangeMaking_n, METH_NOARGS,
			"DOC"
		},
	    {
			"coins", (PyCFunction)ChangeMaking_coins, METH_NOARGS,
		 	"DOC"
		},
	    {
			"change", (PyCFunction)ChangeMaking_change, METH_NOARGS,
		 	"DOC"
		},
	    {
			"val", (PyCFunction)ChangeMaking_val, METH_NOARGS,
			"DOC"
		},
		{NULL} 
};


static PyTypeObject ChangeMakingType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "change_making.ChangeMaking",       /* tp_name */
    sizeof(ChangeMaking),          /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor)ChangeMaking_dealloc, /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT |
        Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "DOC",           /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ChangeMaking_methods,          /* tp_methods */
    ChangeMaking_members,          /* tp_members */
    0,
	0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,						   /* tp_dictoffset */
    (initproc)ChangeMaking_init,   /*tp_init*/
    0,                         /* tp_alloc */
    ChangeMaking_new,              /* tp_new */
};


static PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "change_making",
    "DOC",
    -1,
    NULL, NULL, NULL, NULL, NULL
};


PyMODINIT_FUNC PyInit_change_making(void)
{
    PyObject* m;
    
	if (PyType_Ready(&ChangeMakingType) < 0)
        return NULL;

    m = PyModule_Create(&module);
    if (m == NULL)
        return NULL;

    Py_INCREF(&ChangeMakingType);
    PyModule_AddObject(m, "ChangeMaking", (PyObject *)&ChangeMakingType);
    return m;
}
