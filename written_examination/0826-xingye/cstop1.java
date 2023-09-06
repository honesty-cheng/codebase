import java.util.Scanner;

// so easy
// have done

/**
 * the next one
 */


// 注意类名必须为 Main, 不要有任何 package xxx 信息
public class cstop1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        
        // 注意 hasNext 和 hasNextLine 的区别
        while (in.hasNextInt()) { // 注意 while 处理多个 case
            int a = in.nextInt();
            int b = in.nextInt();
            System.out.println(a + b);
        }
    }
}