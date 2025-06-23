import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;

public class ReplaceCommasGUI extends JFrame {
    private JLabel label;
    private JButton button;

    public ReplaceCommasGUI() {
        setTitle("Reemplazar comas por guiones");
        setSize(400, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());

        label = new JLabel("Resultado aparecerá aquí");
        button = new JButton("Cargar archivo");

        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFileChooser fileChooser = new JFileChooser();
                int result = fileChooser.showOpenDialog(null);
                if (result == JFileChooser.APPROVE_OPTION) {
                    String filePath = fileChooser.getSelectedFile().getPath();
                    String content = readFile(filePath);
                    if (content != null) {
                        content = content.replace(",", "-");
                        label.setText(content);
                        writeFile(filePath, content);  // Sobrescribir el archivo con el contenido modificado
                    } else {
                        label.setText("Error al leer el archivo.");
                    }
                }
            }
        });

        add(button);
        add(label);
    }

    // Método para leer el contenido del archivo
    private String readFile(String filePath) {
        StringBuilder content = new StringBuilder();
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                content.append(line);
            }
            return content.toString();
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
    }

    // Método para sobrescribir el archivo con el contenido modificado
    private void writeFile(String filePath, String content) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filePath))) {
            bw.write(content);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new ReplaceCommasGUI().setVisible(true);
            }
        });
    }
}
