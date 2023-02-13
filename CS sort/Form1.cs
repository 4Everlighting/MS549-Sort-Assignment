using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CS_sort
{
    public partial class Form1 : Form
    {
        int[] nums = new int[100];
        Random rand = new Random();

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String strNum1 = " ";
            for (int i = 0; i< 100; i++)
            {
                nums[i] = rand.Next(0, 1000);
                strNum1 = strNum1 + nums[i].ToString() + " ";
                textBox1.Text = strNum1;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Array.Sort(nums);
            String strNum1 = " ";
            for (int i = 0; i < 100; i++)
            {
                nums[i] = rand.Next(0, 1000);
                strNum1 = strNum1 + nums[i].ToString() + " ";
                textBox1.Text = strNum1;
            }

        }
    }
}