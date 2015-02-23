using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace CSharpTest
{
    class MyCallback : MyLibrary.CallbackExample
    {
        public override int ImplementMe()
        {
            return 54321;
        }
    };

    [TestClass]
    public class CallbackTest
    {
        [TestMethod]
        public void OverrideTest()
        {
            var m = new MyCallback();
            Assert.AreEqual(54321, m.GetCallbackResult());
        }
    }
}
