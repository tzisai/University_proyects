import javax.swing.*;
import java.awt.*;


public class MyGUI {
    public static void main(String[] args) {
        // Crear el marco (ventana)
        JFrame frame = new JFrame("Mi Primera GUI");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);

        // Crear un botón
        JButton button = new JButton("Haz clic aquí");
        
        // Añadir el botón al marco
        frame.getContentPane().add(button, BorderLayout.CENTER);

        // Hacer visible la ventana
        frame.setVisible(true);
    }
}
