import MyLibrary.*;
import org.junit.*;

import static org.junit.Assert.*;

public class CallbackTest extends TestBase {

    class MyCallback extends CallbackExample
    {
        public int ImplementMe()
        {
            return 54321;
        }
    }

    @Test
    public void OverrideTest() {
        MyCallback m = new MyCallback();
        assertEquals(54321, m.GetCallbackResult());
    }
}
