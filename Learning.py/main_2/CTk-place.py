import customtkinter as ctk

app = ctk.CTk()
app.title("GEEyah!")
app.geometry("400x300")

label0 =ctk.CTkLabel(app, text="Register")
label0.place(relx=0.45, rely=0.08, anchor="center")

label1 = ctk.CTkLabel(app, text="Username")
label1.place(x=50,y=50)

entry1 = ctk.CTkEntry(app, show="*", width=150)
entry1.place(x=130,y=50)

label2 = ctk.CTkLabel(app, text="Password")
label2.place(x=50,y=100)

entry2 = ctk.CTkEntry(app, show="*", width=150)
entry2.place(x=130,y=100)

button1 = ctk.CTkButton(app, text="Login", width=100)
button1.place(x=120,y=160)
























app.mainloop()