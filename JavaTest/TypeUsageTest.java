import MyLibrary.*;
import org.junit.*;

import static org.junit.Assert.*;
import static org.junit.Assert.assertEquals;

public class TypeUsageTest extends TestBase {
    @Test
    public void ObjectsTest() {
        TypeUsageExample t = new TypeUsageExample();
        t.PassByValue("PassByValue");
        assertEquals("PassByValue", t.ReturnByValue());
        t.PassByConstRef("PassByConstRef");
        assertEquals("PassByConstRef", t.ReturnByConstRef());
    }
}
