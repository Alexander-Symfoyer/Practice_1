from tkinter import*
import math

main = Tk()

def BMI(event):
    x = (float(textbox2.get())/math.pow(float(textbox1.get())/100,2))
    label3.configure(text=f"{x:.2f}")
    if x >= 30:
        label4.configure(text = "Very Fat!")
    elif 30 >= x >= 25:
        label4.configure(text = "Fat!")
    elif 25 >= x >= 23:
        label4.configure(text = "Overweight!")
    elif 23 >= x >= 18.6:
        label4.configure(text = "Normal weight!")
    else:
        label4.configure(text = "Too Thin!")


label1 = Label(main,text="Height (cm)")
label1.grid(row=0,column=0)
textbox1 = Entry(main)
textbox1.grid(row=0,column=1)

label2 = Label(main,text="Weight (kg)")
label2.grid(row=1,column=0)
textbox2 = Entry(main)
textbox2.grid(row=1,column=1)

button= Button(main,text = "Calculate")
button.grid(row=2)
button.bind('<Button-1>',BMI)
label3 = Label(main,text="Result")
label3.grid(row=2,column=1)

label4 = Label(main,text="Result")
label4.grid(row=2,column=2)

main.mainloop()