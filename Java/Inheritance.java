class Person {
    // attributes
    private int id;
    private String name;

    // constructor
    public Person() {
        System.out.println("Person constructor called.");
    }

    // setters
    public void set_id(int id) {
        this.id = id;
    }

    public void set_name(String name) {
        this.name = name;
    }

    // getters
    public int get_id() {
        return id;
    }

    public String get_name() {
        return name;
    }
}

class Student extends Person {
    // attributes
    private int roll;
    private int _class;
    private String department;
    private String section;

    // constructor
    public Student() {
        System.out.println("Student constructor called.");
    }

    // setters
    public void set_student_roll(int roll) {
        this.roll = roll;
    }

    public void set_student_class(int _class) {
        this._class = _class;
    }

    public void set_student_department(String department) {
        this.department = department;
    }

    public void set_student_section(String section) {
        this.section = section;
    }

    // getters
    public int get_student_roll() {
        return roll;
    }

    public int get_student_class() {
        return _class;
    }

    public String get_student_department() {
        return department;
    }

    public String get_student_section() {
        return section;
    }
}

class Employee extends Person {
    // attributes
    private String department;
    private double salary;

    // constructor
    public Employee() {
        System.out.println("Employee constructor called.");
    }

    // setters
    public void set_emp_department(String department) {
        this.department = department;
    }

    public void set_emp_salary(double salary) {
        this.salary = salary;
    }

    // getters
    public String get_emp_department() {
        return department;
    }

    public double get_emp_salary() {
        return salary;
    }

    // properties
    public void display() {
        System.out.println();
        System.out.println("Name : " + get_name());
        System.out.println("Id : " + get_id());
        System.out.println("Department : " + get_emp_department());
        System.out.println("Salary : " + get_emp_salary());
    }
}

class Teacher extends Employee {
    // attributes
    private String subject;

    // constructor
    public Teacher() {
        System.out.println("Teacher constructor called.");
    }

    // setters
    public void set_teacher_subject(String subject) {
        this.subject = subject;
    }

    // getters
    public String get_teacher_subject() {
        return subject;
    }

    // properties
    @Override
    public void display() {
        // calling parent display()
        super.display();
        System.out.println("Subject : " + get_teacher_subject());
    }
}

class Inheritance {
    public static void main(String[] args) {
        // Student data
        String[] name = { "Yash", "Ankit", "Aman", "Anish", "Sonu" };
        String[] department = { "CSE", "ECE", "CE", "IT", "CST" };
        String[] section = { "A", "B", "C", "D", "E" };
        int[] roll = { 17, 32, 36, 62, 25 };
        int[] id = { 123, 124, 126, 642, 422 };
        int[] class_ = { 12, 11, 10, 9, 8 };
        Student student[] = new Student[5];

        // initializing students data to student objects
        for (int i = 0; i < 5; i++) {
            student[i] = new Student();
            student[i].set_name(name[i]);
            student[i].set_id(id[i]);
            student[i].set_student_class(class_[i]);
            student[i].set_student_department(department[i]);
            student[i].set_student_roll(roll[i]);
            student[i].set_student_section(section[i]);
        }

        // initializing teacher object
        Teacher teacher = new Teacher();
        teacher.set_name("Mr. Google");
        teacher.set_id(12830);
        teacher.set_emp_department("CSE");
        teacher.set_emp_salary(82800);
        teacher.set_teacher_subject("Java");

        // Calling superclass display() from class teacher
        teacher.display();
    }
}