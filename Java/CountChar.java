// 1. Java Program to count the total number of characters in a string

public class CountChar {
    public static void main(String[] args) {
        String str = "Meghnad Saha Institute of Technology";
        int count = 0;
        char[] letters = str.toCharArray();
        for (char ch : letters) {
            if (ch != ' ') {
                count++;
            }
        }
        System.out.println(count);
    }
}
