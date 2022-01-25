/* 3. Java Program to replace lower-case
      characters with upper-case and vice-
      versa */

public class UpperLower {
    public static void main(String[] args) {
        String str = "Meghnad Saha Institute of Technology";
        String str1 = "";
        for (int i = 0; i < str.length(); i++) {
            if (Character.isUpperCase(str.charAt(i))) {
                str1 += str.substring(i, i + 1).toLowerCase();
            } else {
                str1 += str.substring(i, i + 1).toUpperCase();
            }
        }
        System.out.println(str1);
    }
}
