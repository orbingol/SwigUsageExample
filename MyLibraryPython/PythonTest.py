#!/usr/bin/env python
# -*- coding: utf-8 -*-
import unittest;
from mylibrary import *;

class PrimitiveTypesTest(unittest.TestCase):
    def testRoundTrip(self):
        self.assertEqual(12345678, PrimitiveTypesExample.RoundTrip(12345678))
        self.assertEqual(123456789101112, PrimitiveTypesExample.RoundTrip(123456789101112))
        self.assertAlmostEqual(1.23, PrimitiveTypesExample.RoundTrip(1.23), places=2)
        self.assertAlmostEqual(1.2345678, PrimitiveTypesExample.RoundTrip(1.2345678), places=7)

class StringBuilderTest(unittest.TestCase):
    def testAscii(self):
        s = "Some value";
        sb = StringBuilderExample(s)
        self.assertEqual(s, sb.CreateString())
    
    def testUnicode(self):
        s = "吝吞吟吠吡";
        sb = StringBuilderExample(s)
        self.assertEqual(s, sb.CreateString())

class MyCallback(CallbackExample):
    def ImplementMe(self):
        return 54321

class CallbackTest(unittest.TestCase):
    def testOverride(self):
        m = MyCallback()
        self.assertEqual(54321, m.GetCallbackResult())

class EnumerationTest(unittest.TestCase):
    def testEnumValues(self):
        e = Label2 # Unfortunately, module level rather than some kind of enum type
        self.assertEqual(2, EnumerationUserExample.ConvertToInteger(e))
        self.assertEqual(e, EnumerationUserExample.ConvertToEnumeration(2))

class TypeUsageTest(unittest.TestCase):
    def testObjects(self):
        t = TypeUsageExample()
        t.PassByValue("PassByValue")
        self.assertEqual("PassByValue", t.ReturnByValue())
        t.PassByConstRef("PassByConstRef")
        self.assertEqual("PassByConstRef", t.ReturnByConstRef())

class MemberVariablesTest(unittest.TestCase):
    def testMembers(self):
        m = MemberVariablesExample()
        m.BooleanMember = True
        self.assertEqual(True, m.BooleanMember)
        self.assertEqual(True, m.QueryBooleanMember())
        m.IntegerMember = 1234
        self.assertEqual(1234, m.IntegerMember)
        self.assertEqual(1234, m.QueryIntegerMember())
        m.FloatingPointMember = 1.23
        self.assertAlmostEqual(1.23, m.FloatingPointMember, places=2)
        self.assertAlmostEqual(1.23, m.QueryFloatingPointMember(), places=2)
        m.StringMember = "Some string"
        self.assertEqual("Some string", m.StringMember)
        self.assertEqual("Some string", m.QueryStringMember())
        s = SomeClass()
        s.SomeString = "Some class string"
        m.ClassMember = s
        self.assertEqual("Some class string", m.ClassMember.SomeString)
        self.assertEqual("Some class string", m.QueryClassMember().QuerySomeString())
        classMember = m.ClassMember;
        classMember.SomeString = "Some other string";
        self.assertEqual("Some other string", m.ClassMember.SomeString);

class ExceptionTest(unittest.TestCase):
    def testCatchException(self):
        f = FileIOExample()
        self.assertRaises(IOError, f.OpenFile, "This file does not exist") # Expect to throw IOError

class CollectionsTest(unittest.TestCase):
    def testVectorPassing(self):
        v = StringVector()
        v.push_back("a")
        v.push_back("b")
        v.push_back("c")
        
        self.assertEqual(3, CollectionUserExample.GetCount(v));
        self.assertEqual("b", CollectionUserExample.GetObjectAtIndex(v, 1));

    def testMapUse(self):
        m = StringToIntMap()
        m["1"] = 1
        m["2"] = 2
        m["3"] = 3
        
        self.assertEqual(3, len(m));
        self.assertEqual(3, m["3"]);

if __name__ == "__main__":
    unittest.main()
