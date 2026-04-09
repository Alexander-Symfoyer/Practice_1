import customtkinter as ctk
from database import Database as db

class CourseManagementApp:
    def __init__(self):
        ctk.set_appearance_mode("light")
        ctk.set_default_color_theme("dark-blue")

        self.app = ctk.CTk()
        self.app.title("Course Management System")
        self.app.geometry("1000x650")

        self.app.minisize(900, 550)
        
        self.db = db()
        
        self.pages = {}
        self.current_page = None

        self.show_page("login")

    def show_page(self, page_name, user_data = None):
        if self.current_page:
            self.current_page.pack_forget()

        if page_name in self.pages:
            self.current_page = self.pages[page_name]
            self.current_pages.pack(fill="both", expand=True)

        else:
            if page_name == "login":
                pass