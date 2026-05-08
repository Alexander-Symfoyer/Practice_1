import customtkinter as ctk
from PIL import Image

ctk.set_appearance_mode("light")
ctk.set_default_color_theme("dark-blue")

app = ctk.CTk()
app.title("GEEyah!")
app.geometry("300x200")

pages = {}

def show_page(page_name):
    for page in pages.values():
        page.pack_forget()
    pages[page_name].pack(fill="both", expand=True)


class login(ctk.CTkFrame):
    def __init__(self, master, switch_page):
        super().__init__(master)
        self.switch_page = switch_page

        # ✅ โหลดรูป
        self.image = ctk.CTkImage(
            dark_image=Image.open("main_2/python.png"),
            size=(100, 100)
        )

        # ✅ แก้ตรงนี้
        self.image_label = ctk.CTkLabel(self, image=self.image, text="")
        self.image_label.pack(pady=10)

        self.entry = ctk.CTkEntry(self, placeholder_text="Username")
        self.entry.pack(pady=10)

        self.label = ctk.CTkLabel(self, text="")
        self.label.pack(pady=10)

        self.button = ctk.CTkButton(self, text="Login", command=self.login)
        self.button.pack(pady=5)

    def login(self):
        name = self.entry.get()
        if name == "admin":
            self.switch_page("home")
        else:
            self.label.configure(text="User Not Found", text_color="red")


class home(ctk.CTkFrame):
    def __init__(self, master, switch_page):
        super().__init__(master)
        self.switch_page = switch_page

        label = ctk.CTkLabel(self, text="Welcome to Home pages!", font=("Arial", 16))
        label.pack(pady=20)

        button = ctk.CTkButton(self, text="Logout",
                            command=lambda: self.switch_page("login"))
        button.pack()


pages["login"] = login(app, show_page)
pages["home"] = home(app, show_page)

show_page("login")

app.mainloop()




















app.mainloop()