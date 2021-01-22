import javax.swing.*;
import java.awt.*;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

import static java.lang.Integer.parseInt;

public class WriteStdInfo {
    public static void writeStdInfo(JPanel pane) {

        pane.removeAll();

        try {
            FileOutputStream fs = new FileOutputStream("output.txt");
            ObjectOutputStream oos = new ObjectOutputStream(fs);

            JLabel[] stdInfoPrompt = {
                    new JLabel("Student number: "),
                    new JLabel("Student's first name: "),
                    new JLabel("Student's last name: "),
                    new JLabel("Student's course: ")
            };

            ArrayList<JTextField> stdInfoInput = new ArrayList<JTextField>();

            for(int i = 0; i < 4; i++){
                stdInfoInput.add(new JTextField());
            }


            JButton submit = new JButton("Submit");
            submit.setBounds(300, 300, 100, 50);

            JButton reset = new JButton("Reset");
            reset.setBounds(300, 300, 100, 50);

            JButton back = new JButton("Back");
            back.setBounds(300, 300, 100, 50);

            JButton addCourse = new JButton("Add Course");
            addCourse.setBounds(300, 300, 100, 50);

            GridBagConstraints gbc = new GridBagConstraints();

            Student std = new Student();

            // ---------------- Adding GUI components to panel -------------
            gbc.gridx = 0;
            gbc.gridy = 0;
            gbc.insets = new Insets(5, 0, 5, 3);

            // Enter ...:  -- Input here --
            // Enter ...:  -- Input here --
            // Enter ...:  -- Input here --
            for (int i = 0; i < stdInfoInput.size(); i++) {
                stdInfoInput.get(i).setColumns(15);
                stdInfoInput.get(i).setEditable(true);

                pane.add(stdInfoPrompt[i], gbc);
                gbc.gridx++;

                pane.add(stdInfoInput.get(i), gbc);

                gbc.gridx = 0;
                gbc.gridy++;

            }

            gbc.insets = new Insets(5, 10, 5, 0);
            pane.add(addCourse, gbc);
            gbc.gridy++;

            pane.add(back, gbc);
            gbc.gridx++;

            pane.add(reset, gbc);
            gbc.gridx++;

            pane.add(submit, gbc);

            // ------------ Action Listeners ----------------
            addCourse.addActionListener(e ->{
                gbc.gridy--;
                gbc.gridx = 0;
                pane.remove(submit);
                pane.remove(reset);
                pane.remove(back);
                pane.remove(addCourse);

                gbc.insets = new Insets(5, 0, 5, 0);
                gbc.gridx++;

                JTextField field = new JTextField();
                field.setColumns(15);

                stdInfoInput.add(field);
                pane.add(field, gbc);
                gbc.gridy++;
                gbc.gridx--;

                gbc.insets = new Insets(5, 10, 5, 0);
                pane.add(addCourse, gbc);
                gbc.gridy++;

                pane.add(back, gbc);
                gbc.gridx++;

                pane.add(reset, gbc);
                gbc.gridx++;

                pane.add(submit, gbc);

                pane.validate();
                //pane.repaint();
            });

            back.addActionListener(e -> {
                try {
                    oos.flush();
                    fs.close();
                }catch (Throwable e1){
                    System.out.println(e1);
                }

                Main.displayMenu(pane);
            });

            reset.addActionListener(e ->{
                for(JTextField inputField : stdInfoInput){
                    inputField.setText("");
                }
            });

            submit.addActionListener(e -> {
                try {
                    std.setStdID(parseInt(stdInfoInput.get(0).getText()));
                    std.setFirstName(stdInfoInput.get(1).getText());
                    std.setLastName(stdInfoInput.get(2).getText());

                    for(int i = 3; i < stdInfoInput.size(); i++) {
                        std.setCourses(stdInfoInput.get(i).getText());
                    }

                    for (JTextField txtField : stdInfoInput) {
                        txtField.setText("");
                    }

                    oos.writeObject(std);
                    oos.flush();

                } catch (Throwable e1) {
                    System.out.println(e1);
                }

            });


            pane.validate();
            pane.repaint();


        } catch (Throwable e) {
            System.out.println(e);
        }
    }
}
