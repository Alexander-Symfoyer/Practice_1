import customtkinter as ctk

ctk.set_appearance_mode("light")
ctk.set_default_color_theme("dark-blue")

app = ctk.CTk()
app.title("GEEyah!")
app.geometry("200x200")

def show_name():
    name = entry.get()
    print(f"Hello {name}!")

def enter(event):
    print("Enter!")

def spacebar(event):
    print("Space!")

def up(event):
    print("Up!")

def down(event):
    print("Down!")

entry = ctk.CTkEntry(app, placeholder_text="Enter a name")
entry.pack(pady=10)

button1 = ctk.CTkButton(app, text="Show name", command=show_name)
button1.pack(pady=10)

button2 = ctk.CTkButton(app, text="Clear", command=lambda: entry.delete(0,"end"))
button2.pack(pady=10)





app.bind("<Down>", down)
app.bind("<Up>", up)
app.bind("<space>", spacebar)
app.bind("<Return>", enter)

app.mainloop()