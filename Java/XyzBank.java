import java.util.Random;

class XyzBank {

	public static void main(String[] args) {
		Bank savingAccount = new Bank();
		savingAccount.createAccount("Yash");
		savingAccount.deposite(savingAccount.getAccountNo(), 5000.0);
		savingAccount.withdraw(savingAccount.getAccountNo(), 3000.0);
		savingAccount.display();
		
		// Current Account
		CurrentAccount currAccount = new CurrentAccount();
		currAccount.createAccount("Ankit");
		currAccount.withdraw(currAccount.getAccountNo(), 19000);
		currAccount.display();
	}

}

class Bank {
	
	private String name;
	private long accountNo;
	private double amount;
	
	public void createAccount(String name) {
		System.out.println("-------------------------------------");
		this.name = name;
		Random rnd = new Random();
		accountNo = rnd.nextInt(999999);
		System.out.println("Account has created : " + this.accountNo);
		System.out.println("-------------------------------------\n");
	}
	
	public void deposite(long accountNo, double amount) {
		System.out.println("-------------------------------------");
		System.out.println("Account Number : " + accountNo);
		System.out.println("Before deposite "+ this.amount);
		this.amount += amount;
		System.out.println("After deposite "+ this.amount);
		System.out.println("-------------------------------------\n");
	}
	
	public void withdraw(long accountNo, double amount) {
		System.out.println("-------------------------------------");
		if(this.amount >= amount) {
			System.out.println("Account Number : " + accountNo);
			System.out.println("Before withdraw : " + this.amount);
			deductAmount(amount);
			System.out.println("After withdraw : " + this.amount);
		} else {
			System.out.println("Transaction failed (insufficient balance)");
		}
		System.out.println("-------------------------------------");
	}
	
	public void display() {
		System.out.println("\n-------------------------------------");
		System.out.println("Account Number : " + accountNo);
		System.out.println("Name : " + name);
		System.out.println("Balance : " + amount);
		System.out.println("-------------------------------------\n");
	}
	
	public long getAccountNo() {
		return accountNo;
	}
	
	public double getAmount() {
		return amount;
	}
	
	public void deductAmount(double amount) {
		this.amount -= amount;
	}
	
	public void addAmount(double amount) {
		this.amount += amount;
	}
}

class CurrentAccount extends Bank {
	private double limit = 20000.0;
	
	@Override
	public void deposite(long accountNo, double amount) {
		System.out.println("-------------------------------------");
		if(limit == 20000.0) {
			addAmount(amount);
		} else {
			limit += amount;
		}
		System.out.println("-------------------------------------\n");
	}
	
	@Override
	public void withdraw(long accountNo, double amount) {
		System.out.println("-------------------------------------");
		if(getAmount() >= amount) {
			System.out.println("Account Number : " + accountNo);
			System.out.println("Before withdraw : " + getAmount());
			deductAmount(amount);
			System.out.println("After withdraw : " + getAmount());
		} else if(amount >= limit) {
			System.out.println("Account Number : " + accountNo);
			System.out.println("Before withdraw : " + getAmount());
			limit -= amount;
			deductAmount(amount);
			System.out.println("After withdraw : " + getAmount());
		} else {
			System.out.println("Transaction failed (insufficient balance)");
		}
		System.out.println("-------------------------------------");
	}
	
	@Override
	public void display() {
		System.out.println("Current Account : \n");
		super.display();
	}
	
}
