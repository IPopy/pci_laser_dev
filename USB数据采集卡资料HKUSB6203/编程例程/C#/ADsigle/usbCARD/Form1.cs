using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;



namespace usbCARD
{
    
    public partial class Form1 : Form
    {
        

[DllImport("./Usb_Daq_V52_Dll.dll")]  
       static extern  int openUSB();
[DllImport("./Usb_Daq_V52_Dll.dll")]  
       static extern  void closeUSB();
[DllImport("./Usb_Daq_V52_Dll.dll")]   
       static extern  void Reset();
[DllImport("./Usb_Daq_V52_Dll.dll")]  
       static extern  int get_device_num();

[DllImport("./Usb_Daq_V52_Dll.dll")]  
       static extern  int ad_single(int dev,int ad_os,int ad_range,float[]  databuf);
[DllImport("./Usb_Daq_V52_Dll.dll")]
        static extern int ad_continu_conf(int dev, int ad_os, int ad_range, int freq, int trig_sl, int trig_pol, int clk_sl, int ext_clk_pol);
[DllImport("./Usb_Daq_V52_Dll.dll")] 
      static extern   int Get_AdBuf_Size(int dev); 
[DllImport("./Usb_Daq_V52_Dll.dll")]
        static extern int Read_AdBuf(int dev, ref float[] databuf, int num);
[DllImport("./Usb_Daq_V52_Dll.dll")] 
      static extern   int AD_continu_stop(int dev);
[DllImport("./Usb_Daq_V52_Dll.dll")]
        static extern int ad_continu(int dev, int ad_os, int ad_range, int freq, int trig_sl, int trig_pol, int clk_sl, int ext_clk_pol, int num, float[] databuf);

[DllImport("./Usb_Daq_V52_Dll.dll")]
        static extern int Read_Port_In(int dev, ref  ushort in_port);
[DllImport("./Usb_Daq_V52_Dll.dll")]
        static extern int Read_Port_Out(int dev, ref ushort out_port);


[DllImport("./Usb_Daq_V52_Dll.dll")]
        static extern int Write_Port_Out(int dev, ushort out_port);
[DllImport("./Usb_Daq_V52_Dll.dll")]
        static extern int Set_Port_Out(int dev, ushort out_port); 
[DllImport("./Usb_Daq_V52_Dll.dll")]
        static extern int Reset_Port_Out(int dev, ushort out_port);
[DllImport("./Usb_Daq_V52_Dll.dll")]
        static extern int Write_Port_OutL(int dev, Byte out_port);
[DllImport("./Usb_Daq_V52_Dll.dll")]
        static extern int Write_Port_OutH(int dev, Byte out_port);


        public Form1()

        {
            InitializeComponent();
        }



        int usb_open = 0;

        private void button1_Click(object sender, EventArgs e)
        {
            int  num,  freq;
           
         
            num = (int)numad.Value;
            freq = (int)freqad.Value;
             
            unsafe
            {
                //short* databuf;
               // double* adv;
                string str = "";

                float[] Buf = new float[num * 8];
              //  fixed (float* databuf = Buf)
              //  {
                ad_continu(0,0,0, freq,0,0,0,0,num, Buf);
                    double vv;
                    for (int j = 0; j <8; j++)
                    {
                        str +="第" +j.ToString() +"通道数据："+ "\n";
                        for (int i = 0; i < num; i++)
                        {

                            vv = Buf[i*8+j];
                            str += vv.ToString() + "\n";

                        }
                 //   }
                richTextBox1.Text = str;
                }
            }
               
        }

