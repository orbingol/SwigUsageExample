/// \file
/// Example implementation

#include "MyLibrary.hpp"
#include <streambuf>

////////////////////////////////////////////////////////////////
// PrimitiveTypesExample

mybyte PrimitiveTypesExample::RoundTrip(mybyte x)
{
    return x;
}

myshort PrimitiveTypesExample::RoundTrip(myshort x)
{
    return x;
}

myint PrimitiveTypesExample::RoundTrip(myint x)
{
    return x;
}

mylong PrimitiveTypesExample::RoundTrip(mylong x)
{
    return x;
}

myfloat PrimitiveTypesExample::RoundTrip(myfloat x)
{
    return x;
}

mydouble PrimitiveTypesExample::RoundTrip(mydouble x)
{
    return x;
}

////////////////////////////////////////////////////////////////
// StringBuilderExample

StringBuilderExample::StringBuilderExample()
{
}

StringBuilderExample::StringBuilderExample(const mystring& s)
    : value(s)
{
}

void StringBuilderExample::AppendString(const mystring& s)
{
    value += s;
}

void StringBuilderExample::AppendLine()
{
    value += "\n";
}

void StringBuilderExample::AppendLine(const mystring& s)
{
    AppendString(s);
    AppendLine();
}

mystring StringBuilderExample::CreateString()
{
    return value;
}

////////////////////////////////////////////////////////////////
// CallbackExample

myint CallbackExample::GetCallbackResult()
{
    return ImplementMe();
}

CallbackExample::~CallbackExample()
{
}

////////////////////////////////////////////////////////////////
// TypeUsageExample
mystring TypeUsageExample::ReturnByValue()
{
    return value;
}
const mystring& TypeUsageExample::ReturnByConstRef()
{
    return value;
}

const mystring* TypeUsageExample::ReturnByConstPtr()
{
    return &value;
}

mystring& TypeUsageExample::ReturnByRef()
{
    return value;
}

mystring* TypeUsageExample::ReturnByPtr()
{
    return &value;
}

void TypeUsageExample::PassByValue(mystring x)
{
    value = x;
}

void TypeUsageExample::PassByConstRef(const mystring& x)
{
    value = x;
}

void TypeUsageExample::PassByConstPtr(const mystring* x)
{
    value = *x;
}

void TypeUsageExample::PassByRef(mystring& x)
{
    x = value;
}

void TypeUsageExample::PassByPtr(mystring* x)
{
    *x = value;
}

////////////////////////////////////////////////////////////////
// EnumerationUserExample

myint EnumerationUserExample::ConvertToInteger(EnumerationTypeExample e)
{
    return static_cast<myint>(e);
}

EnumerationTypeExample EnumerationUserExample::ConvertToEnumeration(myint x)
{
    if (x >= Label1 && x <= Label4)
    {
        return static_cast<EnumerationTypeExample>(x);
    }

    return Unknown;
}

////////////////////////////////////////////////////////////////
// MemberVariablesExample

const mystring& SomeClass::QuerySomeString()
{
    return SomeString;
}

mybool MemberVariablesExample::QueryBooleanMember()
{
    return BooleanMember;
}

myint MemberVariablesExample::QueryIntegerMember()
{
    return IntegerMember;
}

mydouble MemberVariablesExample::QueryFloatingPointMember()
{
    return FloatingPointMember;
}

const mystring& MemberVariablesExample::QueryStringMember()
{
    return StringMember;
}

const SomeClass& MemberVariablesExample::QueryClassMember()
{
    return ClassMember;
}

////////////////////////////////////////////////////////////////
// FileIOExample

MyIOException::MyIOException()
{
}

MyIOException::MyIOException(const mystring& message)
    : message(message)
{
}

const char* MyIOException::what() const
{
    return message.c_str();
}

FileIOExample::FileIOExample()
{
}

void FileIOExample::OpenFile(const mystring& fileName)
{
    file.open(fileName.c_str());
    if (!file.is_open())
    {
        throw MyIOException("Failed to open file " + fileName);
    }
}

/// Read entire file as string
mystring FileIOExample::ReadAll()
{
    if (!file.is_open())
    {
        throw MyIOException("File isn't open.");
    }

    mystring ret((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    if (file.bad())
    {
        throw MyIOException("Error reading file.");
    }

    return ret;
}

/// Close file
void FileIOExample::Close()
{
    file.close();
}

/// Destructor
FileIOExample::~FileIOExample()
{
    Close();
}

////////////////////////////////////////////////////////////////
// CollectionUserExample

const mystring& CollectionUserExample::GetObjectAtIndex(const std::vector<mystring>& c, myint i)
{
    return c[i];
}

myint CollectionUserExample::GetCount(const std::vector<mystring>& c)
{
    return static_cast<myint>(c.size());
}