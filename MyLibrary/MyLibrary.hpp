/// \file
/// Example SWIG-wrapped API header

#ifndef INCLUDED_MYLIBRARY_HPP
#define INCLUDED_MYLIBRARY_HPP

#ifndef SWIG // Hide system headers from SWIG
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <map>
#endif

////////////////////////////////////////////////////////////////
// Primitive types

/// Boolean type (C# bool, Java boolean)
typedef bool mybool;

/// Byte type (C# byte, Java byte)
#ifdef SWIGJAVA // byte is signed in Java
typedef signed char mybyte;
#else
typedef unsigned char mybyte;
#endif

// NOTE: Actual sizes of integer types vary according to platform. Adjust as necessary. These typedefs are in practice correct for the more common platforms.

/// 16-bit signed integer type (C# short, Java short)
typedef short myshort;

/// 32-bit signed integer type (C# int, Java int)
typedef int myint;

/// 64-bit signed integer type (C# long, Java long)
typedef long long mylong;

/// Single-precision floating-point type (C# float, Java float)
typedef float myfloat;

/// Double-precision floating-point type (C# double, Java double)
typedef double mydouble;

////////////////////////////////////////////////////////////////
// String type

/// String type (C# string, Java String)
typedef std::string mystring;

////////////////////////////////////////////////////////////////
// Classes

/// Example class showing use of primitive types (and method name overloading and static methods)
class PrimitiveTypesExample
{
public:

    static mybyte RoundTrip(mybyte x);
    static myshort RoundTrip(myshort x);
    static myint RoundTrip(myint x);
    static mylong RoundTrip(mylong x);
    static myfloat RoundTrip(myfloat x);
    static mydouble RoundTrip(mydouble x);
};

/// Example of passing strings between languages
class StringBuilderExample
{
private:

    mystring value;

public:

    /// Construct with empty string
    StringBuilderExample();

    /// Construct with initial string
    StringBuilderExample(const mystring& s);

    /// Append a string
    void AppendString(const mystring& s);

    /// Append a new-line
    void AppendLine();

    /// Append a string and add a new line
    void AppendLine(const mystring& s);

    /// Return the string created
    mystring CreateString();
};

/// Example of enumeration type
enum EnumerationTypeExample
{
    Unknown = 0,
    Label1 = 1,
    Label2 = 2,
    Label3 = 3,
    Label4 = 4
};

/// Example of class making use of an enumeration type
class EnumerationUserExample
{
public:

    /// Convert from enumeration type to integer
    static myint ConvertToInteger(EnumerationTypeExample e);

    /// Convert from integer to enumeration type
    static EnumerationTypeExample ConvertToEnumeration(myint x);
};

/// Example of callback into target-language via virtual methods
class CallbackExample
{
public:

    /// Return the value returned by ImplementMe()
    myint GetCallbackResult();

    /// Callback, which will be implemented in target language
    virtual myint ImplementMe() = 0;

    virtual ~CallbackExample();
};

/// Example of different mechanisms of passing and returning values.
/// SWIG-unfriendly methods are hidden by the preprocessor.
class TypeUsageExample
{
private:
    mystring value;

public:
    /// OK
    mystring ReturnByValue();

    /// OK
    const mystring& ReturnByConstRef();

#ifndef SWIG
    /// Un-idiomatic
    const mystring* ReturnByConstPtr();
    
    /// Doesn't compile in C#
    mystring& ReturnByRef();

    // Un-idiomatic
    mystring* ReturnByPtr();
#endif

    /// OK
    void PassByValue(mystring x);

    /// OK
    void PassByConstRef(const mystring& x);

#ifndef SWIG
    /// Un-idiomatic
    void PassByConstPtr(const mystring* x);

    /// Doesn't compile in C#
    void PassByRef(mystring& x);

    /// Un-idiomatic
    void PassByPtr(mystring* x);
#endif
};

/// A class for the MemberVariablesExample
class SomeClass
{
public:

    /// Some string value
    mystring SomeString;

    /// Retrieve SomeString from method (to check it was set correctly)
    const mystring& QuerySomeString();
};

/// Example of class with public member variables
class MemberVariablesExample
{
public:

    /// Boolean-type member
    mybool BooleanMember;

    /// Retrieve BooleanMember from method (to check it was set correctly)
    mybool QueryBooleanMember();

    /// Integer-type member
    myint IntegerMember;

    /// Retrieve IntegerMember from method (to check it was set correctly)
    myint QueryIntegerMember();

    /// Floating-point-type member
    mydouble FloatingPointMember;

    /// Retrieve FloatingPointMember from method (to check it was set correctly)
    mydouble QueryFloatingPointMember();

    /// String-type member
    mystring StringMember;

    /// Retrieve StringMember from method (to check it was set correctly)
    const mystring& QueryStringMember();

    /// Class-instance member
    SomeClass ClassMember;

    /// Retrieve ClassMember from method (to check it was set correctly)
    const SomeClass& QueryClassMember();
};

#ifndef SWIG
/// I/O Exception
class MyIOException : public std::exception
{
private:
    mystring message;

public:

    MyIOException();

    MyIOException(const mystring& message);

    virtual const char* what() const throw();
};
#else
// Create an exception mapping for MyIOException
#ifdef SWIGJAVA
%typemap(throws, throws="java.io.IOException") MyIOException {
    jclass excep = jenv->FindClass("java/io/IOException");
    if (excep)
        jenv->ThrowNew(excep, $1.what());
    return $null;
}
#else
%typemap(throws, canthrow=1) MyIOException {
    SWIG_exception( SWIG_IOError, $1.what() );
}
#endif
#endif

#ifdef _WIN32
// warning C4290: C++ exception specification ignored except to indicate a function is not __declspec(nothrow)
#pragma warning(disable: 4290)
#endif

/// Example of a class which throws an exception
class FileIOExample
{
private:
    std::ifstream file;

public:

    /// Initialize
    FileIOExample();

    /// Open a file
    void OpenFile(const mystring& fileName) throw(MyIOException);

    /// Read entire file as string
    mystring ReadAll() throw(MyIOException);

    /// Close file
    void Close();

    /// Destructor
    ~FileIOExample();
};

// Convenience macros for declaring SWIG collections, with correspondingly named typedefs
#ifdef SWIG
#define MYLIB_DECLARE_VECTOR(MemberType, TypeName) namespace std { %template(TypeName) vector<MemberType>; } typedef std::vector<MemberType> TypeName;
#define MYLIB_DECLARE_MAP(KeyType, ValueType, TypeName) namespace std { %template(TypeName) map<KeyType, ValueType>; } typedef std::map<KeyType, ValueType> TypeName;
#else
#define MYLIB_DECLARE_VECTOR(MemberType, TypeName) typedef std::vector<MemberType> TypeName;
#define MYLIB_DECLARE_MAP(KeyType, ValueType, TypeName) typedef std::map<KeyType, ValueType> TypeName;
#endif

MYLIB_DECLARE_VECTOR(mystring, StringVector);
MYLIB_DECLARE_MAP(mystring, myint, StringToIntMap);

/// Example of class which uses an exception
class CollectionUserExample
{
public:

    static const mystring& GetObjectAtIndex(const StringVector& c, myint i);

    static myint GetCount(const StringVector& c);
};

#endif
