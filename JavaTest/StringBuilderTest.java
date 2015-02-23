import MyLibrary.*;
import org.junit.*;

import static org.junit.Assert.*;

public class StringBuilderTest extends TestBase {
    @Test
    public void AsciiTest() {
        String asciiValue = "Some value";
        StringBuilderExample sb = new StringBuilderExample(asciiValue);
        assertEquals(asciiValue, sb.CreateString());
    }

    @Test
    public void UnicodeTest() {
        String unicodeValue = "吝吞吟吠吡";
        StringBuilderExample sb = new StringBuilderExample(unicodeValue);
        assertEquals(unicodeValue, sb.CreateString());
    }
}
