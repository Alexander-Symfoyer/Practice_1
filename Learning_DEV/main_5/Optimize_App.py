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

        self.geometry("1100x900")
        
        ctk.set_appearance_mode("dark")

        ctk.set_default_color_theme("dark-blue")

        self.configure(
            fg_color = "#0F172A"
        )

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

        self.create_widgets()

    
    
    def create_widgets(self):
        self.title_label = ctk.CTkLabel(
            self,
            text = "Forex Historical Analyzer",
            font = ("Arial",38,"bold"),
            text_color = "#F8FAFC"
            )
        
        self.title_label.pack(pady = (30,5))

        self.subtitle_label = ctk.CTkLabel(
                self, 
                text = "Analyze Historical Exchange Rate Trends",
                font = ("Arial",16),
                text_color = "#94A3B8"
                )
        
        self.subtitle_label.pack()

        self.control_frame = ctk.CTkFrame(
            self,
            width = 800,
            height = 120,
            corner_radius = 20,
            fg_color = "#1E293B"
            )
        
        self.control_frame.pack(pady = 30)
        self.control_frame.pack_propagate(False)

        self.from_label = ctk.CTkLabel(
            self.control_frame,
            text = "From",
            font = ("Arial", 16, "bold"),
            text_color="#E2E8F0"
            )
        
        self.from_label.place(x = 40, y = 20)

        self.combo_from = ctk.CTkComboBox(
            self.control_frame,
            values = self.currency_list,
            width = 180,
            height = 45,
            font = ("Arial", 16),
            fg_color="#334155",
            button_color="#3B82F6",
            button_hover_color="#2563EB",
            border_color="#475569",
            dropdown_fg_color="#1E293B"
            )
        
        self.combo_from.set("USD")

        self.combo_from.place(x = 40, y = 55)

        self.to_label = ctk.CTkLabel(
            self.control_frame,
            text = "To",
            font = ("Arial", 16, "bold"),
            text_color="#E2E8F0"
        )
        
        self.to_label.place( x = 285, y = 20)

        self.combo_to = ctk.CTkComboBox(
            self.control_frame,
            values = self.currency_list,
            width = 180,
            height = 45,
            font = ("Arial", 16),
            fg_color="#334155",
            button_color="#3B82F6",
            button_hover_color="#2563EB",
            border_color="#475569",
            dropdown_fg_color="#1E293B"
        )

        self.combo_to.set("THB")

        self.combo_to.place(x = 285, y = 55)

        self.time_label = ctk.CTkLabel(
            self.control_frame,
            text = "Time Range",
            font = ("Arial", 16, "bold"),
            text_color="#E2E8F0"
        )

        self.time_label.place(x = 530, y = 20)

        self.combo_time = ctk.CTkComboBox(
            self.control_frame,
            values = self.time_options,
            width = 180,
            height = 45,
            font = ("Arial", 16),
            fg_color="#334155",
            button_color="#3B82F6",
            button_hover_color="#2563EB",
            border_color="#475569",
            dropdown_fg_color="#1E293B"
        )

        self.combo_time.set("30 Days")
        
        self.combo_time.place(x = 530, y = 55)

        self.analyze_button = ctk.CTkButton(
            self,
            text = "Analyze Historical Data",
            width = 300,
            height = 50,
            font = ("Arial", 18, "bold"),
            command = self.show_chart,
            fg_color="#2563EB",
            hover_color="#1D4ED8",
            corner_radius=15
        )

        self.analyze_button.pack(pady = 10)

        self.chart_frame = ctk.CTkFrame(
            self,
            width = 980,
            height = 520,
            corner_radius = 25,
            fg_color = "#1E293B"
        )

        self.chart_frame.pack(pady = 30)
        self.chart_frame.pack_propagate(False)

    def get_forex_data(self):
        pass

    
    
    def show_chart(self):
        
        for widget in self.chart_frame.winfo_children():
            widget.destroy()

        from_currency = self.combo_from.get()
        to_currency = self.combo_to.get()
        selected_time = self.combo_time.get()

        today = datetime.today()
        data =[]

        if selected_time == "7 Days":
            days = 7

        elif selected_time == "30 Days":
            days = 30

        elif selected_time == "90 Days":
            days = 90

        elif selected_time == "1 Year":
            days = 365

        for i in range(days):
            day = today - timedelta(days = i)

            try:
                rate = self.c.get_rate(
                from_currency,
                to_currency,
                day
            )
                
                data.append([day.date(), rate])

            except Exception as e:
                print(f"Error on {day.date()} : {e}")
        
        if len(data) == 0:
            return

        
        df = pd.DataFrame(
            data, 
            columns = ["Date", "Rate"]
            )
        
        df = df.sort_values(by = "Date")

        if len(df) < 20:
            return

        df["SMA_5"] = df["Rate"].rolling(5).mean()
        df["SMA_20"] = df["Rate"].rolling(20).mean()

        latest_sma5 = df["SMA_5"].iloc[-1]
        latest_sma20 = df["SMA_20"].iloc[-1]

        previous_sma5 = df["SMA_5"].iloc[-2]
        previous_sma20 = df["SMA_20"].iloc[-2]

        if previous_sma5 < previous_sma20 and latest_sma5 > latest_sma20:
            
            signal = "Golden Cross"
            signal_color = "#22C55E"

            cross_x = df["Date"].iloc[-1]
            cross_y = latest_sma5
        
        elif previous_sma5 > previous_sma20 and latest_sma5 < latest_sma20:
            
            signal = "Death Cross"
            signal_color = "#EF4444"

            cross_x = df["Date"].iloc[-1]
            cross_y = latest_sma5

        else:

            signal = "No CrossOver"
            signal_color = "#CBD5E1"

        


        plt.style.use("dark_background")

        fig, ax = plt.subplots(
            figsize = (11, 6.5)
        )
        
        ax.plot(
            df["Date"],
            df["Rate"],
            marker = "o",
            linewidth = 3,
            markersize = 4.5,
            color = "#38BDF8",
            label = "Exchange Rate"
        )
        
        ax.plot(
            df["Date"],
            df["SMA_5"],
            linewidth = 1.5,
            color = "#FACC15",
            label = "SMA 5"
        )

        ax.plot(
            df["Date"],
            df["SMA_20"],
            linewidth = 1.5,
            color = "#A855F7",
            label = "SMA 20"
        )

        ax.fill_between(
            df["Date"],
            df["SMA_5"],
            df["SMA_20"],
            alpha = 0.1,
            color = signal_color
        )

        ax.margins(x = 0.02)

        ax.set_facecolor("#0F172A")
        fig.patch.set_facecolor("#1E293B")
        
        ax.set_title(
            f"{from_currency} to {to_currency} - {selected_time} Trends",
            color = "#F8FAFC",
            fontsize = 16
            )
        
        ax.text(
            0.02,
            0.95,
            signal,
            transform = ax.transAxes,
            fontsize = 14,
            fontweight = "bold",
            color = signal_color,
            verticalalignment = "top"
        )

        ax.set_xlabel(
            "Date",
            color = "#CBD5E1")
        
        ax.set_ylabel(
            "Exchange Rate",
            color = "#CBD5E1")

        plt.xticks(rotation = 25)
        
        ax.tick_params(
            colors = "#94A3B8"
        )
        
        ax.grid(
            True,
            linestyle = "--",
            alpha = 0.3
        )

        if signal != "No CrossOver":
            
            ax.scatter(
                cross_x,
                cross_y,
                color = signal_color,
                s = 200,
                zorder = 5
            )
        
        ax.legend(
            facecolor = "#1E293B",
            edgecolor = "#334155",
            labelcolor = "#F8FAFC"
        )

        for spine in ax.spines.values():
            spine.set_color("#334155")


        fig.tight_layout()

        canvas = FigureCanvasTkAgg(
            fig,
            master = self.chart_frame
        )
        canvas.draw()

        canvas.get_tk_widget().pack(
            fill = "both",
            expand = True
        )

        plt.close(fig)

        
app = ForexAnalyzerApp()

app.mainloop()