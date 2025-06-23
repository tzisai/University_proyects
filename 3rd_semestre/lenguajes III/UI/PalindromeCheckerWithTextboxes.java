import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class PalindromeCheckerWithTextboxes extends JFrame {
    private JTextField inputField, correctedField, palindromeField;

    public PalindromeCheckerWithTextboxes() {
        setTitle("Verificador de Palíndromos");
        setSize(500, 250);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(null);

        // Etiqueta y campo para ingresar la palabra
        JLabel inputLabel = new JLabel("Ingresa una palabra:");
        inputLabel.setBounds(30, 30, 150, 30);
        add(inputLabel);

        inputField = new JTextField();
        inputField.setBounds(180, 30, 150, 30);
        add(inputField);

        // Botón para verificar
        JButton checkButton = new JButton("Verificar");
        checkButton.setBounds(180, 70, 100, 30);
        add(checkButton);

        // Campo para mostrar la palabra corregida
        JLabel correctedLabel = new JLabel("Palabra corregida:");
        correctedLabel.setBounds(30, 110, 150, 30);
        add(correctedLabel);

        correctedField = new JTextField();
        correctedField.setBounds(180, 110, 150, 30);
        correctedField.setEditable(false); // Solo lectura
        add(correctedField);

        // Campo para mostrar si es palíndromo o no
        JLabel palindromeLabel = new JLabel("¿Es palíndromo?");
        palindromeLabel.setBounds(30, 150, 150, 30);
        add(palindromeLabel);

        palindromeField = new JTextField();
        palindromeField.setBounds(180, 150, 150, 30);
        palindromeField.setEditable(false); // Solo lectura
        add(palindromeField);

        // Acción del botón
        checkButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String inputText = inputField.getText();
                processInput(inputText);
            }
        });
    }

    private void processInput(String input) {
        // Eliminar espacios y capitalizar
        String correctedInput = capitalizeFirstLetter(input.replaceAll("\\s+", ""));

        // Verificar si es palíndromo
        boolean isPalindrome = checkPalindrome(correctedInput);

        // Mostrar resultados en los textboxes correspondientes
        correctedField.setText(correctedInput);
        palindromeField.setText(isPalindrome ? "Sí, es un palíndromo" : "No, no es un palíndromo");
    }

    // Función para verificar si es palíndromo
    private boolean checkPalindrome(String input) {
        String reversed = new StringBuilder(input.toLowerCase()).reverse().toString();
        return input.toLowerCase().equals(reversed);
    }

    // Función para capitalizar la primera letra
    private String capitalizeFirstLetter(String input) {
        if (input.isEmpty()) {
            return input;
        }
        return input.substring(0, 1).toUpperCase() + input.substring(1).toLowerCase();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            PalindromeCheckerWithTextboxes checker = new PalindromeCheckerWithTextboxes();
            checker.setVisible(true);
        });
    }
}
