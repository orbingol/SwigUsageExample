/// \file
/// Python native interface code

// For Visual Studio build, expects PYTHON_HOME is set appropriately

#define _CRT_SECURE_NO_WARNINGS // strcpy used by SWIG
#define HAVE_ROUND // Stop pymath.h defining round() with wrong linkage

#include <MyLibrary.hpp>

// We #include the generated SWIG source file into another cpp file so that
//  we can include or define as appropriate before the generated definitions.
#define SWIG_PYTHON_INTERPRETER_NO_DEBUG // Build against the release Python even if this library is built with debugging symbols
#include "MyLibrary_Wrap_Python.cxx"
