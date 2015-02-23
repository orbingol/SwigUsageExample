import MyLibrary.*;
import org.junit.*;

import static org.junit.Assert.*;

public class PrimitiveTypesTest extends TestBase {
    @Test
    public void RoundTripTest() {
        assertEquals((byte)123, PrimitiveTypesExample.RoundTrip((byte)123));
        assertEquals((short)12345, PrimitiveTypesExample.RoundTrip((short)12345));
        assertEquals((int)12345678, PrimitiveTypesExample.RoundTrip((int)12345678));
        assertEquals((long)123456789101112L, PrimitiveTypesExample.RoundTrip((long)123456789101112L));
        assertEquals((float)1.23, PrimitiveTypesExample.RoundTrip((float)1.23), (float)0.0);
        assertEquals((double)1.23456789, PrimitiveTypesExample.RoundTrip((double)1.23456789), (double)0.0);
    }
}
