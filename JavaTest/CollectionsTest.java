import MyLibrary.*;
import org.junit.*;

import static org.junit.Assert.*;

public class CollectionsTest {
    @Test
    public void VectorPassingTest() {
        StringVector v = new StringVector();
        v.add("a");
        v.add("b");
        v.add("c");

        assertEquals(3, CollectionUserExample.GetCount(v));
        assertEquals("b", CollectionUserExample.GetObjectAtIndex(v, 1));
    }

    @Test
    public void MapUseTest() {
        StringToIntMap m = new StringToIntMap();
        m.set("1", 1);
        m.set("2", 2);
        m.set("3", 3);

        assertEquals(3, m.size());
        assertEquals(3, m.get("3"));
    }
}
