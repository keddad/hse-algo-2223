from pathlib import Path
import csv

import matplotlib as mpl
import matplotlib.pyplot as plt
import pandas as pd

df = pd.DataFrame(columns=["sort", "total_array_size",
                  "array_type", "size", "time_ns", "operations"])

def read_csv(csv_path: Path):
    global df

    sort, array, size = csv_path.name.rstrip(".csv").split("_")

    with open(csv_path) as f:
        reader = csv.DictReader(f, delimiter=",")

        for row in reader:
            # warnings are ok because i'm supposed to be learning algorithms and not data visualisation
            # also append is an order of magnitude faster then concat for some reason
            df = df.append({"sort": sort, "total_array_size": size, "array_type": array,
                            "size": int(row["size"]), "time_ns": int(row["time_ns"]), "operations": int(row["operations"])}, ignore_index=True)


csvs = list(Path("data").glob("*.csv"))
graphs = Path("graphs")

for csv_file in csvs:
    read_csv(csv_file)

# Array plots

for total_array_size in df["total_array_size"].unique():
    for array_type in df["array_type"].unique():
        for data_type in ["time_ns", "operations"]:
            fig, ax = plt.subplots(nrows=1, ncols=1)
            ax.set_title(f"{total_array_size} - {array_type} - {data_type}")
            ax.set_xlabel("Array size")
            ax.set_ylabel(data_type)

            for sort in df["sort"].unique():
                sort_data = df.query(
                    "total_array_size == @total_array_size & array_type == @array_type & sort == @sort")[["size", data_type]]

                ax.plot(sort_data["size"], sort_data[data_type], label=sort)

            ax.legend()
            # to include in markdown
            print(f"![](graphs/arrays_{array_type}_{total_array_size}_{data_type}.png)")
            fig.savefig(graphs / f"arrays_{array_type}_{total_array_size}_{data_type}.png")
            plt.close(fig)

# Sort plots

for sort_type in df["sort"].unique():
    for data_type in ["time_ns", "operations"]:
        fig, ax = plt.subplots(nrows=1, ncols=1)
        ax.set_title(f"{sort_type} - {data_type}")
        ax.set_xlabel("Array size")
        ax.set_ylabel(data_type)

        for array_type in df["array_type"].unique():
            for total_array_size in df["total_array_size"].unique():
                sort_data = df.query(
                    "total_array_size == @total_array_size & array_type == @array_type & sort == @sort_type")[["size", data_type]]

                ax.plot(sort_data["size"], sort_data[data_type], label=f"{array_type}_{total_array_size}")

        ax.legend()
        print(f"![](graphs/sorts_{sort_type}_{data_type}.png)")
        fig.savefig(graphs / f"sorts_{sort_type}_{data_type}.png")
        plt.close(fig)

df.to_csv("aggregate_data.csv")