public class CountVowels {
    public static void main(String[] args) {
        int hash[] = new int[26];
        String vowels = "aeiou";
        String word = "Meghnad Saha Institute of technology".toLowerCase();
        for(int i=0; i<word.length(); i++) {
            if(word.charAt(i) == ' ') {
                continue;
            }
            hash[word.charAt(i)-'a']++;
        }
        int count = 0;
        for(int i=0; i<vowels.length(); i++) {
            if(hash[vowels.charAt(i)-'a'] > 0) {
                count += hash[vowels.charAt(i)-'a'];
            }
        }
        System.out.println("Number of vowels in the string : " + count);
    }
}
