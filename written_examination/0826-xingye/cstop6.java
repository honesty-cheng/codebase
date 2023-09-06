import java.util.*;
// 从 0 开始，建造尽量最少的站点满足所有约束，满足的话输出每个站点到 0 的距离*2 的和的最小值，不行则输出-1

// eg
// 3 3   可以建设站点数量 和 约束数量
// 1 3 5 三个站点位置
// 1 3 第一个约束 [1, 3] 位置在 1 3 之间
// 2 4 第二个约束 [2, 4] 位置在 2 4 之间
// 4 6 第三个约束 [4, 6] 位置在 4 6 之间

// output：16
// 在 3 5 建造站点，3*2 + 5*2 = 16


// just trying
public class cstop6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // 站点数量
        int m = sc.nextInt(); // 约束数量
        int[] a = new int[n]; // 站点位置
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[][] b = new int[m][2]; // 约束
        for (int i = 0; i < m; i++) {
            b[i][0] = sc.nextInt();
            b[i][1] = sc.nextInt();
        }
        int[] c = new int[n]; // 站点到 0 的距离
        for (int i = 0; i < n; i++) {
            c[i] = a[i];
        }
        Arrays.sort(c); // 排序
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int min = Integer.MAX_VALUE;
            for (int j = 0; j < m; j++) {
                if (b[j][0] <= c[i] && c[i] <= b[j][1]) {
                    min = Math.min(min, b[j][1] - b[j][0]);
                }
            }
            if (min == Integer.MAX_VALUE) {
                System.out.println(-1);
                return;
            }
            ans += min;
        }
        System.out.println(ans * 2);
    }
    //不太对。。
    public static int calculateMinimumDistanceSum(int n, int m, int[] positions, int[][] restrict) {
        int minDistanceSum = Integer.MAX_VALUE;
        int len = restrict[restrict.length-1][1];
        int[] selectedPositions = new int[len];

        // 遍历所有站点子集，逐一判断是否满足约束条件
        for (int i = 0; i < (1 << n); i++) {
            int numSelected = Integer.bitCount(i);
            if (numSelected > n) {
                continue; // 选中站点数量超过可建立站点数量的情况，忽略
            }

            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    positions[j] = 1; // 将选中的站点标记为1
                } else {
                    positions[j] = 0;
                }
            }

            boolean satisfiesConstraints = true;
            // 检查约束条件是否满足
            for (int j = 0; j < m; j++) {
                int start = restrict[j][0];
                int end = restrict[j][1];
                if (selectedPositions[start] != 1 && selectedPositions[end] != 1) {
                    satisfiesConstraints = false;
                    break;
                }
            }

            if (satisfiesConstraints) {
                int distanceSum = 0;
                for (int j = 0; j < n; j++) {
                    if (selectedPositions[j] == 1) {
                        int distance = Math.abs(positions[j]);
                        distanceSum += distance * 2;
                    }
                }
                minDistanceSum = Math.min(minDistanceSum, distanceSum);
            }
        }
        // 如果找不到满足约束的方案，返回-1
        if (minDistanceSum == Integer.MAX_VALUE) {
            return -1;
        } else {
            return minDistanceSum;
        }
    }
    
}
