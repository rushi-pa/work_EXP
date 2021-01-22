import javax.swing.*;
import java.awt.*;
import java.io.*;

public class ReadStdInfo {
    public static void readStdInfo(JPanel pane){

        pane.removeAll();

        GridBagConstraints gbc = new GridBagConstraints();
        JTextArea txtArea = new JTextArea();
        boolean read = true;
        int stdCounter = 1;


        JButton back = new JButton("Back");
        back.setBounds(300, 300, 100, 50);

        try {
            FileInputStream fis = new FileInputStream("output.txt");
            ObjectInputStream ois = new ObjectInputStream(fis);

            while(read) {
                Student std = (Student) ois.readObject();

                if(std != null) {
                    JTextField[] stdInfoLabel = {
                            new JTextField("Student "),
                            new JTextField("Student Number: "),
                            new JTextField("Student Name: "),
                            new JTextField("Student Course(s): ")
                    };

                    txtArea.append(
                            "Student " + stdCounter++ + '\n'
                            + "-----------------------------------\n"
                            + "Student Number: " + std.getStdID() + '\n'
                            + "Student Name: " + std.getFullName() + '\n'
                            + "Student Course(s): " + std.getCourses() + "\n\n"
                    );

                    txtArea.setMinimumSize(new Dimension(350, 350));

                    txtArea.setFont(txtArea.getFont().deriveFont(21.0f));

                } else{
                    read = false;
                }
            }

            fis.close();

        }catch(EOFException e){
            txtArea.append("End of file reached!\n");
        } catch(Throwable e){
            System.err.println(e);
        }

        gbc.gridx = 0;
        gbc.gridy = 0;

        pane.add(txtArea, gbc);
        gbc.gridy++;
        pane.add(back, gbc);

        back.addActionListener(e ->{
            Main.displayMenu(pane);
        });

        pane.validate();
        pane.repaint();

    }
}
