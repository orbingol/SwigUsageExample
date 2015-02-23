import MyLibrary.*;
import org.junit.*;

import static org.junit.Assert.*;

public class MemberVariablesTest extends TestBase {
    @Test
    public void MembersTest() {
        MemberVariablesExample m = new MemberVariablesExample();
        m.setBooleanMember(true);
        assertEquals(true, m.getBooleanMember());
        assertEquals(true, m.QueryBooleanMember());
        m.setIntegerMember(1234);
        assertEquals(1234, m.getIntegerMember());
        assertEquals(1234, m.QueryIntegerMember());
        m.setFloatingPointMember(1.23);
        assertEquals(1.23, m.getFloatingPointMember(), 0.0);
        assertEquals(1.23, m.QueryFloatingPointMember(), 0.0);
        m.setStringMember("Some string");
        assertEquals("Some string", m.getStringMember());
        assertEquals("Some string", m.QueryStringMember());
        SomeClass s = new SomeClass();
        s.setSomeString("Some class string");
        m.setClassMember(s);
        assertEquals("Some class string", m.getClassMember().getSomeString());
        assertEquals("Some class string", m.QueryClassMember().QuerySomeString());
        SomeClass classMember = m.getClassMember();
        classMember.setSomeString("Some other string");
        assertEquals("Some other string", m.getClassMember().getSomeString());
    }
}
