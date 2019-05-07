import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("Onda.dat")

plt.figure(figsize=(15,5))
plt.subplot(1,2,1)
plt.imshow(data)
plt.xlabel("Indice X")
plt.ylabel("Indice D")
plt.colorbar(label="Desplazamiento")

plt.subplot(1,2,2)
plt.plot(data[0,:], label="tiempo inicial")
plt.plot(data[-1,:], label="tiempo final")
plt.xlabel("Indice X")
plt.ylabel("Desplazamiento")
plt.legend()
plt.savefig("plot.png", bbox_="tight")
