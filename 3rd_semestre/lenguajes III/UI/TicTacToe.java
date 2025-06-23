import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class TicTacToe extends JFrame {
    private JButton[][] botones;
    private int jugadorActual;
    private int[] contVict; // Para contar victorias
    private JLabel victoriasLabel; // Para mostrar el número de victorias
    private JButton reset; // Botón para reiniciar el tablero

    public TicTacToe() {
        jugadorActual = 0; // Inicializar el jugador
        botones = new JButton[3][3];
        contVict = new int[2]; // Inicializar contador de victorias
        contVict[0] = 0; // Victorias de P1
        contVict[1] = 0; // Victorias de P2

        setTitle("Tic Tac Toe");
        setSize(300, 400); // Aumentar el tamaño para incluir el JButton
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BorderLayout()); // Usar BorderLayout para colocar el JLabel y el JButton

        // Crear el panel del tablero
        JPanel panelTablero = new JPanel();
        panelTablero.setLayout(new GridLayout(3, 3));

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                botones[i][j] = new JButton();
                botones[i][j].setFont(new Font("Arial", Font.PLAIN, 60));
                botones[i][j].setFocusPainted(false);
                botones[i][j].addActionListener(new BotonClickListener(i, j));
                panelTablero.add(botones[i][j]);
            }
        }

        // Agregar el panel del tablero a la ventana
        add(panelTablero, BorderLayout.CENTER);

        // Crear y agregar el JLabel para las victorias
        victoriasLabel = new JLabel("Victorias - P1: " + contVict[0] + " P2: " + contVict[1]);
        victoriasLabel.setFont(new Font("Arial", Font.PLAIN, 20));
        add(victoriasLabel, BorderLayout.NORTH); // Colocar el JLabel en la parte superior

        // Crear y agregar el botón de reinicio
        reset = new JButton("Reiniciar");
        reset.setFont(new Font("Arial", Font.PLAIN, 20));
        reset.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                reiniciarTablero(); // Llamar al método para reiniciar el tablero
            }
        });
        add(reset, BorderLayout.SOUTH); // Colocar el botón en la parte inferior

        setVisible(true);
    }

    private class BotonClickListener implements ActionListener {
        private int fila;
        private int columna;

        public BotonClickListener(int fila, int columna) {
            this.fila = fila;
            this.columna = columna;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            if (botones[fila][columna].getText().equals("")) { // Si la casilla está vacía
                if(jugadorActual%2==0){
                    botones[fila][columna].setText(String.valueOf('O')); // Marcar la casilla
                    jugadorActual++;
                }
                else{
                    botones[fila][columna].setText(String.valueOf('X')); // Marcar la casilla
                    jugadorActual++;
                }
                
                if (verificarGanador(fila, columna)) { // Verificar si hay un ganador
                char ganador_=(jugadorActual%2==1)?'O':'X';
                    JOptionPane.showMessageDialog(null, "¡El jugador " + ganador_ + " ha ganado!");
                    int jugadorIndex = (jugadorActual%2 ==0 ) ? 1 : 0;
                    contVict[jugadorIndex]++; // Incrementar el contador de victorias
                    actualizarVictoriasLabel(); // Actualizar el JLabel
                    reiniciarTablero(); // Reiniciar el tablero después de anunciar el ganador
                } 
            
            }
        }
        
    }

    private void actualizarVictoriasLabel() {
        victoriasLabel.setText("Victorias - P1: " + contVict[0] + " P2: " + contVict[1]);
    }

    private void reiniciarTablero() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                botones[i][j].setText(""); // Limpiar el tablero
            }
        }
        jugadorActual =0; // Reiniciar a jugador X
    }

    private boolean verificarGanador(int fila, int columna) {
        // Verificar fila
        if (!botones[0][0].getText().equals("") &&
            botones[0][0].getText().equals(botones[0][1].getText()) &&
            botones[0][1].getText().equals(botones[0][2].getText())) {
            return true;
        }
    
        if (!botones[1][0].getText().equals("") &&
            botones[1][0].getText().equals(botones[1][1].getText()) &&
            botones[1][1].getText().equals(botones[1][2].getText())) {
            return true;
        }
    
        if (!botones[2][0].getText().equals("") &&
            botones[2][0].getText().equals(botones[2][1].getText()) &&
            botones[2][1].getText().equals(botones[2][2].getText())) {
            return true;
        }
    
        // Verificar columna
        if (!botones[0][0].getText().equals("") &&
            botones[0][0].getText().equals(botones[1][0].getText()) &&
            botones[1][0].getText().equals(botones[2][0].getText())) {
            return true;
        }
    
        if (!botones[0][1].getText().equals("") &&
            botones[0][1].getText().equals(botones[1][1].getText()) &&
            botones[1][1].getText().equals(botones[2][1].getText())) {
            return true;
        }
    
        if (!botones[0][2].getText().equals("") &&
            botones[0][2].getText().equals(botones[1][2].getText()) &&
            botones[1][2].getText().equals(botones[2][2].getText())) {
            return true;
        }
    
        // Verificar diagonales
        if (!botones[0][0].getText().equals("") &&
            botones[0][0].getText().equals(botones[1][1].getText()) &&
            botones[1][1].getText().equals(botones[2][2].getText())) {
            return true;
        }
    
        if (!botones[0][2].getText().equals("") &&
            botones[0][2].getText().equals(botones[1][1].getText()) &&
            botones[1][1].getText().equals(botones[2][0].getText())) {
            return true;
        }
    
        return false; // No hay ganador
    }
    

    public static void main(String[] args) {
        new TicTacToe(); // Crear la instancia del juego
    }
}