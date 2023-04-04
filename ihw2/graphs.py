import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("data.csv")

for alphabet_type in df["alphabet"].unique():
  for text_size in df["text_size"].unique():
    for sub_cnt in df["sub_cnt"].unique():
      fig, ax = plt.subplots(nrows=1, ncols=2)
      fig.set_size_inches(17, 8)

      for plot, oper_type in zip(ax, ("avg_time", "avg_oper")):
        plot.set_xlabel("Pattern size")
        plot.set_ylabel(oper_type)
        plot.set_title(f"{alphabet_type} - {text_size} - {sub_cnt} - {oper_type}")

        for algo_type in df["algo"].unique():
          data = df.query("algo == @algo_type & alphabet == @alphabet_type & text_size == @text_size & sub_cnt == @sub_cnt")

          plot.plot(data["pattern_size"], data[oper_type], label=algo_type)
        
        plot.legend()

      print(f"![](graphs/{alphabet_type}_{text_size}_{sub_cnt}.png)")
      fig.savefig(f"graphs/{alphabet_type}_{text_size}_{sub_cnt}.png")
      plt.close(fig)
      

              
            