import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MesDelAno {
    public static void main(String[] args) {
        // Crear el marco (ventana)
        JFrame frame = new JFrame("Mes del Año");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 150);
        frame.setLayout(null);  // Usamos un layout nulo para establecer posiciones manualmente

        // Crear los componentes
        JLabel labelPrompt = new JLabel("Ingresa un número (1-12):");
        labelPrompt.setBounds(10, 10, 200, 25);
        JTextField textField = new JTextField();
        textField.setBounds(10, 40, 50, 25);
        JButton button = new JButton("Mostrar Mes");
        button.setBounds(70, 40, 150, 25);
        JLabel labelMes = new JLabel();
        labelMes.setBounds(10, 70, 250, 25);

        // Añadir los componentes al marco
        frame.add(labelPrompt);
        frame.add(textField);
        frame.add(button);
        frame.add(labelMes);

        // Acción al hacer clic en el botón
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String numeroTexto = textField.getText();
                try {
                    int numero = Integer.parseInt(numeroTexto);
                    String mes = obtenerMes(numero);
                    if (mes != null) {
                        labelMes.setText("El mes es: " + mes);
                    } else {
                        labelMes.setText("Número fuera de rango (1-12).");
                    }
                } catch (NumberFormatException ex) {
                    labelMes.setText("Por favor, ingresa un número válido.");
                }
            }
        });

        // Hacer visible la ventana
        frame.setVisible(true);
    }

    // Método para obtener el nombre del mes
    private static String obtenerMes(int numero) {
        String[] meses = {"Invierno", "Invierno", "Primavera", "Primavera", "Primavera", "Primavera",
                          "Verano", "Verano", "Verano", "Otoño", "Otoño", "Invierno"};
        if (numero >= 1 && numero <= 12) {
            return meses[numero - 1];
        }
        return null;
    }
}
