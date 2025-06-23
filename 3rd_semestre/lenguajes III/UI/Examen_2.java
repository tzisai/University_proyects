import java.awt.*;
import java.io.*;
import javax.swing.*;

public class Examen_2 {
    public static String CargaR_Archivo(String ruta) {
        StringBuilder ArchivoL = new StringBuilder();
        try {
            BufferedReader lector = new BufferedReader(new FileReader(ruta));
            String lineaLect;
            while ((lineaLect = lector.readLine()) != null) {
                ArchivoL.append(lineaLect).append("\n");
            }
            lector.close();
        } catch (IOException e) {
            ArchivoL.append("No se pudo leer el archivo: ").append(e.getMessage());
        }
        return ArchivoL.toString();
    }

    public static void GuardaR_Archivo(String ruta, String contenido) {
        try {
            BufferedWriter escritor = new BufferedWriter(new FileWriter(ruta));
            escritor.write(contenido);
            escritor.close();
        } catch (IOException e) {
            System.out.println("No se pudo guardar el archivo: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        String ruta1 = "assets/txt/Casa.txt";
        String ruta2 = "assets/txt/Gym.txt";
        String ruta3 = "assets/txt/Trabajo.txt";
        int tam1, tam2;
        tam1 = 150;
        tam2 = 250;

        ImageIcon imgr1 = new ImageIcon("assets\\imgs\\kabayashi_chambeando.png");
        Image imgRed1 = imgr1.getImage().getScaledInstance(tam2, tam1, Image.SCALE_SMOOTH);
        ImageIcon imgREd1 = new ImageIcon(imgRed1);

        ImageIcon imgr2 = new ImageIcon("assets\\imgs\\levi_limpiando.jpg");
        Image imgRed2 = imgr2.getImage().getScaledInstance(tam2, tam1, Image.SCALE_SMOOTH);
        ImageIcon imgREd2 = new ImageIcon(imgRed2);

        ImageIcon imgr3 = new ImageIcon("assets\\imgs\\rei_mancuerna.jpg");
        Image imgRed3 = imgr3.getImage().getScaledInstance(tam2, tam1, Image.SCALE_SMOOTH);
        ImageIcon imgREd3 = new ImageIcon(imgRed3);

        JFrame frame = new JFrame("TO DO LIST");
        frame.getContentPane().setBackground(new Color(45, 45, 45)); // Fondo oscuro
        JTabbedPane pestañas = new JTabbedPane();
        pestañas.setBackground(new Color(194, 221, 255)); // Fondo de las pestañas
        
        // Personaliza la fuente y color del texto
        Font font = new Font("Arial", Font.PLAIN, 14);
        Color textColor = Color.BLACK;

        // Panel 1: Trabajo
        JPanel panel1 = new JPanel(new GridBagLayout());
        panel1.setBackground(new Color(194, 221, 255));
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5);
        gbc.gridx = 0;
        gbc.gridy = 0;
        panel1.add(new JLabel("Cosas por hacer Trabajo") {{
            setForeground(textColor);
        }}, gbc);

        JTextArea textarea1 = new JTextArea(10, 20);
        textarea1.setText(CargaR_Archivo(ruta3));
        textarea1.setFont(font);
        textarea1.setForeground(textColor);
        textarea1.setBackground(new Color(255, 255, 255));
        gbc.gridy = 1;
        panel1.add(new JScrollPane(textarea1), gbc);

        gbc.gridy = 2;
        panel1.add(new JLabel(imgREd1), gbc);

        JButton guardar1 = new JButton("Guardar");
        guardar1.addActionListener(e -> GuardaR_Archivo(ruta3, textarea1.getText()));
        gbc.gridy = 3;
        panel1.add(guardar1, gbc);

        // Panel 2: Casa
        JPanel panel2 = new JPanel(new GridBagLayout());
        panel2.setBackground(new Color(194, 221, 255));
        gbc.gridx = 0;
        gbc.gridy = 0;
        panel2.add(new JLabel("Lista pendientes de la Casa") {{
            setForeground(textColor);
        }}, gbc);

        JTextArea textarea2 = new JTextArea(10, 30);
        textarea2.setText(CargaR_Archivo(ruta1));
        textarea2.setFont(font);
        textarea2.setForeground(textColor);
        textarea2.setBackground(new Color(255, 255, 255));
        gbc.gridy = 1;
        panel2.add(new JScrollPane(textarea2), gbc);

        gbc.gridy = 2;
        panel2.add(new JLabel(imgREd2), gbc);

        JButton guardar2 = new JButton("Guardar");
        guardar2.addActionListener(e -> GuardaR_Archivo(ruta1, textarea2.getText()));
        gbc.gridy = 3;
        panel2.add(guardar2, gbc);

        // Panel 3: Gimnasio
        JPanel panel3 = new JPanel(new GridBagLayout());
        panel3.setBackground(new Color(194, 221, 255));
        gbc.gridx = 0;
        gbc.gridy = 0;
        panel3.add(new JLabel("Rutina del Gimnasio") {{
            setForeground(textColor);
        }}, gbc);

        JTextArea textarea3 = new JTextArea(10, 30);
        textarea3.setText(CargaR_Archivo(ruta2));
        textarea3.setFont(font);
        textarea3.setForeground(textColor);
        textarea3.setBackground(new Color(255, 255, 255));
        gbc.gridy = 1;
        panel3.add(new JScrollPane(textarea3), gbc);

        gbc.gridy = 2;
        panel3.add(new JLabel(imgREd3), gbc);

        JButton guardar3 = new JButton("Guardar");
        guardar3.addActionListener(e -> GuardaR_Archivo(ruta2, textarea3.getText()));
        gbc.gridy = 3;
        panel3.add(guardar3, gbc);

        // Añadir los paneles a las pestañas
        pestañas.add("Trabajo", panel1);
        pestañas.add("Casa", panel2);
        pestañas.add("Gimnasio", panel3);

        // Configuración del frame
        frame.add(pestañas);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(720, 500);
        frame.setVisible(true);


                // Dentro del método main, después de crear el JFrame y configurar las pestañas.
        frame.addWindowListener(new java.awt.event.WindowAdapter() {
            @Override
            public void windowClosing(java.awt.event.WindowEvent windowEvent) {
                // Guardar el contenido de los JTextArea en los archivos correspondientes
                GuardaR_Archivo(ruta3, textarea1.getText());  // Guardar el contenido del panel Trabajo
                GuardaR_Archivo(ruta1, textarea2.getText());  // Guardar el contenido del panel Casa
                GuardaR_Archivo(ruta2, textarea3.getText());  // Guardar el contenido del panel Gimnasio
            }
        });


    }
    
}
