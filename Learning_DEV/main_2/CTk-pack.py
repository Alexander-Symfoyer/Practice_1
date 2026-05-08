import customtkinter as ctk

app = ctk.CTk()
app.title("GEEyah!")
app.geometry("400x600")

frame = ctk.CTkFrame(app)
frame.pack(fill = "both", expand = True, padx = 10, pady = 10)

label1 = ctk.CTkLabel(app, text="Username")
label1.pack(side="top",pady=5)

entry1 = ctk.CTkEntry(app, placeholder_text="Username")
entry1.pack(pady=5)

label2 = ctk.CTkLabel(app, text="Password")
label2.pack(side="top",pady=5)

entry2 = ctk.CTkEntry(app, placeholder_text="Password")
entry2.pack(pady=5)

button1 = ctk.CTkButton(app, text="Login")
button1.pack(pady=20,side="bottom")





app.mainloop()