/// \file
/// Java native interface code

// For Visual Studio build, expects JDK_HOME is set appropriately

#define _CRT_SECURE_NO_WARNINGS // strncpy used by SWIG

#include <MyLibrary.hpp>

// We #include the generated SWIG source file into another cpp file so that
//  we can include or define as appropriate before the generated definitions.
#include "MyLibrary_Wrap_Java.cxx"
