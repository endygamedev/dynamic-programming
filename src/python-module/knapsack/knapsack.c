#include <Python.h>
#include "structmember.h"
#include "functions.h"


typedef struct {
    PyObject_HEAD
    int w;
	int n;
	PyObject *weights;
	PyObject *values;
	int val;
	PyObject *items;
} Knapsack;


static void Knapsack_dealloc(Knapsack* self) {
    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject *Knapsack_new(PyTypeObject *type, PyObject *args) {
    Knapsack *self;

    self = (Knapsack *)type->tp_alloc(type, 0);
    if (self != NULL) {
		self->w = 0;
		self->n = 0;
		self->weights = NULL;
		self->values = NULL;
		self->val = 0;
		self->items = NULL;
    }

    return (PyObject *)self;
}


static int Knapsack_init(Knapsack *self, PyObject *args, PyObject *kwds) {

	PyObject *py_weights = NULL, *py_values = NULL, *tmp;

	static char *kwlist[] = {"w", "weights", "values", NULL};

	if (!PyArg_ParseTupleAndKeywords(args, kwds, "|iOO", kwlist, &self->w, &py_weights, &py_values))
		return -1;

	if (py_weights) {
		tmp = self->weights;
		Py_INCREF(py_weights);
		self->weights = py_weights;
		Py_XDECREF(tmp);
	}
	
	if (py_values) {
		tmp = self->values;
		Py_INCREF(py_values);
		self->values = py_values;
		Py_XDECREF(tmp);
	}

	Py_ssize_t n = PyList_Size(py_weights);
	self->n = n;

	int weights[n], values[n];
	for(int i = 0; i < n; i++) {
		weights[i] = PyLong_AsLong(PyList_GetItem(py_weights, i));
		values[i] = PyLong_AsLong(PyList_GetItem(py_values, i));
	}

	if (!self->val) {
		int table[n+1][self->w+1];
		knapsack_table(self->w, n, weights, values, table);
		self->val = table[n][self->w];
	}

	if (!self->items) {
		int items[n];
		PyObject *py_items = PyList_New(n);
		knapsack_items(self->w, n, weights, values, items);
		for (int i = 0; i < n; i++)
			PyList_SetItem(py_items, i, Py_BuildValue("i", items[i]));
		tmp = self->items;
		Py_INCREF(py_items);
		self->items = py_items;
		Py_XDECREF(tmp);
	}
	
	return 0;
}


static PyMemberDef Knapsack_members[] = {
    {"w", T_INT, offsetof(Knapsack, w), 0, "doc"},
    {"n", T_INT, offsetof(Knapsack, n), 0, "doc"},
    {"weights", T_OBJECT_EX, offsetof(Knapsack, weights), 0, "doc"},
    {"values", T_OBJECT_EX, offsetof(Knapsack, weights), 0, "doc"},
    {"val", T_INT, offsetof(Knapsack, val), 0, "doc"},
    {"items", T_OBJECT_EX, offsetof(Knapsack, items), 0, "doc"},
    {NULL}
};


static PyObject *Knapsack_w(Knapsack* self) {
	return Py_BuildValue("i", self->w);
}


static PyObject *Knapsack_n(Knapsack* self) {
	return Py_BuildValue("i", self->n);
}


static PyObject *Knapsack_weights(Knapsack* self) {
	return self->weights;
}


static PyObject *Knapsack_values(Knapsack* self) {
	return self->values;
}


static PyObject *Knapsack_val(Knapsack* self) {
	return Py_BuildValue("i", self->val);
}


static PyObject *Knapsack_items(Knapsack* self) {
	return self->items;
}


static PyMethodDef Knapsack_methods[] = {
	    {
			"w", (PyCFunction)Knapsack_w, METH_NOARGS,
			"DOC"
		},
	    {
			"n", (PyCFunction)Knapsack_n, METH_NOARGS,
			"DOC"
		},
	    {
			"weights", (PyCFunction)Knapsack_weights, METH_NOARGS,
		 	"DOC"
		},
	    {
			"values", (PyCFunction)Knapsack_values, METH_NOARGS,
		 	"DOC"
		},
	    {
			"val", (PyCFunction)Knapsack_val, METH_NOARGS,
			"DOC"
		},
	    {
			"items", (PyCFunction)Knapsack_items, METH_NOARGS,
		 	"DOC"
		},
		{NULL} 
};


static PyTypeObject KnapsackType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "knapsack.Knapsack",       /* tp_name */
    sizeof(Knapsack),          /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor)Knapsack_dealloc, /* tp_dealloc */
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
    "Noddy objects",           /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    Knapsack_methods,          /* tp_methods */
    Knapsack_members,          /* tp_members */
    0,
	0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,						   /* tp_dictoffset */
    (initproc)Knapsack_init,   /*tp_init*/
    0,                         /* tp_alloc */
    Knapsack_new,              /* tp_new */
};


static PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "knapsack",
    "DOC",
    -1,
    NULL, NULL, NULL, NULL, NULL
};


PyMODINIT_FUNC PyInit_knapsack(void)
{
    PyObject* m;
    
	if (PyType_Ready(&KnapsackType) < 0)
        return NULL;

    m = PyModule_Create(&module);
    if (m == NULL)
        return NULL;

    Py_INCREF(&KnapsackType);
    PyModule_AddObject(m, "Knapsack", (PyObject *)&KnapsackType);
    return m;
}
