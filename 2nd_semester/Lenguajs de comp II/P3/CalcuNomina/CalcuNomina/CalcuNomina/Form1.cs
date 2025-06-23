using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CalcuNomina
{
    public partial class Form1 : Form
    {
        Empleados myEmpleado = new Empleados();
        Nominas myNomina = new Nominas();
        public Form1()
        {
            InitializeComponent();
        }

        private void gunaAdvenceButton3_Click(object sender, EventArgs e)
        {
            gunaTextBox1.Clear();
            gunaTextBox2.Clear();
            gunaTextBox3.Clear();
            gunaTextBox4.Clear();
            gunaTextBox5.Clear();
        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void gunaControlBox1_Click(object sender, EventArgs e)
        {

        }

        private void gunaAdvenceButton4_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void gunaAdvenceButton1_Click(object sender, EventArgs e)
        {
            if(gunaTextBox1.Text == "")
            {
                error1.SetError(gunaTextBox1, "Debe ingresar un nombre");
                gunaTextBox1.Focus();
                return;
            }
            error1.SetError(gunaTextBox1, "");

            decimal AsignacionDia;
            if(!decimal.TryParse(gunaTextBox3.Text, out AsignacionDia))
            {
                error1.SetError(gunaTextBox3, "Debe ingresar un numero");
                gunaTextBox3.Focus();
                return;
            }
            myEmpleado.Nombre = gunaTextBox1.Text;
            myEmpleado.Identificacion = gunaTextBox2.Text;
            myEmpleado.AsignacionDia = Convert.ToDecimal(gunaTextBox3.Text);
            myNomina.DiasLaborados = Convert.ToInt32(gunaTextBox4.Text);
            MessageBox.Show("Se guardo el registro correctamente");
        }

        private void gunaAdvenceButton2_Click(object sender, EventArgs e)
        {
            gunaTextBox5.Text = myNomina.CalcularNomina(Convert.ToInt32(myNomina.DiasLaborados), Convert.ToDecimal(myEmpleado.AsignacionDia)).ToString();
        }
    }
}
