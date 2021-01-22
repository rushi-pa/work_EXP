package functionalStudent;
import java.text.DecimalFormat;
public class Student {
	private String firstName;
	private String lastName;
	private double grade;
	private String department;

	public Student(String fName, String lName, double grade, String depart) {
		this.firstName = fName;
		this.lastName = lName;
		this.grade = grade;
		this.department = depart;
	}
	public String getFirstName() {
		return this.firstName;
	}
	public String getLastName() {
		return this.lastName;
	}	
	public double getGrade() {
		return this.grade;
	}
	public String getDepartment() {
		return this.department;
	}
	public String getName() {
		return this.firstName + " " + this.lastName;
	}
	public void setFirstName(String fName) {
		this.firstName = fName;
	}
	public void setLastName(String lName) {
		this.lastName = lName;
	}
	public void setGrade(double grade) {
		this.grade = grade;
	}
	public void setDepartment(String depart) {
		this.department = depart;
	}
	@Override
	public String toString() {
		String rstring= getFirstName() + "        " + getLastName() + "        " + new DecimalFormat("0.00").format(getGrade()) + "        " + getDepartment();
				return rstring;
	}
	public boolean equals(Student obj) {
		Boolean istrue =this.getFirstName() == obj.getFirstName() && this.getLastName() == obj.getLastName() && this.getGrade() == obj.getGrade() && this.getDepartment() == obj.getDepartment();
			return istrue;
	}
}