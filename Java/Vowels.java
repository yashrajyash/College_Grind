// 2. Java Program to count the total number of vowels and consonants in a string

public class Vowels {

    private String str;
    private int vowelsCount;

    public Vowels(String word) {
        str = word.toLowerCase();
        vowelsCount = 0;
    }

    int countVowels() {
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelsCount++;
            }
        }
        return vowelsCount;
    }

    int countConsonants() {
        int count = str.length() - vowelsCount;
        return count;
    }

    public static void main(String[] args) {
        Vowels str = new Vowels("aeihmlk");
        System.out.println(str.countVowels());
        System.out.println(str.countConsonants());
    }
}
