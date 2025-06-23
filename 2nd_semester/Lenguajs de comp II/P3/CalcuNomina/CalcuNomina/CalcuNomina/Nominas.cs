using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CalcuNomina
{
    public class Nominas
    {
        private int diasLaborados;

        public int DiasLaborados {  get; set; }

        public decimal CalcularNomina (int diasLab, decimal valorDia)
        {
            decimal totalSalario = diasLab * valorDia;
            return totalSalario;
        }
    }
}
