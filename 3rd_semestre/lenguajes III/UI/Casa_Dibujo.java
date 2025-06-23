/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

 

 import java.awt.*;
 import java.awt.event.*;
 import java.util.ArrayList;
 import java.util.List;
 import javax.swing.*;
 
 public class Casa_Dibujo extends JPanel implements ActionListener{
     JButton confirm1;
     private List<Figura> figuras = new ArrayList<>();
     
     public Casa_Dibujo(){
         confirm1 = new JButton("Mostrar");
         confirm1.addActionListener(this);
         add(confirm1);
     }
     
     abstract class Figura{
         protected int x, y;
         public Figura(int x, int y){
             this.x = x;
             this.y = y;
         }
         public abstract void dibujo(Graphics g);
     }
     
     class cuadrado extends Figura{
         private int lado;
         
         public cuadrado(int x, int y, int lado){
             super(x,y);
             this.lado = lado;
         }
         
         @Override
         public void dibujo(Graphics g){
             g.drawRect(x, y, lado, lado);
         }
     }
     
     class rectangulo extends Figura{
         private int base1, altura1;
         public rectangulo(int x, int y, int base1, int altura1) {
             super(x, y);
             this.base1 = base1;
             this.altura1 = altura1;
         }
 
         @Override
         public void dibujo(Graphics g) {
             g.drawRect(x, y, base1, altura1);
         }
     }
     
     class triangulo extends Figura {
         private int base, altura;
         public triangulo(int x, int y, int base, int altura) {
             super(x, y);
             this.base = base;
             this.altura = altura;
         }
         @Override
         public void dibujo(Graphics g) {
             int[] xPoints = {x, x + (base / 2), x - (base / 2)};
             int[] yPoints = {y - altura, y, y};
             g.drawPolygon(xPoints, yPoints, 3);
             //g.setColor(Color.red);
             //g.fillPolygon(xPoints, yPoints, 3);
         }
     }
     
     class circulo extends Figura {
         private int radio;
 
         public circulo(int x, int y, int radio) {
             super(x, y);
             this.radio = radio;
         }
 
         @Override
         public void dibujo(Graphics g) {
             g.drawOval(x, y, radio * 2, radio * 2);
         }
     }
     
     class lineas extends Figura{
         private int linea1, linea2;
         
         public lineas(int x, int y, int linea1, int linea2){
             super(x, y);
             this.linea1 = linea1;
             this.linea2 = linea2;
         }
         
         @Override
         public void dibujo(Graphics g){
             g.drawLine(x, y, linea1, linea2);
         }
     }
     
     public void agregarFigura(Figura figura) {
         figuras.add(figura);
         repaint();
     }
 
     @Override
     protected void paintComponent(Graphics g) {
         super.paintComponent(g);
         for (Figura figura : figuras) {
             figura.dibujo(g);
         }
     }
     
     @Override
     public void actionPerformed(ActionEvent ae){
         if(ae.getSource() == confirm1){
             agregarFigura(new cuadrado(150, 150, 100));
             agregarFigura(new triangulo(200, 150, 100, 70));
             agregarFigura(new circulo(205, 165, 20));
             agregarFigura(new rectangulo(170, 200, 35, 50));
             agregarFigura(new lineas(205, 185, 245, 185));
             agregarFigura(new lineas(225, 165, 225, 205));
             
         }
     }
     public static void main(String[] args) {
         JFrame.setDefaultLookAndFeelDecorated(true);
         JFrame frame = new JFrame("Figuras");
         frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
         
         Casa_Dibujo bot = new Casa_Dibujo();
         frame.getContentPane().add(bot, BorderLayout.CENTER);
         frame.setBounds(100,100,400,325);
         frame.setVisible(true);
     }
 }