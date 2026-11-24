from tkinter import*

def leftclick(event):
    print("Left Click!")

def rightclick(event):
    print("Right Click!")

def doubleclick(event):
    print("Double click")



main =Tk()

button = Button(main,text="My Button!!",)
button.pack()
button.bind('<Button-1>',leftclick)
button.bind('<Button-3>',rightclick)
button.bind('<Double-1>',doubleclick)

main.mainloop()

