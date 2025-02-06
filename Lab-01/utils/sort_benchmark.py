"""
@file sort_benchmark.py
@brief Скрипт для генерации данных, запуска C++ сортировки и анализа результатов.

Этот скрипт генерирует случайные данные о кораблях, сохраняет их в CSV-файлы, 
вызывает исполняемый C++ файл с реализацией сортировки и анализирует время выполнения различных алгоритмов.
"""

import random
import csv
import subprocess
import pandas as pd
import matplotlib.pyplot as plt
from typing import Any
from tqdm import tqdm
import os

# --- Константы ---
NAMES = [
    "Poseidon", "Neptune", "Titanic", "Enterprise",
    "Odyssey", "Aurora", "Viking", "Nautilus",
]
COUNTRIES = ["USA", "Russia", "China", "UK", "Germany", "France", "Japan"]
SHIP_TYPES = ["Tanker", "BulkCarrier", "Passenger"]
CAPTAINS = [
    "John Smith", "Ivan Petrov", "Hans Müller", "Jean Dupont",
    "William Brown", "Li Wei", "Carlos Sanchez",
]
DATA_SIZES = [100, 1000, 5000, 10000, 50000, 100000]

def generate_data(size: int) -> list[list[Any]]:
    """
    @brief Генерирует случайные данные о кораблях.
    
    @param size Количество записей.
    @return Список списков, содержащих информацию о кораблях.
    """
    return [
        [
            random.choice(NAMES) + f" {random.randint(1, 100)}",
            random.randint(1950, 2025),
            random.choice(COUNTRIES),
            random.choice(SHIP_TYPES),
            random.choice(CAPTAINS),
        ]
        for _ in range(size)
    ]

def save_to_csv(data: list[list[Any]], filename: str = "ships.csv"):
    """
    @brief Сохраняет данные о кораблях в CSV-файл.
    
    @param data Данные о кораблях.
    @param filename Имя файла для сохранения.
    """
    with open(filename, "w", newline="") as f:
        writer = csv.writer(f)
        writer.writerow(["Name", "Year", "Country", "Type", "Captain"])
        writer.writerows(data)

def run_cpp_sort(algorithm: str) -> pd.DataFrame:
    """
    @brief Запускает сортировку в C++ и замеряет время выполнения.
    
    @param algorithm Название алгоритма сортировки (insertion, heap, merge).
    @return DataFrame с результатами замеров времени.
    """
    results = {"size": [], "time": [], "algo": []}
    for size in tqdm(DATA_SIZES, desc=f"Sorting with {algorithm}..."):
        process = subprocess.run(
            ["./build/sort_ships", f"data/raw/ships_{size}.csv", algorithm],
            capture_output=True,
            text=True,
        )

        output = process.stdout.strip().split("\n")
        time = float(output[1].split(":")[1].split()[0])
        results["size"].append(size)
        results["time"].append(time)
        results["algo"].append(algorithm)

    return pd.DataFrame(results)

def plot_results(df: pd.DataFrame):
    """
    @brief Строит график времени выполнения алгоритмов сортировки.
    
    @param df DataFrame с результатами замеров времени.
    """
    plt.figure(figsize=(10, 6))
    for algo in df["algo"].unique():
        algo_df = df[df["algo"] == algo]
        plt.plot(algo_df["size"], algo_df["time"], marker="o", label=algo)

    plt.xlabel("Размер массива")
    plt.ylabel("Время (секунды)")
    plt.title("Сравнение алгоритмов сортировки")
    plt.legend()
    plt.grid(True)
    plt.xscale("log")
    plt.savefig("images/sorting_results.png")
    plt.show()

if __name__ == "__main__":
    """
    @brief Основной блок выполнения скрипта.
    
    Генерирует тестовые данные, запускает C++ сортировку и анализирует результаты.
    """
    total_df = pd.DataFrame()
    algorithms = ["insertion", "heap", "merge"]

    for size in tqdm(DATA_SIZES, desc="Generating Data..."):
        if not os.path.exists(f"data/raw/ships_{size}.csv"):
            data = generate_data(size)
            save_to_csv(data, f"data/raw/ships_{size}.csv")

    for algo in algorithms:
        df_results = run_cpp_sort(algo)
        total_df = pd.concat([total_df, df_results], axis=0, ignore_index=True)
        df_results.to_csv(f"data/results/{algo}_results.csv", index=False)

    plot_results(total_df)