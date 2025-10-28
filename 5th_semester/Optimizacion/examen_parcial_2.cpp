/*
*Universidad autonoma del estado de Aguascalientes
*21 de Octubre del 2025
*Optimizacion Inteligenete Examen 2 Parcial
*Prof: Dr. Luis Fernando Gutierrez Marfileño
*Realizop:Martin Isai Nuñez Villeda
*Problema:
        Se quiere definir la asignación de 5 trabajos a 5 máquinas en un taller. El objetivo es minimizar el tiempo total de procesamiento, considerando que cada trabajo tiene un tiempo diferente en cada máquina.

        Supuestos del problema

        Hay 5 trabajos: J1, J2, J3, J4, J5.
        Hay 5 máquinas: M1, M2, M3, M4, M5.
        Cada trabajo tiene un tiempo de ejecución distinto en cada máquina.
        Se busca una asignación óptima: cada máquina realiza un solo trabajo y viceversa.
        Parámetros del algoritmo:

        TEMPERATURA_INICIAL = 1000
        TEMPERATURA_FINAL = 1
        FACTOR_ENFRIAMIENTO = 0.95
        ITERACIONES_POR_T = 100

        Dicho durante examen:
            Tiempo 1 para la maquina 1
            tiempo 2 para la maquina 2
            tiempo 3 para la maquina 3
            tiempo 4 para la maquina 4
            tiempo 5 para la maquina 5
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <chrono>
#include <cmath>


int TAREAS_A_MAQUILAR = 5;
int MAQUINAS_CHAMBEADORAS = 5;


std::vector<std::vector<int>> TIEMPOS_DE_EXPLOTACION = {
    // M1, M2, M3, M4, M5
    {1, 2, 3, 4, 5},  // J1
    {1, 2, 3, 4, 5},  // J2
    {1, 2, 3, 4, 5},  // J3
    {1, 2, 3, 4, 5},  // J4
    {1, 2, 3, 4, 5}   // J5
};


int calcula_la_dolorosa(const std::vector<int>& el_merequetengue) {
    int la_cuenta_final = 0;
    for (int i = 0; i < MAQUINAS_CHAMBEADORAS; ++i) {
        la_cuenta_final += TIEMPOS_DE_EXPLOTACION[el_merequetengue[i]][i];
    }
    return la_cuenta_final;
}


void el_milagrito_de_recocido() {

    double calor_del_momento = 1000.0;
    const double TEMPERATURA_FRESCA = 1.0;
    const double FACTOR_DE_ENFRIAMIENTO_CHIDO = 0.95;
    const int VUELTAS_POR_CALOR = 100;


    unsigned la_semilla_de_la_suerte = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine la_ruleta_de_la_suerte(la_semilla_de_la_suerte);
    std::uniform_real_distribution<double> el_azar(0.0, 1.0);

    std::vector<int> el_merequetengue_actual(TAREAS_A_MAQUILAR);
    std::iota(el_merequetengue_actual.begin(), el_merequetengue_actual.end(), 0); // Rellena con 0, 1, 2, 3, 4
    std::shuffle(el_merequetengue_actual.begin(), el_merequetengue_actual.end(), la_ruleta_de_la_suerte);

    std::vector<int> el_merequetengue_ganador = el_merequetengue_actual;
    int la_dolorosa_actual = calcula_la_dolorosa(el_merequetengue_actual);
    int la_dolorosa_menor = la_dolorosa_actual;

    std::cout << "Asignación inicial: ";
    for (int i = 0; i < MAQUINAS_CHAMBEADORAS; ++i) {
        std::cout << "M" << i + 1 << "->J" << el_merequetengue_actual[i] + 1 << " ";
    }
    std::cout << "(Tiempo total: " << la_dolorosa_actual << ")" << std::endl;

    while (calor_del_momento > TEMPERATURA_FRESCA) {
        for (int i = 0; i < VUELTAS_POR_CALOR; ++i) {

            std::vector<int> el_merequetengue_vecino = el_merequetengue_actual;
            int maquina_escogida1 = la_ruleta_de_la_suerte() % MAQUINAS_CHAMBEADORAS;
            int maquina_escogida2 = la_ruleta_de_la_suerte() % MAQUINAS_CHAMBEADORAS;
            while (maquina_escogida1 == maquina_escogida2) {
                maquina_escogida2 = la_ruleta_de_la_suerte() % MAQUINAS_CHAMBEADORAS;
            }
            std::swap(el_merequetengue_vecino[maquina_escogida1], el_merequetengue_vecino[maquina_escogida2]);

            int la_dolorosa_del_vecino = calcula_la_dolorosa(el_merequetengue_vecino);

            int diferencia_de_costo = la_dolorosa_del_vecino - la_dolorosa_actual;

            if (diferencia_de_costo < 0) {
                el_merequetengue_actual = el_merequetengue_vecino;
                la_dolorosa_actual = la_dolorosa_del_vecino;
                if (la_dolorosa_actual < la_dolorosa_menor) {
                    el_merequetengue_ganador = el_merequetengue_actual;
                    la_dolorosa_menor = la_dolorosa_actual;
                }
            } else {
                double chance_de_aceptar = std::exp(-diferencia_de_costo / calor_del_momento);
                if (el_azar(la_ruleta_de_la_suerte) < chance_de_aceptar) {
                    el_merequetengue_actual = el_merequetengue_vecino;
                    la_dolorosa_actual = la_dolorosa_del_vecino;
                }
            }
        }
        calor_del_momento *= FACTOR_DE_ENFRIAMIENTO_CHIDO;
    }

    std::cout << "\nMejor asignación encontrada: ";
    for (int i = 0; i < MAQUINAS_CHAMBEADORAS; ++i) {
        std::cout << "M" << i + 1 << "->J" << el_merequetengue_ganador[i] + 1 << " ";
    }
    std::cout << "(Tiempo total: " << la_dolorosa_menor << ")" << std::endl;
}

int main() {
    el_milagrito_de_recocido();
    return 0;
}
