import java.util.Scanner;
import java.util.*;
import java.lang.String;

// 注意类名必须为 Main, 不要有任何 package xxx 信息
public class Main {
    public static void main(String[] args) {
        class User {
            String name;
            String num;
            String safecode;
            int trynum;

            public User() {
            }
            public User(String name, String num, String safecode) {
                this.name = name;
                this.num = num;
                this.safecode = safecode;
                this.trynum = 0;
            }
        }
        HashSet<User> set = new HashSet<>();
        Scanner in = new Scanner(System.in);
        String sn = in.nextLine();
        int n = Integer.parseInt(sn);
        for (int i = 0; i < n; i++) {
            String line = in.nextLine();
            String []s = line.split(" ");
            if (s[0].equals("1")) {
                int isHave = 0;
                for (User user : set) {
                    if (user.name.equals(s[1]) || user.num.equals(s[2])) {
                        System.out.println("register failed");
                        isHave = 1;
                        break;
                    }
                }
                if (isHave == 0) {
                    set.add(new User(s[1], s[2], s[3]));
                    System.out.println("register accomplished");
                }

            } else if (s[0].equals("2")) {
                int isHave = 0;
                for (User user : set) {
                    if (user.name.equals(s[1])) {
                        String s1 = s[2].substring(0, 4);
                        String s2 = s[2].substring(4, 7);
                        String scmp1 = user.num.substring(12, 16);
                        if ( s1.    equals(scmp1) && s2.equals(user.safecode)) {
                            if (user.trynum >= 3) {
                                System.out.println("card locked");
                            } else {
                                System.out.println("passed");
                                user.trynum = 0;
                            }
                        } else {
                            System.out.println("unsanctioned");
                            user.trynum ++;
                        }
                        isHave = 1;
                        break;
                    }
                }
                if (isHave == 0) {
                    System.out.println("unexisted name");
                }

            } else if (s[0].equals("3")) {
                int isHave = 0;
                for (User user : set) {
                    if (user.name.equals(s[1])) {
                        isHave = 1;
                        System.out.println("cancellation succeed");
                        set.remove(user);
                        break;
                    }
                }
                if (isHave == 0) {
                    System.out.println("unexisted name");
                }
            }
        }
    }
}