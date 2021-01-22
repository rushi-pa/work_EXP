import javax.swing.*;
import java.awt.*;

public class Main {

    public static void main(String[] args) {

        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setTitle("Workshop 5");
        frame.setSize(new Dimension(500,500));

        JPanel pane = new JPanel(new GridBagLayout());

        displayMenu(pane);

        frame.add(pane);
        frame.setVisible(true);
    }

    public static void displayMenu(JPanel pane){
        pane.removeAll();

        GridBagConstraints gbc = new GridBagConstraints();

        JLabel title = new JLabel("Student Information");
        title.setFont(title.getFont().deriveFont(35.0f));

        JButton[] menuButtons = {
                new JButton("Add New Student"),
                new JButton("Display Students"),
                new JButton("Exit")
        };

        menuButtons[0].addActionListener(e -> {
            WriteStdInfo.writeStdInfo(pane);
        });

        menuButtons[1].addActionListener(e -> {
            ReadStdInfo.readStdInfo(pane);
        });

        menuButtons[2].addActionListener(e -> System.exit(0));

        gbc.gridx = 0;
        gbc.gridy = 0;

        gbc.insets = new Insets(5, 0, 10, 0);
        pane.add(title, gbc);
        gbc.gridy++;

        gbc.insets = new Insets(5, 0, 5, 0);
        for(JButton button : menuButtons){
            button.setFont(button.getFont().deriveFont(15.0f));
            button.setPreferredSize(new Dimension(350, 27));
            pane.add(button, gbc);
            gbc.gridy++;
        }

        pane.validate();
        pane.repaint();
    }
}
