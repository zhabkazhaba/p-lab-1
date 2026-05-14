import csv
import random
import os
import sys

FIO_LIST = [
    "Иванов И.И.", "Петров П.П.", "Сидоров С.С.", "Джон Д.Д.",
    "Фет А.А.", "Пушкин А.С.", "Булгаков М.А.", "Лермонтов М.Ю.",
    "Ричард Д.Д.", "Дэвид Б.", "Джон Л.", "Дейв Г."
]

STREET_LIST = [
    "Первая", "Вторая", "Третья", "Главная", "Красная",
    "Синяя", "Пушкина", "Ломоносова", "Пушкина", "Ленина",
    "Авиаторов", "Таллинская", "Московская", "Мира", "Шипиловская"
]

def main():
    try:
        n = int(sys.argv[1])
    except IndexError:
        n = 100

    output_dir = os.path.join(os.path.dirname(__file__), "..", "data")
    os.makedirs(output_dir, exist_ok=True)
    
    filepath = os.path.join(output_dir, "in_data.csv")
    unique_records = set()

    while len(unique_records) < n:
        fio = random.choice(FIO_LIST)
        street = random.choice(STREET_LIST)
        house = random.randint(1, 100)
        apartment = random.randint(1, 1000)
        birth_year = random.randint(1900, 2026)
        
        record = (fio, street, house, apartment, birth_year)
        unique_records.add(record)

    with open(filepath, mode="w", encoding="utf-8", newline="") as file:
        writer = csv.writer(file, delimiter=';')
        
        writer.writerow(["fio", "street", "house", "apartment", "birth_year"])
        
        for record in unique_records:
            writer.writerow(record)

if __name__ == "__main__":
    main()