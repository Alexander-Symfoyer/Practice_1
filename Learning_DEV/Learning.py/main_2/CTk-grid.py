import customtkinter as ctk

app = ctk.CTk()
app.title("GEEyah!")
app.geometry("300x200")

app.grid_rowconfigure((0,1,2), weight=1)
app.grid_columnconfigure((0,1), weight=1)

label1 = ctk.CTkLabel(app, text="Username")
label1.grid(row=0,column=0,padx=10,pady=10,sticky="w")

entry1 = ctk.CTkEntry(app, show="*")
entry1.grid(row=0,column=1,padx=10,pady=10,sticky="ew")

label2 = ctk.CTkLabel(app, text="Password")
label2.grid(row=1,column=0,padx=10,pady=10,sticky="w")

entry2 = ctk.CTkEntry(app, show="*")
entry2.grid(row=1,column=1,padx=10,pady=10,sticky="ew")

button1 = ctk.CTkButton(app, text="Login")
button1.grid(row=2,column=0,padx=100,pady=10,columnspan=2,sticky="ew")























app.mainloop()