import java.util.*;
/**
 * 计算黑色面积，半径 r，步骤数 n
 * 步骤 1 画一个半径 r 的黑圆，填充左上部四分之一为白色
 * 步骤 2 黑色部分内画一个半径 r/2 的白圆，填充右下角 1/4 为黑色
 * 步骤 3 白色部分内画一个半径 r/4 的黑圆，填充左上角 1/4 为白色
 *   
 */
//  例题
 // 1 1
 // 2.3561945

 // 2 4
 // 7.5103699
//have done


public class cstop4 {
    public static void main(String[] args) {
        //7.510369937488099
        System.out.println(calculateBlackArea(2.0, 4));
        //2.356194490192345
        System.out.println(calculateBlackArea(1.0, 1));
        
    }
    public static double calculateBlackArea(double radius, int steps) {
        double blackArea = 0;
        double currentRadius = radius;
        boolean isBlack = true;

        for (int i = 1; i <= steps; i++) {
            double area = Math.PI * currentRadius * currentRadius;

            if (isBlack) {
                blackArea += 3.0/4.0*area;
                isBlack = false;
            } else {
                blackArea -= 3.0/4.0*area;
                isBlack = true;
            }

            currentRadius = currentRadius / 2;
        }

        return blackArea;
    }
}
