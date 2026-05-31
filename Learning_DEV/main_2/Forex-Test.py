from forex_python.converter import CurrencyRates
import customtkinter as ctk


class ForexApp(ctk.CTk):

    def __init__(self):

        super().__init__()

        # =========================================
        # WINDOW SETUP
        # =========================================

        self.title("Forex Analyzing App")
        self.geometry("700x700")
        self.resizable(False, False)

        ctk.set_appearance_mode("light")
        ctk.set_default_color_theme("dark-blue")

        # =========================================
        # FOREX API
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
    # CREATE WIDGETS
    # =========================================

    def create_widgets(self):

        # =========================
        # TITLE
        # =========================

        self.title_label = ctk.CTkLabel(
            self,
            text="Forex Analyzing App",
            font=("Arial", 32, "bold")
        )

        self.title_label.pack(pady=(30, 5))

        self.subtitle_label = ctk.CTkLabel(
            self,
            text="Real-time currency conversion",
            font=("Arial", 16),
            text_color="gray50"
        )

        self.subtitle_label.pack()

        # =========================
        # MAIN FRAME
        # =========================

        self.main_frame = ctk.CTkFrame(
            self,
            width=620,
            height=300,
            corner_radius=20
        )

        self.main_frame.pack(pady=40)
        self.main_frame.pack_propagate(False)

        # =========================
        # FROM SECTION
        # =========================

        self.from_label = ctk.CTkLabel(
            self.main_frame,
            text="From",
            font=("Arial", 16, "bold")
        )

        self.from_label.place(x=40, y=30)

        self.combo_from = ctk.CTkComboBox(
            self.main_frame,
            values=self.currency_list,
            width=180,
            height=40,
            font=("Arial", 16)
        )

        self.combo_from.set("USD")

        self.combo_from.place(x=40, y=60)

        # =========================
        # TO SECTION
        # =========================

        self.to_label = ctk.CTkLabel(
            self.main_frame,
            text="To",
            font=("Arial", 16, "bold")
        )

        self.to_label.place(x=390, y=30)

        self.combo_to = ctk.CTkComboBox(
            self.main_frame,
            values=self.currency_list,
            width=180,
            height=40,
            font=("Arial", 16)
        )

        self.combo_to.set("THB")

        self.combo_to.place(x=390, y=60)

        # =========================
        # SWAP BUTTON
        # =========================

        self.swap_button = ctk.CTkButton(
            self.main_frame,
            text="⇄",
            width=50,
            height=40,
            font=("Arial", 20),
            command=self.swap_currency
        )

        self.swap_button.place(x=285, y=60)

        # =========================
        # AMOUNT SECTION
        # =========================

        self.amount_label = ctk.CTkLabel(
            self.main_frame,
            text="Amount",
            font=("Arial", 16, "bold")
        )

        self.amount_label.place(x=40, y=140)

        self.amount_entry = ctk.CTkEntry(
            self.main_frame,
            placeholder_text="Enter amount",
            width=250,
            height=45,
            font=("Arial", 18)
        )

        self.amount_entry.place(x=40, y=170)

        # =========================
        # RESULT SECTION
        # =========================

        self.result_title = ctk.CTkLabel(
            self.main_frame,
            text="Result",
            font=("Arial", 16, "bold")
        )

        self.result_title.place(x=360, y=140)

        self.result_box = ctk.CTkFrame(
            self.main_frame,
            width=220,
            height=70,
            corner_radius=15
        )

        self.result_box.place(x=360, y=170)

        self.result_label = ctk.CTkLabel(
            self.result_box,
            text="0.00 THB",
            font=("Arial", 24, "bold"),
            text_color="#16A34A"
        )

        self.result_label.place(
            relx=0.5,
            rely=0.5,
            anchor="center"
        )

        # =========================
        # LIVE RATE LABEL
        # =========================

        self.live_rate_label = ctk.CTkLabel(
            self.main_frame,
            text="1 USD = 0.00 THB",
            font=("Arial", 14),
            text_color="gray50"
        )

        self.live_rate_label.place(x=360, y=250)

        # =========================
        # CONVERT BUTTON
        # =========================

        self.convert_button = ctk.CTkButton(
            self,
            text="Convert",
            width=220,
            height=50,
            font=("Arial", 18, "bold"),
            corner_radius=15,
            command=self.convert_currency
        )

        self.convert_button.pack()

    # =========================================
    # CONVERT FUNCTION
    # =========================================

    def convert_currency(self):

        from_currency = self.combo_from.get()
        to_currency = self.combo_to.get()

        try:

            amount = float(self.amount_entry.get())

            rate = self.c.get_rate(
                from_currency,
                to_currency
            )

            result = amount * rate

            self.result_label.configure(
                text=f"{result:,.2f} {to_currency}"
            )

            self.live_rate_label.configure(
                text=f"1 {from_currency} = {rate:.4f} {to_currency}"
            )

        except ValueError:

            self.result_label.configure(
                text="Invalid"
            )

        except Exception as e:

            self.result_label.configure(
                text="Error"
            )

            self.live_rate_label.configure(
                text=str(e)
            )

    # =========================================
    # SWAP FUNCTION
    # =========================================

    def swap_currency(self):

        current_from = self.combo_from.get()
        current_to = self.combo_to.get()

        self.combo_from.set(current_to)
        self.combo_to.set(current_from)


# =========================================
# RUN APP
# =========================================

app = ForexApp()
app.mainloop()