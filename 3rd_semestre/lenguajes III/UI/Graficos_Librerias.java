/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
/* 
 package graficos_librerias;



import javax.swing.*;
import java.awt.*;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PiePlot3D;
import org.jfree.data.general.DefaultPieDataset;
import org.jfree.data.general.PieDataset;
import org.jfree.chart.util.Rotation;
import org.jfree.data.category.DefaultCategoryDataset;
import org.jfree.data.xy.XYDataset;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;


public class Graficos_Librerias extends JFrame{
    private int currentChartIndex = 0;
    private JPanel chartPanel;

    public Graficos_Librerias(String title) {
         super(title);
        chartPanel = new JPanel(new BorderLayout());
        add(chartPanel, BorderLayout.CENTER);
        JButton changeButton = new JButton("Cambiar Gráfico");
        changeButton.addActionListener(e -> changeChart());
        add(changeButton, BorderLayout.SOUTH);
        changeChart();
    }
    
    private void changeChart() {
        currentChartIndex = (currentChartIndex + 1) % 5;
        chartPanel.removeAll();
        switch (currentChartIndex) {
            case 0:
                chartPanel.add(createChartPanel1(), BorderLayout.CENTER);
                break;
            case 1:
                chartPanel.add(createChartPanel2(), BorderLayout.CENTER);
                break;
            case 2:
                chartPanel.add(createChartPanel3(), BorderLayout.CENTER);
                break;
            case 3:
                chartPanel.add(createChartPanel4(), BorderLayout.CENTER);
                break;
            case 4:
                chartPanel.add(createChartPanel5(), BorderLayout.CENTER);
                break;
        }
        chartPanel.revalidate();
        chartPanel.repaint();
    }

    private ChartPanel createChartPanel1() {
        PieDataset dataset = createDataset1();
        JFreeChart chart = createChart(dataset, "¿Qué sistema operativo usas?");
        return new ChartPanel(chart);
    }

    private ChartPanel createChartPanel2() {
        DefaultCategoryDataset dataset = createDataset2();
        JFreeChart chart = ChartFactory.createLineChart(
            "Tráfico del Sitio",
            "Fecha",
            "Número de Visitantes",
            dataset
        );
        return new ChartPanel(chart);
    }

    private ChartPanel createChartPanel3() {
        XYDataset dataset = createDataset3();
        JFreeChart chart = ChartFactory.createScatterPlot(
            "Chicos vs Chicas - Gráfico Comparativo de Estaturas",
            "Edad",
            "Estatura",
            dataset
        );
        return new ChartPanel(chart);
    }

    private ChartPanel createChartPanel4() {
        DefaultCategoryDataset dataset = createDataset4();
        JFreeChart chart = ChartFactory.createBarChart(
            "Medición de Gentuza",
            "Año",
            "Población en Millones",
            dataset
        );
        return new ChartPanel(chart);
    }

    private ChartPanel createChartPanel5() {
        PieDataset dataset = createDataset5();
        JFreeChart chart = ChartFactory.createPieChart(
            "Posibilidades de Terminar el Año con Pareja",
            dataset,
            true,
            true,
            false
        );
        return new ChartPanel(chart);
    }

    private  PieDataset createDataset1() {
        DefaultPieDataset result = new DefaultPieDataset();
        result.setValue("Linux", 29);
        result.setValue("Mac", 20);
        result.setValue("Windows", 51);
        return result;
    }
    
    private DefaultCategoryDataset createDataset2() {
        String series1 = "Visitantes";  
        String series2 = "Visitante Unico"; 
        DefaultCategoryDataset dataset = new DefaultCategoryDataset();
        dataset.addValue(200, "Visitantes", "2016-12-19");
        dataset.addValue(150, "Visitantes", "2016-12-20");
        // Agrega los demás datos como en el ejemplo original...dataset.addValue(200, series1, "2016-12-19");  
        dataset.addValue(150, series1, "2016-12-20");  
        dataset.addValue(100, series1, "2016-12-21");  
        dataset.addValue(210, series1, "2016-12-22");  
        dataset.addValue(240, series1, "2016-12-23");  
        dataset.addValue(195, series1, "2016-12-24");  
        dataset.addValue(245, series1, "2016-12-25");  
      
        dataset.addValue(150, series2, "2016-12-19");  
        dataset.addValue(130, series2, "2016-12-20");  
        dataset.addValue(95, series2, "2016-12-21");  
        dataset.addValue(195, series2, "2016-12-22");  
        dataset.addValue(200, series2, "2016-12-23");  
        dataset.addValue(180, series2, "2016-12-24");  
        dataset.addValue(230, series2, "2016-12-25");
        return dataset;
    }

    private XYDataset createDataset3() {
        XYSeriesCollection dataset = new XYSeriesCollection();
        
        XYSeries series1 = new XYSeries("Chavales");
        series1.add(1, 72.9);
        series1.add(1, 72.9);  
        series1.add(2, 81.6);  
        series1.add(3, 88.9);  
        series1.add(4, 96);  
        series1.add(5, 102.1);  
        series1.add(6, 108.5);  
        series1.add(7, 113.9);  
        series1.add(8, 119.3);  
        series1.add(9, 123.8);  
        series1.add(10, 124.4); 
        dataset.addSeries(series1);
        
        XYSeries series2 = new XYSeries("Chavalas");  
        series2.add(1, 72.5);  
        series2.add(2, 80.1);  
        series2.add(3, 87.2);  
        series2.add(4, 94.5);  
        series2.add(5, 101.4);  
        series2.add(6, 107.4);  
        series2.add(7, 112.8);  
        series2.add(8, 118.2);  
        series2.add(9, 122.9);  
        series2.add(10, 123.4);  
      
        dataset.addSeries(series2); 
        return dataset;
    }
    
    private DefaultCategoryDataset createDataset4() {
        DefaultCategoryDataset dataset = new DefaultCategoryDataset();
        
        // Population in 2005  
        dataset.addValue(10, "USA", "2005");  
        dataset.addValue(15, "India", "2005");  
        dataset.addValue(20, "China", "2005");  
      
        // Population in 2010  
        dataset.addValue(15, "USA", "2010");  
        dataset.addValue(20, "India", "2010");  
        dataset.addValue(25, "China", "2010");  
      
        // Population in 2015  
        dataset.addValue(20, "USA", "2015");  
        dataset.addValue(25, "India", "2015");  
        dataset.addValue(30, "China", "2015"); 
        return dataset;
    }

    private PieDataset createDataset5() {
        DefaultPieDataset dataset = new DefaultPieDataset();
        dataset.setValue("Ninguna pero en Rojo", 120);
        dataset.setValue("Ninguna pero en Azul", 80);
        dataset.setValue("Quizás?", 2);
        return dataset;
    }

    /**     * Creates a chart     */
    /* 
    private JFreeChart createChart(PieDataset dataset, String title) {
        JFreeChart chart = ChartFactory.createPieChart3D(title, dataset, true, true, false);
        PiePlot3D plot = (PiePlot3D) chart.getPlot();
        plot.setStartAngle(290);
        plot.setDirection(Rotation.CLOCKWISE);
        plot.setForegroundAlpha(0.5f);
        return chart;
    }
    
    public static void main(String[] args) {
        SwingUtilities.invokeLater(()-> {
            Graficos_Librerias ej = new Graficos_Librerias("Ejemplos");
            ej.setSize(800, 600);
            ej.setLocationRelativeTo(null);
            ej.setDefaultCloseOperation(EXIT_ON_CLOSE);
            ej.setVisible(true);
        });
    }
}
*/