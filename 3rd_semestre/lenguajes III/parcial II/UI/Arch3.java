import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.Scanner;

public class Arch3 extends JFrame {

    private JTextArea textArea;
    private JButton btnLeerArchivo;

    public Arch3() {
        // Configuración de la ventana principal
        setTitle("Lectura y Procesamiento de Archivo - datos.txt");
        setSize(600, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        // Crear componentes
        textArea = new JTextArea();
        textArea.setEditable(false);
        textArea.setBorder(BorderFactory.createTitledBorder("Texto Original y Procesado"));
        JScrollPane scrollPane = new JScrollPane(textArea);

        btnLeerArchivo = new JButton("Leer archivo");

        // Agregar eventos
        btnLeerArchivo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                leerYProcesarArchivo();
            }
        });

        // Diseño de la interfaz
        setLayout(new BorderLayout());
        add(scrollPane, BorderLayout.CENTER);
        add(btnLeerArchivo, BorderLayout.SOUTH);
    }

    private void leerYProcesarArchivo() {
        File archivo = new File("texto.txt");
        if (!archivo.exists()) {
            JOptionPane.showMessageDialog(this, "El archivo datos.txt no existe.", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        textArea.setText("");  // Limpiar el área de texto antes de procesar

        try (Scanner sc = new Scanner(archivo)) {
            while (sc.hasNextLine()) {
                String linea = sc.nextLine();
                String resultado = procesarLinea(linea);

                // Mostrar el texto original y el texto procesado en la misma línea
                textArea.append(linea + " " + resultado + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Error al leer el archivo.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private String procesarLinea(String linea) {
        StringBuilder sb = new StringBuilder();
        String[] partes = linea.split(",");
        for (String parte : partes) {
            if (!parte.isEmpty()) {
                sb.append(parte.trim().charAt(0)); // Tomar el primer caracter de cada palabra/número
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        // Ejecutar la interfaz gráfica en el hilo principal de la GUI
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new Arch3().setVisible(true);
            }
        });
    }
}