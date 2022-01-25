import java.util.ArrayList;
import java.util.Arrays;

class AlphaNumericSort {

    private String str;

    public AlphaNumericSort(String sentence) {
        str = sentence;
    }

    public void showSortedResult() {
        str = str.toLowerCase();
        String[] words = str.split(" ");
        Arrays.sort(words);
        ArrayList<Integer> nums = new ArrayList<Integer>();
        ArrayList<String> names = new ArrayList<String>();
        for (int i = 0; i < words.length; i++) {
            try {
                int num = Integer.parseInt(words[i]);
                nums.add(num);
            } catch (NumberFormatException e) {
                names.add(words[i]);
            }
        }
        int p = 0, q = 0;
        for (int i = 0; i < words.length; i++) {
            if (p < names.size()) {
                System.out.print(names.get(p++) + " ");
            }
            if (q < nums.size()) {
                System.out.print(nums.get(q++) + " ");
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        AlphaNumericSort sentence1 = new AlphaNumericSort("Sagar 35 sanjay 12 ganesH 53 ramesh 19");
        sentence1.showSortedResult();
        // ganesh 12 ramesh 19 sagar 35 sanjay 53

        AlphaNumericSort sentence2 = new AlphaNumericSort("Ganesh 59 suresh 19 rakesh 26 laliT 96");
        sentence2.showSortedResult();
        // ganesh 19 lalit 26 rakesh 59 suresh 96
    }
}