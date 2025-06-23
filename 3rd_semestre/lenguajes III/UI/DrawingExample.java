import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class DrawingExample extends JFrame {
    private Image image;

    public DrawingExample() {
        setTitle("Ejemplo de Dibujo");
        setSize(600, 600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        JLabel labelLado1 = new JLabel("ipsumm lorem");

        // Cargar la imagen
        image = new ImageIcon("C:\\Users\\Isai Nuñez\\Documents\\3er semestres\\primer parcial\\lenguajes III\\Original_Doge_meme.jpg").getImage();  // Reemplaza con la ruta de tu imagen

        DrawingPanel drawingPanel = new DrawingPanel();
        add(drawingPanel);
        
        JButton drawButton = new JButton("Dibujar");
        drawButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                drawingPanel.repaint();
            }
        });

        add(drawButton, BorderLayout.SOUTH);
    }

    

    // Panel personalizado para realizar los dibujos
    private class DrawingPanel extends JPanel {
        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);

            
            // Dibujar la imagen
            g.drawImage(image, 50, 50, this);  // Dibuja la imagen en (50, 50)

            // Dibujar una línea
            g.setColor(Color.RED);
            g.drawLine(50, 50, 200, 200);  // Línea de (50, 50) a (200, 200)

            // Dibujar un óvalo
            g.setColor(Color.BLUE);
            g.drawOval(250, 100, 100, 150);  // Óvalo con dimensiones (100x150) en (250, 100)
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            DrawingExample example = new DrawingExample();
            example.setVisible(true);
        });
    }
}
