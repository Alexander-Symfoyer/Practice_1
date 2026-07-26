from forex_python.converter import CurrencyRates
import customtkinter as ctk

from datetime import datetime, timedelta

import pandas as pd
import matplotlib.pyplot as plt

from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg


class ForexAnalyzerApp(ctk.CTk):

    def __init__(self):

        super().__init__()

        # ---------------- WINDOW ----------------

        self.title("Forex Historical Analyzer")

        self.geometry("900x700")

        ctk.set_appearance_mode("dark")
        ctk.set_default_color_theme("dark-blue")

        self.configure(
            fg_color="#0F172A"
        )

        # ---------------- FOREX ----------------

        self.c = CurrencyRates()

        self.currency_list = [
            "USD",
            "EUR",
            "GBP",
            "JPY",
            "THB"
        ]

        self.time_options = [
            "7 Days",
            "30 Days",
            "90 Days",
            "1 Year"
        ]

        # ---------------- UI ----------------

        self.create_widgets()

    def create_widgets(self):

        # ---------------- TITLE ----------------

        self.title_label = ctk.CTkLabel(
            self,
            text="Forex Historical Analyzer",
            font=("Arial", 38, "bold"),
            text_color="#F8FAFC"
        )

        self.title_label.pack(
            pady=(30, 5)
        )

        self.subtitle_label = ctk.CTkLabel(
            self,
            text="Analyze Historical Exchange Rate Trends",
            font=("Arial", 16),
            text_color="#94A3B8"
        )

        self.subtitle_label.pack()

        # ---------------- CONTROL FRAME ----------------

        self.control_frame = ctk.CTkFrame(
            self,
            width=800,
            height=120,
            corner_radius=20,
            fg_color="#1E293B"
        )

        self.control_frame.pack(
            pady=30
        )

        self.control_frame.pack_propagate(False)

        # ---------------- FROM ----------------

        self.from_label = ctk.CTkLabel(
            self.control_frame,
            text="From",
            font=("Arial", 16, "bold"),
            text_color="#E2E8F0"
        )

        self.from_label.place(
            x=40,
            y=20
        )

        self.combo_from = ctk.CTkComboBox(
            self.control_frame,
            values=self.currency_list,

            width=180,
            height=45,

            font=("Arial", 16),

            fg_color="#334155",
            button_color="#3B82F6",
            button_hover_color="#2563EB",
            border_color="#475569",
            dropdown_fg_color="#1E293B"
        )

        self.combo_from.set("USD")

        self.combo_from.place(
            x=40,
            y=55
        )

        # ---------------- TO ----------------

        self.to_label = ctk.CTkLabel(
            self.control_frame,
            text="To",
            font=("Arial", 16, "bold"),
            text_color="#E2E8F0"
        )

        self.to_label.place(
            x=310,
            y=20
        )

        self.combo_to = ctk.CTkComboBox(
            self.control_frame,
            values=self.currency_list,

            width=180,
            height=45,

            font=("Arial", 16),

            fg_color="#334155",
            button_color="#3B82F6",
            button_hover_color="#2563EB",
            border_color="#475569",
            dropdown_fg_color="#1E293B"
        )

        self.combo_to.set("THB")

        self.combo_to.place(
            x=310,
            y=55
        )

        # ---------------- TIME ----------------

        self.time_label = ctk.CTkLabel(
            self.control_frame,
            text="Time Range",
            font=("Arial", 16, "bold"),
            text_color="#E2E8F0"
        )

        self.time_label.place(
            x=580,
            y=20
        )

        self.combo_time = ctk.CTkComboBox(
            self.control_frame,
            values=self.time_options,

            width=180,
            height=45,

            font=("Arial", 16),

            fg_color="#334155",
            button_color="#3B82F6",
            button_hover_color="#2563EB",
            border_color="#475569",
            dropdown_fg_color="#1E293B"
        )

        self.combo_time.set("30 Days")

        self.combo_time.place(
            x=580,
            y=55
        )

        # ---------------- BUTTON ----------------

        self.analyze_button = ctk.CTkButton(
            self,

            text="Analyze Historical Data",

            width=320,
            height=55,

            font=("Arial", 18, "bold"),

            fg_color="#2563EB",
            hover_color="#1D4ED8",

            corner_radius=15,

            command=self.show_chart
        )

        self.analyze_button.pack(
            pady=10
        )

        # ---------------- CHART FRAME ----------------

        self.chart_frame = ctk.CTkFrame(
            self,

            width=820,
            height=420,

            corner_radius=25,

            fg_color="#1E293B"
        )

        self.chart_frame.pack(
            pady=30
        )

        self.chart_frame.pack_propagate(False)

    def show_chart(self):

        # ---------------- CLEAR OLD GRAPH ----------------

        for widget in self.chart_frame.winfo_children():

            widget.destroy()

        # ---------------- GET VALUES ----------------

        from_currency = self.combo_from.get()

        to_currency = self.combo_to.get()

        selected_time = self.combo_time.get()

        # ---------------- TIME RANGE ----------------

        if selected_time == "7 Days":

            days = 7

        elif selected_time == "30 Days":

            days = 30

        elif selected_time == "90 Days":

            days = 90

        elif selected_time == "1 Year":

            days = 365

        # ---------------- FOREX DATA ----------------

        today = datetime.today()

        data = []

        for i in range(days):

            day = today - timedelta(days=i)

            try:

                rate = self.c.get_rate(
                    from_currency,
                    to_currency,
                    day
                )

                data.append([
                    day.date(),
                    rate
                ])

            except:

                pass

        # ---------------- DATAFRAME ----------------

        df = pd.DataFrame(
            data,
            columns=["Date", "Rate"]
        )

        df = df.sort_values(
            by="Date"
        )

        # ---------------- GRAPH STYLE ----------------

        plt.style.use("dark_background")

        fig, ax = plt.subplots(
            figsize=(9, 4.5)
        )

        # ---------------- LINE GRAPH ----------------

        ax.plot(
            df["Date"],
            df["Rate"],

            marker="o",

            linewidth=3,

            markersize=8,

            color="#3B82F6"
        )

        # ---------------- COLORS ----------------

        ax.set_facecolor("#0F172A")

        fig.patch.set_facecolor("#1E293B")

        # ---------------- TITLE ----------------

        ax.set_title(
            f"{from_currency} to {to_currency} - {selected_time} Trends",

            color="#F8FAFC",

            fontsize=16
        )

        # ---------------- AXIS LABELS ----------------

        ax.set_xlabel(
            "Date",

            color="#CBD5E1"
        )

        ax.set_ylabel(
            "Exchange Rate",

            color="#CBD5E1"
        )

        # ---------------- TICKS ----------------

        ax.tick_params(
            colors="#94A3B8"
        )

        # ---------------- GRID ----------------

        ax.grid(
            True,

            linestyle="--",

            alpha=0.3
        )

        # ---------------- BORDER ----------------

        for spine in ax.spines.values():

            spine.set_color("#334155")

        # ---------------- AUTO LAYOUT ----------------

        fig.tight_layout()

        # ---------------- TKINTER CANVAS ----------------

        canvas = FigureCanvasTkAgg(
            fig,
            master=self.chart_frame
        )

        canvas.draw()

        canvas.get_tk_widget().pack(
            fill="both",
            expand=True
        )

        # ---------------- FREE MEMORY ----------------

        plt.close(fig)


# ---------------- RUN APP ----------------

app = ForexAnalyzerApp()

app.mainloop()