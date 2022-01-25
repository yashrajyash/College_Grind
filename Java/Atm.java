public class Atm {
    private int wd;
    private double total;

    public Atm(int x, double y) {
        wd = x;
        total = y;
    }

    public void displaybalance() {
        if (wd % 5 != 0 || wd + 0.5 > total)
            System.out.println(String.format("%.2f", total));
        else {
            total -= wd;
            total -= 0.50;
            System.out.println(String.format("%.2f", total));
        }
    }

    public static void main(String[] args) {
        Atm account = new Atm(42, 120.00);
        account.displaybalance();
    }
}
