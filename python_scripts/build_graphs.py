import matplotlib.pyplot as plt
import csv
import os

def main():
    data_dir = os.path.join(os.path.dirname(__file__), '..', 'data')
    input_file = os.path.join(data_dir, 'out_times.csv')
    output_image = os.path.join(data_dir, 'sorting_plot.png')

    if not os.path.exists(input_file):
        print(f"Файл {input_file} не найден")
        return

    sizes = []
    time_std = []
    time_heap = []
    time_insertion = []
    time_shaker = []

    with open(input_file, mode='r', encoding='utf-8') as file:
        reader = csv.reader(file, delimiter=';')
        next(reader)
        for row in reader:
            if not row or len(row) < 5:
                continue
            sizes.append(int(row[0]))
            time_std.append(int(row[1]))
            time_heap.append(int(row[2]))
            time_insertion.append(int(row[3]))
            time_shaker.append(int(row[4]))

    plt.figure(figsize=(10, 6))
    
    plt.plot(sizes, time_std, label='std::sort', marker='o', linewidth=2)
    plt.plot(sizes, time_heap, label='Heap Sort', marker='s', linewidth=2)
    plt.plot(sizes, time_insertion, label='Insertion Sort', marker='^', linewidth=2)
    plt.plot(sizes, time_shaker, label='Shaker Sort', marker='d', linewidth=2)

    plt.title('Зависимость времени сортировки от размера массива', fontsize=14)
    plt.xlabel('Количество элементов (шт)', fontsize=12)
    plt.ylabel('Время выполнения (мс)', fontsize=12)
    
    plt.grid(True, linestyle='--', alpha=0.7)
    plt.legend(fontsize=11)
    plt.tight_layout()

    plt.savefig(output_image)
    print(f"График сохранен в {os.path.abspath(output_image)}")
    plt.show()

if __name__ == '__main__':
    main()