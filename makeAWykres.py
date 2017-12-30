# coding=utf-8
import matplotlib.pyplot as plt
import numpy as np
import sklearn
import sklearn.datasets
import sklearn.linear_model
import matplotlib
from pprint import pprint











# print positions

# print type(positions)

# convertToCsv(y)

print u"Wykreślamy wykresy"

mat = np.loadtxt("output.csv",delimiter=",")



print mat[:,0]



x = np.unique(mat[:,0])
y = np.unique(mat[:,1])

z = mat[:,2].reshape((len(x), len(y)))

plt.title(u"Sieć marki Armadillo")

plt.contourf(x,y,z, cmap=plt.cm.Spectral)

plt.show()








# plt.show()