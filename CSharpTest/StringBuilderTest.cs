using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace CSharpTest
{
    using SB = MyLibrary.StringBuilderExample;

    [TestClass]
    public class StringBuilderTest
    {
        [TestMethod]
        public void AsciiTest()
        {
            string asciiValue = "Some value";
            var sb = new SB(asciiValue);
            Assert.AreEqual(asciiValue, sb.CreateString());
        }

        [TestMethod]
        public void UnicodeTest()
        {
            // Known to fail with SWIGWin 3.0.5
            string unicodeValue = "吝吞吟吠吡";
            var sb = new SB(unicodeValue);
            Assert.AreEqual(unicodeValue, sb.CreateString());
        }
    }
}
