from forex_python.converter import CurrencyRates 
import customtkinter as ctk

c = CurrencyRates()

ctk.set_appearance_mode("light")
ctk.set_default_color_theme("dark-blue")

app = ctk.CTk()
app.title("Analyze Forex")
app.geometry("700x800")
app.resizable(False,False)

title = ctk.CTkLabel(app, 
                    text = "Forex Analyzing App", 
                    font = ("Arial", 32, "bold")
                    )
title.pack(side = "top", pady = (30, 5))

currency_list = ["USD", "EUR", "GBP", "JPY", "THB"]


form_label = ctk.CTkLabel(app,
                        text = "From")
form_label.place(x = 50, y = 75)

to_label = ctk.CTkLabel(app,
                        text = "To")
to_label.place(x = 300, y = 75)

combo_form = ctk.CTkComboBox(app,
                            values = currency_list,
                            width = 120)
combo_form.set("USD")
combo_form.place(x = 50, y = 100)

combo_to = ctk.CTkComboBox(app,
                            values = currency_list,
                            width = 120)
combo_to.set("THB")
combo_to.place(x = 300, y = 100)

amount_label = ctk.CTkLabel(app,
                            text = "Amount")
amount_label.place(x = 50, y = 150)

output_label = ctk.CTkLabel(app,
                            text = "Result")
output_label.place(x = 300, y = 150)

amount_entry = ctk.CTkEntry(app, 
                        placeholder_text = "Enter an amount")
amount_entry.pack(side = "top", pady = 5, padx = 5)
amount_entry.place(x = 50, y = 175)

result_label = ctk.CTkLabel(app, 
                        text = "Output will show here")
result_label.pack(side = "top", pady = 5, padx = 5)
result_label.place(x = 300, y = 175)


def convert_currency():

    from_currency = combo_form.get()
    to_currency = combo_to.get()

    try:
        amount = float(amount_entry.get())
        rate = c.get_rate(from_currency, to_currency)
        result = amount * rate

        result_label.configure(
            text = f"{amount:.2f} {from_currency} = {result:.2f} {to_currency}"
            )

    except ValueError:
        result_label.configure(text = "Please enter a valid number")

    except Exception as e:
        result_label.configure(text = f"Error : {e}")


convert_button = ctk.CTkButton(app,
                                text = "Convert",
                                command = convert_currency)
convert_button.pack(pady = 20, padx = 5)
convert_button.place(x = 175, y = 225)

app.mainloop()