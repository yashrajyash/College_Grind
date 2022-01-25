class Member {

    protected String name;
    protected int age;
    protected long phoneNo;
    protected String address;
    protected double salary;

    protected void printBasicInfo() {
        System.out.println("\nName : " + name);
        System.out.println("Age : " + age);
        System.out.println("Phone no.: " + phoneNo);
        System.out.println("Address : " + address);
    }

    protected void printSalary() {
        System.out.println("Salary : " + salary);
    }
}

class Employee extends Member {
    protected String specialization;
}

class Manager extends Member {
    protected String department;
}

class MemberEmployeeManager {
    public static void main(String[] args) {
        // Employee Object
        Employee employee = new Employee();
        employee.name = "Jesse Pinkman";
        employee.age = 26;
        employee.address = "Albuquerque";
        employee.phoneNo = 6668265;
        employee.salary = 2000;
        employee.specialization = "Jr. Chemist";

        // Manager Object
        Manager manager = new Manager();
        manager.name = "Walter White";
        manager.age = 50;
        manager.address = "Albuquerque";
        manager.phoneNo = 476487;
        manager.salary = 8000;
        manager.department = "Sales";

        // Employee
        System.out.print("\nEmployee \n");
        employee.printBasicInfo();
        employee.printSalary();

        System.out.println("-----------------------------");

        // Manager
        System.out.println("\nManager ");
        manager.printBasicInfo();
        manager.printSalary();
    }
}