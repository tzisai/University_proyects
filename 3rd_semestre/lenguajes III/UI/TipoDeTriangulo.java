import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TipoDeTriangulo {
    public static void main(String[] args) {
        // Crear el marco (ventana)
        JFrame frame = new JFrame("Tipo de Triángulo");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 200);
        frame.setLayout(null);

        // Crear los componentes
        JLabel labelLado1 = new JLabel("Lado 1:");
        labelLado1.setBounds(10, 10, 80, 25);
        JTextField textFieldLado1 = new JTextField();
        textFieldLado1.setBounds(100, 10, 80, 25);

        JLabel labelLado2 = new JLabel("Lado 2:");
        labelLado2.setBounds(10, 40, 80, 25);
        JTextField textFieldLado2 = new JTextField();
        textFieldLado2.setBounds(100, 40, 80, 25);

        JLabel labelLado3 = new JLabel("Lado 3:");
        labelLado3.setBounds(10, 70, 80, 25);
        JTextField textFieldLado3 = new JTextField();
        textFieldLado3.setBounds(100, 70, 80, 25);

        JButton button = new JButton("Determinar Tipo");
        button.setBounds(200, 40, 150, 25);
        JLabel labelResultado = new JLabel();
        labelResultado.setBounds(10, 110, 350, 25);

        // Añadir los componentes al marco
        frame.add(labelLado1);
        frame.add(textFieldLado1);
        frame.add(labelLado2);
        frame.add(textFieldLado2);
        frame.add(labelLado3);
        frame.add(textFieldLado3);
        frame.add(button);
        frame.add(labelResultado);

        // Acción al hacer clic en el botón
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    double lado1 = Double.parseDouble(textFieldLado1.getText());
                    double lado2 = Double.parseDouble(textFieldLado2.getText());
                    double lado3 = Double.parseDouble(textFieldLado3.getText());

                    String tipoTriangulo = determinarTipoTriangulo(lado1, lado2, lado3);
                    labelResultado.setText("El triángulo es: " + tipoTriangulo);
                } catch (NumberFormatException ex) {
                    labelResultado.setText("Por favor, ingresa números válidos.");
                }
            }
        });

        // Hacer visible la ventana
        frame.setVisible(true);
    }

    // Método para determinar el tipo de triángulo
    private static String determinarTipoTriangulo(double lado1, double lado2, double lado3) {
        if (lado1 == lado2 && lado2 == lado3) {
            return "Equilátero";
        } else if (lado1 == lado2 || lado2 == lado3 || lado1 == lado3) {
            return "Isósceles";
        } else {
            return "Escaleno";
        }
    }
}
