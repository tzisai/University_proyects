import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.StringTokenizer;

public class CapitalizeWordsGUI extends JFrame {
    private JLabel label;
    private JButton button;

    public CapitalizeWordsGUI() {
        setTitle("Capitalizar palabras");
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
                        content = capitalizeWords(content);
                        label.setText("<html>" + content.replaceAll("\n", "<br>") + "</html>");  // Mostrar el resultado
                        writeFile(filePath, content);  // Sobrescribir el archivo con el contenido capitalizado
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
                content.append(line).append("\n");
            }
            return content.toString();
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
    }

    // Método para capitalizar la primera letra de cada palabra
    private String capitalizeWords(String content) {
        StringBuilder result = new StringBuilder();
        StringTokenizer tokenizer = new StringTokenizer(content, " \t\n\r\f,.;:!?", true);  // Separa por palabras, pero mantiene los delimitadores
        while (tokenizer.hasMoreTokens()) {
            String word = tokenizer.nextToken();
            if (word.length() > 0 && Character.isLetter(word.charAt(0))) {
                result.append(Character.toUpperCase(word.charAt(0))).append(word.substring(1).toLowerCase());
            } else {
                result.append(word);  // Mantiene los delimitadores
            }
        }
        return result.toString();
    }

    // Método para sobrescribir el archivo con el contenido capitalizado
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
                new CapitalizeWordsGUI().setVisible(true);
            }
        });
    }
}
