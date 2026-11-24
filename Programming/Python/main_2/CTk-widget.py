import customtkinter as ctk

def say():
    name = entry.get()
    label.configure(text=f"Boombayahhhh  {name}!!")


app = ctk.CTk()
app.title("GEEyah!")
app.geometry("600x600")

label = ctk.CTkLabel(app, text="Welcomeee!!!")
label.pack(pady=20)

entry = ctk.CTkEntry(app, placeholder_text="Enter a name")
entry.pack(pady=10)

button = ctk.CTkButton(app, text = "Process", command = say)
button.pack(pady=10)

check = ctk.CTkCheckBox(app ,text = "Comfirm")
check.pack(pady=10)

switch = ctk.CTkSwitch(app ,text = "Light mode/Dark mode")
switch.pack(pady=10)









































app.mainloop()
