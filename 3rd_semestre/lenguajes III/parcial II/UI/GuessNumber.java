import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class GuessNumber extends JFrame {
    private JPanel Mpanel;
    private JButton GuessButton;
    private JTextField NumInput;
    private JLabel L1;
    private int numAlea;
    private int max;
    private int min;
    private int cont;
    private int vict;
    private int derr;

    public GuessNumber() {
        Random ramdom = new Random();

        min = 1;
        max = 25;

        vict = 0;
        derr = 0;

        numAlea = ramdom.nextInt((max - min) + 1) + min;

        setTitle("Número de Adivinadas: " + vict + " Número de Derrotas: " + derr);
        setSize(500, 100);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        Mpanel = new JPanel();
        Mpanel.setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(1, 1, 1, 1);

        L1 = new JLabel("Ingresa tu número para adivinar:");
        gbc.gridx = 0;
        gbc.gridy = 1;
        Mpanel.add(L1, gbc);

        NumInput = new JTextField();
        NumInput.setPreferredSize(new Dimension(40,20));
        gbc.gridx = 1;
        Mpanel.add(NumInput, gbc);

        GuessButton = new JButton("Adivina Adivinador");
        GuessButton.setFont(new Font("Arial", Font.PLAIN, 20));
        GuessButton.setFocusPainted(false);
        GuessButton.addActionListener(new BotonClickListener());

        gbc.gridx = 0;
        gbc.gridy = 3;
        gbc.gridwidth = 2;
        gbc.anchor = GridBagConstraints.SOUTH;
        Mpanel.add(GuessButton, gbc);

        add(Mpanel, BorderLayout.NORTH);
        setVisible(true);  // Muestra la ventana al iniciar
    }

    private class BotonClickListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            int num = Integer.parseInt(NumInput.getText());

            if (num == numAlea) {
                JOptionPane.showMessageDialog(null, "¡Le atinaste, qué suerte tienes!");
                vict++;
                cont = 0;  // Reiniciar el contador de intentos
                resetGame(); // Reiniciar el juego
            } else {
                cont++;
                if (num < numAlea) {
                    JOptionPane.showMessageDialog(null, "Un poquito más arriba, carnal");
                } else {
                    JOptionPane.showMessageDialog(null, "Menos, mi pay... menos");
                }

                if (cont == 3) {
                    JOptionPane.showMessageDialog(null, "¡Hijole, perdiste! No le atinaste, no más intentos :C");
                    derr++;
                    resetGame(); // Reiniciar el juego
                }
            }

            // Actualizar el título con los puntajes
            setTitle("Número de Adivinadas: " + vict + " Número de Derrotas: " + derr);
        }
    }

    private void resetGame() {
        Random ramdom = new Random();
        numAlea = ramdom.nextInt((max - min) + 1) + min; // Reiniciar el número aleatorio
        NumInput.setText(""); // Limpiar el campo de entrada
        cont = 0; // Reiniciar el contador de intentos
    }

    public static void main(String[] args) {
        new GuessNumber(); // Crear y mostrar la ventana
    }
}
