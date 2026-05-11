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

    