class Flower {

    private String flower_name;
    private int price_per_kg;
    private int stock_available;
    private int stock_alert_level;

    public Flower() {
        flower_name = null;
        price_per_kg = 0;
        stock_available = 0;
        stock_alert_level = 0;
    }

    public void set_flower_name(String flower_name) {
        this.flower_name = flower_name;
    }

    public void set_price_per_kg(int price_per_kg) {
        this.price_per_kg = price_per_kg;
    }

    public void set_stock_available(int stock_available) {
        this.stock_available = stock_available;
    }

    public void set_stock_alert_level(int stock_alert_level) {
        this.stock_alert_level = stock_alert_level;
    }

    public String get_flower_name() {
        return this.flower_name;
    }

    public int get_price_per_kg() {
        return this.price_per_kg*this.stock_available;
    }

    public int get_stock_available() {
        return this.stock_available;
    }

    public int get_stock_alert_level() {
        return this.stock_alert_level;
    }

    public boolean validate_flower(String flower_name) {
        boolean flag = false;
        if(flower_name.equalsIgnoreCase(this.flower_name)) {
            flag = true;
        }
        return flag;
    }

    public boolean validate_stock(int quantity) {
        if(this.stock_available > this.stock_alert_level) {
            return true;
        }
        return false;
    }

    public void sell_flower(String flower_name, int quantity) {
        if(validate_flower(flower_name) && validate_stock(quantity)) {

            System.out.println("Price: "+ price_per_kg*quantity);
            this.stock_available = this.stock_available - quantity;
            if(check_level()) {
                System.out.println("Remaining stock: "+this.stock_available);
            } else {
                System.out.println("Stock unavilable");
            }

        } else {
            System.err.println("Stock unavailable");
        }
    }

    public boolean check_level() {
        if(stock_available >= stock_alert_level) {
            return true;
        }
        return false;
    }
    public static void main(String[] args) {
        
        Flower flower1 = new Flower();

        flower1.set_flower_name("Rose");
        flower1.set_price_per_kg(10);
        flower1.set_stock_available(25);
        flower1.set_stock_alert_level(2);
        
        flower1.sell_flower("Rose", 20);
        flower1.sell_flower("Rose", 3);
        flower1.sell_flower("Rose", 3);

    }
}