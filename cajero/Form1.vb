Imports System.Data.OleDb


Public Class Form1
    Dim cn As New OleDb.OleDbConnection("provider= microsoft.ace.oledb.12.0;data source=|datadirectory|\base1.accdb")
    Public Function ask()
        Dim dt As New DataTable
        Dim ds As New DataSet
        ds.Tables.Add(dt)
        cn.Open()
        Dim da As New OleDbDataAdapter("select * from Tabla1", cn)
        da.Fill(dt)
        For Each DataRow In dt.Rows
            If TextBox1.Text = DataRow(0) Then
                cn.Close()
                Return True

            End If
        Next
        cn.Close()
        Return False
    End Function
    Sub buscar()
        Dim CMD As New OleDb.OleDbCommand("select * from Tabla1 where clave='" & TextBox1.Text & "'", cn)
        Dim dr As OleDb.OleDbDataReader
        cn.Open()
        dr = CMD.ExecuteReader
        If dr.Read Then
            TextBox2.Text = dr(1)
        Else
            MsgBox("Error el PIN es incorrecto")
        End If
        cn.Close()
    End Sub


    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        TextBox1.Text = TextBox1.Text & "1"
    End Sub
    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        TextBox1.Text = TextBox1.Text & "2"
    End Sub
    Private Sub Button3_Click_1(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        TextBox1.Text = TextBox1.Text & "3"
    End Sub
    Private Sub Button6_Click_1(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click
        TextBox1.Text = TextBox1.Text & "4"
    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        TextBox1.Text = TextBox1.Text & "5"
    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
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

    Private Sub Button13_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button13.Click
        Call buscar()
        If ask() = True Then
            Form2.Show()
            Hide()
            'Else
            ' MsgBox("ERROR")
        End If
    End Sub
    Protected Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load
        Label5.Text = DateTime.Now.ToString("dd/MM/yyyy")
        Label4.Text = DateTime.Now.ToShortTimeString()
    End Sub

    Private Sub Button16_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button16.Click
        TextBox1.Text = TextBox1.Text.Substring(0, TextBox1.Text.Count() - 1)
    End Sub
End Class
