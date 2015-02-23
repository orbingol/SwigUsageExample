// SWIG interface file

%module(directors="1") mylibrary
%feature("director");

#ifdef SWIGJAVA
%include <enums.swg>
#endif

#ifdef SWIGCSHARP
%include <csharp_utf8_std_string.i>
#else
#ifdef SWIGXML
// Dummy entry for SWIG XML
namespace std
{
class string;
}
#else
%include <std_string.i>
#endif
#endif

%include <exception.i>

#ifdef SWIGXML
// Dummy entries for SWIG XML
namespace std
{
template<typename T> class vector;
template<typename TKey, typename TValue> class map;
}
#else
%include <std_vector.i>
%include <std_map.i>
#endif

// Include the header for externally visible QTest interfaces 
//  (this is the same header as is used by C++ programs)
%include <MyLibrary.hpp>
