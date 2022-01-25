public class Payment {

    // Attributes
    private int bill_id;
    private String customer_name;
    private double bill_amount;
    private String payment_method;

    // Constructor
    public Payment() {
        bill_id = 0;
        customer_name = null;
        bill_amount = 0.0;
        payment_method = null;
    }

    // Setter Methods
    public void set_bill_id(int bill_id) {
        this.bill_id = bill_id;
    }

    public void set_customer_name(String customer_name) {
        this.customer_name = customer_name;
    }

    public void set_bill_amount(double bill_amount) {
        this.bill_amount = bill_amount;
    }

    public void set_payment_method(String payment_method) {
        this.payment_method = payment_method;
    }

    // Getter Methods
    public int get_bill_id() {
        return bill_id;
    }

    public String get_customer_name() {
        return customer_name;
    }

    public double get_bill_amount() {
        return bill_amount;
    }

    public String get_payment_method() {
        return payment_method;
    }

    // Methods
    public boolean validate_bill(double bill_value) {
        if(bill_value > 0) {
            set_bill_amount(bill_value);
            return true;
        }
        return false;
    }

    public boolean validate_id(int id) {
        return bill_id == id;
    }

    public boolean pay_bill(int id, double bill_value) {
        if(validate_id(id) && validate_bill(bill_value)) {
            set_payment_method("Cash Payment");
            return true;
        }
        return false;
    }

    public boolean pay_bill(int id, double bill_value, long card_number) {
        if(validate_id(id)&& validate_bill(bill_value)) {
            set_payment_method("Card Payment");
            return true;
        }
        return false;
    }

    public boolean pay_bill(int id, double bill_value, long account_no, String bank_name) {
        if(validate_id(id)&& validate_bill(bill_value)) {
            set_payment_method("Net Banking");
            return true;
        }
        return false;
    }

    public boolean pay_bill(int id, double bill_value, String upi_id) {
        if(validate_id(id)&& validate_bill(bill_value)) {
            set_payment_method("UPI");
            return true;
        }
        return false;
    }

    public static void display(Payment obj) {
        System.out.println("Customer Name : " +obj.get_customer_name());
        System.out.println("Bill ID : " +obj.get_bill_id());
        System.out.println("Bill Amount : " +obj.get_bill_amount() +" $");
        System.out.println("Payment Method : " +obj.get_payment_method());
    }

    // Main
    public static void main(String[] args) {
        Payment p1 = new Payment();
        p1.set_bill_id(123);
        p1.set_customer_name("Yash");

        // Cash Payment
        // p1.pay_bill(123, 500);

        // Card Payment
        // p1.pay_bill(123, 750, 987654321);

        // Net Banking
        // p1.pay_bill(123, 900, 12345678, "ICICI");

        // UPI
        p1.pay_bill(123, 1999, "yash_raj_yash");
        display(p1);
    }    
}
