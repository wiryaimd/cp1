import java.util.HashMap;
import java.util.Map;
import java.util.function.BiConsumer;
import java.util.function.Consumer;

public class cekj1{

    public static void main(String[] args) {
        

        Map<String, Boolean> map = new HashMap<>();
        map.put("cek", true);
        map.put("cek2", true);
        map.put("cek3", true);
        System.out.println(map.get("cek1"));
        System.out.println(map.get("cek"));
        // map.forEach(new BiConsumer<String,Boolean>() {
        //     @Override
        //     public void accept(String t, Boolean u) {
        //         System.out.println(t + " asd " + u);
        //     }
        // });

    }

}