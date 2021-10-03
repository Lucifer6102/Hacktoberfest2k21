import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

class sam2
{
    protected void finalize()
    {
        System.out.println("Coding!!");
    }
    public static void main(String[] args)
    {
        sam2 hacker=new sam2();
        hacker=null;
        System.gc();
		//what does the above command do?
    }
}
    