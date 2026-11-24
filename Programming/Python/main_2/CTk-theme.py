import customtkinter as ctk

ctk.set_appearance_mode("light")
ctk.set_default_color_theme("green")

app = ctk.CTk()
app.title("GEEyah!")
app.geometry("400x300")

def toggle_mode():
    current = ctk.get_appearance_mode()
    new_mode = "dark" if current == "Light" else "light"
    ctk.set_appearance_mode(new_mode)
    label.configure(text=f"Current mode: {new_mode.title()}")

label = ctk.CTkLabel(app, text="Current mode: Light")
label.pack(pady=20)

switch = ctk.CTkSwitch(app, text="Toggle Mode", command=toggle_mode)
switch.pack(pady=10)
















app.mainloop()