from forex_python.converter import CurrencyRates
import customtkinter as ctk

from datetime import datetime, timedelta

import pandas as pd
import matplotlib.pyplot as plt

from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg


class ForexAnalyzerApp(ctk.CTk):

    def __init__(self):

        super().__init__()

        self.title("Forex Historical Analyzer")

        self.geometry("900x700")

        ctk.set_appearance_mode("light")

        ctk.set_default_color_theme("dark-blue")

        
        self.c = CurrencyRates()

        

        self.currency_list = [
            "USD",
            "EUR",
            "GBP",
            "JPY",
            "THB"
        ]

        

        self.create_widgets()

    def create_widgets(self):
        self.title_label = ctk.CTkLabel(
            self,
            text = "Forex Historical Analyzer",
            font = ("Arial",32,"Bold")
            )
        
        self.title_label.pack(pady = (30,5))

        self.subtitle_label = ctk.CTkLabel(
                self, 
                text = "Analyze 30-days Exchage Rate Trends",
                font = ("Arial",16),
                text_color = "gray50"
                )
        
        self.subtitle_label.pack()

        self.control_frame = ctk.CTkFrame(
            self,
            width = 750,
            height = 120,
            corner_radius = 20
            )
        
        self.control_frame.pack(pady = 30)
        self.control_frame.pack_propagate(False)

        self.from_label = ctk.CTkLabel(
            self.control_frame,
            text = "From",
            font = ("Arial", 16, "Bold")
            )
        
        self.from_label.place(x = 60, y = 20)

        self.combo_from = ctk.CTkComboBox(
            self.control_frame,
            values = self.currency_list,
            width = 220,
            height = 45,
            font = ("Arial", 16)
            )
        
        self.combo_from.set("USD")

        self.combo_from.place(x = 60, y = 20)

        self.to_label = ctk.CTkLabel(
            self.control_frame,
            text = "To",
            font = ("Arial", 16, "Bold")
        )
        
        self.to_label.place( x = 430, y = 20)

        self.combo_to = ctk.CTkComboBox(
            self.control_frame,
            valuse = self.currency_lits,
            width = 220,
            height = 45,
            font = ("Arial", 16)
        )

        self.combo_to.place(x = 440, y = 20)


        self.analyze_button = ctk.CTkButton(
            self,
            text = "Analyze Historical Data",
            width = 300,
            height = 50,
            font = ("Arial", 18, "Bold"),
            command = self.show_chart
        )

        self.analyze_button.pack(pady = 10)

        self.chart_frame = ctk.CTkFrame(
            self,
            width = 820,
            height = 400,
            corner_radius = 20
        )

        self.chart_frame.pack(pady = 30)
        self.chart_frame.pack_propagate(False)

    def show_chart(self):
        
        for widget in self.chart_frame.winfo_children():
            widget.destroy()

        form_currency = self.combo_from.get()
        to_currency = self.combo_to.get()

        today = datetime.today()
        data =[]

        



















app = ForexAnalyzerApp
app.mainloop