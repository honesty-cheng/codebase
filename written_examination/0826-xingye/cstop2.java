import java.util.Scanner;
import java.util.*;

// have done

// 注意类名必须为 Main, 不要有任何 package xxx 信息
public class cstop2 {
    public static void main(String[] args) {
        int ans = 0;
        Scanner in = new Scanner(System.in);
        // 注意 hasNext 和 hasNextLine 的区别
        int a = in.nextInt();
        int b = in.nextInt();
        int [][]num = new int[a][b];
        int []sumLike = new int [b];
        int []index = new int[b];
        int temp;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                temp = in.nextInt();
                sumLike[j] += temp;
                num[i][j] = temp;
            }
        }
        int []top3 = findThreeBiggest(sumLike);

        System.out.println(top3[0]);
        System.out.println(top3[1]);
        System.out.println(top3[2]);
        ans += sumLike[top3[0]];
        System.out.println(ans);
        ans += sumLike[top3[1]];
        System.out.println(ans);
        ans += sumLike[top3[2]];
        System.out.println(ans);

        index[top3[0]] = 1;
        index[top3[1]] = 1;
        index[top3[2]] = 1;
        for (int i = 1; i < a; i++) {
            int soloi = findBig(num[i], index);
            ans += sumLike[soloi];
            System.out.println(ans);
        }
        System.out.println(ans);
    }

    static int findBig(int[] num, int []index) {
        int ind = findBiggest(num);
        while (index[ind] == 1) {
            num[ind] = 0;
            ind = findBiggest(num);
        }
        index[ind] = 1;
        return ind;
    }
    static int[] findThreeBiggest(int[] num) {
        int[] index = new int[3];
        int[] temp = new int[num.length];
        for (int i = 0; i < num.length; i++) {
            temp[i] = num[i];
        }
        for (int i = 0; i < 3; i++) {
            index[i] = findBiggest(temp);
            temp[index[i]] = 0;
        }
        return index;
    }
    static int findBiggest(int[] num) {
        int index = 0;
        int max = num[0];
        for (int i = 0; i < num.length; i++) {
            if (num[i] > max) {
                max = num[i];
                index = i;
            }
        }
        return index;
    }
}