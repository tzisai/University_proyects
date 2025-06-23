import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SumaNumerosUI {
    public static void main(String[] args) {
        // Crear el marco (JFrame)
        JFrame frame = new JFrame("Suma de Dos Números");
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);

        // Etiqueta y campo de texto para el primer número
        JLabel label1 = new JLabel("Número 1:");
        label1.setBounds(20, 20, 80, 25);
        frame.add(label1);

        JTextField num1Field = new JTextField();
        num1Field.setBounds(100, 20, 150, 25);
        frame.add(num1Field);

        // Etiqueta y campo de texto para el segundo número
        JLabel label2 = new JLabel("Número 2:");
        label2.setBounds(20, 60, 80, 25);
        frame.add(label2);

        JTextField num2Field = new JTextField();
        num2Field.setBounds(100, 60, 150, 25);
        frame.add(num2Field);

        // Botón para realizar la suma
        JButton sumarButton = new JButton("Sumar");
        sumarButton.setBounds(100, 100, 80, 25);
        frame.add(sumarButton);

        // Etiqueta para mostrar el resultado
        JLabel resultadoLabel = new JLabel("Resultado:");
        resultadoLabel.setBounds(20, 140, 250, 25);
        frame.add(resultadoLabel);

        // Acción al hacer clic en el botón "Sumar"
        sumarButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    // Obtener los valores ingresados y realizar la suma
                    double num1 = Double.parseDouble(num1Field.getText());
                    double num2 = Double.parseDouble(num2Field.getText());
                    double resultado = num1 + num2;

                    // Mostrar el resultado
                    resultadoLabel.setText("Resultado: " + resultado);
                } catch (NumberFormatException ex) {
                    resultadoLabel.setText("Por favor ingrese números válidos.");
                }
            }
        });

        // Hacer visible la ventana
        frame.setVisible(true);
    }
}
