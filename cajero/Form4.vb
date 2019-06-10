Imports System.Data.OleDb

Public Class Form4
    Dim CN As New OleDbConnection
    Sub modificar()
        Dim cmd As New OleDb.OleDbCommand("update Tabla1 set saldo='" & Form1.TextBox2.Text & "' where clave = '" & Form1.TextBox1.Text & "'", CN)
        CN.Open()
        cmd.ExecuteNonQuery()
        CN.Close()
        MsgBox("usted recibio")

    End Sub
    Private Sub Form4_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        CN.ConnectionString = "provider= microsoft.ace.oledb.12.0;data source=|datadirectory|\base1.accdb"
    End Sub

    Private Sub Button21_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button21.Click
        If Val(Form1.TextBox2.Text) < Val(TextBox1.Text) Then
            MsgBox("Usted no cuenta con fondos suficientes")
        Else
            'Form1.TextBox2.Text = Val(Form1.TextBox2.Text) / 200
            Form1.TextBox2.Text = Val(Form1.TextBox2.Text) - Val(TextBox1.Text)
            Call modificar()
        End If
    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        Form2.Show()
        Close()
    End Sub

    Private Sub Button20_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button20.Click
        TextBox1.Text = TextBox1.Text & "1"
    End Sub

    Private Sub Button19_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button19.Click
        TextBox1.Text = TextBox1.Text & "2"
    End Sub

    Private Sub Button18_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button18.Click
        TextBox1.Text = TextBox1.Text & "3"
    End Sub

    Private Sub Button17_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button17.Click
        TextBox1.Text = TextBox1.Text & "4"
    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click
        TextBox1.Text = TextBox1.Text & "5"
    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        TextBox1.Text = TextBox1.Text & "6"
    End Sub

    Private Sub Button9_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button9.Click
        TextBox1.Text = TextBox1.Text & "7"
    End Sub

    Private Sub Button8_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button8.Click
        TextBox1.Text = TextBox1.Text & "8"
    End Sub

    Private Sub Button7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button7.Click
        TextBox1.Text = TextBox1.Text & "9"
    End Sub

    Private Sub Button11_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button11.Click
        TextBox1.Text = TextBox1.Text & "0"
    End Sub

    Private Sub Button14_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button14.Click
        TextBox1.Text = ""
    End Sub
    Protected Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load
        Label5.Text = DateTime.Now.ToString("dd/MM/yyyy")
        Label6.Text = DateTime.Now.ToShortTimeString()
    End Sub

    Private Sub Button16_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button16.Click
        TextBox1.Text = TextBox1.Text.Substring(0, TextBox1.Text.Count() - 1)
    End Sub

    Private Sub Button13_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button13.Click
        If Val(Form1.TextBox2.Text) < Val(TextBox1.Text) Or Val(Form1.TextBox2.Text)= Then
            MsgBox("Usted no cuenta con fondos suficientes")
        Else
            Form1.TextBox2.Text = Val(Form1.TextBox2.Text) - Val(TextBox1.Text)
            Call modificar()
        End If
    End Sub



End Class