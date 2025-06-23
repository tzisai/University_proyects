import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class TrianguloUIP extends JFrame {

    private JButton calcular;
    private JPanel panel;
    private JTextField[] textfields;
    private TrianguloPanel trianguloPanel; // Panel para dibujar el triángulo

    public TrianguloUIP() {
        setTitle("Tamaño de los lados del Triángulo");
        setSize(400, 600); 
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Crear el panel y configurar el GridBagLayout
        panel = new JPanel();
        panel.setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(1, 1, 1, 1); // Añadir un margen

        textfields = new JTextField[3]; // Arreglo para las 3 cajas de texto

        for (int i = 0; i < 3; i++) {
            // Etiqueta para cada lado
            JLabel label = new JLabel("Lado " + (i + 1) + ": ");
            gbc.gridx = 0; // Columna 0
            gbc.gridy = i; // Fila i
            panel.add(label, gbc);

            // Crear y agregar la caja de texto
            textfields[i] = new JTextField(10);
            gbc.gridx = 1; // Columna 1
            panel.add(textfields[i], gbc);
        }

        // Crear y configurar el botón
        calcular = new JButton("Dibujar");
        calcular.setFont(new Font("Arial", Font.PLAIN, 20));
        calcular.setFocusPainted(false);
        calcular.addActionListener(new BotonClickListener()); 

        // Configurar el botón en el centro
        gbc.gridx = 0; // Columna 0
        gbc.gridy = 3; // Fila 3 (debajo de las cajas de texto)
        gbc.gridwidth = 2; // Hacer que ocupe las dos columnas
        gbc.anchor = GridBagConstraints.SOUTH; // Centrar el botón
        panel.add(calcular, gbc);

        // Agregar el panel a la ventana
        add(panel, BorderLayout.NORTH);

        // Crear el panel para dibujar el triángulo
        trianguloPanel = new TrianguloPanel();
        add(trianguloPanel, BorderLayout.CENTER);

        // Hacer visible la ventana
        setVisible(true);
    }

    // Clase interna que implementa ActionListener para manejar el evento del botón
    private class BotonClickListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            try {
                // Obtener los valores de las cajas de texto
                double lado1 = Double.parseDouble(textfields[0].getText());
                double lado2 = Double.parseDouble(textfields[1].getText());
                double lado3 = Double.parseDouble(textfields[2].getText());

                // Determinar el tipo de triángulo
                String tipoTriangulo;
                if (lado1 == lado2 && lado2 == lado3) {
                    tipoTriangulo = "Equilátero";
                } else if (lado1 != lado2 && lado2 != lado3 && lado1 != lado3) {
                    tipoTriangulo = "Escaleno";
                } else {
                    tipoTriangulo = "Isósceles";
                }

                // Mostrar el resultado
                JOptionPane.showMessageDialog(null, "El triángulo es: " + tipoTriangulo);

                // Dibujar el triángulo en el panel
                trianguloPanel.setLados(lado1, lado2, lado3);
                trianguloPanel.repaint();

            } catch (NumberFormatException ex) {
                // En caso de que el usuario ingrese un valor no numérico
                JOptionPane.showMessageDialog(null, "Por favor, ingresa valores numéricos válidos para los lados.");
            }
        }
    }

    // Clase para dibujar el triángulo
    class TrianguloPanel extends JPanel {
        private double lado1, lado2, lado3;

        public void setLados(double lado1, double lado2, double lado3) {
            this.lado1 = lado1;
            this.lado2 = lado2;
            this.lado3 = lado3;
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            // Calcular las coordenadas del triángulo
            double maxLado = Math.max(lado1, Math.max(lado2, lado3));
            double scale = 200 / maxLado; // Escalar para que quepa en el panel

            int x1 = 50, y1 = 300; // Punto A
            int x2 = (int) (x1 + lado1 * scale), y2 = 300; // Punto B
            int x3 = (int) (x1 + lado2 * scale / 2), y3 = (int) (300 - (Math.sqrt(lado3 * lado3 - (lado2 * lado2 / 4) )) * scale); // Punto C

            // Dibujar el triángulo
            g.setColor(Color.BLACK);
            g.drawLine(x1, y1, x2, y2); // Línea AB
            g.drawLine(x2, y2, x3, y3); // Línea BC
            g.drawLine(x3, y3, x1, y1); // Línea CA
        }
    }

    public static void main(String[] args) {
        new TrianguloUIP();
    }
}
