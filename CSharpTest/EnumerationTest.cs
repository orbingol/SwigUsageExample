using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace CSharpTest
{
    using E = MyLibrary.EnumerationTypeExample;
    using C = MyLibrary.EnumerationUserExample;

    [TestClass]
    public class EnumerationTest
    {
        [TestMethod]
        public void EnumValuesTest()
        {
            var e = E.Label2;
            Assert.AreEqual(2, C.ConvertToInteger(e));
            Assert.AreEqual(e, C.ConvertToEnumeration(2));
        }
    }
}
