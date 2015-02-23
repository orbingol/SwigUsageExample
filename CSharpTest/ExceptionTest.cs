using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.IO;

namespace CSharpTest
{
    [TestClass]
    public class ExceptionTest
    {
        [TestMethod]
        [ExpectedException(typeof(IOException), "A non-existent file was inappropriately allowed.")]
        public void CatchExceptionTest()
        {
            var f = new MyLibrary.FileIOExample();
            f.OpenFile("This file does not exist"); // We expect this to throw IOException
        }
    }
}
