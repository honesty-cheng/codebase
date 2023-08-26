import java.util.Scanner;
/**
 * 点菜，对于每个菜、每个人都有个喜爱度，第一个人选三个总喜爱度最高的，后续每人选一个自己最喜爱的（点菜不重复）
 */

// 2 5
// 1 2 3 4 5
// 1 2 3 4 5

// 2 人数 5 菜数
// 先选 3+4+5
// 第二个人选 2
// output: (3+4+5+2）+ (3+4+5+2）

public class cstop2 {
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
