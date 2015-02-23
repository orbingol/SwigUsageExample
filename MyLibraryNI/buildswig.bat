mkdir ..\MyLibrarySharp
swig -c++ -includeall -o MyLibrary_Wrap_CSharp.cxx -outcurrentdir -outdir ..\MyLibrarySharp -csharp -namespace MyLibrary -dllimport MyLibraryNI ..\MyLibrary\MyLibrary.i
mkdir ..\MyLibraryJava
mkdir ..\MyLibraryJava\MyLibary
swig -c++ -includeall -o MyLibrary_Wrap_Java.cxx -outcurrentdir -outdir ..\MyLibraryJava\MyLibrary -java -package MyLibrary ..\MyLibrary\MyLibrary.i
mkdir ..\MyLibraryPython
swig -c++ -includeall -o MyLibrary_Wrap_Python.cxx -outcurrentdir -outdir ..\MyLibraryPython -python ..\MyLibrary\MyLibrary.i
