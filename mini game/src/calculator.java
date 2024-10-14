import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class calculator extends JFrame implements ActionListener {

    private JTextField display;
    private JButton[] numberButtons;
    private JButton[] functionButtons;
    private JButton addButton, subButton, mulButton, divButton;
    private JButton clearButton, equalsButton, decimalButton;

    private double num1 = 0, num2 = 0, result = 0;
    private char operator;

    public calculator() {
        setTitle("Calculator");
        setSize(300, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        display = new JTextField();
        display.setEditable(false);
        display.setHorizontalAlignment(JTextField.RIGHT);
        add(display, BorderLayout.NORTH);

        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(4, 4, 10, 10));

        numberButtons = new JButton[10];
        for (int i = 0; i < 10; i++) {
            numberButtons[i] = new JButton(String.valueOf(i));
            numberButtons[i].addActionListener(this);
            buttonPanel.add(numberButtons[i]);
        }

        functionButtons = new JButton[6];
        functionButtons[0] = addButton = new JButton("+");
        functionButtons[1] = subButton = new JButton("-");
        functionButtons[2] = mulButton = new JButton("*");
        functionButtons[3] = divButton = new JButton("/");
        functionButtons[4] = clearButton = new JButton("C");
        functionButtons[5] = equalsButton = new JButton("=");

        for (int i = 0; i < 6; i++) {
            functionButtons[i].addActionListener(this);
            buttonPanel.add(functionButtons[i]);
        }

        decimalButton = new JButton(".");
        decimalButton.addActionListener(this);
        buttonPanel.add(decimalButton);

        add(buttonPanel, BorderLayout.CENTER);

        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        for (int i = 0; i < 10 ; i++) {
            if (e.getSource() == numberButtons[i]) {
                display.setText(display.getText() + i);
            }
        }

        if (e.getSource() == addButton) {
            num1 = Double.parseDouble(display.getText());
            operator = '+';
            display.setText("");
        } else if (e.getSource() == subButton) {
            num1 = Double.parseDouble(display.getText());
            operator = '-';
            display.setText("");
        } else if (e.getSource() == mulButton) {
            num1 = Double.parseDouble(display.getText());
            operator = '*';
            display.setText("");
        } else if (e.getSource() == divButton) {
            num1 = Double.parseDouble(display.getText());
            operator = '/';
            display.setText("");
        } else if (e.getSource() == equalsButton) {
            num2 = Double.parseDouble(display.getText());
            switch (operator) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = num1 / num2;
                    break;
            }
            display.setText(String.valueOf(result));
        } else if (e.getSource() == clearButton) {
            display.setText("");
            num1 = 0;
            num2 = 0;
            result = 0;
        } else if (e.getSource() == decimalButton) {
            if (!display.getText().contains(".")) {
                display.setText(display.getText() + ".");
            }
        }
    }

    public static void main(String[] args) {
        new calculator();
    }
}