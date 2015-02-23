import MyLibrary.*;
import org.junit.*;

import static org.junit.Assert.*;

public class EnumerationTest extends TestBase {
    @Test
    public void EnumValuesTest() {
        EnumerationTypeExample e = EnumerationTypeExample.Label2;
        assertEquals(2, EnumerationUserExample.ConvertToInteger(e));
        assertEquals(e, EnumerationUserExample.ConvertToEnumeration(2));
    }
}
