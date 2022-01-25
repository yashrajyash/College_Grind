// 4. Java Program to determine whether two strings are the anagram

import java.util.Arrays;

public class Anagrams {
    public static void main(String[] args) {
        String str1 = "heart";
        String str2 = "earth";
        char[] letters1 = str1.toLowerCase().toCharArray();
        char[] letters2 = str2.toLowerCase().toCharArray();
        Arrays.sort(letters1);
        Arrays.sort(letters2);
        if(Arrays.equals(letters1, letters2)) {
            System.out.println("Anagram");
        } else {
            System.out.println("Not an Anagram");
        }
    }
}
