using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace CSharpTest
{
    [TestClass]
    public class TypeUsageTest
    {
        [TestMethod]
        public void ObjectsTest()
        {
            var t = new MyLibrary.TypeUsageExample();
            t.PassByValue("PassByValue");
            Assert.AreEqual("PassByValue", t.ReturnByValue());
            t.PassByConstRef("PassByConstRef");
            Assert.AreEqual("PassByConstRef", t.ReturnByConstRef());
        }
    }
}
