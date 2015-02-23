# SwigUsageExample
Example showing use of SWIG to generate wrappers for Java, Python and C#.

Structure:
  * **SwigExample.sln** - Visual Studio 2013 solution
  * **CSharpTest** - Visual Studio unit-test code showing use of generated C# wrapper
  * **JavaTest** - JUnit unit-test code showing use of generated Java wrapper
  * **MyLibrary** - Example C++ library that is being wrapped by SWIG
  * **MyLibraryJava** - Contains script to build JAR of generated SWIG java files
  * **MyLibraryPython** - PyUnit unit-test code, plus script to copy the native-interface DLL to the right name
  * **MyLibrarySharp** - Builds the generated C# wrapper classes

The Visual Studio solution can be used to build the C++ code and the generated C# bindings. It also generates the language wrappers for Java and Python, and builds the native interface DLLs too (in Java and Python solution configurations respectively). The Java JAR is build separately with the script in the **MyLibraryJava** directory.

This example illustrates the language features discussed in the article [C++ API Design for SWIG](https://www.softwariness.com/articles/api-design-for-swig/).
