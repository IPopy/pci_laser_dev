namespace usbCARD
{
     partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.设备ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.打开设备ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.关闭设备ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.tabPage4 = new System.Windows.Forms.TabPage();
            this.buttonIo = new System.Windows.Forms.Button();
            this.out8 = new System.Windows.Forms.CheckBox();
            this.out7 = new System.Windows.Forms.CheckBox();
            this.out6 = new System.Windows.Forms.CheckBox();
            this.out5 = new System.Windows.Forms.CheckBox();
            this.out4 = new System.Windows.Forms.CheckBox();
            this.out3 = new System.Windows.Forms.CheckBox();
            this.out2 = new System.Windows.Forms.CheckBox();
            this.out1 = new System.Windows.Forms.CheckBox();
            this.in8 = new System.Windows.Forms.CheckBox();
            this.in7 = new System.Windows.Forms.CheckBox();
            this.in6 = new System.Windows.Forms.CheckBox();
            this.in5 = new System.Windows.Forms.CheckBox();
            this.in4 = new System.Windows.Forms.CheckBox();
            this.in3 = new System.Windows.Forms.CheckBox();
            this.in2 = new System.Windows.Forms.CheckBox();
            this.in1 = new System.Windows.Forms.CheckBox();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.freqad = new System.Windows.Forms.NumericUpDown();
            this.label20 = new System.Windows.Forms.Label();
            this.numad = new System.Windows.Forms.NumericUpDown();
            this.label19 = new System.Windows.Forms.Label();
            this.label17 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.button2 = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.textBox6 = new System.Windows.Forms.TextBox();
            this.textBox7 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox0 = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.menuStrip1.SuspendLayout();
            this.tabPage4.SuspendLayout();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.freqad)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numad)).BeginInit();
            this.tabPage1.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.设备ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(874, 25);
            this.menuStrip1.TabIndex = 3;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 设备ToolStripMenuItem
            // 
            this.设备ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.打开设备ToolStripMenuItem,
            this.关闭设备ToolStripMenuItem});
            this.设备ToolStripMenuItem.Name = "设备ToolStripMenuItem";
            this.设备ToolStripMenuItem.Size = new System.Drawing.Size(44, 21);
            this.设备ToolStripMenuItem.Text = "设备";
            // 
            // 打开设备ToolStripMenuItem
            // 
            this.打开设备ToolStripMenuItem.Name = "打开设备ToolStripMenuItem";
            this.打开设备ToolStripMenuItem.Size = new System.Drawing.Size(124, 22);
            this.打开设备ToolStripMenuItem.Text = "打开设备";
            this.打开设备ToolStripMenuItem.Click += new System.EventHandler(this.打开设备ToolStripMenuItem_Click);
            // 
            // 关闭设备ToolStripMenuItem
            // 
            this.关闭设备ToolStripMenuItem.Name = "关闭设备ToolStripMenuItem";
            this.关闭设备ToolStripMenuItem.Size = new System.Drawing.Size(124, 22);
            this.关闭设备ToolStripMenuItem.Text = "关闭设备";
            this.关闭设备ToolStripMenuItem.Click += new System.EventHandler(this.关闭设备ToolStripMenuItem_Click);
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // tabPage4
            // 
            this.tabPage4.Controls.Add(this.buttonIo);
            this.tabPage4.Controls.Add(this.out8);
            this.tabPage4.Controls.Add(this.out7);
            this.tabPage4.Controls.Add(this.out6);
            this.tabPage4.Controls.Add(this.out5);
            this.tabPage4.Controls.Add(this.out4);
            this.tabPage4.Controls.Add(this.out3);
            this.tabPage4.Controls.Add(this.out2);
            this.tabPage4.Controls.Add(this.out1);
            this.tabPage4.Controls.Add(this.in8);
            this.tabPage4.Controls.Add(this.in7);
            this.tabPage4.Controls.Add(this.in6);
            this.tabPage4.Controls.Add(this.in5);
            this.tabPage4.Controls.Add(this.in4);
            this.tabPage4.Controls.Add(this.in3);
            this.tabPage4.Controls.Add(this.in2);
            this.tabPage4.Controls.Add(this.in1);
            this.tabPage4.Location = new System.Drawing.Point(4, 22);
            this.tabPage4.Name = "tabPage4";
            this.tabPage4.Size = new System.Drawing.Size(837, 260);
            this.tabPage4.TabIndex = 3;
            this.tabPage4.Text = "IO";
            this.tabPage4.UseVisualStyleBackColor = true;
            // 
            // buttonIo
            // 
            this.buttonIo.Location = new System.Drawing.Point(338, 192);
            this.buttonIo.Name = "buttonIo";
            this.buttonIo.Size = new System.Drawing.Size(75, 23);
            this.buttonIo.TabIndex = 16;
            this.buttonIo.Text = "读写IO";
            this.buttonIo.UseVisualStyleBackColor = true;
            this.buttonIo.Click += new System.EventHandler(this.buttonIo_Click);
            // 
            // out8
            // 
            this.out8.AutoSize = true;
            this.out8.Location = new System.Drawing.Point(725, 128);
            this.out8.Name = "out8";
            this.out8.Size = new System.Drawing.Size(48, 16);
            this.out8.TabIndex = 15;
            this.out8.Text = "out8";
            this.out8.UseVisualStyleBackColor = true;
            // 
            // out7
            // 
            this.out7.AutoSize = true;
            this.out7.Location = new System.Drawing.Point(641, 128);
            this.out7.Name = "out7";
            this.out7.Size = new System.Drawing.Size(48, 16);
            this.out7.TabIndex = 14;
            this.out7.Text = "out7";
            this.out7.UseVisualStyleBackColor = true;
            // 
            // out6
            // 
            this.out6.AutoSize = true;
            this.out6.Location = new System.Drawing.Point(557, 128);
            this.out6.Name = "out6";
            this.out6.Size = new System.Drawing.Size(48, 16);
            this.out6.TabIndex = 13;
            this.out6.Text = "out6";
            this.out6.UseVisualStyleBackColor = true;
            // 
            // out5
            // 
            this.out5.AutoSize = true;
            this.out5.Location = new System.Drawing.Point(457, 128);
            this.out5.Name = "out5";
            this.out5.Size = new System.Drawing.Size(48, 16);
            this.out5.TabIndex = 12;
            this.out5.Text = "out5";
            this.out5.UseVisualStyleBackColor = true;
            // 
            // out4
            // 
            this.out4.AutoSize = true;
            this.out4.Location = new System.Drawing.Point(358, 128);
            this.out4.Name = "out4";
            this.out4.Size = new System.Drawing.Size(48, 16);
            this.out4.TabIndex = 11;
            this.out4.Text = "out4";
            this.out4.UseVisualStyleBackColor = true;
            // 
            // out3
            // 
            this.out3.AutoSize = true;
            this.out3.Location = new System.Drawing.Point(255, 128);
            this.out3.Name = "out3";
            this.out3.Size = new System.Drawing.Size(48, 16);
            this.out3.TabIndex = 10;
            this.out3.Text = "out3";
            this.out3.UseVisualStyleBackColor = true;
            // 
            // out2
            // 
            this.out2.AutoSize = true;
            this.out2.Location = new System.Drawing.Point(158, 128);
            this.out2.Name = "out2";
            this.out2.Size = new System.Drawing.Size(48, 16);
            this.out2.TabIndex = 9;
            this.out2.Text = "out2";
            this.out2.UseVisualStyleBackColor = true;
            // 
            // out1
            // 
            this.out1.AutoSize = true;
            this.out1.Location = new System.Drawing.Point(58, 128);
            this.out1.Name = "out1";
            this.out1.Size = new System.Drawing.Size(48, 16);
            this.out1.TabIndex = 8;
            this.out1.Text = "out1";
            this.out1.UseVisualStyleBackColor = true;
            // 
            // in8
            // 
            this.in8.AutoSize = true;
            this.in8.Location = new System.Drawing.Point(725, 51);
            this.in8.Name = "in8";
            this.in8.Size = new System.Drawing.Size(42, 16);
            this.in8.TabIndex = 7;
            this.in8.Text = "in8";
            this.in8.UseVisualStyleBackColor = true;
            // 
            // in7
            // 
            this.in7.AutoSize = true;
            this.in7.Location = new System.Drawing.Point(641, 51);
            this.in7.Name = "in7";
            this.in7.Size = new System.Drawing.Size(42, 16);
            this.in7.TabIndex = 6;
            this.in7.Text = "in7";
            this.in7.UseVisualStyleBackColor = true;
            // 
            // in6
            // 
            this.in6.AutoSize = true;
            this.in6.Location = new System.Drawing.Point(557, 51);
            this.in6.Name = "in6";
            this.in6.Size = new System.Drawing.Size(42, 16);
            this.in6.TabIndex = 5;
            this.in6.Text = "in6";
            this.in6.UseVisualStyleBackColor = true;
            // 
            // in5
            // 
            this.in5.AutoSize = true;
            this.in5.Location = new System.Drawing.Point(457, 51);
            this.in5.Name = "in5";
            this.in5.Size = new System.Drawing.Size(42, 16);
            this.in5.TabIndex = 4;
            this.in5.Text = "in5";
            this.in5.UseVisualStyleBackColor = true;
            // 
            // in4
            // 
            this.in4.AutoSize = true;
            this.in4.Location = new System.Drawing.Point(358, 51);
            this.in4.Name = "in4";
            this.in4.Size = new System.Drawing.Size(42, 16);
            this.in4.TabIndex = 3;
            this.in4.Text = "in4";
            this.in4.UseVisualStyleBackColor = true;
            // 
            // in3
            // 
            this.in3.AutoSize = true;
            this.in3.Location = new System.Drawing.Point(255, 51);
            this.in3.Name = "in3";
            this.in3.Size = new System.Drawing.Size(42, 16);
            this.in3.TabIndex = 2;
            this.in3.Text = "in3";
            this.in3.UseVisualStyleBackColor = true;
            // 
            // in2
            // 
            this.in2.AutoSize = true;
            this.in2.Location = new System.Drawing.Point(158, 51);
            this.in2.Name = "in2";
            this.in2.Size = new System.Drawing.Size(42, 16);
            this.in2.TabIndex = 1;
            this.in2.Text = "in2";
            this.in2.UseVisualStyleBackColor = true;
            // 
            // in1
            // 
            this.in1.AutoSize = true;
            this.in1.Location = new System.Drawing.Point(57, 51);
            this.in1.Name = "in1";
            this.in1.Size = new System.Drawing.Size(42, 16);
            this.in1.TabIndex = 0;
            this.in1.Text = "in1";
            this.in1.UseVisualStyleBackColor = true;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.freqad);
            this.tabPage2.Controls.Add(this.label20);
            this.tabPage2.Controls.Add(this.numad);
            this.tabPage2.Controls.Add(this.label19);
            this.tabPage2.Controls.Add(this.label17);
            this.tabPage2.Controls.Add(this.button1);
            this.tabPage2.Controls.Add(this.richTextBox1);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(837, 260);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "连续采集";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // freqad
            // 
            this.freqad.Location = new System.Drawing.Point(550, 233);
            this.freqad.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.freqad.Minimum = new decimal(new int[] {
            100,
            0,
            0,
            0});
            this.freqad.Name = "freqad";
            this.freqad.Size = new System.Drawing.Size(84, 21);
            this.freqad.TabIndex = 9;
            this.freqad.Value = new decimal(new int[] {
            100,
            0,
            0,
            0});
            // 
            // label20
            // 
            this.label20.AutoSize = true;
            this.label20.Location = new System.Drawing.Point(484, 234);
            this.label20.Name = "label20";
            this.label20.Size = new System.Drawing.Size(65, 12);
            this.label20.TabIndex = 8;
            this.label20.Text = "采样频率：";
            // 
            // numad
            // 
            this.numad.Location = new System.Drawing.Point(370, 234);
            this.numad.Maximum = new decimal(new int[] {
            100000000,
            0,
            0,
            0});
            this.numad.Minimum = new decimal(new int[] {
            512,
            0,
            0,
            0});
            this.numad.Name = "numad";
            this.numad.Size = new System.Drawing.Size(90, 21);
            this.numad.TabIndex = 7;
            this.numad.Value = new decimal(new int[] {
            512,
            0,
            0,
            0});
            // 
            // label19
            // 
            this.label19.AutoSize = true;
            this.label19.Location = new System.Drawing.Point(312, 235);
            this.label19.Name = "label19";
            this.label19.Size = new System.Drawing.Size(53, 12);
            this.label19.TabIndex = 6;
            this.label19.Text = "采样数：";
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Location = new System.Drawing.Point(71, 225);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(0, 12);
            this.label17.TabIndex = 2;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(684, 231);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 1;
            this.button1.Text = "采集";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(27, 18);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.Size = new System.Drawing.Size(781, 192);
            this.richTextBox1.TabIndex = 0;
            this.richTextBox1.Text = "";
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.button2);
            this.tabPage1.Controls.Add(this.label5);
            this.tabPage1.Controls.Add(this.textBox4);
            this.tabPage1.Controls.Add(this.textBox5);
            this.tabPage1.Controls.Add(this.textBox6);
            this.tabPage1.Controls.Add(this.textBox7);
            this.tabPage1.Controls.Add(this.textBox3);
            this.tabPage1.Controls.Add(this.textBox2);
            this.tabPage1.Controls.Add(this.textBox1);
            this.tabPage1.Controls.Add(this.textBox0);
            this.tabPage1.Controls.Add(this.label6);
            this.tabPage1.Controls.Add(this.label7);
            this.tabPage1.Controls.Add(this.label8);
            this.tabPage1.Controls.Add(this.label4);
            this.tabPage1.Controls.Add(this.label3);
            this.tabPage1.Controls.Add(this.label2);
            this.tabPage1.Controls.Add(this.label1);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(837, 260);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "单次单端模式采集";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(329, 220);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 32;
            this.button2.Text = "采集";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(553, 150);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(23, 12);
            this.label5.TabIndex = 15;
            this.label5.Text = "AD7";
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(78, 147);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(100, 21);
            this.textBox4.TabIndex = 14;
            // 
            // textBox5
            // 
            this.textBox5.Location = new System.Drawing.Point(258, 147);
            this.textBox5.Name = "textBox5";
            this.textBox5.Size = new System.Drawing.Size(100, 21);
            this.textBox5.TabIndex = 12;
            // 
            // textBox6
            // 
            this.textBox6.Location = new System.Drawing.Point(424, 147);
            this.textBox6.Name = "textBox6";
            this.textBox6.Size = new System.Drawing.Size(100, 21);
            this.textBox6.TabIndex = 10;
            // 
            // textBox7
            // 
            this.textBox7.Location = new System.Drawing.Point(596, 147);
            this.textBox7.Name = "textBox7";
            this.textBox7.Size = new System.Drawing.Size(100, 21);
            this.textBox7.TabIndex = 8;
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(596, 55);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(100, 21);
            this.textBox3.TabIndex = 6;
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(424, 55);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(100, 21);
            this.textBox2.TabIndex = 4;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(258, 55);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 21);
            this.textBox1.TabIndex = 2;
            // 
            // textBox0
            // 
            this.textBox0.Location = new System.Drawing.Point(78, 55);
            this.textBox0.Name = "textBox0";
            this.textBox0.Size = new System.Drawing.Size(100, 21);
            this.textBox0.TabIndex = 0;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(381, 150);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(23, 12);
            this.label6.TabIndex = 13;
            this.label6.Text = "AD6";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(215, 150);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(23, 12);
            this.label7.TabIndex = 11;
            this.label7.Text = "AD5";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(35, 150);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(23, 12);
            this.label8.TabIndex = 9;
            this.label8.Text = "AD4";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(553, 58);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(23, 12);
            this.label4.TabIndex = 7;
            this.label4.Text = "AD3";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(381, 58);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(23, 12);
            this.label3.TabIndex = 5;
            this.label3.Text = "AD2";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(215, 58);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(23, 12);
            this.label2.TabIndex = 3;
            this.label2.Text = "AD1";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(35, 55);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(23, 12);
            this.label1.TabIndex = 1;
            this.label1.Text = "AD0";
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage4);
            this.tabControl1.Location = new System.Drawing.Point(17, 28);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(845, 286);
            this.tabControl1.TabIndex = 2;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(874, 314);
            this.Controls.Add(this.tabControl1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.tabPage4.ResumeLayout(false);
            this.tabPage4.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.freqad)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numad)).EndInit();
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.tabControl1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
         private System.Windows.Forms.ToolStripMenuItem 设备ToolStripMenuItem;
         private System.Windows.Forms.ToolStripMenuItem 打开设备ToolStripMenuItem;
         private System.Windows.Forms.ToolStripMenuItem 关闭设备ToolStripMenuItem;
         private System.Windows.Forms.Timer timer1;
         private System.Windows.Forms.TabPage tabPage4;
         private System.Windows.Forms.Button buttonIo;
         private System.Windows.Forms.CheckBox out8;
         private System.Windows.Forms.CheckBox out7;
         private System.Windows.Forms.CheckBox out6;
         private System.Windows.Forms.CheckBox out5;
         private System.Windows.Forms.CheckBox out4;
         private System.Windows.Forms.CheckBox out3;
         private System.Windows.Forms.CheckBox out2;
         private System.Windows.Forms.CheckBox out1;
         private System.Windows.Forms.CheckBox in8;
         private System.Windows.Forms.CheckBox in7;
         private System.Windows.Forms.CheckBox in6;
         private System.Windows.Forms.CheckBox in5;
         private System.Windows.Forms.CheckBox in4;
         private System.Windows.Forms.CheckBox in3;
         private System.Windows.Forms.CheckBox in2;
         private System.Windows.Forms.CheckBox in1;
         private System.Windows.Forms.TabPage tabPage2;
         private System.Windows.Forms.NumericUpDown freqad;
         private System.Windows.Forms.Label label20;
         private System.Windows.Forms.NumericUpDown numad;
         private System.Windows.Forms.Label label19;
         private System.Windows.Forms.Label label17;
         private System.Windows.Forms.Button button1;
         private System.Windows.Forms.RichTextBox richTextBox1;
         private System.Windows.Forms.TabPage tabPage1;
         private System.Windows.Forms.Button button2;
         private System.Windows.Forms.Label label5;
         private System.Windows.Forms.TextBox textBox4;
         private System.Windows.Forms.TextBox textBox5;
         private System.Windows.Forms.TextBox textBox6;
         private System.Windows.Forms.TextBox textBox7;
         private System.Windows.Forms.TextBox textBox3;
         private System.Windows.Forms.TextBox textBox2;
         private System.Windows.Forms.TextBox textBox1;
         private System.Windows.Forms.TextBox textBox0;
         private System.Windows.Forms.Label label6;
         private System.Windows.Forms.Label label7;
         private System.Windows.Forms.Label label8;
         private System.Windows.Forms.Label label4;
         private System.Windows.Forms.Label label3;
         private System.Windows.Forms.Label label2;
         private System.Windows.Forms.Label label1;
         private System.Windows.Forms.TabControl tabControl1;
    }
}

