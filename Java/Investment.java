import java.util.Scanner;

public class Investment {

    private static double calculateCompoundInterestAmount(double principle, double rate, double time) {
        double CI = principle *
                    (Math.pow((1 + rate / 1200), time*12));

        return CI;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Input the investment amount: ");
        double principle = sc.nextDouble();

        System.out.print("Input the rate of interest: ");
        double rate = sc.nextDouble();

        System.out.print("Input number of years: ");
        double time = sc.nextDouble();

        sc.close();

        System.out.println("\nYears\t\tFuture Value");
        for (int i = 1; i <= time; i++) {
            System.out.printf("%d\t\t%.2f\n", i, calculateCompoundInterestAmount(principle, rate, i));
        }
    }
}
