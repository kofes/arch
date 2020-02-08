import sys
import csv
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d
import math

import os
from os.path import dirname, abspath
directory = dirname(dirname(abspath(__file__)))


# Read CSV
csvFileName = sys.argv[1]
csvData = []
with open(csvFileName, 'r') as csvFile:
    csvReader = csv.reader(csvFile, delimiter=' ')
    for csvRow in csvReader:
        csvData.append(csvRow)

# Get X, Y, Z
csvData = np.array(csvData)
csvData = csvData.astype(np.float)
X, Y, Z = csvData[:,0], csvData[:,1], csvData[:,2]

data = {}

def indToId(ind):
    if ind == 0:
        return "switch"
    if ind == 1:
        return "if/else"
    if ind == 2:
        return "func"
    return "self-modfy"

for i in range(len(X)):
    typeid = int(X[i])
    count = int(Y[i])
    time = Z[i]
    if not (typeid in data):
        data[typeid] = {0: [], 1: []}
    data[typeid][0].append(count)
    data[typeid][1].append(time)

fig, ax = plt.subplots()
legends = []
for key in data:
    label = indToId(key)
    plt.plot(data[key][0], data[key][1], label=label)
    legends.append(label)
plt.ylabel("среднее время на переход, нс")
plt.xlabel("количество рассматриваемых ветвлений")
plt.legend(legends)
fig.savefig(directory + "/image/complete.png")
# 
fig, ax = plt.subplots()
legends = []
for key in data:
    if key < 3:
        continue
    label = indToId(key)
    plt.plot(data[key][0], data[key][1], label=label)
    legends.append(label)
plt.ylabel("среднее время на переход, нс")
plt.xlabel("количество рассматриваемых ветвлений")
plt.legend(legends)
fig.savefig(directory + "/image/self-modify.png")
# 
fig, ax = plt.subplots()
legends = []
for key in data:
    if key > 2:
        continue
    label = indToId(key)
    plt.plot(data[key][0], data[key][1], label=label)
    legends.append(label)
plt.ylabel("среднее время на переход, нс")
plt.xlabel("количество рассматриваемых ветвлений")
plt.legend(legends)
fig.savefig(directory + "/image/without-self-modify.png")