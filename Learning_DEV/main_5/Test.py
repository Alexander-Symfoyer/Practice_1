from forex_python.converter import CurrencyRates
import customtkinter as ctk

from datetime import datetime, timedelta

import pandas as pd
import matplotlib.pyplot as plt

from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg


class ForexAnalyzerApp(ctk.CTk):

    def __init__(self):

        super().__init__()

        # =========================================
        # WINDOW
        # =========================================

        self.title("Forex Historical Analyzer")

        self.geometry("900x700")

        ctk.set_appearance_mode("light")

        ctk.set_default_color_theme("dark-blue")

        # =========================================
        # API
        # =========================================

        self.c = CurrencyRates()

        # =========================================
        # CURRENCY LIST
        # =========================================

        self.currency_list = [
            "USD",
            "EUR",
            "GBP",
            "JPY",
            "THB"
        ]

        # =========================================
        # CREATE UI
        # =========================================

        self.create_widgets()

    # =========================================
    # UI
    # =========================================

    def create_widgets(self):

        # =========================================
        # TITLE
        # =========================================

        self.title_label = ctk.CTkLabel(
            self,
            text="Forex Historical Analyzer",
            font=("Arial", 32, "bold")
        )

        self.title_label.pack(
            pady=(30, 5)
        )

        self.subtitle_label = ctk.CTkLabel(
            self,
            text="Analyze 30-Day Exchange Rate Trends",
            font=("Arial", 16),
            text_color="gray50"
        )

        self.subtitle_label.pack()

        # =========================================
        # CONTROL FRAME
        # =========================================

        self.control_frame = ctk.CTkFrame(
            self,
            width=750,
            height=120,
            corner_radius=20
        )

        self.control_frame.pack(
            pady=30
        )

        self.control_frame.pack_propagate(False)

        # =========================================
        # FROM
        # =========================================

        self.from_label = ctk.CTkLabel(
            self.control_frame,
            text="From",
            font=("Arial", 16, "bold")
        )

        self.from_label.place(
            x=40,
            y=20
        )

        self.combo_from = ctk.CTkComboBox(
            self.control_frame,
            values=self.currency_list,
            width=220,
            height=45,
            font=("Arial", 16)
        )

        self.combo_from.set("USD")

        self.combo_from.place(
            x=40,
            y=50
        )

        # =========================================
        # TO
        # =========================================

        self.to_label = ctk.CTkLabel(
            self.control_frame,
            text="To",
            font=("Arial", 16, "bold")
        )

        self.to_label.place(
            x=490,
            y=20
        )

        self.combo_to = ctk.CTkComboBox(
            self.control_frame,
            values=self.currency_list,
            width=220,
            height=45,
            font=("Arial", 16)
        )

        self.combo_to.set("THB")

        self.combo_to.place(
            x=490,
            y=50
        )

        # =========================================
        # ANALYZE BUTTON
        # =========================================

        self.analyze_button = ctk.CTkButton(
            self,
            text="Analyze Historical Data",
            width=300,
            height=50,
            font=("Arial", 18, "bold"),
            command=self.show_chart
        )

        self.analyze_button.pack(
            pady=10
        )

        # =========================================
        # CHART FRAME
        # =========================================

        self.chart_frame = ctk.CTkFrame(
            self,
            width=820,
            height=400,
            corner_radius=20
        )

        self.chart_frame.pack(
            pady=30
        )

        self.chart_frame.pack_propagate(False)

    # =========================================
    # SHOW CHART
    # =========================================

    def show_chart(self):

        # =========================================
        # CLEAR OLD GRAPH
        # =========================================

        for widget in self.chart_frame.winfo_children():

            widget.destroy()

        # =========================================
        # GET SELECTED CURRENCY
        # =========================================

        from_currency = self.combo_from.get()

        to_currency = self.combo_to.get()

        # =========================================
        # GET HISTORICAL DATA
        # =========================================

        today = datetime.today()

        data = []

        for i in range(30):

            day = today - timedelta(days=i)

            rate = self.c.get_rate(
                from_currency,
                to_currency,
                day
            )

            data.append(
                [day.date(), rate]
            )

        # =========================================
        # CREATE DATAFRAME
        # =========================================

        df = pd.DataFrame(
            data,
            columns=["Date", "Rate"]
        )

        # =========================================
        # SORT DATE
        # =========================================

        df = df.sort_values(
            by="Date"
        )

        # =========================================
        # CREATE GRAPH
        # =========================================

        fig, ax = plt.subplots(
            figsize=(8, 4)
        )

        ax.plot(
            df["Date"],
            df["Rate"],
            marker="o"
        )

        ax.set_title(
            f"{from_currency} to {to_currency} - 30 Day Trend"
        )

        ax.set_xlabel("Date")

        ax.set_ylabel("Exchange Rate")

        ax.grid(True)

        # =========================================
        # EMBED GRAPH
        # =========================================

        canvas = FigureCanvasTkAgg(
            fig,
            master=self.chart_frame
        )

        canvas.draw()

        canvas.get_tk_widget().pack(
            fill="both",
            expand=True
        )


# =========================================
# RUN APP
# =========================================

app = ForexAnalyzerApp()

app.mainloop()