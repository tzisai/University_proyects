/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */


 import java.awt.*;
 import java.awt.event.*;
 import javax.swing.*;
 
 /**
  *
  * @author dairo
  */
 public class PalindromosYNombres extends JPanel implements ActionListener {
 
     
     JButton verificarPalindromo, formatearTexto;
     JTextField textoPalindromo, textoFormateado, resultadoPalindromo, resultadoFormateado;
 
     public PalindromosYNombres() {
         textoPalindromo = new JTextField(15); // Campo para ingresar la palabra
         resultadoPalindromo = new JTextField(20); // Resultado de la verificación
         resultadoPalindromo.setEditable(false); // No editable
 
         textoFormateado = new JTextField(15); // Campo para el texto a formatear
         resultadoFormateado = new JTextField(20); // Resultado del formateo
         resultadoFormateado.setEditable(false); // No editable
 
         verificarPalindromo = new JButton("Verificar Palíndromo");
         formatearTexto = new JButton("Formatear Texto");
 
         verificarPalindromo.addActionListener(this);
         formatearTexto.addActionListener(this);
 
         setLayout(new FlowLayout());
         add(new JLabel("Palabra para verificar si es palíndromo:"));
         add(textoPalindromo);
         add(verificarPalindromo);
         add(resultadoPalindromo);
 
         add(new JLabel("Texto a formatear:"));
         add(textoFormateado);
         add(formatearTexto);
         add(resultadoFormateado);
     }
 
     public void actionPerformed(ActionEvent ae) {
         if (ae.getSource() == verificarPalindromo) {
             String palabra = textoPalindromo.getText().replaceAll("\\s+", "").toLowerCase(); // Quita espacios y pone en minúsculas
             String invertida = new StringBuilder(palabra).reverse().toString();
 
             if (palabra.equals(invertida)) {
                 resultadoPalindromo.setText("Es un palíndromo");
             } else {
                 resultadoPalindromo.setText("No es un palíndromo");
             }
         } else if (ae.getSource() == formatearTexto) {
             String texto = textoFormateado.getText().replaceAll("\\s+", ""); // Quitar espacios
             String formateado = texto.substring(0, 1).toUpperCase() + texto.substring(1).toLowerCase(); // Primera en mayúsculas, resto en minúsculas
             resultadoFormateado.setText(formateado);
         }
     }
 
     public static void main(String[] args) {
         JFrame.setDefaultLookAndFeelDecorated(true);
         JFrame frame = new JFrame("Verificación y Formateo de Texto");
         frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 
         PalindromosYNombres panel = new PalindromosYNombres();
         frame.getContentPane().add(panel, BorderLayout.CENTER);
         frame.setBounds(100, 100, 400, 200);
         frame.setVisible(true);
     }
 }