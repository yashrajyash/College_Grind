public class TfsProblem {
    private int s; // Starting position
    private int n; // Ending position

    public TfsProblem() {
        s = 1;
        n = 100;
    }

    public TfsProblem(int x) {
        s = 1;
        n = x;
    }

    public TfsProblem(int x, int y) {
        s = x;
        n = y;
    }

    public void displaySeries() {
        for (int i = s, j = 1; i <= n; i++, j++) {
            if (i % 3 == 0) {
                System.out.print("T");
            } 
            if (i % 5 == 0) {
                System.out.print("F");
            }
            if (i % 7 == 0) {
                System.out.print("S");
            }
            if(i%3 != 0 && i%5 != 0 && i%7 != 0) {
                System.out.print(i);
            }
            if (j % 10 == 0) {
                System.out.println();
            }
            if (i != n && j % 10 != 0) {
                System.out.print(", ");
            }
        }
    }

    // Main

    public static void main(String[] args) {
        // TfsProblem problem1 = new TfsProblem();
        // problem1.displaySeries();

        // TfsProblem problem2 = new TfsProblem(20);
        // problem2.displaySeries();

        TfsProblem problem3 = new TfsProblem(92, 120);
        problem3.displaySeries();
    }
}
