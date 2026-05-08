from tkinter import*
import tkinter as tk
from tkinter import font

mainwindow = Tk()

my_font = font.Font(family="Helvetica",size = 15,weight="bold",slant="italic",underline=0,overstrike=1,)
my_font.config(size = 12,weight="normal",underline=1)

print(my_font.cget("family"))


def say():
    print("Hello world")

button1 = Button(mainwindow,text = "Click me",command = say,width = 7,height=1).grid(row=0,column=0)

button2 = Button(mainwindow,text = "Click me",command = say).grid(row=1,column = 1)

label1 = Label(mainwindow,text = "Hello World",width = 15,fg = "magenta",bg = "pink",font=("Helvetica",20),anchor=E).grid(row =1 ,column = 0)

label2 = Label(mainwindow,text = "Hello World",width = 15,fg = "red",bg = "black",font=("Helvetica",30),anchor=W).grid(row =0 ,column = 1)

label3 = Label(mainwindow,text = "You are Awesome!",width = 20,font = my_font,fg = "orange",bg = "yellow").grid(row = 2,column = 0)




mainwindow.mainloop()

