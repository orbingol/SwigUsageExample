import MyLibrary.*;
import org.junit.*;

import java.io.IOException;

import static org.junit.Assert.*;

public class ExceptionTest extends TestBase {
    @Test(expected=java.io.IOException.class)
    public void CatchExceptionTest() throws java.io.IOException {
        FileIOExample f = new FileIOExample();
        f.OpenFile("This file does not exist"); // We expect this to throw java.io.IOException
    }
}
