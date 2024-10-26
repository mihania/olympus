# 5

Бесконечно количество решений
Вот первые решения
105263157894736842
105263157894736842105263157894736842
105263157894736842105263157894736842105263157894736842

Программа которая находит все решения
```
// "static void main" must be defined in a public class.
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        int d = 2;
        int m = 0;
        String cur = "2";
        String next;
        BigInteger b2 = new BigInteger("2");
        
        while (true) {
            BigInteger bCur = new BigInteger(cur);
            BigInteger bNext = new BigInteger(getNext(cur));
            if (bCur.multiply(b2).equals(bNext)) {
                System.out.printf("%s\n", bCur);
                // break;
            }
            
            int newM = (d * 2 + m) / 10;
            d = (d * 2 + m) % 10;
            m = newM;
            cur = d + cur;
        }                
    }
    
    private static String getNext(String cur) {
        return "2" + cur.substring(0, cur.length() - 1);
    }
}
```
