import csv
def read_csv():
    with open('main_1/CSV-101.csv') as csv_file:
        csv_reader = csv.reader(csv_file, delimiter =',')
        line_count = 0

        for row in csv_reader:
            if line_count == 0:
                print(f'Column names are {", ".join(row)}')
                line_count += 1
            else:
                print(f'\t{row[0]} Likes {row[1]} and Loves {row[2]}.')
                line_count += 1
        print(f'Processed {line_count} lines.')

def write_csv():
    with open('main_1/CSV-103.csv', mode='w') as Friend_file:
        csv_writer = csv.writer(Friend_file, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
        csv_writer.writerow(['Name', 'Favs movie', 'Favs pet'])
        csv_writer.writerow(['Jane', 'Godfather', 'Cat'])
        csv_writer.writerow(['John', 'Shawnshank', 'Fox'])

def append_csv():
    with open('main_1/CSV-103.csv',mode ='a',newline='') as file:
        writer = csv.writer(file)

        writer.writerow(['Mike','Avengers','Dog'])
        writer.writerow(['Wade','Good will hunting','Rabbit'])


read_csv()
write_csv()
append_csv()