using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace CSharpTest
{
    [TestClass]
    public class CollectionsTest
    {
        [TestMethod]
        public void VectorPassingTest()
        {
            var v = new MyLibrary.StringVector();
            v.Add("a");
            v.Add("b");
            v.Add("c");

            Assert.AreEqual(3, MyLibrary.CollectionUserExample.GetCount(v));
            Assert.AreEqual("b", MyLibrary.CollectionUserExample.GetObjectAtIndex(v, 1));
        }

        [TestMethod]
        public void MapUseTest()
        {
            var m = new MyLibrary.StringToIntMap();
            m["1"] = 1;
            m["2"] = 2;
            m["3"] = 3;

            Assert.AreEqual(3, m.Count);
            Assert.AreEqual(3, m["3"]);
        }
    }
}
