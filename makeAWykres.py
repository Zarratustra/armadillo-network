# coding=utf-8
import matplotlib.pyplot as plt
import numpy as np
import sklearn
import sklearn.datasets
import sklearn.linear_model
import matplotlib
from pprint import pprint
from scipy.interpolate import griddata

# convertToCsv(y)

print u"Wykreślamy wykresy"

mat = np.loadtxt("output.csv",delimiter=",")
positions = np.loadtxt("positions.csv",delimiter=",")
classification = np.loadtxt("przynaleznosc.csv",delimiter=",")

print mat[:,0]

x = np.unique(mat[:,0])
y = np.unique(mat[:,1])

z = mat[:,2].reshape((len(y), len(x)))

plt.title(u"Sieć marki Armadillo")

plt.contourf(x,y,z, cmap=plt.cm.Spectral)

plt.scatter(positions[:,0], positions[:,1], s=40, c=classification, cmap=plt.cm.Spectral)
# grid_x, grid_y = np.mgrid[-4:4:1000j, -4:4:1000j]
#
# points = mat[:,0:2]
# values = mat[:,2]
#
# grid_z0 = griddata(points, values, (grid_x, grid_y), method='nearest')
# plt.imshow(grid_z0.T, extent=(-3,3,-2,2), origin='lower')

plt.show()
