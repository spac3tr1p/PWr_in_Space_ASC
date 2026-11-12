import pandas as pd
import matplotlib.pyplot as plt

d = pd.read_csv("data.csv")
t = d["t"] / 1000.0
fig, (a, b) = plt.subplots(2, 1, sharex=True)
a.plot(d.t, d.theta)
a.axhline(0, ls="--", c="gray")
a.set_ylabel("theta")
a.set_xlabel("t [ms]")
b.plot(d.t, d.u)
b.axhline(0, ls="--", c="gray")
b.set_ylabel("u")
b.set_xlabel("t [ms]")
plt.savefig("chart.png")