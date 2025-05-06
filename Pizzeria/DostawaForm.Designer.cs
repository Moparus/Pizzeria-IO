namespace Pizzeria
{
    partial class DostawaForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            button1 = new Button();
            listView1 = new ListView();
            listBox1 = new ListBox();
            SuspendLayout();
            // 
            // button1
            // 
            button1.Location = new Point(12, 645);
            button1.Name = "button1";
            button1.Size = new Size(625, 79);
            button1.TabIndex = 4;
            button1.Text = "Zatwierdź";
            button1.UseVisualStyleBackColor = true;
            // 
            // listView1
            // 
            listView1.Location = new Point(12, 12);
            listView1.Name = "listView1";
            listView1.Size = new Size(625, 569);
            listView1.TabIndex = 3;
            listView1.UseCompatibleStateImageBehavior = false;
            // 
            // listBox1
            // 
            listBox1.FormattingEnabled = true;
            listBox1.ItemHeight = 15;
            listBox1.Location = new Point(12, 587);
            listBox1.Name = "listBox1";
            listBox1.Size = new Size(625, 49);
            listBox1.TabIndex = 5;
            // 
            // Dostawa
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(650, 736);
            Controls.Add(listBox1);
            Controls.Add(button1);
            Controls.Add(listView1);
            Name = "Dostawa";
            Text = "Dostawa";
            ResumeLayout(false);
        }

        #endregion
        private Button button1;
        private ListView listView1;
        private ListBox listBox1;
    }
}