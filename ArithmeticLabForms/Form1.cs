using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MyDLL;
namespace ArithmeticLabForms
{
    public partial class Form1 : Form
    {
        Csh_Func func=new Csh_Func();
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String str = func.setExpression(textBox1.Text);
            label3.Text = str;
            for (int i = 0; i < str.Length; i++)
            {
                if((str[i]>='a')&&(str[i] <= 'z'))
                {
                    dataGridView1.Rows.Add(str[i].ToString(), " ");
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
          //  for(int i = 0; i < dataGridView1.Rows.Count; i++)
          //  {
          //        func.Match_Val(dataGridView1.Rows[i].Cells[0].Value, dataGridView1.Rows[i].Cells[1].Value);
          //  }
        }
    }
}
