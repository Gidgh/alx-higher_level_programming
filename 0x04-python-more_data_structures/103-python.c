#include <Python.h>

void print_python_bytes(PyObject *p)
{
    PyBytesObject *bytes = (PyBytesObject *)p;
    Py_ssize_t size = PyBytes_Size(p);
    const char *str = PyBytes_AsString(p);

    printf("[.] bytes object info\n");
    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", str);
    printf("  first 10 bytes: ");
    for (Py_ssize_t i = 0; i < size && i < 10; i++)
        printf("%02x ", (unsigned char)str[i]);
    printf("\n");
}

void print_python_list(PyObject *p)
{
    PyListObject *list = (PyListObject *)p;
    Py_ssize_t size = PyList_Size(p);

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", list->allocated);

    for (Py_ssize_t i = 0; i < size; i++)
    {
        PyObject *item = PyList_GetItem(p, i);
        printf("Element %ld: ", i);

        if (PyBytes_Check(item))
            print_python_bytes(item);
        else if (PyList_Check(item))
            print_python_list(item);
        else if (PyTuple_Check(item))
            print_python_tuple(item);
        else if (PyFloat_Check(item))
            printf("float\n");
        else if (PyLong_Check(item))
            printf("int\n");
        else if (PyUnicode_Check(item))
            printf("str\n");
        else
            printf("Unknown\n");
    }
}