        private void button2_Click(object sender, EventArgs e)
        {
             
            float[] adResult= new float[8];
            int erro = 0;
            erro = ad_single(0, 0, 0, adResult);
            if (erro == 0)
            {
                textBox0.Text = Convert.ToString(adResult[0]);
                textBox1.Text = Convert.ToString(adResult[1]);
                textBox2.Text = Convert.ToString(adResult[2]);
                textBox3.Text = Convert.ToString(adResult[3]);
                textBox4.Text = Convert.ToString(adResult[4]);
                textBox5.Text = Convert.ToString(adResult[5]);
                textBox6.Text = Convert.ToString(adResult[6]);
                textBox7.Text = Convert.ToString(adResult[7]);

            }
            else
            {
                textBox7.Text = Convert.ToString( 0);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
           
          
            numad.Value=1024;
             freqad.Value=10000;
             关闭设备ToolStripMenuItem.Enabled = false;
        }

       

      

        private void 打开设备ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (usb_open == 0)
            {
                openUSB();
                
                usb_open = 1;
                关闭设备ToolStripMenuItem.Enabled = true;
                打开设备ToolStripMenuItem.Enabled = false;
            }
        }

        private void 关闭设备ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (usb_open == 1)
            {
                closeUSB();
                usb_open = 0;
                关闭设备ToolStripMenuItem.Enabled = false;
                打开设备ToolStripMenuItem.Enabled = true;
            }
        }

        private void buttonIo_Click(object sender, EventArgs e)
        {
            ushort io_in = 0;
            Read_Port_In(0, ref io_in);
            if ((io_in & 0x01) != 0)
            {
                in1.Checked = true;
            }
            else
            {
                in1.Checked = false;
            }

            if ((io_in & 0x02) != 0)
            {
                in2.Checked = true;
            }
            else
            {
                in2.Checked = false;
            }
            if ((io_in & 0x04) != 0)
            {
                in3.Checked = true;
            }
            else
            {
                in3.Checked = false;
            }
            if ((io_in & 0x08) != 0)
            {
                in4.Checked = true;
            }
            else
            {
                in4.Checked = false;
            }
            if ((io_in & 0x10 )!= 0)
            {
                in5.Checked = true;
            }
            else
            {
                in5.Checked = false;
            }
            if ((io_in & 0x20 )!= 0)
            {
                in6.Checked = true;
            }
            else
            {
                in6.Checked = false;
            }
            if ((io_in & 0x40 )!= 0)
            {
                in7.Checked = true;
            }
            else
            {
                in7.Checked = false;
            }
            if ((io_in & 0x80) != 0)
            {
                in8.Checked = true;
            }
            else
            {
                in8.Checked = false;
            }

           
            if(out1.Checked)
            {
                Set_Port_Out(0, (ushort)0x1);
            }
            else
            {
                Reset_Port_Out(0, (ushort)0x1);
            }
            if (out2.Checked)
            {
                Set_Port_Out(0, (ushort)0x1 << 1);
            }
            else
            {
                Reset_Port_Out(0, (ushort)0x1 << 1);
            }
            if (out3.Checked)
            {
                Set_Port_Out(0, (ushort)0x1 << 2);
            }
            else
            {
                Reset_Port_Out(0, (ushort)0x1 << 2);
            }
            if (out4.Checked)
            {
                Set_Port_Out(0, (ushort)0x1 << 3);
            }
            else
            {
                Reset_Port_Out(0, (ushort)0x1 << 3);
            }
            if (out5.Checked)
            {
                Set_Port_Out(0, (ushort)0x1 << 4);
            }
            else
            {
                Reset_Port_Out(0, (ushort)0x1 << 4);
            }
            if (out6.Checked)
            {
                Set_Port_Out(0, (ushort)0x1 << 5);
            }
            else
            {
                Reset_Port_Out(0, (ushort)0x1 << 5);
            }
            if (out7.Checked)
            {
                Set_Port_Out(0, (ushort)0x1 << 6);
            }
            else
            {
                Reset_Port_Out(0, (ushort)0x1 << 6);
            }
            if (out8.Checked)
            {
                Set_Port_Out(0, (ushort)0x1 << 7);
            }
            else
            {
                Reset_Port_Out(0, (ushort)0x1 << 7);
            }
        }


        private void timer1_Tick(object sender, EventArgs e)
        {

        }

    }
}