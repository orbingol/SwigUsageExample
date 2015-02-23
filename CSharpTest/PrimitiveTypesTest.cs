using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace CSharpTest
{
    using PT = MyLibrary.PrimitiveTypesExample;

    [TestClass]
    public class PrimitiveTypesTest
    {
        [TestMethod]
        public void RoundTripTest()
        {
            Assert.AreEqual((byte)123, PT.RoundTrip((byte)123));
            Assert.AreEqual((short)12345, PT.RoundTrip((short)12345));
            Assert.AreEqual((int)12345678, PT.RoundTrip((int)12345678));
            Assert.AreEqual((long)123456789101112, PT.RoundTrip((long)123456789101112));
            Assert.AreEqual((float)1.23, PT.RoundTrip((float)1.23));
            Assert.AreEqual((double)1.23456789, PT.RoundTrip((double)1.23456789));
        }
    }
}
