namespace Pizzeria
{
    partial class DodajZamowienieForm
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
            menuListView = new ListView();
            button1 = new Button();
            zamowienieListView = new ListView();
            button2 = new Button();
            button3 = new Button();
            textBox1 = new TextBox();
            label1 = new Label();
            label2 = new Label();
            Nazwa = new ColumnHeader();
            Opis = new ColumnHeader();
            Rozmiar = new ColumnHeader();
            Cena = new ColumnHeader();
            SuspendLayout();
            // 
            // menuListView
            // 
            menuListView.Columns.AddRange(new ColumnHeader[] { Nazwa, Opis, Rozmiar, Cena });
            menuListView.Location = new Point(12, 12);
            menuListView.Name = "menuListView";
            menuListView.Size = new Size(281, 426);
            menuListView.TabIndex = 0;
            menuListView.UseCompatibleStateImageBehavior = false;
            menuListView.View = View.Details;
            // 
            // button1
            // 
            button1.Location = new Point(299, 12);
            button1.Name = "button1";
            button1.Size = new Size(182, 56);
            button1.TabIndex = 1;
            button1.Text = "Dodaj";
            button1.UseVisualStyleBackColor = true;
            // 
            // zamowienieListView
            // 
            zamowienieListView.Location = new Point(487, 12);
            zamowienieListView.Name = "zamowienieListView";
            zamowienieListView.Size = new Size(281, 426);
            zamowienieListView.TabIndex = 2;
            zamowienieListView.UseCompatibleStateImageBehavior = false;
            // 
            // button2
            // 
            button2.Location = new Point(299, 205);
            button2.Name = "button2";
            button2.Size = new Size(182, 56);
            button2.TabIndex = 3;
            button2.Text = "Usuń";
            button2.UseVisualStyleBackColor = true;
            // 
            // button3
            // 
            button3.Location = new Point(299, 349);
            button3.Name = "button3";
            button3.Size = new Size(182, 89);
            button3.TabIndex = 4;
            button3.Text = "Zatwierdź";
            button3.UseVisualStyleBackColor = true;
            // 
            // textBox1
            // 
            textBox1.Location = new Point(299, 98);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(182, 23);
            textBox1.TabIndex = 5;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(299, 80);
            label1.Name = "label1";
            label1.Size = new Size(64, 15);
            label1.TabIndex = 6;
            label1.Text = "Podaj ilość";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(299, 331);
            label2.Name = "label2";
            label2.Size = new Size(105, 15);
            label2.TabIndex = 7;
            label2.Text = "Całkowita cena: xx";
            // 
            // DodajZamowienieForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(778, 450);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(textBox1);
            Controls.Add(button3);
            Controls.Add(button2);
            Controls.Add(zamowienieListView);
            Controls.Add(button1);
            Controls.Add(menuListView);
            Name = "DodajZamowienieForm";
            Text = "DodajZamowienieForm";
            Load += DodajZamowienieForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ListView menuListView;
        private Button button1;
        private ListView zamowienieListView;
        private Button button2;
        private Button button3;
        private TextBox textBox1;
        private Label label1;
        private Label label2;
        private ColumnHeader Nazwa;
        private ColumnHeader Opis;
        private ColumnHeader Rozmiar;
        private ColumnHeader Cena;
    }
}