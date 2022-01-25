public class ValidPassword {
    public static void main(String[] args) {
        String pass = "g1tpAss0rd";
        int len = pass.length(), digits = 0, symbols = 0;
        for(int i=0; i<len; i++) {
            if(Character.isDigit(pass.charAt(i))) {
                digits++;
            }
            if(!Character.isAlphabetic(pass.charAt(i)) && !Character.isDigit(pass.charAt(i))) {
                symbols++;
            }
        }
        if(len >= 10 && digits >=2 && symbols == 0) {
            System.out.println("Valid Password!");
        } else {
            System.out.println("Invalid Password!");
        }
    }
}
