using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace CSharpTest
{
    [TestClass]
    public class MemberVariablesTest
    {
        [TestMethod]
        public void MembersTest()
        {
            var m = new MyLibrary.MemberVariablesExample();
            m.BooleanMember = true;
            Assert.AreEqual(true, m.BooleanMember);
            Assert.AreEqual(true, m.QueryBooleanMember());
            m.IntegerMember = 1234;
            Assert.AreEqual(1234, m.IntegerMember);
            Assert.AreEqual(1234, m.QueryIntegerMember());
            m.FloatingPointMember = 1.23;
            Assert.AreEqual(1.23, m.FloatingPointMember);
            Assert.AreEqual(1.23, m.QueryFloatingPointMember());
            m.StringMember = "Some string";
            Assert.AreEqual("Some string", m.StringMember);
            Assert.AreEqual("Some string", m.QueryStringMember());
            m.ClassMember = new MyLibrary.SomeClass
            {
                SomeString = "Some class string"
            };
            Assert.AreEqual("Some class string", m.ClassMember.SomeString);
            Assert.AreEqual("Some class string", m.QueryClassMember().QuerySomeString());
            MyLibrary.SomeClass classMember = m.ClassMember;
            classMember.SomeString = "Some other string";
            Assert.AreEqual("Some other string", m.ClassMember.SomeString);
        }
    }
}
