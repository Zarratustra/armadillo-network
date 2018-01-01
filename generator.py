import sklearn
from sklearn.datasets import make_moons
import csv

positions, y = sklearn.datasets.make_moons(1000, noise=0.20)
with open('positions.csv', 'wb') as csvfile:
    spamwriter = csv.writer(csvfile, delimiter=',')
    for item in positions[0:700]:
        print str(item)
        spamwriter.writerow([str(item[0]) + " ", item[1]])
with open('przynaleznosc.csv', 'wb') as csvfile:
    spamwriter = csv.writer(csvfile, delimiter=',')
    spamwriter.writerow(y[0:700])
with open('test.csv', 'wb') as csvfile:
    spamwriter = csv.writer(csvfile, delimiter=',')
    for item in positions[700:1000]:
        print str(item)
        spamwriter.writerow([str(item[0]) + " ", item[1]])
with open('przynaleznosc_test.csv', 'wb') as csvfile:
    spamwriter = csv.writer(csvfile, delimiter=',')
    spamwriter.writerow(y[700:1000])
