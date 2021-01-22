import java.util.ArrayList;

public class Student implements java.io.Serializable {
    private int stdID;
    private String firstName;
    private String lastName;
    private ArrayList<String> courses;

    public Student() {
        courses = new ArrayList<String>();
    }

    public String getFullName() {
        return firstName + ' ' + lastName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public int getStdID() {
        return stdID;
    }

    public void setStdID(int stdID) throws Exception {
        if(stdID > 0) {
            this.stdID = stdID;
        }
        else{
            throw new Exception("Invalid student ID!");
        }
    }

    public ArrayList<String> getCourses() {
        return courses;
    }

    public void setCourses(String courses) {
        this.courses.add(courses);
    }
}
